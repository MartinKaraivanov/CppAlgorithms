#include<iostream>
using namespace std;
int main(){
    int broiChisla;
    cin>>broiChisla;

    long long chislaOtVestnika[broiChisla];

    for(int i=0;i<broiChisla;i++){
        cin>>chislaOtVestnika[i];
    }

    bool lybimoLiEChisloto[broiChisla];

    for(int i=0;i<broiChisla;i++){
        lybimoLiEChisloto[i]=false;
    }

    for(int i=0;i<broiChisla;i++){
        bool ima3=false;
        long long chislo = chislaOtVestnika[i];
        while(chislo>0){
            if((chislo%10)==3){
                ima3=true;
                chislo/=10;
            }else{
                if(((chislo%10)==1) && (ima3==true)){
                    lybimoLiEChisloto[i]=true;
                    break;
                }else{
                    chislo/=10;
                }
            }
        }
    }

    int broiLubimiChisla=0;

    for(int i=0;i<broiChisla;i++){
        if(lybimoLiEChisloto[i]==true){
            broiLubimiChisla++;
        }
    }

    if(broiLubimiChisla>0){
        cout<<broiLubimiChisla;
    }else{
        cout<<"No";
    }

    cout<<endl;


    return 0;
}
