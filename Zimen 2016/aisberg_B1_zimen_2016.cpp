#include<iostream>
#include<cmath>
using namespace std;

int maxY;
int maxX;

int more[350][350];

bool visited[350][350];

int broiNuliokoloTozi[350][350];

void obhozhdane(int segX, int segY){
    if(visited[segX][segY] == true || more[segX][segY] <= 0){
        return ;
    }
    visited[segX][segY] = true;

    obhozhdane(segX - 1, segY);
    obhozhdane(segX + 1, segY);
    obhozhdane(segX, segY - 1);
    obhozhdane(segX, segY + 1);
}

int broiOstrovcheta(){
    int pravX = -1;
    int pravY = -1;

    for(int y = 1; y <= maxY; y++){
        for(int x = 1; x <= maxX; x++){
            if(more[x][y] > 0){
                pravX = x;
                pravY = y;
                break;
            }
        }
        if(pravX > 0){
            break;
        }
    }

    if(pravX == -1 && pravY == -1){
        return 0;
    }

    //cout<<pravX<<" "<<pravY<<endl;

    obhozhdane(pravX, pravY);

    int brOstrvcheta = 1;

    for(int y = 1; y <= maxY; y++){
        for(int x = 1; x <= maxX; x++){
            if(more[x][y] > 0 && visited[x][y] == false){
                brOstrvcheta = 2;
                break;
            }
        }
        if(brOstrvcheta > 1){
            break;
        }
    }

    for(int y = 0; y <= maxY; y++){
        for(int x = 0; x <= maxX; x++){
            visited[x][y] = false;
        }
    }

    return brOstrvcheta;
}

void smqtaneNaNulite(){
    for(int y = 0; y <= maxY; y++){
        for(int x = 0; x <= maxX; x++){
            broiNuliokoloTozi[x][y] = 0;
        }
    }

    for(int y = 1; y <= maxY; y++){
        for(int x = 1; x<= maxX; x++){
            if(more[x - 1][y] <= 0){
                broiNuliokoloTozi[x][y]++;
            }
            if(more[x + 1][y] <= 0){
                broiNuliokoloTozi[x][y]++;
            }
            if(more[x][y - 1] <= 0){
                broiNuliokoloTozi[x][y]++;
            }
            if(more[x][y + 1] <= 0){
                broiNuliokoloTozi[x][y]++;
            }
        }
    }
}

int broiNuzhniStapkiZaRaztopqvane(){
    int naiMalakBroi = 100000000;

    for(int y = 0; y <= maxY; y++){
        for(int x = 0; x <= maxX; x++){
            double visochina = more[x][y];
            int brNuliOkoloNego = broiNuliokoloTozi[x][y];

            if(brNuliOkoloNego > 0 && more[x][y] > 0){
                double nuzhniHodoveZaStopqvane = ceil(visochina / brNuliOkoloNego);
                int nuzhni = nuzhniHodoveZaStopqvane;
                naiMalakBroi = min(naiMalakBroi, nuzhni);
            }
        }
    }

    return naiMalakBroi;
}

void topene(int kolkoStapki){

    //for(int t = 0; t < kolkoStapki; t++){
        for(int y = 1; y <= maxY; y++){
            for(int x = 1; x <= maxX; x++){
                more[x][y] -= kolkoStapki * broiNuliokoloTozi[x][y];
            }
        }
    //}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>maxY>>maxX;

    for(int y = 1; y <= maxY; y++){
        for(int x = 1; x <= maxX; x++){
            cin>>more[x][y];
        }
    }

    for(int x = 0; x <= maxX + 1; x++){
        more[x][0] = -1;
        more[x][maxY + 1] = -1;
    }

    for(int y = 0; y <= maxY + 1; y++){
        more[0][y] = -1;
        more[maxX + 1][y] = -1;
    }

    int broiNuzhniMeseci = 0;
    int predenBroiOstrovcheta = 0;

    while(true){
        int brOstrovcheta = broiOstrovcheta();

        //cout<<brOstrovcheta<<endl;

        if(brOstrovcheta != 1){
            if(brOstrovcheta == 0 && predenBroiOstrovcheta == 1){
                broiNuzhniMeseci = -1;
            }
            break;
        }

        smqtaneNaNulite();

        int zaKolkoStapki = broiNuzhniStapkiZaRaztopqvane();

        //cout<<zaKolkoStapki<<endl;

        topene(zaKolkoStapki);

        broiNuzhniMeseci += zaKolkoStapki;
        predenBroiOstrovcheta= brOstrovcheta;
        //cout<<broiNuzhniMeseci<<endl<<endl<<endl;
    }

    cout<<broiNuzhniMeseci<<endl;

    return 0;
}
