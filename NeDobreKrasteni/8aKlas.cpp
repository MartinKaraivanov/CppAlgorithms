#include<iostream>
#include<cstring>
using namespace std;

char simvol[40005];

int main(){
    long long zdravei=0;
    long long rakostis=0;
    long long brMomicheta=0;
    long long brMomcheta=0;

    cin>>simvol;

    long long daljina=strlen(simvol);


    for(long long i=0;i<daljina;i++){
        if((simvol[i]=='+')){
            if((brMomicheta) || (brMomcheta>0)){
                zdravei+=brMomicheta+1+brMomcheta;
                brMomicheta++;
            }else{
                brMomicheta++;
            }
        }else{
            zdravei+=brMomicheta*2;
            rakostis+=brMomcheta;
            brMomcheta++;
        }
    }

    cout<<rakostis<<" "<<zdravei<<endl;

    return 0;
}
