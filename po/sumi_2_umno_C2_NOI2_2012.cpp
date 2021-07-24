#include<iostream>
using namespace std;

int broiChisla;
int a;
int b;
int chisla[25000];
bool sumi[25000];
int nomerche=1;
int broiSumiOtgovarqshti;
int maxSuma;

int main(){
    cin>>broiChisla>>a>>b;

    for(int i=0;i<broiChisla;i++){
        cin>>chisla[i];
    }

    sumi[0]=true;

    for(int j=0;j<broiChisla;j++){
        for(int i=maxSuma;i>=0;i--){
            if(sumi[i]==true){
                if(sumi[i+chisla[j]]==false){
                    sumi[i+chisla[j]]=true;
                    if(i+chisla[j]>maxSuma){
                        maxSuma=i+chisla[j];
                    }
                }
            }
        }
    }


    for(int i=a;i<=b;i++){
        if(sumi[i]>0){
            broiSumiOtgovarqshti++;
        }
    }

    cout<<broiSumiOtgovarqshti<<endl;

    return 0;
}
