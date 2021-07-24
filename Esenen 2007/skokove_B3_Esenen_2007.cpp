#include<iostream>
#include<map>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

int broiTochki;

DanniZaTochka tochki[1000005];


int main(){
    cin>>broiTochki;

    for(int i = 0; i < broiTochki; i++){
        cin>>tochki[i].x>>tochki[i].y;
    }



    return 0;
}
