#include<iostream>
using namespace std;

int kolkoPatiTrqbvaDaSeSluchi;

int naiGolqmObshtDelPati(int a, int b){
    if(b > a){
        swap(a, b);
    }
    int broqchche = 0;
    while(b > 0){
        int c = a % b;
        broqchche++;
        a = b;
        b = c;
    }

    return broqchche;
}

int main(){
    cin>>kolkoPatiTrqbvaDaSeSluchi;

    for(int i = 1; i < 10000; i++){
        for(int j = i + 1; j < 10000; j++){
            int patiSega = naiGolqmObshtDelPati(i, j);
            if(patiSega == kolkoPatiTrqbvaDaSeSluchi){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }

    return 0;
}
