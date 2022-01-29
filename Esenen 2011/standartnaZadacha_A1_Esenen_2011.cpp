#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;

int maxY;
int maxX;

int tablica[1010][1010];

int visochinaNaHistV[1010][1010];

int naiGolqmataDaljinaPriVisochina[1010][1010];

int broiZaqvki;

int kolkoEVisochinata(int y, int x){
    //return min(visochinaNaHistV[y][x], y - gorenRed + 1);
    return visochinaNaHistV[y][x];
}

void preizchisliNaiGolemiteLica(int red){

    stack<int> s;

    for(int i = 0; i < maxX; i++){

        while(s.empty() == false){
            if(kolkoEVisochinata(red, i) >= kolkoEVisochinata(red, s.top())){
                break;
            }else{
                int naiOtgore = kolkoEVisochinata(red, s.top());
                s.pop();

                int tukaShirochina = 0;

                if(s.empty() == true){
                    tukaShirochina = i;
                }else{
                    tukaShirochina = (i - s.top() - 1);
                }

                naiGolqmataDaljinaPriVisochina[red][naiOtgore] = max(tukaShirochina, naiGolqmataDaljinaPriVisochina[red][naiOtgore]);
            }
        }

        s.push(i);
    }

    while(s.empty() == false){
        int naiOtgore = kolkoEVisochinata(red, s.top());
        s.pop();

        int tukaShirochina = 0;

        if(s.empty() == true){
            tukaShirochina = maxX;
        }else{
            tukaShirochina = (maxX - s.top() - 1);
        }

        naiGolqmataDaljinaPriVisochina[red][naiOtgore] = max(tukaShirochina, naiGolqmataDaljinaPriVisochina[red][naiOtgore]);
    }
}

void preizchislqvaneNaVsichkiRedove(){

    for(int y = 0; y < maxY; y++){
        preizchisliNaiGolemiteLica(y);
    }

}

int shirochinaPriNaiMnVis[1010][1010];

void izchisliNaobratno(){

    for(int y = maxY - 1; y >= 0; y--){
        int naiMnogoto = 0;

        for(int i = maxY - 1; i > 0; i--){
            naiMnogoto = max(naiMnogoto, naiGolqmataDaljinaPriVisochina[y][i]);
            shirochinaPriNaiMnVis[y][i] = naiMnogoto;
        }
    }

}

int licaPriVisochina[1010][1010];

void nameriLicata(){

    for(int y = 0; y < maxY; y++){
        for(int v = 0; v <= maxY; v++){
            licaPriVisochina[y][v] = v*shirochinaPriNaiMnVis[y][v];
        }
    }
}

int liceSVisochinaNaiMnogo[1010][1010];

void izchisliSMaxVisochini(){

    for(int y = 0; y < maxY; y++){
        int maxLice = 0;

        for(int v = 0; v <= maxY; v++){
            maxLice = max(maxLice, licaPriVisochina[y][v]);
            liceSVisochinaNaiMnogo[y][v] = maxLice;
        }
    }
}


void nameriHistogramite(){
    for(int i = 0; i <= maxY; i++){
        for(int j = 0; j <= maxX; j++){
            visochinaNaHistV[i][j] = 0;
        }
    }

    for(int x = 0; x < maxX; x++){
        visochinaNaHistV[0][x] = tablica[0][x];
    }
    for(int y = 1; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            if(tablica[y][x] == 1){
                visochinaNaHistV[y][x] = tablica[y][x] + visochinaNaHistV[y - 1][x];
            }
        }
    }
}

int naiGolqmotoLiceNagore[1010][1010];

void nameriNaiGolemiteLica(){

    for(int y = 0; y < maxY; y++){
        naiGolqmotoLiceNagore[y][1] = liceSVisochinaNaiMnogo[y][1];
    }

    for(int y = 1; y < maxY; y++){
        for(int v = 2; v <= maxY; v++){
            naiGolqmotoLiceNagore[y][v] = max(liceSVisochinaNaiMnogo[y][v], naiGolqmotoLiceNagore[y - 1][v - 1]);
        }
    }

}

int otgovori[1000010];

int main(){
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>maxY>>maxX;*/

    scanf("%i %i", &maxY, &maxX);

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            int tuka;
            //cin>>tuka;
            scanf("%i", &tuka);
            if(tuka == 0){
                tablica[y][x] = 1;
            }else{
                tablica[y][x] = 0;
            }
        }
    }

    nameriHistogramite();
    preizchislqvaneNaVsichkiRedove();
    izchisliNaobratno();
    nameriLicata();
    izchisliSMaxVisochini();
    nameriNaiGolemiteLica();

    /*for(int y = 0; y < maxY; y++){
        cout<<"za red "<<y<<endl;
        for(int v = 0; v <= maxY; v++){
            cout<<"za visochina "<<v<<" kazvame "<<licaPriVisochina[y][v]<<endl;
        }
        cout<<endl;
    }*/

    //cin>>broiZaqvki;
    scanf("%i", &broiZaqvki);

    for(int i = 0; i < broiZaqvki; i++){
        int gorenRed;
        int dolenRed;
        //cin>>gorenRed>>dolenRed;
        scanf("%i %i", &gorenRed, &dolenRed);

        gorenRed--;
        dolenRed--;

        //cout<<naiGolqmotoLiceNagore[dolenRed][dolenRed - gorenRed + 1]<<endl;
        printf("%i \n", naiGolqmotoLiceNagore[dolenRed][dolenRed - gorenRed + 1]);
    }

    /*for(int i = 0; i < broiZaqvki; i++){
        cout<<otgovori[i]<<endl;
    }*/

    return 0;
}
