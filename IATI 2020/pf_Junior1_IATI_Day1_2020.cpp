#include<iostream>
using namespace std;

long long inll;
char inc;
long long a;
long long b;
long long c;

void inputChar(){
    cin>>inc;
}

void inputLL(){
    cin>>inll;
}

void copyIN(long long& where){
    where = inll;
}

void copyNormal(long long& from, long long& where){
    where = from;
}

void add(long long& what, long long& where){
    where += what;
}

void sub(long long& what, long long& where){
    where -= what;
}

void mul(long long& what, long long& where){
    where *= what;
}

void store(long long what, long long& where){
    where = what;
}

int main(){
    /// 1 - plus  2 - minus

    inputLL();

    copyIN(b);

    store(1, c);

    inputChar();

    if(inc == '='){
        copyNormal(b, a);
        cout<<a<<endl;
        return 0;
    }

    while(true){
        if(inc == '='){
            if(c == 1){
                add(b, a);
                break;
            }else{
                sub(b, a);
                break;
            }
        }
        if(inc == '+'){
            if(c == 1){
                add(b, a);
            }else{
                sub(b, a);
            }
            store(1, b);
            store(1, c);
        }
        if(inc == '-'){
            if(c == 1){
                add(b, a);
            }else{
                sub(b, a);
            }
            store(1, b);
            store(2, c);
        }

        inputLL();

        mul(inll, b);

        inputChar();
    }

    cout<<a<<endl;

    return 0;
}
