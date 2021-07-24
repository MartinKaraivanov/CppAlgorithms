#include<iostream>
#include<queue>
using namespace std;
int main(){
    long long doKolko;
    long long broinaSistema;
    cin>>doKolko>>broinaSistema;

    queue <long long> chislaS0ili1;

    chislaS0ili1.push(1);

    while((chislaS0ili1.empty()==false) && (chislaS0ili1.front()<=doKolko)){
        long long frond = chislaS0ili1.front();
        chislaS0ili1.pop();
        cout<<frond<<endl;
        chislaS0ili1.push(frond*broinaSistema);
        chislaS0ili1.push(frond*broinaSistema+1);
    }

    return 0;
}
