#include<iostream>
#include<stack>
using namespace std;
int main(){
    char posoka;

    stack<char> posokiteNaHorata;

    while(cin>>posoka){
        if(posokiteNaHorata.empty()==true){
            posokiteNaHorata.push(posoka);
        }else{
            if(posoka=='L'){
                posokiteNaHorata.push(posoka);
            }else{
                if((posoka=='R') && (posokiteNaHorata.top()=='L')){
                    posokiteNaHorata.pop();
                }else{
                    posokiteNaHorata.push(posoka);
                }
            }
        }
    }

    cout<<posokiteNaHorata.size()<<endl;

    stack<char> sledParvoto;

    while(posokiteNaHorata.empty()==false){
        char posokaNaNoviq=posokiteNaHorata.top();
        posokiteNaHorata.pop();

        if(sledParvoto.empty()==true){
            sledParvoto.push(posokaNaNoviq);
        }else{
            if(posokaNaNoviq=='L'){
                sledParvoto.push(posokaNaNoviq);
            }else{
                if((posokaNaNoviq=='R') && (sledParvoto.top()=='L')){
                    sledParvoto.pop();
                }else{
                    sledParvoto.push(posokaNaNoviq);
                }
            }
        }
    }

    cout<<sledParvoto.size();

    return 0;
}
