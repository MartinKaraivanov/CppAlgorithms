#include<iostream>
#include<vector>
using namespace std;

int maxXiY;
int broiPatiNalyavoINagore;

long long kakvoImaTam[1005][1005];

long long priTolkova[1010][1010][110];

long long naiGolqmaVazmozhnaSuma(int x, int y, int broiZaNadoluINadqsno){
    if(x == 0 && y == 0){
        return kakvoImaTam[x][y];
    }

    if(priTolkova[x][y][broiZaNadoluINadqsno] > -1){
        return priTolkova[x][y][broiZaNadoluINadqsno];
    }

    long long sumaSNadolu = 0;
    long long sumaSNadqsno = 0;
    long long sumaSNalqvo = 0;
    long long sumaSNagore = 0;

    if(broiZaNadoluINadqsno > 0){
        if(y < maxXiY - 1){
            sumaSNadolu = kakvoImaTam[x][y] + naiGolqmaVazmozhnaSuma(x, y + 1, broiZaNadoluINadqsno - 1);
        }
        if(x < maxXiY - 1){
            sumaSNadqsno = kakvoImaTam[x][y] + naiGolqmaVazmozhnaSuma(x + 1, y, broiZaNadoluINadqsno - 1);
        }
    }

    if(x > 0){
        sumaSNalqvo = kakvoImaTam[x][y] + naiGolqmaVazmozhnaSuma(x - 1, y, broiZaNadoluINadqsno);
    }

    if(y > 0){
        sumaSNagore = kakvoImaTam[x][y] + naiGolqmaVazmozhnaSuma(x, y - 1, broiZaNadoluINadqsno);
    }

    long long naiDobro = max(max(sumaSNadolu, sumaSNadqsno), max(sumaSNalqvo, sumaSNagore));

    priTolkova[x][y][broiZaNadoluINadqsno] = naiDobro;
    return naiDobro;
}

int sCycli(int zaX, int zaY, int zaTolkovaNalqvoNagore){
    for(int z = 0; z <= broiPatiNalyavoINagore; z++){
        priTolkova[0][0][z] = kakvoImaTam[0][0];
    }

    for(int broiZaNadoluINadqsno = 0; broiZaNadoluINadqsno <= zaTolkovaNalqvoNagore; broiZaNadoluINadqsno++){
        for(int x = 0; x <= zaX; x++){
            for(int y = 0; y <= zaY; y++){
                if(x == 0 && y == 0){
                    continue;
                }
                long long sumaSNadolu = 0;
                long long sumaSNadqsno = 0;
                long long sumaSNalqvo = 0;
                long long sumaSNagore = 0;

                if(broiZaNadoluINadqsno > 0){
                    if(y < zaY){
                        sumaSNadolu = kakvoImaTam[x][y] + priTolkova[x][y + 1][broiZaNadoluINadqsno - 1];
                    }
                    if(x < zaX){
                        sumaSNadqsno = kakvoImaTam[x][y] + priTolkova[x + 1][y][broiZaNadoluINadqsno - 1];
                    }
                }

                if(x > 0){
                    sumaSNalqvo = kakvoImaTam[x][y] + priTolkova[x - 1][y][broiZaNadoluINadqsno];
                }

                if(y > 0){
                    sumaSNagore = kakvoImaTam[x][y] + priTolkova[x][y - 1][broiZaNadoluINadqsno];
                }

                long long naiDobro = max(max(sumaSNadolu, sumaSNadqsno), max(sumaSNalqvo, sumaSNagore));

                priTolkova[x][y][broiZaNadoluINadqsno] = naiDobro;
            }
        }
    }

    return priTolkova[zaX][zaY][zaTolkovaNalqvoNagore];
}

int priTolkova2[1010][1010];

int sCycli2(int zaX, int zaY, int zaTolkovaNalqvoNagore){
    priTolkova2[0][0] = kakvoImaTam[0][0];

    for(int broiZaNadoluINadqsno = 0; broiZaNadoluINadqsno <= zaTolkovaNalqvoNagore; broiZaNadoluINadqsno++){
        for(int x = 0; x <= zaX; x++){
            for(int y = 0; y <= zaY; y++){
                if(x == 0 && y == 0){
                    continue;
                }
                long long sumaSNadolu = 0;
                long long sumaSNadqsno = 0;
                long long sumaSNalqvo = 0;
                long long sumaSNagore = 0;

                if(broiZaNadoluINadqsno > 0){
                    if(y < zaY){
                        sumaSNadolu = kakvoImaTam[x][y] + priTolkova2[x][y + 1];
                    }
                    if(x < zaX){
                        sumaSNadqsno = kakvoImaTam[x][y] + priTolkova2[x + 1][y];
                    }
                }

                if(x > 0){
                    sumaSNalqvo = kakvoImaTam[x][y] + priTolkova2[x - 1][y];
                }

                if(y > 0){
                    sumaSNagore = kakvoImaTam[x][y] + priTolkova2[x][y - 1];
                }

                long long naiDobro = max(max(sumaSNadolu, sumaSNadqsno), max(sumaSNalqvo, sumaSNagore));

                priTolkova2[x][y] = naiDobro;
            }
        }
    }

    return priTolkova2[zaX][zaY];
}

int main(){
    cin>>maxXiY>>broiPatiNalyavoINagore;

    for(int y = 0; y < maxXiY; y++){
        for(int x = 0; x < maxXiY; x++){
            int tuk;
            cin>>tuk;
            kakvoImaTam[x][y] = tuk;
        }
    }

    /*for(int i = 0; i < maxXiY; i++){
        for(int j = 0; j < maxXiY; j++){
            for(int p = 0; p <= broiPatiNalyavoINagore; p++){
                priTolkova[i][j][p] = -1;
            }
        }
    }*/

    long long naiGolqmaSumaKoqtoMozhemDaVzemem = sCycli2(maxXiY - 1, maxXiY - 1, broiPatiNalyavoINagore);

    cout<<naiGolqmaSumaKoqtoMozhemDaVzemem<<endl;

    return 0;
}
