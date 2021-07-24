#include<iostream>
#include<algorithm>
using namespace std;

bool poMalkoLie(int a, int b){
    return a<b;
}

int main(){
    long long broi;
    cin>>broi;
    long long chisla[broi];

    for(int i=0;i<broi;i++){
        cin>>chisla[i];
    }

    sort(chisla,chisla+broi,poMalkoLie);

    long long nasheChislo;
    cin>>nasheChislo;

    bool namerihLiChisloto=false;

    long long nachalenIndex=0;
    long long kraenIndex=broi-1;

    while((nachalenIndex<=kraenIndex) && (namerihLiChisloto==false) ){
        long long sredenindex=(nachalenIndex+kraenIndex)/2;
        if(chisla[sredenindex]==nasheChislo){
            namerihLiChisloto=true;
        }
        if(nasheChislo<chisla[sredenindex]){
            kraenIndex=sredenindex-1;
        }else{
            nachalenIndex=sredenindex+1;
        }
    }


    if(namerihLiChisloto==true ){
        cout<<"Ima go";
    }else{
        cout<<"Nqma go";
    }


    return 0;
}
