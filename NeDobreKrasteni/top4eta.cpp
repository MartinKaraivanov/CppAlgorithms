#include<iostream>
using namespace std;
int main(){
    long long broiSandacheta;
    long long broiTopkiZaPuskane;

    cin>>broiSandacheta>>broiTopkiZaPuskane;

    long long vKoiSandachetaSePuska[broiTopkiZaPuskane];

    long long vKoiSandachetaSmePusnali[broiTopkiZaPuskane];

    long long broiPrazniSandacheta=broiSandacheta;

    for(long long i=1;i<=broiTopkiZaPuskane;i++){
        cin>>vKoiSandachetaSePuska[i];
        bool imaLiGo=false;
        for(int j=0;j<i;j++){
            if(vKoiSandachetaSmePusnali[j]==vKoiSandachetaSePuska[i]){
                imaLiGo=true;
                break;
            }
        }
        if(imaLiGo==false){
            broiPrazniSandacheta--;
            vKoiSandachetaSmePusnali[i]=vKoiSandachetaSePuska[i];
        }
    }


    cout<<broiPrazniSandacheta<<endl;

    return 0;
}
