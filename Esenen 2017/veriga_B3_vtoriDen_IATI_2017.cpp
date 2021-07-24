#include<iostream>
#include<stack>
using namespace std;

int broiChislaVRedicata;

int chisla[500005];

int otgovori[500005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiChislaVRedicata;

    for(int i = 0; i < broiChislaVRedicata; i++){
        cin>>chisla[i];
    }

    otgovori[broiChislaVRedicata - 1] = 0;

    stack<int> s;

    s.push(chisla[broiChislaVRedicata - 1]);

    for(int i = broiChislaVRedicata - 2; i >= 0; i--){
        while(s.empty() == false){
            int naiOtgore = s.top();
            s.pop();

            if(naiOtgore > chisla[i]){
                s.push(naiOtgore);
                break;
            }
        }

        otgovori[i] = s.size();

        s.push(chisla[i]);
    }

    for(int i = 0; i < broiChislaVRedicata; i++){
        cout<<otgovori[i]<<" ";
    }

    cout<<endl;

    return 0;
}
