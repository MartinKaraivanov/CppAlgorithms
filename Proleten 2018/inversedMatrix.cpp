#include<iostream>
using namespace std;

struct Koordinati{
    int y;
    int x;
};

struct DanniZaMatrica33{
    int a[3][3];
};

struct DanniZaMatrica22{
    int a[2][2];
};

int det33(DanniZaMatrica33 matr){

    int det = 0;

    for(int diag = 0; diag < 3; diag++){
        int tukaNadqsno = 1;

        for(int red = 0; red < 3; red++){
            tukaNadqsno *= matr.a[(red)%3][(red + diag)%3];
        }

        det += tukaNadqsno;
    }

    for(int diag = 0; diag < 3; diag++){
        int tukaNalqvo = 1;

        for(int red = 0; red < 3; red++){
            tukaNalqvo *= matr.a[(red)%3][(diag - red + 3)%3];
        }

        det -= tukaNalqvo;
    }

    return det;
}

DanniZaMatrica33 transponirane33(DanniZaMatrica33 matr){

    DanniZaMatrica33 res;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            res.a[i][j] = matr.a[j][i];
        }
    }

    return res;
}

int det22(DanniZaMatrica22 matr){

    int det = matr.a[0][0]*matr.a[1][1] - matr.a[0][1]*matr.a[1][0];

    return det;
}

void otpechataiMatrichka33(DanniZaMatrica33 matr){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<matr.a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void otpechataiMatrichka22(DanniZaMatrica22 matr){

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout<<matr.a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

DanniZaMatrica33 umnojiMatrici33(DanniZaMatrica33 parva, DanniZaMatrica33 vtora){

    DanniZaMatrica33 rezultatna;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            rezultatna.a[i][j] = 0;

            for(int k = 0; k < 3; k++){
                rezultatna.a[i][j] += parva.a[i][k]*vtora.a[k][j];
            }
        }
    }

    return rezultatna;
}

DanniZaMatrica22 mahniRedIKolona(DanniZaMatrica33 originalna, int koiRed, int koqKolona){

    DanniZaMatrica22 res;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            int starRed = i;
            int staraKolona = j;

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

    /*int nomerNaRed = 0;
    int nomerNaKolona = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i != koiRed && j != koqKolona){
                res.a[nomerNaRed][nomerNaKolona] = originalna.a[i][j];
                nomerNaKolona++;

                if(nomerNaKolona >= 2){
                    nomerNaRed++;
                    nomerNaKolona = 0;
                }
            }
        }
    }

    return res;*/
}

DanniZaMatrica33 daiObratnaMatrica(DanniZaMatrica33 matr){

    DanniZaMatrica33 obr;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            obr.a[i][j] = det22(mahniRedIKolona(matr, i, j));

            if((i+j) % 2 == 1){
                obr.a[i][j] *= -1;
            }
        }
    }

    obr = transponirane33(obr);

    int det = det33(matr);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            obr.a[i][j] /= det;
        }
    }

    return obr;
}

DanniZaMatrica33 daiMatricataNaR(){
    return {{{ 0, -1, 11},
             { 1,  0,  0},
             { 0,  0,  1}}};
}

DanniZaMatrica33 daiMatricataNaL(){
    return {{{ 0,  1,  0},
             {-1,  0, 11},
             { 0,  0,  1}}};
}

DanniZaMatrica33 daiMatricataNaQ(){
    return  {{{-1,  0, 11},
              { 0, -1, 11},
              { 0,  0,  1}}};
}

DanniZaMatrica33 daiMatricataNaH(){
    return {{{-1,  0, 11},
             { 0,  1,  0},
             { 0,  0,  1}}};
}

DanniZaMatrica33 daiMatricataNaV(){
    return {{{ 1,  0,  0},
             { 0, -1, 11},
             { 0,  0,  1}}};
}

Koordinati umnojiMatricaSVector(DanniZaMatrica33 matr, Koordinati tochka){

    int novX = matr.a[0][0]*tochka.x + matr.a[0][1]*tochka.y + matr.a[0][2]*1;
    int novY = matr.a[1][0]*tochka.x + matr.a[1][1]*tochka.y + matr.a[1][2]*1;

    return {novY, novX};
}

int main(){

    DanniZaMatrica33 m = {{{ 0, -1, 11},
                           { 1,  0,  0},
                           { 0,  0,  1}}};

    /*int det =   m.a[0][0]*m.a[1][1]*m.a[2][2] +
                m.a[0][1]*m.a[1][2]*m.a[3][0] +
                m.a[0][2]*m.a[1][0]*m.a[2][1] -
                m.a[0][2]*m.a[1][1]*m.a[2][0] -
                m.a[0][1]*m.a[1][0]*m.a[2][2] -
                m.a[0][0]*m.a[1][2]*m.a[2][1];*/

    Koordinati zavarti11 = umnojiMatricaSVector(daiMatricataNaV(), {2, 3});
    cout<<"zavartqh q "<<zavarti11.y<<" "<<zavarti11.x<<endl<<endl;

    DanniZaMatrica33 startova = {{{ 1,  0,  0},
                                  { 0,  1,  0},
                                  { 0,  0,  1}}};

    cout<<"probno we"<<endl;
    otpechataiMatrichka33(umnojiMatrici33(daiMatricataNaR(), startova));
    cout<<endl;

    otpechataiMatrichka33(m);

    int det = det33(m);

    cout<<det<<endl<<endl;

    /*DanniZaMatrica33 obratnaMatrichka = {{{m.a[1][1]*m.a[2][2] - m.a[1][2]*m.a[2][1], m.a[1][0]*m.a[2][2] - m.a[1][2]*m.a[2][0], m.a[1][0]*m.a[2][1] - m.a[1][1]*m.a[2][0]},
                                          {m.a[0][1]*m.a[2][2] - m.a[0][2]*m.a[2][1], m.a[0][0]*m.a[2][2] - m.a[0][2]*m.a[2][0], m.a[0][0]*m.a[2][1] - m.a[0][1]*m.a[2][0]},
                                          {m.a[0][1]*m.a[1][2] - m.a[0][2]*m.a[1][1], m.a[0][0]*m.a[1][2] - m.a[0][2]*m.a[1][0], m.a[0][0]*m.a[1][1] - m.a[0][1]*m.a[1][0]}}};

    obratnaMatrichka = transponirane33(obratnaMatrichka);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            obratnaMatrichka.a[i][j] /= det;
        }
    }

    otpechataiMatrichka33(obratnaMatrichka);*/

    DanniZaMatrica33 obratnaMatrichka = daiObratnaMatrica(m);

    otpechataiMatrichka33(obratnaMatrichka);

    DanniZaMatrica33 obratnaNaObratna = daiObratnaMatrica(obratnaMatrichka);

    otpechataiMatrichka33(obratnaNaObratna);


    DanniZaMatrica33 nqkakva = umnojiMatrici33(m, obratnaMatrichka);

    otpechataiMatrichka33(nqkakva);

    return 0;
}
