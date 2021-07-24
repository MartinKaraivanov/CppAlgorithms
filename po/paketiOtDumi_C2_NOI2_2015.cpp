#include<iostream>
#include<cstring>
using namespace std;

int kolkoSeZastapvat(string parvi, string vtori){
    int ps=parvi.size();
    int vs=vtori.size();

    int start=min(ps, vs)-1;

    for(int brBukviZast=start;brBukviZast>0;brBukviZast--){
        string sc1=parvi.substr(ps-brBukviZast, brBukviZast);
        string sc2=vtori.substr(0, brBukviZast);

        if(sc1.compare(sc2)==0){
            return brBukviZast;
        }
    }
    return 0;
}

int main(){
    int broiDumi;

    cin>>broiDumi;

    string dumi[broiDumi];

    for(int i=0;i<broiDumi;i++){
        cin>>dumi[i];
    }

    int naKoqPoziciqDaIzrezha[broiDumi];

    naKoqPoziciqDaIzrezha[0]=0;

    for(int i=1;i<broiDumi;i++){
        int brZastup=kolkoSeZastapvat(dumi[i-1], dumi[i]);
        if(brZastup>0){
            naKoqPoziciqDaIzrezha[i]=brZastup;
        }else{
            naKoqPoziciqDaIzrezha[i]=0;
        }
    }

    for(int i=0;i<broiDumi;i++){
        cout<<dumi[i].substr(naKoqPoziciqDaIzrezha[i], dumi[i].size());
    }

    return 0;
}
