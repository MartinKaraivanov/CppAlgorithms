#include<iostream>
#include<algorithm>
using namespace std;

int broiProekti;
int otgovori[1000000];

struct DanniZaProekt{
    int nachalenMoment;
    int kraenMoment;
    int nomerche;
};

DanniZaProekt proekti[2000000];

bool zasichatLiSe(DanniZaProekt a, DanniZaProekt b){
    if((b.nachalenMoment>=a.nachalenMoment) && (b.nachalenMoment<=a.kraenMoment)){
        return true;
    }
    if((b.kraenMoment>=a.nachalenMoment) && (b.kraenMoment<=a.kraenMoment)){
        return true;
    }
    if((a.nachalenMoment>=b.nachalenMoment) && (a.nachalenMoment<=b.kraenMoment)){
        return true;
    }
    if((a.kraenMoment>=b.nachalenMoment) && (a.kraenMoment<=b.kraenMoment)){
        return true;
    }
    return false;
}

bool poMalkoLiE(DanniZaProekt a, DanniZaProekt b){
    return a.nachalenMoment<b.nachalenMoment;
}

bool nomerchetoPoMalkoLiE(DanniZaProekt a, DanniZaProekt b){
    return a.nomerche<b.nomerche;
}

int main(){
    cin>>broiProekti;

    for(int i=0;i<broiProekti;i++){
        cin>>proekti[i].nachalenMoment>>proekti[i].kraenMoment;
        proekti[i].nomerche=i;
    }

    sort(proekti, proekti+broiProekti, poMalkoLiE);

    for(int i=0;i<broiProekti;i++){
        for(int j=i+1;j<broiProekti;j++){
            if(proekti[j].nachalenMoment>proekti[i].kraenMoment){
                break;
            }
            if(zasichatLiSe(proekti[i], proekti[j])==true){
                otgovori[proekti[i].nomerche]++;
                otgovori[proekti[j].nomerche]++;
            }
        }
    }

    for(int i=0;i<broiProekti;i++){
        cout<<otgovori[i]<<" ";
    }

    cout<<endl;

    return 0;
}
