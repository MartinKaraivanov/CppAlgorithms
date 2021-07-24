#include<iostream>
using namespace std;

int broiChisla;
int chisla[120000];

int sabirane(){
    int maxSborSPosledno2=0;
    int maxSborSPosledno3=0;

    for(int i=0;i<broiChisla;i++){
        int novSborSPosledno2 = chisla[i]*2+max(maxSborSPosledno2,maxSborSPosledno3);
        int novSborSPosledno3 = chisla[i]*3+maxSborSPosledno2;

        maxSborSPosledno2 = novSborSPosledno2;
        maxSborSPosledno3 = novSborSPosledno3;
    }

    return max(maxSborSPosledno2,maxSborSPosledno3);
}

int main(){
    cin>>broiChisla;

    for(int i=0;i<broiChisla;i++){
        cin>>chisla[i];
    }

    int maxSbor=sabirane();

    cout<<maxSbor<<endl;

    return 0;
}
