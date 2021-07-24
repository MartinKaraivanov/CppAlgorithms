#include<iostream>
using namespace std;

struct DanniZaRebro{
    int otKade;
    int doKade;
};

int broiVarhove;
int broiRebra;

DanniZaRebro rebra[200005];

int main(){
    cin>>broiVarhove>>broiRebra;

    for(int i = 0; i < broiRebra; i++){
        cin>>rebra[i].otKade>>rebra[i].doKade;
    }

    int broiStavashti = 0;

    for(int i = 0; i < broiRebra; i++){
        for(int j = i; j < broiRebra; j++){


        }
    }

    cout<<broiStavashti<<endl;

    return 0;
}
