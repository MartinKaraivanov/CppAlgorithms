#include<iostream>
using namespace std;

long long koeChislo;
int poslednoKogatoNeSePov;

int posledniCifriPriTolkova[1000000];

int main(){
    cin>>koeChislo;

    int predno = 1;
    int segashno = 1;

    int parvo = 1;
    int vtoro = 1;

    posledniCifriPriTolkova[1] = 1;
    posledniCifriPriTolkova[2] = 1;

    for(long long i = 3; true; i++){
        int sledvashto = (predno+ segashno)%100;

        if(segashno == parvo && sledvashto == vtoro){
            poslednoKogatoNeSePov = i - 2;
            break;
        }

        posledniCifriPriTolkova[i] = sledvashto;

        predno = segashno;
        segashno = sledvashto;
    }

    //cout<<9876543210%300<<endl;

    /*while(koeChislo > poslednoKogatoNeSePov){
        koeChislo -= poslednoKogatoNeSePov;
    }*/

    /*for(int i = 0; i <= poslednoKogatoNeSePov; i++){
        if(posledniCifriPriTolkova[i] == 80){
            cout<<" ";
        }
        cout<<i<<" "<<posledniCifriPriTolkova[i]<<endl;
    }*/



    //cout<<(koeChislo%poslednoKogatoNeSePov) + 1<<endl;

    if(posledniCifriPriTolkova[koeChislo % poslednoKogatoNeSePov] < 10){
        cout<<0;
    }

    cout<<posledniCifriPriTolkova[koeChislo % poslednoKogatoNeSePov]<<endl;

    //cout<<poslednoKogatoNeSePov<<endl;

    return 0;
}
