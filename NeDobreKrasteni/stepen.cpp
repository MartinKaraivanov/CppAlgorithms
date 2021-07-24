#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long chislo;

    cin>>chislo;

    long long broiPredstavqniq=0;

    long long a;
    long long stepen;

    for(a=sqrt(chislo);a>=2;a--){
        for(stepen=2;stepen<=sqrt(chislo);stepen++){
            long long stepenuvano=pow(a,stepen);
            if(stepenuvano<=chislo){
                if(stepenuvano==chislo){
                    broiPredstavqniq++;
                }
            }else{
                break;
            }
        }
    }

    cout<<broiPredstavqniq<<endl;

   for(a=sqrt(chislo);a>=2;a--){
        for(stepen=2;stepen<=sqrt(chislo);stepen++){
            long long stepnuvano=pow(a,stepen);
            if(stepnuvano<=chislo){
                if(pow(a,stepen)==chislo){
                    cout<<a<<" "<<stepen <<endl;
                }
            }else{
                break;
            }
        }
    }

    return 0;
}
