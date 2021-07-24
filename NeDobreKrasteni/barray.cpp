#include<iostream>
using namespace std;
int main(){
    long long kolkoChisla;
    cin>>kolkoChisla;
    long long chisla[kolkoChisla];

    for(int i=0;i<kolkoChisla;i++){
        cin>>chisla[i];
    }

    long long sbor=0;
    for(int i=0;i<kolkoChisla;i++){
        sbor=sbor+chisla[i];
    }


    long long elementZaBalans=-1;
    long long sborZaBalans=0;
    for(int i=0;i<kolkoChisla;i++){
       sborZaBalans=sborZaBalans+chisla[i];
       if(sborZaBalans==sbor/2){
            elementZaBalans=i+1;
       }else{
            elementZaBalans=elementZaBalans;
       }
    }
    cout<<elementZaBalans<<endl;

    return 0;
}
