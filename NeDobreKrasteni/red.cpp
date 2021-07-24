#include <iostream>
using namespace std;
int main(){
long long kolkoChisla,naKoqPoziciq,/*poziciq[naKoqPoziciq],*/kolkoSaPredi,kolkoSaSled,kolkoPati;
cin>>kolkoChisla;
cout<<"ghjyt"<<endl;
cin>>kolkoPati;
cout<<"sdrt"<<endl;
int naKoiiChoveshkiPozicii[kolkoPati];

int vhod[kolkoChisla];

for(int i=0;i<kolkoChisla;i++){
    cin>>vhod[i];
}
cout<<"fghtc"<<endl;
for(int i=0;i<kolkoPati;i++){
    cin>>naKoiiChoveshkiPozicii[i];
}

cout<<endl;

for(int i=0;i<kolkoPati;i++){
    kolkoSaPredi=0;
    kolkoSaSled=0;
    naKoqPoziciq = naKoiiChoveshkiPozicii[i]-1;

    for(int a=0;a<naKoqPoziciq;a++){
        if(vhod[a]==vhod[naKoqPoziciq]){
            kolkoSaPredi++;
        }
    }
    for(int b=kolkoChisla;b>naKoqPoziciq;b=b-1){
        if(vhod[b]==vhod[naKoqPoziciq]){
            kolkoSaSled++;
        }
    }

    cout<<kolkoSaPredi<<" "<<kolkoSaSled<<endl;
}
/*for(int i=0;i<naKoqPoziciq;i++){
    cin>>poziciq[i];
}


for(int i=0;i<naKoqPoziciq;i++){
    for(int n=0;n<poziciq[i];n++){
        if(poziciq[n]==poziciq[i]){
            imaLiPredi=imaLiPredi+1;
        }
    }
}
*/
return 0;
}
