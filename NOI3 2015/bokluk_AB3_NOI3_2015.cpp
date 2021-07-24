#include<iostream>
#include<vector>
using namespace std;

short maxY;
short maxX;

short bokluci[105][105];

short zaYKaFunkciqta[101][101][101];

short priYOtTolkovaDoTolkovaiXTolkova(short nachalenY, short kraenY, short xche){
    if(zaYKaFunkciqta[nachalenY][kraenY][xche] > 0){
        return zaYKaFunkciqta[nachalenY][kraenY][xche];
    }

    short naiGoliqmao = 0;
    for(short y = nachalenY; y <= kraenY; y++){
        naiGoliqmao = max(naiGoliqmao, bokluci[xche][y]);
    }

    zaYKaFunkciqta[nachalenY][kraenY][xche] = naiGoliqmao;
    return naiGoliqmao;
}

short zaXFunkciqta[101][101][101];

short priXOtTolkovaDoTokovaIYTolkova(short nachalenX, short kraenX, short ych){
    if(zaXFunkciqta[nachalenX][kraenX][ych] > 0){
        return zaXFunkciqta[nachalenX][kraenX][ych];
    }

    short naiGolqmo = 0;
    for(short x = nachalenX; x <= kraenX; x++){
        naiGolqmo = max(naiGolqmo, bokluci[x][ych]);
    }

    zaXFunkciqta[nachalenX][kraenX][ych] = naiGolqmo;
    return naiGolqmo;
}

vector<vector<short>> priTolkova[101][101];

short naiMalkoEnergiqIzrazhodvana(short nachalenY, short nachalenX, short dalzhinaPoY, short dalzhinaPoX){
    if(dalzhinaPoY <= 0 || dalzhinaPoX <= 0){
        return 0;
    }

    if(priTolkova[nachalenY][nachalenX][dalzhinaPoY][dalzhinaPoX] > 0){
        return priTolkova[nachalenY][nachalenX][dalzhinaPoY][dalzhinaPoX];
    }

    short lqvaEnergiq = priYOtTolkovaDoTolkovaiXTolkova(nachalenY, nachalenY + dalzhinaPoY - 1, nachalenX);

    short gornaEnergiq = priXOtTolkovaDoTokovaIYTolkova(nachalenX, nachalenX + dalzhinaPoX - 1, nachalenY);

    short dqsnaEnergiq = priYOtTolkovaDoTolkovaiXTolkova(nachalenY, nachalenY + dalzhinaPoY - 1, nachalenX+dalzhinaPoX-1);

    short dolnaEnergiq = priXOtTolkovaDoTokovaIYTolkova(nachalenX, nachalenX + dalzhinaPoX - 1, nachalenY+dalzhinaPoY-1);

    lqvaEnergiq = lqvaEnergiq + naiMalkoEnergiqIzrazhodvana(nachalenY, nachalenX + 1, dalzhinaPoY, dalzhinaPoX - 1);
    gornaEnergiq = gornaEnergiq + naiMalkoEnergiqIzrazhodvana(nachalenY + 1, nachalenX, dalzhinaPoY - 1, dalzhinaPoX);
    dqsnaEnergiq = dqsnaEnergiq + naiMalkoEnergiqIzrazhodvana(nachalenY, nachalenX, dalzhinaPoY, dalzhinaPoX - 1);
    dolnaEnergiq = dolnaEnergiq + naiMalkoEnergiqIzrazhodvana(nachalenY, nachalenX, dalzhinaPoY - 1, dalzhinaPoX);

    short naiMalkoKolichestvoEnergy = min(min(lqvaEnergiq, dqsnaEnergiq), min(gornaEnergiq, dolnaEnergiq));

    priTolkova[nachalenY][nachalenX][dalzhinaPoY][dalzhinaPoX] = naiMalkoKolichestvoEnergy;
    return naiMalkoKolichestvoEnergy;
}

short sCycli(short nachalenY, short nachalenX, short dalzhinaPoY, short dalzhinaPoX){

    for(short dalzY = 1; dalzY <= maxY; dalzY++){
        for(short dalzX = 1; dalzX <= maxX; dalzX++){
            for(short startY = 0; startY <= maxY - dalzY; startY++){
                for(short startX = 0; startX <= maxX - dalzX; startX++){

                    short lqvaEnergiq = priYOtTolkovaDoTolkovaiXTolkova(startY, startY + dalzY - 1, startX);

                    short gornaEnergiq = priXOtTolkovaDoTokovaIYTolkova(startX,startX+dalzX-1, startY);

                    short dqsnaEnergiq = priYOtTolkovaDoTolkovaiXTolkova(startY,startY+dalzY-1,startX+dalzX-1);

                    short dolnaEnergiq = priXOtTolkovaDoTokovaIYTolkova(startX,startX+dalzX-1,startY+dalzY-1);

                    lqvaEnergiq += priTolkova[startY][startX + 1][dalzY][dalzX - 1];
                    gornaEnergiq += priTolkova[startY + 1][startX][dalzY - 1][dalzX];
                    dqsnaEnergiq += priTolkova[startY][startX][dalzY][dalzX - 1];
                    dolnaEnergiq += priTolkova[startY][startX][dalzY - 1][dalzX];

                    short naiMalkoKolichestvoEnergy = min(min(lqvaEnergiq, dqsnaEnergiq), min(gornaEnergiq, dolnaEnergiq));

                    priTolkova[startY][startX][dalzY][dalzX] = naiMalkoKolichestvoEnergy;

                }
            }
        }
    }

    return priTolkova[nachalenY][nachalenX][dalzhinaPoY][dalzhinaPoX];
}

int main(){
    cin>>maxY>>maxX;

    for(short y = 0; y < maxY; y++){
        for(short x = 0; x < maxX; x++){
            cin>>bokluci[x][y];
        }
    }

    for(short y = 0; y <= maxY; y++){
        for(short x = 0; x <= maxX; x++){
            priTolkova[y][x] = vector<vector<short>>(maxY - y + 2);
            for(short dy = 0; dy <= maxY - y; dy++){
                priTolkova[y][x][dy] = vector<short>(maxX - x + 2);
            }
        }
    }

    short naiMalkoKolichestvoEnergiq = sCycli(0, 0, maxY, maxX);

    cout<<naiMalkoKolichestvoEnergiq<<endl;

    return 0;
}
