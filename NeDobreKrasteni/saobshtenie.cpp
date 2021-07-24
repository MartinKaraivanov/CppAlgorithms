#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<char> zakodirano;
    char bukva;

    while(cin>>bukva){
        if(bukva>='A' && bukva<='z'){
            if(zakodirano.empty()==false){
                if(zakodirano.top()!=bukva){
                    zakodirano.push(bukva);
                }else{
                    zakodirano.pop();
                }
            }else{
                zakodirano.push(bukva);
            }
        }
    }

    stack<char> otpechatvane;

    if(zakodirano.empty()==true){
        cout<<endl;
    }else{
        while(zakodirano.empty()==false){
            otpechatvane.push(zakodirano.top());
            zakodirano.pop();
        }
        while(otpechatvane.empty()==false){
            cout<<otpechatvane.top();
            otpechatvane.pop();
        }
    }

    return 0;
}
