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
    }

    for(int komputer=0;komputer<broiKomputri;komputer++){
        queue<int> q;
        q.push(komputer);

        while(q.empty()==false){
            int predenKomputer=q.front();
            q.pop();

            for(int drugKomputer=0;drugKomputer<broiKomputri;drugKomputer++){
                if(sasedstvo[predenKomputer][drugKomputer]==true){
                    if(stiganeZaVreme[komputer][drugKomputer]==0){
                        stiganeZaVreme[komputer][drugKomputer]=stiganeZaVreme[komputer][predenKomputer]+1;
                        q.push(drugKomputer);
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
