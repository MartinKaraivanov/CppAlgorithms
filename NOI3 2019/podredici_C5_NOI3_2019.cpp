#include<iostream>
using namespace std;

int broiChisla;
int chisla[100010];

int main(){
    cin>>broiChisla;

    for(int i = 0; i < broiChisla; i++){
        cin>>chisla[i];
    }

    long long naiDobro = 0;

    for(int parvi = 0; parvi< broiChisla; parvi++){
        int naiMalkoOtNachDoTuk = 100010;
        int sumaDoTuk = 0;
        for(int vtori = parvi; vtori < broiChisla; vtori++){
            if(chisla[vtori] < naiMalkoOtNachDoTuk){
                naiMalkoOtNachDoTuk = chisla[vtori];
            }

            sumaDoTuk+=chisla[vtori];

            long long suma = sumaDoTuk;
            int naiMalakElement = naiMalkoOtNachDoTuk;

            long long segashno = suma * naiMalakElement;

            if(segashno > naiDobro){
                naiDobro = segashno;
            }
        }
    }


    cout<<naiDobro<<endl;

    return 0;
}
