#include<iostream>
#include<vector>
using namespace std;

int broiVarhove;
int startSin;
int startCherven;

vector<int> sasedstvo[500010];

int main(){
    cin>>broiVarhove>>startSin>>startCherven;

    for(int i = 0; i < broiVarhove; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;
        sasedstvo[otKade].push_back(doKade);
        sasedstvo[doKade].push_back(otKade);
    }

    return 0;
}
