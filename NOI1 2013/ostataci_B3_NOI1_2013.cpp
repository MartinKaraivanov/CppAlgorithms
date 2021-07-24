#include<iostream>
#include<queue>
using namespace std;

struct Danni{
    int nomerNaTova;
    int kolkoEPatqDoNego;
};

long long chislotoZaZamestvane;
long long priDelenieNaKolko;
long long zaPribEdno;
long long zaPribDve;
long long ostatakZaPoluch;

bool visited[100000010];

int main(){
    cin>>chislotoZaZamestvane>>priDelenieNaKolko>>zaPribEdno>>zaPribDve>>ostatakZaPoluch;

    queue<Danni> q;

    int n = chislotoZaZamestvane%priDelenieNaKolko;

    Danni nachalno = {n, 0};

    q.push(nachalno);

    while(q.empty() == false){
        Danni naiOtgore = q.front();
        q.pop();

        if(visited[naiOtgore.nomerNaTova]){
            continue;
        }

        if(naiOtgore.kolkoEPatqDoNego > 0){
            visited[naiOtgore.nomerNaTova] = true;
        }

        if(naiOtgore.nomerNaTova == ostatakZaPoluch && naiOtgore.kolkoEPatqDoNego != 0){
            cout<<naiOtgore.kolkoEPatqDoNego<<endl;
            return 0;
            break;
        }

        int p = (naiOtgore.nomerNaTova + zaPribEdno)%priDelenieNaKolko;
        int v = (naiOtgore.nomerNaTova + zaPribDve)%priDelenieNaKolko;

        Danni parvoSledvashto = {p, naiOtgore.kolkoEPatqDoNego + 1};
        Danni vtoroSledvashto = {v, naiOtgore.kolkoEPatqDoNego + 1};

        if(!visited[parvoSledvashto.nomerNaTova]){
            q.push(parvoSledvashto);
        }

        if(!visited[vtoroSledvashto.nomerNaTova]){
            q.push(vtoroSledvashto);
        }
    }

    cout<<-1<<endl;

    return 0;
}
