#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct masiv{
    int masiv[3][3];
};

masiv nachalno;

masiv kraino;

map<int, bool> visited;
map<int, int> dalbochina;

vector<int> otChisloVavVector(int chislo){
    vector<int> zaVrasht;
    zaVrasht.resize(9);

    int index = 8;
    while(chislo > 0){
        zaVrasht[index] = chislo % 10;
        chislo /= 10;
        index--;
    }

    return zaVrasht;
}

masiv otVectorVTablica(vector<int> chisla){
    masiv zaVrasht;

    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            zaVrasht.masiv[y][x] = chisla[y * 3 + x];
        }
    }

    return zaVrasht;
}

masiv otChisloDoTablica(int chislo){
    vector<int> vctor = otChisloVavVector(chislo);
    masiv msiv = otVectorVTablica(vctor);

    return msiv;
}

vector<int> otTablicaVavVector(masiv tablica){
    vector<int> zaVrasht;

    zaVrasht.resize(9);

    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            zaVrasht[y*3 + x] = tablica.masiv[y][x];
        }
    }

    return zaVrasht;
}

int otVectorVChislo(vector<int> chislata){
    int zaVrasht = 0;

    for(unsigned int i = 0; i < chislata.size(); i++){
        zaVrasht = 10*zaVrasht + chislata[i];
    }

    return zaVrasht;
}

int otTablicaDoChislo(masiv msiv){
    vector<int> vctor = otTablicaVavVector(msiv);
    int chisl = otVectorVChislo(vctor);

    return chisl;
}

bool tovaSansuLiE(masiv p){
    int kvadratche[3][3];

    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            kvadratche[y][x] = p.masiv[y][x];
        }
    }

    bool hubavoLiE = true;

    for(int x = 0; x < 3; x++){
        int sborTuka = 0;
        for(int y = 0; y < 3; y++){
            sborTuka += kvadratche[y][x];
        }
        if(sborTuka % 3 != 0){
            hubavoLiE = false;
        }
    }

    for(int y = 0; y < 3; y++){
        int sborTuka = 0;
        for(int x = 0; x < 3; x++){
            sborTuka += kvadratche[y][x];
        }
        if(sborTuka % 3 != 0){
            hubavoLiE = false;
        }
    }

    int ediniqDiagonal = kvadratche[0][0] + kvadratche[1][1] + kvadratche[2][2];
    int drugiqDiagonal = kvadratche[0][2] + kvadratche[1][1] + kvadratche[2][0];

    if(ediniqDiagonal % 3 != 0 || drugiqDiagonal % 3 != 0){
        hubavoLiE = false;
    }

    return hubavoLiE;
}

int naiMalkoStapki = 30;

void namirane(){
    int nachalnoChislo = otTablicaDoChislo(nachalno);

    queue<int> q;
    q.push(nachalnoChislo);
    visited[nachalnoChislo];
    dalbochina[nachalnoChislo] = 0;

    while(q.empty() == false){
        int naiOtpred = q.front();
        q.pop();

        /*if(dalbochina[naiOtpred] > 27){
            break;
        }*/

        masiv tablicaNaChisloto = otChisloDoTablica(naiOtpred);
        if(visited[naiOtpred] == true){
            continue;
        }

        visited[naiOtpred] = true;

        if(tovaSansuLiE(tablicaNaChisloto)){
            naiMalkoStapki = dalbochina[naiOtpred];
            kraino = tablicaNaChisloto;
            break;
        }

        for(int y = 0; y < 3; y++){
            for(int x = 0; x < 3; x++){

                if(x < 2){
                    masiv nov = tablicaNaChisloto;

                    swap(nov.masiv[y][x], nov.masiv[y][x + 1]);

                    int chisloNaNov = otTablicaDoChislo(nov);

                    dalbochina[chisloNaNov] = 1 + dalbochina[naiOtpred];

                    if(visited[chisloNaNov] == false){
                        q.push(chisloNaNov);
                    }
                }
                if(y < 2){
                    masiv nov = tablicaNaChisloto;

                    swap(nov.masiv[y][x], nov.masiv[y + 1][x]);

                    int chisloNaNov = otTablicaDoChislo(nov);

                    dalbochina[chisloNaNov] = 1 + dalbochina[naiOtpred];

                    if(visited[chisloNaNov] == false){
                        q.push(chisloNaNov);
                    }
                }

            }
        }

    }

}

/*void premestvane(int naKoiHod, int predishnoSmenenX, int predishnoSmenenY){
    if(naKoiHod > 8){
        return ;
    }

    if(tovaSansuLiE(nachalno) == true){
        if(naKoiHod < naiMalkoStapki){
            naiMalkoStapki = naKoiHod;
            for(int y = 0; y < 3; y++){
                for(int x = 0; x < 3; x++){
                    kraino[y][x] = nachalno[y][x];
                }
            }
        }

        return ;
    }


    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){

            if(x < 2 && (x != predishnoSmenenX || y != predishnoSmenenY) && (nachalno[y][x] % 3 != nachalno[y][x + 1] % 3)){
                swap(nachalno[y][x], nachalno[y][x + 1]);

                premestvane(naKoiHod + 1, x, y);

                swap(nachalno[y][x], nachalno[y][x + 1]);
            }
            if(y < 2 && (x != predishnoSmenenX || y != predishnoSmenenY) && (nachalno[y][x] % 3 != nachalno[y + 1][x] % 3)){
                swap(nachalno[y][x], nachalno[y + 1][x]);

                premestvane(naKoiHod + 1, x, y);

                swap(nachalno[y][x], nachalno[y + 1][x]);
            }

        }
    }

}*/

int main(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin>>nachalno.masiv[i][j];
        }
    }

    //premestvane(0, -1 , -1);

    namirane();

    cout<<naiMalkoStapki<<endl;

    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            cout<<kraino.masiv[y][x]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
