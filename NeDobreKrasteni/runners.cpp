#include<iostream>
using namespace std;

int nomeraNaStartPoNomerNaFinishirane[101];

int nomeraNaFinishiranePoNomerNaStart[101];

int VremeNaBegachPoNomerNaStart(int nomerNaStart){
    return 100+nomeraNaFinishiranePoNomerNaStart[nomerNaStart]-nomerNaStart;
}

int main(){
    int broiBegachi;
    cin>>broiBegachi;

    for(int nomerNaFinishirane=1;nomerNaFinishirane<=broiBegachi;nomerNaFinishirane++){
        cin>>nomeraNaStartPoNomerNaFinishirane[nomerNaFinishirane];
    }

    for(int nomerNaFinishirane=1;nomerNaFinishirane<=broiBegachi;nomerNaFinishirane++){
        int nomerNaStart = nomeraNaStartPoNomerNaFinishirane[nomerNaFinishirane];
        nomeraNaFinishiranePoNomerNaStart[nomerNaStart] = nomerNaFinishirane;
    }

    int broeveBegachiSVreme[2*100];

    for(int vreme=0;vreme<200;vreme++){
        broeveBegachiSVreme[vreme]=0;
    }

    for(int nomerNaStart=1;nomerNaStart<=broiBegachi;nomerNaStart++){
        int vreme = VremeNaBegachPoNomerNaStart(nomerNaStart);
        broeveBegachiSVreme[vreme]++;
    }

    int poziciqBroqch=0;
    int tretoVreme=0;

    for(int vreme=0;vreme<2*100;vreme++){
        if(broeveBegachiSVreme[vreme]>0){
            if(poziciqBroqch==2){
                tretoVreme=vreme;
                break;
            }else{
                poziciqBroqch++;
            }
        }
    }

    cout<<broeveBegachiSVreme[tretoVreme];


    for(int nomerNaStart=1;nomerNaStart<=broiBegachi;nomerNaStart++){
        if(VremeNaBegachPoNomerNaStart(nomerNaStart) == tretoVreme){
            cout<<" "<<nomerNaStart;
        }
    }

    return 0;
}
