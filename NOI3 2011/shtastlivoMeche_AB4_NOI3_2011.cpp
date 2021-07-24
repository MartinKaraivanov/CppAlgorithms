#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

struct DanniZaPatq{
    int dalzhina;
    long double kolkoPatiSeSreshta;
};

int strana;
int nachalo;
int krai;

int chi = 1;

vector<int> redove[50];
vector<int> sasedstvo[30000];

//int sasedstvo[2000][2000];

void praveneNaSasedstvoto(){
    for(int i = 0; i < 2 * strana - 1; i++){
        if(i < strana - 1){
            for(unsigned int j = 0; j < redove[i].size(); j++){
                if(j < redove[i].size() - 1){
                    sasedstvo[redove[i][j + 1]].push_back(redove[i][j]);
                    //sasedstvo[redove[i][j]][redove[i][j+1]] = 1;
                }
                sasedstvo[redove[i + 1][j]].push_back(redove[i][j]);
                //sasedstvo[redove[i][j]][redove[i + 1][j]] = 1;
                sasedstvo[redove[i + 1][j + 1]].push_back(redove[i][j]);
                //sasedstvo[redove[i][j]][redove[i + 1][j+1]] = 1;
            }
        }else{
            for(unsigned int j = 0; j < redove[i].size(); j++){
                if(j < redove[i].size() - 1){
                    sasedstvo[redove[i][j + 1]].push_back(redove[i][j]);
                    //sasedstvo[redove[i][j]][redove[i][j+1]] = 1;
                    if(i < 2*strana - 2){
                        sasedstvo[redove[i + 1][j]].push_back(redove[i][j]);
                        //sasedstvo[redove[i][j]][redove[i + 1][j]] = 1;
                    }
                }
                if(j > 0){
                    if(i < 2*strana - 2){
                        sasedstvo[redove[i + 1][j - 1]].push_back(redove[i][j]);
                        //sasedstvo[redove[i][j]][redove[i + 1][j-1]] = 1;
                    }
                }
            }
        }
    }
}

int naiDalagPat[2000][2000];
long long broiNaiDalagPat[2000][2000];

/*void floyd(){
    for(int i = 1; i < chi; i++){
        for(int j = 1; j < chi; j++){
            naiDalagPat[i][j] = sasedstvo[i][j];
            if(sasedstvo[i][j] > 0){
                broiNaiDalagPat[i][j] = 1;
            }
        }
    }

    for(int m = nachalo + 1; m < krai; m++){
        for(int i = nachalo; i < m; i++){
            for(int j = m + 1; j <= krai; j++){
                if(naiDalagPat[i][m] == 0 || naiDalagPat[m][j] == 0){
                    continue;
                }
                if(naiDalagPat[i][m] + naiDalagPat[m][j] > naiDalagPat[i][j]){
                    naiDalagPat[i][j] = naiDalagPat[i][m] + naiDalagPat[m][j];
                    broiNaiDalagPat[i][j] = broiNaiDalagPat[i][m] * broiNaiDalagPat[m][j];
                }else{
                    if(naiDalagPat[i][m] + naiDalagPat[m][j]  == naiDalagPat[i][j]){
                        broiNaiDalagPat[i][j] = broiNaiDalagPat[i][j] + (broiNaiDalagPat[i][m] * broiNaiDalagPat[m][j]);
                    }
                }
            }
        }
    }
}*/

DanniZaPatq priTolkova[2000];

DanniZaPatq naiGolqmaPechalba(int doKoi){
    if(doKoi == nachalo){
        return {1, 1};
    }
    if(doKoi < nachalo){
        return {-10000000, -10000000};
    }

    if(priTolkova[doKoi].dalzhina > 0 && priTolkova[doKoi].kolkoPatiSeSreshta > 0){
        return priTolkova[doKoi];
    }

    int naiMnogo = -10000000;
    long double kolkoPati = -10000000;

    for(unsigned int i = 0; i < sasedstvo[doKoi].size(); i++){
        DanniZaPatq segashno = naiGolqmaPechalba(sasedstvo[doKoi][i]);

        int med = 1 + segashno.dalzhina;

        if(med > naiMnogo){
            naiMnogo = med;
            kolkoPati = segashno.kolkoPatiSeSreshta;
        }else{
            if(med == naiMnogo){
                kolkoPati += segashno.kolkoPatiSeSreshta;
            }
        }
    }

    priTolkova[doKoi] = {naiMnogo, kolkoPati};
    return {naiMnogo, kolkoPati};
}

int main(){
    cin>>strana>>nachalo>>krai;

    for(int i = 0; i < strana * 2 - 1; i++){
        if(i < strana){
            int broiche = 0;

            while(broiche < i + strana){
                redove[i].push_back(chi);
                chi++;
                broiche++;
            }
        }else{
            int broiche = 0;

            while(broiche < (2*strana - i - 2) + strana){
                redove[i].push_back(chi);
                chi++;
                broiche++;
            }
        }
    }

    praveneNaSasedstvoto();

    /*for(int i = 0; i < strana * 2 - 1; i++){
        for(int j : redove[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }*/

    /*for(int i = 1; i < chi; i++){
        cout<<i<<":"<<endl;
        for(int j : sasedstvo[i]){
            cout<<j<<" ";
        }
        cout<<endl<<endl;
    }*/

    /*for(int i = 1; i < chi; i++){
        cout<<i<<":"<<endl;
        for(int j = 1; j < chi; j++){
            if(sasedstvo[i][j] > 0){
                cout<<j<<" ";
            }
        }
        cout<<endl<<endl;
    }*/

    /*for(int i = 1; i < chi; i++){
        for(int j = 1; j < chi; j++){
            cout<<i<<" "<<j<<" "<<naiDalagPat[i][j]<<" "<<broiNaiDalagPat[i][j]<<endl;
        }
    }*/

    //floyd();

    /*for(int i = 1; i < chi; i++){
        for(int j = 1; j < chi; j++){
            cout<<i<<" "<<j<<" "<<naiDalagPat[i][j]<<" "<<broiNaiDalagPat[i][j]<<endl;
        }
    }*/

    /*if(naiDalagPat[nachalo][krai] > 0){
        cout<<naiDalagPat[nachalo][krai] + 1<<" "<<broiNaiDalagPat[nachalo][krai]<<endl;
    }else{
        cout<<0<<" "<<0<<endl;
    }*/


    DanniZaPatq naiMnogoMed = naiGolqmaPechalba(krai);

    if(naiMnogoMed.dalzhina > 0){
        cout<<naiMnogoMed.dalzhina<<" "<<fixed<<setprecision(0)<<naiMnogoMed.kolkoPatiSeSreshta<<endl;
    }else{
        cout<<0<<" "<<0<<endl;
    }

    return 0;
}
