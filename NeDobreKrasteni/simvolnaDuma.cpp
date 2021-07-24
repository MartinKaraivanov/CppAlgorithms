#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack <char> duma;
    char bukva;

    while(cin>>bukva){
        if(duma.empty()==false){
            if(duma.top()!=bukva){
                duma.push(bukva);
            }else{
                duma.pop();
            }
        }else{
            duma.push(bukva);
        }
    }

    stack<char> otpechatvane;

    if(duma.empty()==true){
        cout<<"0";
    }else{
        while(duma.empty()==false){
            otpechatvane.push(duma.top());
            duma.pop();
        }
        while(otpechatvane.empty()==false){
            cout<<otpechatvane.top();
            otpechatvane.pop();
        }
    }

    return 0;
}
