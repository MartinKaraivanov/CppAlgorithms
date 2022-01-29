#include<iostream>
#include<vector>
using namespace std;

long long broiVarhove;

vector<long long> sasedstvo[100010];

int main(){

    cin>>broiVarhove;

    for(long long i = 0; i < broiVarhove - 1; i++){
        long long otKade;
        long long doKade;
        cin>>otKade>>doKade;

        sasedstvo[otKade].push_back(doKade);
        sasedstvo[doKade].push_back(otKade);
    }

    long long broiPovtoreni = 0;

    for(long long i = 1; i <= broiVarhove; i++){
        broiPovtoreni += (sasedstvo[i].size()*(sasedstvo[i].size() - 1))/2;
    }

    cout<<((broiVarhove*(broiVarhove - 1)*(broiVarhove - 2))/6) - ((broiVarhove - 1)*(broiVarhove - 2) - broiPovtoreni)<<endl;

    return 0;
}
