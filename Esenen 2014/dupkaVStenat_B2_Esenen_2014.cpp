#include<iostream>
using namespace std;

int strana;

int koqTuhlaETuka[1010][1010];

int koiNomerEOtgore[1010][1010];
int koiNomerEOtlqvo[1010][1010];

int nomerche = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>strana;

    for(int y = 1; y <= strana; y++){
        for(int x = 1; x <= strana; x++){
            cin>>koqTuhlaETuka[y][x];
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

    int naiGolqmoLice = 0;
    int otKadeX = -1;
    int otKadeY = -1;
    int doKadeX = -1;
    int doKadeY = -1;

    /*for(int gorenY = 2; gorenY < strana; gorenY++){
        for(int gorenX = 2; gorenX < strana; gorenX++){
            for(int dolenY = gorenY; dolenY < strana; dolenY++){
                for(int dolenX = gorenX; dolenX < strana; dolenX++){
                    /*cout<<gorenY<<" "<<gorenX<<" "<<dolenY<<" "<<dolenX<<endl;
                    cout<<koiNomerEOtgore[gorenY][gorenX]<<" "<<koiNomerEOtgore[gorenY][dolenX]<<" ";
                    cout<<koiNomerEOtgore[dolenY + 1][gorenX]<<" "<<koiNomerEOtgore[dolenY + 1][dolenX]<<endl;
                    cout<<koiNomerEOtlqvo[gorenY][gorenX]<<" "<<koiNomerEOtlqvo[dolenY][gorenX]<<" ";
                    cout<<koiNomerEOtlqvo[gorenY][dolenX + 1]<<" "<<koiNomerEOtlqvo[dolenY][dolenX + 1]<<endl;
                    cout<<endl;

                    bool stavaLi = true;

                    //cout<<koiNomerEOtgore[gorenX][dolenY + 1]<<" "<<koiNomerEOtgore[dolenX][dolenY + 1]<<endl<<endl;

                    if((koiNomerEOtgore[gorenY][gorenX] != koiNomerEOtgore[gorenY][dolenX]) ||
                        (koiNomerEOtgore[dolenY + 1][gorenX] != koiNomerEOtgore[dolenY + 1][dolenX]) ||
                        (koiNomerEOtlqvo[gorenY][gorenX] != koiNomerEOtlqvo[dolenY][gorenX]) ||
                        (koiNomerEOtlqvo[gorenY][dolenX + 1] != koiNomerEOtlqvo[dolenY][dolenX + 1]) ||
                        (koiNomerEOtgore[gorenY][gorenX] == 0) ||
                        (koiNomerEOtgore[dolenY + 1][dolenX] == 0) ||
                        (koiNomerEOtlqvo[gorenY][gorenX] == 0) ||
                        (koiNomerEOtlqvo[dolenY][dolenX + 1] == 0))
                    {
                        stavaLi = false;
                    }

                    if(stavaLi == true){
                        /*cout<<"tova stava"<<endl;
                        cout<<koqTuhlaETuka[gorenY][dolenX]<<" "<<koqTuhlaETuka[gorenY][dolenX + 1]<<" ";
                        cout<<koiNomerEOtlqvo[gorenY][dolenX + 1]<<endl;
                        cout<<koqTuhlaETuka[dolenY][dolenX]<<" "<<koqTuhlaETuka[dolenY][dolenX + 1]<<" ";
                        cout<<koiNomerEOtlqvo[dolenY][dolenX + 1]<<endl<<endl;

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
    }*/

    for(int gorenRed = 2; gorenRed < strana; gorenRed++){
        for(int dolenRed = gorenRed + 1; dolenRed <= strana; dolenRed++){
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


    cout<<naiGolqmoLice<<" "<<otKadeY<<" "<<otKadeX<<" "<<doKadeY<<" "<<doKadeX<<endl;

    return 0;
}
