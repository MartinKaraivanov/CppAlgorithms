#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int broiRedove;
    cin>>broiRedove;

    char koqBukva;
    cin>>koqBukva;
    koqBukva= toupper(koqBukva);

    string dumi[broiRedove*4];

    for(int i=0;i<broiRedove*4;i++){
        cin>>dumi[i];
    }

    int broiZaParvaKolonka=0;
    int broiZaVtoraKolonka=0;
    int broiZaTretaKolonka=0;
    int broiZaChetvartaKolonka=0;

    for(int i=0;i<broiRedove*4;i+=4){
        char parvaBukva=toupper(dumi[i][0]);
        if(parvaBukva==koqBukva){
            broiZaParvaKolonka++;
        }
    }

    for(int i=3;i<broiRedove*4;i+=4){
        char poslednaBukva=toupper(dumi[i][dumi[i].size()-1]);
        if(poslednaBukva==koqBukva){
            broiZaChetvartaKolonka++;
        }
    }

    for(int i=1;i<broiRedove*4;i+=4){
        for(int j=0;j<dumi[i].size();j++){
            if(toupper(dumi[i][j])==koqBukva){
                broiZaVtoraKolonka++;
                break;
            }
        }
    }

    for(int i=2;i<broiRedove*4;i+=4){
        int kolkoPatiQIma=0;
        for(int j=0;j<dumi[i].size();j++){
            if(toupper(dumi[i][j])==koqBukva){
                kolkoPatiQIma++;
            }
        }
        if(kolkoPatiQIma>=2){
            broiZaTretaKolonka++;
        }
    }

    cout<<broiZaParvaKolonka<<" "<<broiZaVtoraKolonka<<" "<<broiZaTretaKolonka<<" "<<broiZaChetvartaKolonka<<endl;

    return 0;
}
