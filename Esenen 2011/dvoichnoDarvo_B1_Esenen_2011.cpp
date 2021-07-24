#include<iostream>
using namespace std;

int p;

long long chisla[4];

bool stavaLi(long long chi){
    int broiEdinici = 0;
    bool imameLiNeshtoDrugoOsvenEdinica = false;
    bool samoNulaEdnoIDveLiImame = true;
    bool imameLiDvoika = false;

    while(chi > 0){
        long long ostatukTuk = chi%p;
        //cout<<chi<<" "<<ostatukTuk<<endl;

        if(ostatukTuk == 1){
            broiEdinici++;
        }
        if(ostatukTuk == 0){
            imameLiNeshtoDrugoOsvenEdinica = true;
        }
        if(ostatukTuk == 2){
            imameLiNeshtoDrugoOsvenEdinica = true;
            imameLiDvoika = true;
        }
        if(ostatukTuk >= 3){
            samoNulaEdnoIDveLiImame = false;
            break;
        }

        chi /= p;
    }

    return (broiEdinici == 1 && imameLiNeshtoDrugoOsvenEdinica && samoNulaEdnoIDveLiImame && imameLiDvoika) ||
        (broiEdinici == 2 && !imameLiDvoika && imameLiNeshtoDrugoOsvenEdinica && samoNulaEdnoIDveLiImame);
}

int main(){
    cin>>p;

    for(int i = 0; i < 4; i++){
        cin>>chisla[i];
    }

    for(int i = 0; i < 4; i++){
        bool zaTuk = stavaLi(chisla[i]);
        //cout<<chisla[i]<<" "<<zaTuk<<endl;
        if(zaTuk == true){
            cout<<1<<" ";
        }else{
            cout<<0<<" ";
        }
    }

    cout<<endl;

    return 0;
}
