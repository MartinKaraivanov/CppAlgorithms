#include<iostream>
#include<queue>
using namespace std;

int sasedstvo[4000][4000];
int stiganeZaVreme[4000][4000];
bool imameLiNaiKasPat[4000][4000];
int vremeZaStigane[4000];
bool imaLiPatDoVsichki[4000];


const int Bezkrai = 1000000;

int main(){
    int broiKomputri;
    int broiSaobshteniq;
    cin>>broiKomputri>>broiSaobshteniq;

    int izprashtashtKomputer[broiSaobshteniq];
    int poluchavashtKomputer[broiSaobshteniq];

    for(int i=0;i<broiSaobshteniq;i++){
        cin>>izprashtashtKomputer[i]>>poluchavashtKomputer[i];
    }

    for(int i=0;i<broiSaobshteniq;i++){
        sasedstvo[izprashtashtKomputer[i]][poluchavashtKomputer[i]]=1;
    }

    for(int otKomputer=0;otKomputer<broiKomputri;otKomputer++){
        // dijkstra

        // init
        for(int i=0;i<broiKomputri;i++){
            if(i!=otKomputer){
                if(sasedstvo[otKomputer][i]>0){
                    stiganeZaVreme[otKomputer][i]=sasedstvo[otKomputer][i];
                }else{
                    stiganeZaVreme[otKomputer][i]=Bezkrai;
                }
            }else{
                stiganeZaVreme[otKomputer][i]=0;
            }
        }

        imameLiNaiKasPat[otKomputer][otKomputer]=true;

        bool nameriliLiSmeNeshto=true;
        while(nameriliLiSmeNeshto==true){
            nameriliLiSmeNeshto=false;

            int naiMalko=Bezkrai;
            int koiKomputerENaiMalkoto;
            for(int mezhdinenKomputer=0;mezhdinenKomputer<broiKomputri;mezhdinenKomputer++){
                if((stiganeZaVreme[otKomputer][mezhdinenKomputer]<naiMalko) &&
                   (imameLiNaiKasPat[otKomputer][mezhdinenKomputer]==false))
                {
                    naiMalko=stiganeZaVreme[otKomputer][mezhdinenKomputer];
                    koiKomputerENaiMalkoto=mezhdinenKomputer;
                    nameriliLiSmeNeshto=true;
                }
            }

            if(nameriliLiSmeNeshto==true){
                imameLiNaiKasPat[otKomputer][koiKomputerENaiMalkoto]=true;

                for(int doKomputer=0;doKomputer<broiKomputri;doKomputer++){
                    if((imameLiNaiKasPat[otKomputer][doKomputer]==false) &&
                        (sasedstvo[koiKomputerENaiMalkoto][doKomputer]>0) &&
                        (stiganeZaVreme[otKomputer][doKomputer] >
                            stiganeZaVreme[otKomputer][koiKomputerENaiMalkoto]+sasedstvo[koiKomputerENaiMalkoto][doKomputer]))
                    {
                        stiganeZaVreme[otKomputer][doKomputer]=
                            stiganeZaVreme[otKomputer][koiKomputerENaiMalkoto]+sasedstvo[koiKomputerENaiMalkoto][doKomputer];
                    }
                }
            }
        }
    }


    for(int i=0;i<broiKomputri;i++){
        int naiGolqmoVremeZaToziKomputer=0;
        for(int j=0;j<broiKomputri;j++){
            if(stiganeZaVreme[i][j]>naiGolqmoVremeZaToziKomputer){
                naiGolqmoVremeZaToziKomputer=stiganeZaVreme[i][j];
            }
        }
        vremeZaStigane[i]=naiGolqmoVremeZaToziKomputer;
    }

    for(int i=0;i<broiKomputri;i++){
        bool stigaLiDoVsichki=true;
        for(int j=0;j<broiKomputri;j++){
            if(stiganeZaVreme[i][j]==Bezkrai && j!=i){
                stigaLiDoVsichki=false;
                break;
            }
        }
        if(stigaLiDoVsichki==true){
            imaLiPatDoVsichki[i]=true;
        }else{
            imaLiPatDoVsichki[i]=false;
        }
    }

    int naiMalkoVreme=1000000;

    for(int i=0;i<broiKomputri;i++){
        if(vremeZaStigane[i]<naiMalkoVreme && vremeZaStigane[i]>0 && imaLiPatDoVsichki[i]==true){
            naiMalkoVreme=vremeZaStigane[i];
        }
    }

    int broiZaNaiMalkoVreme=0;

    for(int i=0;i<broiKomputri;i++){
        if(vremeZaStigane[i]==naiMalkoVreme && imaLiPatDoVsichki[i]==true){
            broiZaNaiMalkoVreme++;
        }
    }

    cout<<broiZaNaiMalkoVreme<<endl;

    for(int i=0;i<broiKomputri;i++){
        if(vremeZaStigane[i]==naiMalkoVreme && imaLiPatDoVsichki[i]==true){
            cout<<i<<" ";
        }
    }

    cout<<endl;

    return 0;
}
