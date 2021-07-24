#include<iostream>
using namespace std;

bool vlizaLi(long long x, long long y, long long a, long long b){
    if(b*x <= y*(x - a)){
        return true;
    }

    if((b*x*y + a*(x*x + y*y))*(b*x*y + a*(x*x + y*y)) <= (x*x + y*y)*x*x*y*y){
        return true;
    }

    return false;
}

int main(){
    long long x;
    long long y;

    cin>>x>>y;

    long long otgovori[4];

    for(long long i = 0; i < 4; i++){
        long long a;
        long long b;
        long long c;

        cin>>a>>b>>c;

        if(vlizaLi(x, y, a, b) || vlizaLi(x, y, a, c) || vlizaLi(x, y, b, c) ||
            vlizaLi(x, y, b, a) || vlizaLi(x, y, c, a) || vlizaLi(x, y, c, b))
        {
            otgovori[i] = 1;
        }else{
            otgovori[i] = 0;
        }
    }

    for(long long i = 0; i < 4; i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
