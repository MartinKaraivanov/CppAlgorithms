#include<iostream>
#include<algorithm>
using namespace std;

struct Mnozhestvo{
    long long nachaloNaMnozhestvo;
    long long kraiNaMnozhestvo;

};

bool poMalkoLiE(Mnozhestvo a, Mnozhestvo b){
    return a.nachaloNaMnozhestvo<b.nachaloNaMnozhestvo;
}

int main(){
    long long broiNachalniMnozhestva;
    cin>>broiNachalniMnozhestva;

    Mnozhestvo nachalniMnozhestva [broiNachalniMnozhestva];

    for(int i=0;i<broiNachalniMnozhestva;i++){
        cin>>nachalniMnozhestva[i].nachaloNaMnozhestvo>>nachalniMnozhestva[i].kraiNaMnozhestvo;
    }

    sort(nachalniMnozhestva,nachalniMnozhestva+broiNachalniMnozhestva,poMalkoLiE);

    long long broiKrainiMnozhestva=0;
    Mnozhestvo krainiMnozhestva[broiNachalniMnozhestva];

    krainiMnozhestva[broiKrainiMnozhestva].nachaloNaMnozhestvo=nachalniMnozhestva[0].nachaloNaMnozhestvo;
    krainiMnozhestva[broiKrainiMnozhestva].kraiNaMnozhestvo=nachalniMnozhestva[0].kraiNaMnozhestvo;
    broiKrainiMnozhestva++;

    for(int i=1;i<broiNachalniMnozhestva;i++){
        if(nachalniMnozhestva[i].nachaloNaMnozhestvo>1+krainiMnozhestva[broiKrainiMnozhestva-1].kraiNaMnozhestvo){
            krainiMnozhestva[broiKrainiMnozhestva].nachaloNaMnozhestvo=nachalniMnozhestva[i].nachaloNaMnozhestvo;
            krainiMnozhestva[broiKrainiMnozhestva].kraiNaMnozhestvo=nachalniMnozhestva[i].kraiNaMnozhestvo;
            broiKrainiMnozhestva++;
        }else{
            if(nachalniMnozhestva[i].kraiNaMnozhestvo>krainiMnozhestva[broiKrainiMnozhestva-1].kraiNaMnozhestvo){
                krainiMnozhestva[broiKrainiMnozhestva-1].kraiNaMnozhestvo=nachalniMnozhestva[i].kraiNaMnozhestvo;
            }
        }
    }

    cout<<broiKrainiMnozhestva<<endl;

    for(int i=0;i<broiKrainiMnozhestva;i++){
        cout<<krainiMnozhestva[i].nachaloNaMnozhestvo<<" "<<krainiMnozhestva[i].kraiNaMnozhestvo<<endl;
    }


    return 0;
}
