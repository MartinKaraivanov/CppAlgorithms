#include<iostream>
#include<sstream>
#include<string>
using namespace std;

long long doKolko;

const long long mnogo = 1000000007;

long long faktoriel(long long kolko){
    long long fakt = 1;

    for(long long i = 2; i <= kolko; i++){
        fakt = (fakt * i)%mnogo;
    }

    return fakt;
}

int main(){
    cin>>doKolko;

    if(doKolko < 5){
        cout<<0<<endl;
        return 0;
    }

    long long faktoriela = faktoriel(doKolko - 4);

    long long kolkoPatiFaktoriela = 0;

    for(long long i = 1; i <= doKolko; i++){
        for(long long j = 1; j <= doKolko; j++){
            if(j != i){
                for(long long k = 1; k <= doKolko; k++){
                    if(k != j && k != i){
                        for(long long p = 1; p <= doKolko; p++){
                            if(p != k && p != j && p != i){
                               /* string chisloto;

                                chisloto += to_string(i);
                                chisloto += to_string(j);
                                chisloto += to_string(k);
                                chisloto += to_string(p);

                                long long chislo = stoll(chisloto);*/

                                long long chislo = i;

                                if(j < 10){
                                    chislo = 10*chislo+j;
                                }else{
                                    chislo = 100*chislo + j;
                                }

                                if(k < 10){
                                    chislo = 10*chislo+k;
                                }else{
                                    chislo = 100*chislo + k;
                                }

                                if(p < 10){
                                    chislo = 10*chislo+p;
                                }else{
                                    chislo = 100*chislo + p;
                                }

                                if(chislo % 16 == 0){
                                    kolkoPatiFaktoriela++;
                                }

                            }
                        }
                    }
                }
            }
        }
    }

    cout<<(kolkoPatiFaktoriela*faktoriela)%mnogo<<endl;

    return 0;
}
