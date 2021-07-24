#include<iostream>
using namespace std;

int masiv[100];
bool izpolzvaliLiSmeGo[100];

void otpechatva(int broi){
    for(int i=0;i<broi;i++){
        cout<<masiv[i]<<" ";
    }
    cout<<endl;
}

void kombinacii(int a,int b,int broi,int poziciq){
    if(poziciq==broi){
        otpechatva(broi);
    }else{
        for(int x=a;x<=b;x++){
            if(izpolzvaliLiSmeGo[x]==false){
                masiv[poziciq]=x;
                izpolzvaliLiSmeGo[x]=true;
                kombinacii(a,b,broi,poziciq+1);
                izpolzvaliLiSmeGo[x]=false;
            }
        }
    }
}

int main(){
    int a;
    int b;
    int broi;
    cin>>a>>b>>broi;

    kombinacii(a,b,broi,0);

    return 0;
}
