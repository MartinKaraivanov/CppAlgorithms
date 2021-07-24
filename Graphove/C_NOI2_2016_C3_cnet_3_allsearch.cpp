#include<iostream>
#include<queue>
using namespace std;

bool sasedstvo[4000][4000];
int stiganeZaVreme[4000][4000];
int vremeZaStigane[4000];
bool imaLiPatDoVsichki[4000];

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
        sasedstvo[izprashtashtKomputer[i]][poluchavashtKomputer[i]]=true;
        stiganeZaVreme[izprashtashtKomputer[i]][poluchavashtKomputer[i]]=1;
    }

    bool pravimLiNeshto=true;
    while(pravimLiNeshto==true){
        pravimLiNeshto=false;
        for(int otKomputer=0;otKomputer<broiKomputri;otKomputer++){
            for(int prezKomputer=0;prezKomputer<broiKomputri;prezKomputer++){
                if((stiganeZaVreme[otKomputer][prezKomputer]>0) && (otKomputer!=prezKomputer)){
                    for(int doKomputer=0;doKomputer<broiKomputri;doKomputer++){
                        if((stiganeZaVreme[prezKomputer][doKomputer]>0) &&
                           (doKomputer!=otKomputer) &&
                           (doKomputer!=prezKomputer))
                        {
                            if((stiganeZaVreme[otKomputer][doKomputer]==0) ||
                               ( stiganeZaVreme[otKomputer][doKomputer]
                                 >
                                 stiganeZaVreme[otKomputer][prezKomputer]+stiganeZaVreme[prezKomputer][doKomputer]))
                            {
                                stiganeZaVreme[otKomputer][doKomputer]=
                                    stiganeZaVreme[otKomputer][prezKomputer]+stiganeZaVreme[prezKomputer][doKomputer];
                                pravimLiNeshto=true;
                            }
                        }
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
            if(stiganeZaVreme[i][j]==0 && j!=i){
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
