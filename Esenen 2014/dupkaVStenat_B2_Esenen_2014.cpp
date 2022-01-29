#include<iostream>
#include<stdio.h>
using namespace std;

int strana;

int koqTuhlaETuka[1008][1008];

int koiNomerEOtgore[1008][1008];
int koiNomerEOtlqvo[1008][1008];

int nomerche = 1;

int posledniqXNaKoitoImaDupka[1008][1008];
int posledniqYNaKoitoImaDupka[1008][1008];

int parviqXNaKoitoImaDupkaSled[1008][1008];
int parviqYNaKoitoImaDupkaSled[1008][1008];

int main(){
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/

    //cin>>strana;

    scanf("%i", &strana);

    for(int y = 1; y <= strana; y++){
        for(int x = 1; x <= strana; x++){
            //cin>>koqTuhlaETuka[y][x];
            scanf("%i", &koqTuhlaETuka[y][x]);
        }
    }

    for(int y = 2; y <= strana; y++){
        for(int x = 2; x <= strana; x++){
            if(koqTuhlaETuka[y - 1][x] != koqTuhlaETuka[y][x]){
                koiNomerEOtgore[y][x] = nomerche;
                //cout<<"Tuko shto slozhih otgore na "<<x<<" "<<y<<" da e "<<nomerche<<endl;
            }else{
                nomerche++;
                //cout<<"Otgore na "<<x<<" "<<y<<" ne trqva da ima nishto"<<endl;
            }
        }
        nomerche++;
    }

    //cout<<endl;


    for(int x = 2; x <= strana; x++){
        for(int y = 2; y <= strana; y++){
            if(koqTuhlaETuka[y][x - 1] != koqTuhlaETuka[y][x]){
                koiNomerEOtlqvo[y][x] = nomerche;
                //cout<<"Tuko shto slozhih otlqvo na "<<x<<" "<<y<<" da e "<<nomerche<<endl;
            }else{
                nomerche++;
                //cout<<"Otlqvo na "<<x<<" "<<y<<" ne trqva da ima nishto"<<endl;
            }
        }
        nomerche++;
    }

    //cout<<endl<<endl;

    for(int y = 1; y < strana; y++){
        for(int x = 1; x < strana; x++){
            if(koqTuhlaETuka[y][x] == koqTuhlaETuka[y - 1][x]){
                posledniqXNaKoitoImaDupka[y][x] = x;
            }else{
                posledniqXNaKoitoImaDupka[y][x] = posledniqXNaKoitoImaDupka[y][x - 1];
            }
        }
    }

    for(int x = 1; x < strana; x++){
        for(int y = 1; y < strana; y++){
            if(koqTuhlaETuka[y][x] == koqTuhlaETuka[y][x - 1]){
                posledniqYNaKoitoImaDupka[y][x] = y;
            }else{
                posledniqYNaKoitoImaDupka[y][x] = posledniqYNaKoitoImaDupka[y - 1][x];
            }
        }
    }

    for(int y = strana - 1; y >= 0; y--){
        for(int x = strana - 1; x >= 0; x--){
            if(koqTuhlaETuka[y][x] == koqTuhlaETuka[y + 1][x]){
                parviqXNaKoitoImaDupkaSled[y][x] = x;
            }else{
                parviqXNaKoitoImaDupkaSled[y][x] = parviqXNaKoitoImaDupkaSled[y][x + 1];
            }
            if(parviqXNaKoitoImaDupkaSled[y][x] == 0){
                parviqXNaKoitoImaDupkaSled[y][x] = strana - 2;
            }
        }
    }

    for(int x = strana - 1; x >= 0; x--){
        for(int y = strana; y >= 0; y--){
            if(koqTuhlaETuka[y][x] == koqTuhlaETuka[y][x + 1]){
                parviqYNaKoitoImaDupkaSled[y][x] = y;
            }else{
                parviqYNaKoitoImaDupkaSled[y][x] = parviqYNaKoitoImaDupkaSled[y + 1][x];
            }
            if(parviqYNaKoitoImaDupkaSled[y][x] == 0){
                parviqYNaKoitoImaDupkaSled[y][x] = strana - 2;
            }
        }
    }

    int naiGolqmoLice = 0;
    int otKadeX = -1;
    int otKadeY = -1;
    int doKadeX = -1;
    int doKadeY = -1;

    for(int gorenRed = 2; gorenRed < strana; gorenRed++){
        for(int dolenRed = strana; dolenRed >= gorenRed; dolenRed--){

            if((dolenRed - gorenRed + 1)*strana <= naiGolqmoLice){
                break;
            }

            int broiPodred = 0;
            int otKoqKolonaEPochnalo = 2;

            for(int kolona = 2; kolona < strana; kolona++){
                int gorenY = gorenRed;
                int gorenX = otKoqKolonaEPochnalo;
                int dolenY = dolenRed - 1;
                int dolenX = kolona;

                //cout<<gorenY<<" "<<gorenX<<" "<<dolenY<<" "<<dolenX<<endl;

                if(koiNomerEOtgore[gorenY][dolenX] == 0 ||
                    koiNomerEOtgore[dolenY + 1][dolenX] == 0 ||
                    koiNomerEOtlqvo[gorenY][gorenX] != koiNomerEOtlqvo[dolenY][gorenX] ||
                    koiNomerEOtlqvo[gorenY][gorenX] == 0 ||
                    koiNomerEOtlqvo[dolenY][gorenX] == 0)
                {
                    otKoqKolonaEPochnalo = kolona + 1;
                }else{
                    if(koiNomerEOtlqvo[gorenY][dolenX + 1] == koiNomerEOtlqvo[dolenY][dolenX + 1] &&
                       koiNomerEOtlqvo[gorenY][dolenX + 1] != 0)
                    {
                        //cout<<koiNomerEOtlqvo[gorenY][gorenX]<<" "<<koiNomerEOtlqvo[dolenY][gorenX]<<endl<<endl;
                        int segLice = (dolenY - gorenY + 1)*(dolenX - gorenX + 1);
                        if(segLice > naiGolqmoLice){
                            naiGolqmoLice = segLice;
                            otKadeX = gorenX;
                            otKadeY = gorenY;
                            doKadeX = dolenX;
                            doKadeY = dolenY;
                        }
                    }
                }

            }
        }
    }

    printf("%i %i %i %i %i \n", naiGolqmoLice, otKadeY, otKadeX, doKadeY, doKadeX);

    //cout<<naiGolqmoLice<<" "<<otKadeY<<" "<<otKadeX<<" "<<doKadeY<<" "<<doKadeX<<endl;

    return 0;
}
