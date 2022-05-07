#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

long long broiKvadratchetaStr;
long long broiNachalniCherni;
long long broiZaqvki;
long long parviteKolkoCherni;

struct Koordinati{
    long long y;
    long long x;

    bool operator==(const Koordinati &a) const
    {
        return y == a.y && x == a.x;
    }

    bool operator<(const Koordinati &a) const
    {
        if(y < a.y){
            return true;
        }
        if(y > a.y){
            return false;
        }
        return x < a.x;
    }
};

set<Koordinati> cherniTochki;

bool koqEPoNapred(Koordinati a, Koordinati b){
    if(a.y < b.y){
        return true;
    }
    if(a.y > b.y){
        return false;
    }
    return a.x < b.x;
}

struct DanniZaMatrica33{
    long long a[3][3];
};

struct DanniZaMatrica22{
    long long a[2][2];
};

DanniZaMatrica33 daiMatricataNaR(){
    return {{{ 0, -1, broiKvadratchetaStr+1},
             { 1,  0,  0},
             { 0,  0,  1}}};
}

DanniZaMatrica33 daiMatricataNaL(){
    return {{{ 0,  1,  0},
             {-1,  0, broiKvadratchetaStr+1},
             { 0,  0,  1}}};
}

DanniZaMatrica33 daiMatricataNaQ(){
    return  {{{-1,  0, broiKvadratchetaStr+1},
              { 0, -1, broiKvadratchetaStr+1},
              { 0,  0,  1}}};
}

DanniZaMatrica33 daiMatricataNaH(){
    return {{{-1,  0, broiKvadratchetaStr+1},
             { 0,  1,  0},
             { 0,  0,  1}}};
}

DanniZaMatrica33 daiMatricataNaV(){
    return {{{ 1,  0,  0},
             { 0, -1, broiKvadratchetaStr+1},
             { 0,  0,  1}}};
}

DanniZaMatrica33 daiIdentitetna(){
    return {{{ 1,  0,  0},
             { 0,  1,  0},
             { 0,  0,  1}}};
}

DanniZaMatrica33 daiPodhodqshtataMatrica(char operaciq){

    if(operaciq == 'R'){
        return daiMatricataNaR();
    }
    if(operaciq == 'L'){
        return daiMatricataNaL();
    }
    if(operaciq == 'Q'){
        return daiMatricataNaQ();
    }
    if(operaciq == 'H'){
        return daiMatricataNaH();
    }
    return daiMatricataNaV(); /// V
}

long long det33(DanniZaMatrica33 matr){

    long long det = 0;

    for(long long diag = 0; diag < 3; diag++){
        long long tukaNadqsno = 1;

        for(long long red = 0; red < 3; red++){
            tukaNadqsno *= matr.a[(red)%3][(red + diag)%3];
        }

        det += tukaNadqsno;
    }

    for(long long diag = 0; diag < 3; diag++){
        long long tukaNalqvo = 1;

        for(long long red = 0; red < 3; red++){
            tukaNalqvo *= matr.a[(red)%3][(diag - red + 3)%3];
        }

        det -= tukaNalqvo;
    }

    return det;
}

DanniZaMatrica33 transponirane33(DanniZaMatrica33 matr){

    DanniZaMatrica33 res;

    for(long long i = 0; i < 3; i++){
        for(long long j = 0; j < 3; j++){
            res.a[i][j] = matr.a[j][i];
        }
    }

    return res;
}

long long det22(DanniZaMatrica22 matr){

    long long det = matr.a[0][0]*matr.a[1][1] - matr.a[0][1]*matr.a[1][0];

    return det;
}

DanniZaMatrica33 umnojiMatrici33(DanniZaMatrica33 parva, DanniZaMatrica33 vtora){

    DanniZaMatrica33 rezultatna;

    for(long long i = 0; i < 3; i++){
        for(long long j = 0; j < 3; j++){

            rezultatna.a[i][j] = 0;

            for(long long k = 0; k < 3; k++){
                rezultatna.a[i][j] += parva.a[i][k]*vtora.a[k][j];
            }
        }
    }

    return rezultatna;
}

DanniZaMatrica22 mahniRedIKolona(DanniZaMatrica33 originalna, long long koiRed, long long koqKolona){

    DanniZaMatrica22 res;

    for(long long i = 0; i < 2; i++){
        for(long long j = 0; j < 2; j++){
            long long starRed = i;
            long long staraKolona = j;

            if (i >= koiRed){
                starRed++;
            }

            if (j >= koqKolona){
                staraKolona++;
            }

            res.a[i][j] = originalna.a[starRed][staraKolona];
        }
    }

    return res;
}

DanniZaMatrica33 daiObratnaMatrica(DanniZaMatrica33 matr){

    DanniZaMatrica33 obr;

    for(long long i = 0; i < 3; i++){
        for(long long j = 0; j < 3; j++){
            obr.a[i][j] = det22(mahniRedIKolona(matr, i, j));

            if((i+j) % 2 == 1){
                obr.a[i][j] *= -1;
            }
        }
    }

    obr = transponirane33(obr);

    long long det = det33(matr);

    for(long long i = 0; i < 3; i++){
        for(long long j = 0; j < 3; j++){
            if(obr.a[i][j] % det != 0){
                cout<<"grozen text"<<endl;
            }
            obr.a[i][j] /= det;
        }
    }

    return obr;
}


Koordinati umnojiMatricaSVector(DanniZaMatrica33 matr, Koordinati tochka){

    long long novX = matr.a[0][0]*tochka.x + matr.a[0][1]*tochka.y + matr.a[0][2]*1;
    long long novY = matr.a[1][0]*tochka.x + matr.a[1][1]*tochka.y + matr.a[1][2]*1;

    return {novY, novX};
}

int main(){

    cin>>broiKvadratchetaStr>>broiNachalniCherni>>broiZaqvki;

    for(long long i = 0; i < broiNachalniCherni; i++){
        long long y;
        long long x;
        cin>>y>>x;

        cherniTochki.insert({y, x});
    }

    DanniZaMatrica33 sastoqnie = daiIdentitetna();

    for(long long i = 0; i < broiZaqvki; i++){
        long long tip;

        cin>>tip;

        if(tip == 1){
            char koqOperaciq;

            cin>>koqOperaciq;

            sastoqnie = umnojiMatrici33(daiPodhodqshtataMatrica(koqOperaciq), sastoqnie);
        }else{
            long long y;
            long long x;

            cin>>y>>x;

            Koordinati originalnaTochka = umnojiMatricaSVector(daiObratnaMatrica(sastoqnie), {y, x});

            //cout<<"pitame za tochka "<<originalnaTochka.y<<" "<<originalnaTochka.x<<endl;

            if(cherniTochki.find(originalnaTochka) != cherniTochki.end()){
                cherniTochki.erase(originalnaTochka);
                //cout<<"imashe q i q iztrihme "<<endl;
            }else{
                cherniTochki.insert(originalnaTochka);
                //cout<<"nqmashe q i q dobavihme "<<endl;
            }
        }

    }

    cin>>parviteKolkoCherni;

    vector<Koordinati> kraini;

    for(set<Koordinati>::iterator a = cherniTochki.begin(); a != cherniTochki.end(); a++){
        kraini.push_back(umnojiMatricaSVector(sastoqnie, *a));
    }

    sort(kraini.begin(), kraini.end(), koqEPoNapred);

    for(long long i = 0; i < parviteKolkoCherni; i++){
        cout<<kraini[i].y<<" "<<kraini[i].x<<endl;
    }

    return 0;
}
