#include<iostream>
using namespace std;

void PechataneNaObratno(int chi[], int index){
    if(index>=0){
        cout<<chi[index]<<" ";
        PechataneNaObratno(chi, index-1);
    }
}

int main(){
    int broiChisla;
    cin>>broiChisla;

    int chisla[broiChisla];

    for(int i=0;i<broiChisla;i++){
        cin>>chisla[i];
    }

    PechataneNaObratno(chisla, broiChisla-1);

    return 0;
}
