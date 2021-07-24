#include<iostream>
using namespace std;
int main(){
    long long broiTelepoerti;
    cin>>broiTelepoerti;
    long long teleporti[broiTelepoerti];
    long long kolkoPatiMinavamPrezTeleporta[broiTelepoerti];

    for(int i=0;i<broiTelepoerti;i++){
        cin>>teleporti[i];
    }

     for(int i=0;i<broiTelepoerti;i++){
        kolkoPatiMinavamPrezTeleporta[i]=0;
    }

    for(int i=0;kolkoPatiMinavamPrezTeleporta[i]<2;i=teleporti[i]){
        kolkoPatiMinavamPrezTeleporta[i]++;
    }
    long long broika[3];
    broika[0]=0;
    broika[1]=0;
    broika[2]=0;
    for(int i=0;i<broiTelepoerti;i++){
        if(kolkoPatiMinavamPrezTeleporta[i]==0){
            broika[0]++;
        }
        if(kolkoPatiMinavamPrezTeleporta[i]==1){
            broika[1]++;
        }
        if(kolkoPatiMinavamPrezTeleporta[i]>=2){
            broika[2]++;
        }
    }
    cout<<broika[1]<<" "<<broika[2]<<" "<<broika[0]<<endl;

    return 0;
}
