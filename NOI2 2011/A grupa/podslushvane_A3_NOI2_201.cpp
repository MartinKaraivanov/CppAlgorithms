#include<iostream>
using namespace std;

int broiObekti;

long long xoroveNaBitove[64];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiObekti;

    long long xorChe = 0;

    for(int i = 0; i < broiObekti; i++){
        long long obekt;
        cin>>obekt;

        xorChe = xorChe^obekt;

        for(int j = 0; j <= 63; j++){
            if((obekt & (1 << j)) != 0){
                xoroveNaBitove[j] = xoroveNaBitove[j]^obekt;
            }
        }
    }

    long long koiBit = 0;

    while((xorChe & (1<<koiBit)) == 0){
        koiBit++;
    }

    long long parvoto = xoroveNaBitove[koiBit];
    long long vtoroto = xorChe^parvoto;

    if(parvoto > vtoroto){
        swap(parvoto, vtoroto);
    }

    cout<<parvoto<<" "<<vtoroto<<endl;

    return 0;
}
