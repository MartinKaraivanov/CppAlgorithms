#include<iostream>
using namespace std;
int main(){
    int n;
    int m;
    int k;

    cin>>n>>m>>k;

    int tablica[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>tablica[i][j];
        }
    }

    int p=0;
    int abscisa;
    int oordinata;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            p++;
            if(p==k){
                abscisa=i;
                oordinata=j;
            }
        }
    }

    int sborParviKvadrant=0;

    for(int i=0;i<abscisa;i++){
        for(int j=oordinata+1;j<m;j++){
            sborParviKvadrant+=tablica[i][j];
        }
    }

    int sborVtoriKvadrant=0;

    for(int i=0;i<abscisa;i++){
        for(int j=0;j<oordinata;j++){
            sborVtoriKvadrant+=tablica[i][j];
        }
    }

    int sborTretiKvadrant=0;

    for(int i=abscisa+1;i<n;i++){
        for(int j=0;j<oordinata;j++){
            sborTretiKvadrant+=tablica[i][j];
        }
    }

    int sborChetvartiKvadrant=0;

    for(int i=abscisa+1;i<n;i++){
        for(int j=oordinata+1;j<m;j++){
            sborChetvartiKvadrant+=tablica[i][j];
        }
    }

    cout<<sborParviKvadrant<<" "<<sborVtoriKvadrant<<" "<<sborTretiKvadrant<<" "<<sborChetvartiKvadrant<<endl;


    return 0;
}
