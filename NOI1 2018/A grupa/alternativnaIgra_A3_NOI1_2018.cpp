#include<iostream>
using namespace std;

int a;
int b;

int broiIgri;

int priTolkova[1500000];

long long ostatkNaGolqmoChislo(string koeChisloKatoString, long long daljina){
    long long ostatk = 0;

    for(long long i = 0; i < koeChisloKatoString.size(); i++){
        ostatk = (10*ostatk + (koeChisloKatoString[i] - '0'))%daljina;
    }

    return ostatk;
}

long long kasoChisloOtStringKamNormalno(string koeChisloKatoString){
    long long koeChislo = 0;

    for(unsigned long long i = 0; i < koeChisloKatoString.size(); i++){
        koeChislo = koeChislo*10 + (koeChisloKatoString[i] - '0');
    }

    return koeChislo;
}

bool pechelivshLiEHoda(long long ostavashtBroiZvezdi){
    if(ostavashtBroiZvezdi < a){
        return true;
    }

    if(priTolkova[ostavashtBroiZvezdi] != 0){
        if(priTolkova[ostavashtBroiZvezdi] == 1){
            return true;
        }else{
            return false;
        }
    }

    bool zaTuk = false;

    if(ostavashtBroiZvezdi >= b){
        bool tekushto = pechelivshLiEHoda(ostavashtBroiZvezdi - b);
        if(tekushto == true){
            zaTuk = true;
        }
    }

    bool tekushto = pechelivshLiEHoda(ostavashtBroiZvezdi - a);

    if(tekushto == true){
        zaTuk = true;
    }

    if(!zaTuk == true){
        priTolkova[ostavashtBroiZvezdi] = 1;
    }else{
        priTolkova[ostavashtBroiZvezdi] = 2;
    }

    return !zaTuk;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>a>>b;

    if(a > b){
        swap(a, b);
    }

    cin>>broiIgri;

    for(int t = 0; t < broiIgri; t++){
        string broiZvezdi;

        cin>>broiZvezdi;

        long long koeIskame = 0;

        if(broiZvezdi.size() > 18){
            koeIskame = ostatkNaGolqmoChislo(broiZvezdi, a + b);
        }else{
            koeIskame = kasoChisloOtStringKamNormalno(broiZvezdi) % (a + b);
        }

        bool taziIgra = pechelivshLiEHoda(koeIskame);

        if(taziIgra == true){
            cout<<2<<endl;
        }else{
            cout<<1<<endl;
        }
    }


    return 0;
}
