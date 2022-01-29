#include<iostream>
#include<queue>
using namespace std;

int broiChisla;

int chisla[100010];

int main(){

    cin>>broiChisla;

    for(int i = 0; i < broiChisla; i++){
        cin>>chisla[i];
    }

    priority_queue<int> q;

    q.push(chisla[0]);

    int broiUpotrebi = 0;

    for(int i = 1; i < broiChisla; i++){
        if(q.top() > chisla[i]){
            broiUpotrebi += q.top() - chisla[i];
            q.pop();
            q.push(chisla[i]);
        }
        q.push(chisla[i]);
    }

    cout<<broiUpotrebi<<endl;


    return 0;
}
