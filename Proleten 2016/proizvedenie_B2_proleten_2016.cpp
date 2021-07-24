#include<iostream>
#include<map>
using namespace std;

unsigned long long chisla[250000];
int broiChisla;

int naiGolqmPoMalakVlqvo[250000];
int naiGolqmPoGolqmVdqsno[250000];

//const int golqmoChislo = 10000000;

map<int, int> stoinosti;

int obarnatoChislo(int a){
    //return golqmoChislo - a;
    return 0 - a;
}

int main(){
    int chislo;

    while(cin>>chislo){
        broiChisla++;
        chisla[broiChisla] = chislo;
    }

    /*for(int s = 2; s <= broiChisla - 1; s++){
        int naiGolqm = 0;
        int indexNaNaiGolqm = -1;

        for(int p = 1; p < s; p++){
            if(chisla[p] < chisla[s]){
                if(chisla[p] > naiGolqm){
                    naiGolqm = chisla[p];
                    indexNaNaiGolqm = p;
                }
            }
        }

        naiGolqmPoMalakVlqvo[s] = indexNaNaiGolqm;
    }*/

    for(int i = 1; i <= broiChisla; i++){
        auto zaTuka = stoinosti.upper_bound(obarnatoChislo(chisla[i]));
        naiGolqmPoMalakVlqvo[i] = (*zaTuka).second;
        stoinosti[obarnatoChislo(chisla[i])] = i;
    }

    /*for(int i = 1; i <= broiChisla; i++){
        cout<<i<<" "<<naiGolqmPoMalakVlqvo[i]<<endl;
    }*/

    int naiGolqmNadqsno = chisla[broiChisla - 1];
    int indexNaNaiGolemiqNadqsno = broiChisla - 1;

    for(int j = broiChisla; j > 0; j--){
        if(naiGolqmNadqsno > chisla[j]){
            naiGolqmPoGolqmVdqsno[j] = indexNaNaiGolemiqNadqsno;
        }else{
            if(chisla[j] > naiGolqmNadqsno){
                naiGolqmNadqsno = chisla[j];
                indexNaNaiGolemiqNadqsno = j;
            }
            naiGolqmPoGolqmVdqsno[j] = -1;
        }
    }

    unsigned long long maxProizvedenie = 0;
    int parviIndex = 0;
    int vtoriIndex = 0;
    int tretiIndex = 0;

    for(int s = 2; s < broiChisla; s++){
        unsigned long long proizvedenie = chisla[naiGolqmPoMalakVlqvo[s]] * chisla[s] * chisla[naiGolqmPoGolqmVdqsno[s]];
        if(proizvedenie > maxProizvedenie){
            maxProizvedenie = proizvedenie;
            parviIndex = naiGolqmPoMalakVlqvo[s];
            vtoriIndex = s;
            tretiIndex = naiGolqmPoGolqmVdqsno[s];
        }
    }

    cout<<maxProizvedenie<<endl;

    cout<<parviIndex<<" "<<vtoriIndex<<" "<<tretiIndex<<endl;

    return 0;
}
