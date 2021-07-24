#include<iostream>
#include<queue>
using namespace std;

int poziciiIzbrniOtDecata[1000001];

int main(){
    int n;
    int k;
    cin>>n>>k;

    poziciiIzbrniOtDecata[0]=k;

    for(int i=1;i<=n;i++){
        cin>>poziciiIzbrniOtDecata[i];
    }

    queue <int> deca;

    for(int i=1;i<=n;i++){
        deca.push(i);
    }

    int poziciq=poziciiIzbrniOtDecata[0];
    while(deca.size()>1){
        for(int i=1;i<poziciq;i++){
            deca.push(deca.front());
            deca.pop();
        }
        poziciq=poziciiIzbrniOtDecata[deca.front()];
        deca.pop();
    }

    cout<<deca.front()<<endl;
    deca.pop();

    return 0;
}
