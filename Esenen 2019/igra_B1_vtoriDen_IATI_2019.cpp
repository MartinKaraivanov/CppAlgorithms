#include<iostream>
using namespace std;

unsigned long long nod(unsigned long long a, unsigned long long b){
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long nachalnoVParvaKup;
    unsigned long long nachalnoVavVtoraKup;

    cin>>nachalnoVParvaKup>>nachalnoVavVtoraKup;

    if(nachalnoVavVtoraKup == nachalnoVParvaKup){
        cout<<0<<endl;
        return 0;
    }

    if(nachalnoVParvaKup > nachalnoVavVtoraKup){
        swap(nachalnoVParvaKup, nachalnoVavVtoraKup);
    }

    unsigned long long naiGOD = nod(nachalnoVParvaKup, nachalnoVavVtoraKup);

    if(naiGOD == 1){
        cout<<0<<endl;
        return 0;
    }

    unsigned long long sledDelenieParvoto = nachalnoVParvaKup/naiGOD;
    unsigned long long sledDelenieVtoroto = nachalnoVavVtoraKup/naiGOD;

    unsigned long long zaOtpechatvane = sledDelenieVtoroto/sledDelenieParvoto;

    if(sledDelenieVtoroto % sledDelenieParvoto == 0){
        zaOtpechatvane--;
    }

    zaOtpechatvane = min(zaOtpechatvane, nachalnoVParvaKup/sledDelenieVtoroto);

    cout<<zaOtpechatvane<<endl;

    return 0;
}
