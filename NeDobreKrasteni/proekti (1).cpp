#include<iostream>
#include<algorithm>
using namespace std;

struct danniZaProekta{
    int momentNachlo;
    int momentKrai;

};



int main(){
    int broiProjecti;
    cin>>broiProjecti;

    danniZaProekta proekt[broiProjecti];

    for(int i=0;i<broiProjecti;i++){
        cin>>proekt.momentNachlo>>proekt.momentKrai;
    }



    return 0;
}
