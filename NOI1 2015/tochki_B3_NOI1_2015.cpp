#include<iostream>
#include<map>
#include<queue>
using namespace std;

int broiOtsechki;
int broiTochki;

map<long long, long long> kolkoOtsechkiImaTam;

int main(){
    cin>>broiOtsechki>>broiTochki;

    for(int i = 0; i < broiOtsechki; i++){
        int nachalo;
        int krai;
        cin>>nachalo>>krai;
        for(int j = min(nachalo, krai); j <= max(nachalo, krai); j++){
            kolkoOtsechkiImaTam[j]++;
        }
    }

    queue<long long> q;

    for(int i = 0; i < broiTochki; i++){
        int kadeETochkata;
        cin>>kadeETochkata;
        q.push(kolkoOtsechkiImaTam[kadeETochkata]);
    }

    while(q.empty() == false){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}
