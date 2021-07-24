#include<iostream>
#include<cstring>
using namespace std;

char izrechenieMulungu[25000];
long long broiVaprosi;
unsigned long long otgovori[15000000];

long long otNDoTuk[150000];

struct vaprosi{
    long long nachalenElement;
    long long kraenElement;
};

vaprosi vapIzrechenieM[150000];

int main(){
    cin>>izrechenieMulungu>>broiVaprosi;

    for(long long i=0;i<broiVaprosi;i++){
        cin>>vapIzrechenieM[i].nachalenElement>>vapIzrechenieM[i].kraenElement;
    }



    for(long long i=0;i<strlen(izrechenieMulungu);i++){
        if(i==0){
            otNDoTuk[i]=1;
        }else{
            if(izrechenieMulungu[i]<izrechenieMulungu[i-1]){
                otNDoTuk[i]=otNDoTuk[i-1]+1;
            }else{
                otNDoTuk[i]=otNDoTuk[i-1];
            }
        }
    }

    for(long long i=0;i<broiVaprosi;i++){
        otgovori[i]=otNDoTuk[vapIzrechenieM[i].kraenElement-1]-otNDoTuk[vapIzrechenieM[i].nachalenElement-1]+1;
    }

    for(long long i=0;i<broiVaprosi;i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
