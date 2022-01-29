#include<iostream>
#include<unordered_map>
using namespace std;

int broiChisla;
long long chisla[500010];

long long xorDo[500010];

unordered_map<long long, int> kolkoPatiSeSreshta;

int main(){

    cin>>broiChisla;

    for(int i = 1;  i <= broiChisla; i++){
        cin>>chisla[i];
    }

    for(int i = 1; i <= broiChisla; i++){
        xorDo[i] = xorDo[i - 1]^chisla[i];
    }

    long long otgovor = 0;

    for(int i = 0; i <= broiChisla; i++){
        otgovor += kolkoPatiSeSreshta[xorDo[i]];
        kolkoPatiSeSreshta[xorDo[i]]++;
    }

    cout<<otgovor<<endl;

    return 0;
}
