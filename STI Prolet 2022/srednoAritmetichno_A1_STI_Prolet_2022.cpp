#include<iostream>
#include<iomanip>
using namespace std;

const long long mnogo = 10000000000;

long long broiChisla;
long long poneDaljina;

long long chisla[300010];

long long naiGolqmoChislo;

long long sborDo[300010];
long long naiMalkotoDo[300010];

bool mojeLiSTolkova(long long sKolko){

    for(long long i = 1; i <= broiChisla; i++){
        sborDo[i] = sborDo[i - 1] + chisla[i] - sKolko;
    }

    naiMalkotoDo[0] = mnogo;

    for(long long i = 1; i <= broiChisla; i++){
        naiMalkotoDo[i] = min(naiMalkotoDo[i - 1], sborDo[i]);
    }

    long long naiGolqmoto = sborDo[poneDaljina];

    for(long long i = poneDaljina + 1; i <= broiChisla; i++){
        long long tekushto = sborDo[i] - naiMalkotoDo[i - poneDaljina];
        naiGolqmoto = max(naiGolqmoto, tekushto);
    }

    if(naiGolqmoto >= 0){
        return true;
    }

    return false;
}

int main(){

    cin>>broiChisla>>poneDaljina;

    for(long long i = 1; i <= broiChisla; i++){
        cin>>chisla[i];
        chisla[i] *= 10000;
        naiGolqmoChislo = max(naiGolqmoChislo, chisla[i]);
    }

    long long lqvKrai = 0;
    long long desenKrai = naiGolqmoChislo;

    while(lqvKrai < desenKrai){
        long long sredata = (lqvKrai + desenKrai)/2;

        //cout<<"lqv krai "<<lqvKrai<<" desen krai "<<desenKrai<<" sreda "<<sredata<<endl;

        if(mojeLiSTolkova(sredata) == true){
            //cout<<"moje s tolkova"<<endl;
            lqvKrai = sredata + 1;
        }else{
            //cout<<"ne moje s tolkova"<<endl;
            desenKrai = sredata;
        }
    }

    double otgovor = (double)lqvKrai/10000;

    cout<<fixed<<setprecision(4)<<otgovor<<endl;

    return 0;
}
