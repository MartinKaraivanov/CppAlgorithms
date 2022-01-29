#include<iostream>
#include<stdio.h>
using namespace std;

int maxXY;

int stena[2008][2008];

int posledniqXNaKoitoImaDupka[2008][2008];
int posledniqYNaKoitoImaDupka[2008][2008];

int parviqXNaKoitoImaDupkaSled[2008][2008];
int parviqYNaKoitoImaDupkaSled[2008][2008];

int main(){
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>maxXY;*/

    scanf("%i", &maxXY);

    for(int y = 0; y < maxXY; y++){
        for(int x = 0; x < maxXY; x++){
            //cin>>stena[y][x];
            scanf("%i", &stena[y][x]);
        }
    }

    for(int y = 1; y < maxXY; y++){
        for(int x = 1; x < maxXY; x++){
            if(stena[y][x] == stena[y - 1][x]){
                posledniqXNaKoitoImaDupka[y][x] = x;
            }else{
                posledniqXNaKoitoImaDupka[y][x] = posledniqXNaKoitoImaDupka[y][x - 1];
            }
        }
    }

    for(int x = 1; x < maxXY; x++){
        for(int y = 1; y < maxXY; y++){
            if(stena[y][x] == stena[y][x - 1]){
                posledniqYNaKoitoImaDupka[y][x] = y;
            }else{
                posledniqYNaKoitoImaDupka[y][x] = posledniqYNaKoitoImaDupka[y - 1][x];
            }
        }
    }

    for(int y = maxXY - 1; y >= 0; y--){
        for(int x = maxXY - 1; x >= 0; x--){
            if(stena[y][x] == stena[y + 1][x]){
                parviqXNaKoitoImaDupkaSled[y][x] = x;
            }else{
                parviqXNaKoitoImaDupkaSled[y][x] = parviqXNaKoitoImaDupkaSled[y][x + 1];
            }
            if(parviqXNaKoitoImaDupkaSled[y][x] == 0){
                parviqXNaKoitoImaDupkaSled[y][x] = maxXY - 2;
            }
        }
    }

    for(int x = maxXY - 1; x >= 0; x--){
        for(int y = maxXY; y >= 0; y--){
            if(stena[y][x] == stena[y][x + 1]){
                parviqYNaKoitoImaDupkaSled[y][x] = y;
            }else{
                parviqYNaKoitoImaDupkaSled[y][x] = parviqYNaKoitoImaDupkaSled[y + 1][x];
            }
            if(parviqYNaKoitoImaDupkaSled[y][x] == 0){
                parviqYNaKoitoImaDupkaSled[y][x] = maxXY - 2;
            }
        }
    }

    /*for(int y = 1; y < maxXY - 1; y++){
        for(int x = 1; x < maxXY - 1; x++){
            cout<<x<<" "<<y<<" predi "<<posledniqXNaKoitoImaDupka[y][x]<<" "<<posledniqYNaKoitoImaDupka[y][x]<<" sled ";
            cout<<parviqXNaKoitoImaDupkaSled[y][x]<<" "<<parviqYNaKoitoImaDupkaSled[y][x]<<endl;
        }
    }*/

    int naiGolqmaStrana = 0;
    int otX = -1;
    int otY = -1;

    for(int y = 1; y < maxXY - 1; y++){
        for(int x = 1; x < maxXY - 1; x++){
            int otStrana = (min(parviqXNaKoitoImaDupkaSled[y - 1][x] - x + 1, parviqYNaKoitoImaDupkaSled[y][x - 1] - y + 1)/2)*2;

            //cout<<"pri "<<x<<" "<<y<<" stranata pochva ot "<<otStrana<<endl;
            for(int strana = otStrana; strana >= 2; strana -= 2){
                if(strana <= naiGolqmaStrana){
                    break;
                }

                int dolenY = y + strana - 1;
                int dolenX = x + strana - 1;

                if(dolenX >= maxXY - 1 || dolenY >= maxXY - 1){
                    break;
                }

                //cout<<x<<" "<<y<<" dolni "<<dolenX<<" "<<dolenY<<" strana "<<strana<<endl;

                bool okLiE = true;

                if(posledniqXNaKoitoImaDupka[dolenY + 1][dolenX] >= x ||
                    posledniqYNaKoitoImaDupka[dolenY][dolenX + 1] >= y)
                {
                    //cout<<"ne stava shtoto na stranite ima dupka"<<endl;
                    okLiE = false;
                }

                if(posledniqYNaKoitoImaDupka[dolenY][x] >= y || posledniqXNaKoitoImaDupka[y][dolenX] >= x ){
                    //cout<<"ne stava shtoto na stranite ima dupka"<<endl;
                    okLiE = false;
                }

                if(okLiE == true){
                    //cout<<"stava"<<endl;
                    if(strana > naiGolqmaStrana){
                        //cout<<"TUKA IMA PO GOLQMA STRANA---------------------------------------------------------------------------------- "<<endl;
                        naiGolqmaStrana = strana;
                        otX = x;
                        otY = y;
                    }
                    break;
                }
            }
        }
    }

    //cout<<naiGolqmaStrana<<" "<<otY + 1<<" "<<otX + 1<<endl;
    printf("%i %i %i \n", naiGolqmaStrana, otY + 1, otX + 1);

    return 0;
}
