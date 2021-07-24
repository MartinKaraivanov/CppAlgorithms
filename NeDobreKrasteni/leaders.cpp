#include<iostream>
#include<stack>
using namespace std;

int redica[2000000];

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>redica[i];
    }

    stack<int> liderskiChisla;

    int naiGolemo=-2000000000;
    for(int i=n-1;i>=0;i--){
        if(redica[i]>=naiGolemo){
            liderskiChisla.push(redica[i]);
            naiGolemo=redica[i];
        }
    }

    while(liderskiChisla.empty()==false){
        cout<<liderskiChisla.top()<<" ";
        liderskiChisla.pop();
    }

    cout<<endl;
    return 0;
}
