#include<iostream>
using namespace std;

int broiKashoni;
int otgovori[5];

int main(){
    int aVrata;
    int bVrata;

    cin>>aVrata>>bVrata;

    int lichice = (aVrata*bVrata)/2;

    for(int i = 0; i < 4; i++){
        int a;
        int b;
        int c;
        cin>>a>>b>>c;

        int lice1 = a*b;
        int lice2 = a*c;
        int lice3 = b*c;

        int miinimal = min(min(lice1, lice2), lice3);

        if(miinimal < lichice){
            otgovori[i] = 1;
        }

    }

    for(int i = 0; i < 4; i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
