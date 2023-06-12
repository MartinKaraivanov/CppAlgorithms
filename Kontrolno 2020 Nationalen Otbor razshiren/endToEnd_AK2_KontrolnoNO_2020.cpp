#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<stdio.h>
using namespace std;

const int maximalnaStoinost = 10000;

struct Kletka{
    int red;
    int kolona;
};

int maxY;
int maxX;

char tablica[512][512];

queue<Kletka> qLqvoDqsno[maximalnaStoinost];
bool visited[512][512];
int razstLqvo[512][512];
int razstDqsno[512][512];

queue<Kletka> qGoreDolu[4][maximalnaStoinost];
bool vsichkiVisited[4][512][512];
int vsichkiRazst[4][512][512];

int posoki[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int daiCena(int red, int kolona, int cifra){
    return abs(tablica[red][kolona] - '0' - cifra);
}

void deikstra(int cifra, int razst[512][512], int startovaKolona){

    for(int i = 0; i < 512; i++){
        for(int j = 0; j < 512; j++){
            visited[i][j] = false;
        }
    }

    memset(razst, 100, sizeof(razst[0][0]) * 512 * 512);

    for(int red = 0; red < maxY; red++){
        razst[red][startovaKolona] = 0;
        qLqvoDqsno[0].push({red, startovaKolona});
    }

    for(int cena = 0; cena < maximalnaStoinost; cena++){
        while(qLqvoDqsno[cena].empty() == false){
            Kletka naiOtpred = qLqvoDqsno[cena].front();
            qLqvoDqsno[cena].pop();
            if(visited[naiOtpred.red][naiOtpred.kolona] == true){
                continue;
            }
            visited[naiOtpred.red][naiOtpred.kolona] = true;

            int sledvashtaCena = cena + daiCena(naiOtpred.red, naiOtpred.kolona, cifra);

            for(int d = 0; d < 4; d++){
                int novRed = naiOtpred.red + posoki[d][0];
                if(novRed < 0 || novRed >= maxY){
                    continue;
                }
                int novaKolona = naiOtpred.kolona + posoki[d][1];
                if(novaKolona < 0 || novaKolona >= maxX){
                    continue;
                }

                if(razst[novRed][novaKolona] > sledvashtaCena){
                    razst[novRed][novaKolona] = sledvashtaCena;
                    qLqvoDqsno[sledvashtaCena].push({novRed, novaKolona});
                }
            }

        }
    }

}

int sTaqCifra(int cifra){

    memset(vsichkiVisited, 0, sizeof(vsichkiVisited));
    memset(vsichkiRazst, 100, sizeof(vsichkiRazst));

    for(int i = 0; i < 4; i++){
        for(int cena = 0; cena < maximalnaStoinost; cena++){
            while(qGoreDolu[i][cena].empty() == false){
                qGoreDolu[i][cena].pop();
            }
        }
    }

    for(int kolona = 0; kolona < maxX; kolona++){
        vsichkiRazst[0][0][kolona] = daiCena(0, kolona, cifra);
        qGoreDolu[0][vsichkiRazst[0][0][kolona]].push({0, kolona});
    }

    for(int cena = 0; cena < maximalnaStoinost; cena++){
        for(int i = 0; i < 4; i++){

            while(qGoreDolu[i][cena].empty() == false){
                Kletka naiOtpred = qGoreDolu[i][cena].front();
                qGoreDolu[i][cena].pop();
                if(vsichkiVisited[i][naiOtpred.red][naiOtpred.kolona] == true){
                    continue;
                }
                vsichkiVisited[i][naiOtpred.red][naiOtpred.kolona] = true;

                if(naiOtpred.red == maxY - 1 && i == 3){
                    return cena;
                }

                for(int strana = 1;  strana <= 2; strana++)if(!(i & strana)){
                    int sledvashtaCena = cena;
                    if(strana == 1){
                        sledvashtaCena += razstLqvo[naiOtpred.red][naiOtpred.kolona];
                    }else{
                        sledvashtaCena += razstDqsno[naiOtpred.red][naiOtpred.kolona];
                    }

                    if(vsichkiRazst[i | strana][naiOtpred.red][naiOtpred.kolona] > sledvashtaCena){
                        vsichkiRazst[i | strana][naiOtpred.red][naiOtpred.kolona] = sledvashtaCena;
                        qGoreDolu[i | strana][sledvashtaCena].push(naiOtpred);
                    }

                }

                for(int d = 0; d < 4; d++){
                    int novRed = naiOtpred.red + posoki[d][0];
                    if(novRed < 0 || novRed >= maxY){
                        continue;
                    }
                    int novaKolona = naiOtpred.kolona + posoki[d][1];
                    if(novaKolona < 0 || novaKolona >= maxX){
                        continue;
                    }
                    int novaCena = cena + daiCena(novRed, novaKolona, cifra);
                    if(vsichkiRazst[i][novRed][novaKolona] > novaCena){
                        vsichkiRazst[i][novRed][novaKolona] = novaCena;
                        qGoreDolu[i][novaCena].push({novRed, novaKolona});
                    }
                }

            }


        }
    }

    return 100000000;
}

int main(){

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    //cin>>maxY>>maxX;

    scanf("%i %i", &maxY, &maxX);

    for(int i = 0; i < maxY; i++){
        //cin>>tablica[i];
        scanf("%s", &tablica[i]);
    }

    int otgovor = 10000000;

    for(int cifra = 0; cifra < 10; cifra++){
        deikstra(cifra, razstLqvo, 0);
        deikstra(cifra, razstDqsno, maxX - 1);
        otgovor = min(otgovor, sTaqCifra(cifra));
    }

    //cout<<otgovor<<endl;
    printf("%i", otgovor);

    return 0;
}
