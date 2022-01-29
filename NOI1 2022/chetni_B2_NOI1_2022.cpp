#include<iostream>
using namespace std;

int broiChisla;

int chisla[10010];

int main(){

    cin>>broiChisla;

    for(int i = 0; i < broiChisla; i++){
        cin>>chisla[i];
    }

    int broiPodredNech = 0;

    int broiIntervaliBezCh = 0;

    for(int i = 0; i <= broiChisla; i++){
        if(chisla[i] % 2 == 0){
            broiIntervaliBezCh += (broiPodredNech+1)*broiPodredNech/2;
            broiPodredNech = 0;
        }else{
            broiPodredNech++;
        }
    }

    int obshtoIntervali = (broiChisla+1)*broiChisla/2;

    int intervaliSChetno = obshtoIntervali - broiIntervaliBezCh;

    cout<<intervaliSChetno<<endl;

    return 0;
}
