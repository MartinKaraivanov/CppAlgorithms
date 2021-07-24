#include<iostream>
using namespace std;

int dalzhina;
int broiRedoveNaProgramata;

int naKadeSochi[500050];

int stoinosti[500050];

int nomerche;

int getnextint(){
    stoinosti[nomerche] = nomerche;
    nomerche++;
    return nomerche-1;
}

void c(int koeChislo, int otKadeGleda){
    stoinosti[naKadeSochi[koeChislo]] = stoinosti[naKadeSochi[otKadeGleda]];
}

void r(int koeChislo, int kadeGleda){
    naKadeSochi[koeChislo] = naKadeSochi[kadeGleda];
}

void n(int koeChislo){
    naKadeSochi[koeChislo] = getnextint();
}

int main(){
    cin>>dalzhina>>broiRedoveNaProgramata;

    for(int i = 0; i < dalzhina; i++){
        /*naKadeSochi[i] = i;
        stoinosti[i] = getnextint();*/
        n(i);
    }

    /*for(int i = 0; i < dalzhina; i++){
        cout<<i<<" "<<naKadeSochi[i]<<" "<<chisla[i]<<endl;
    }*/

    for(int i = 0; i < broiRedoveNaProgramata; i++){
        char tip;
        cin>>tip;

        if(tip  == 'C'){
            int koeChislo;
            int otKadeGleda;
            cin>>koeChislo>>otKadeGleda;
            c(koeChislo, otKadeGleda);


        }else{
            if(tip == 'R'){
                int koeChislo;
                int kadeGleda;
                cin>>koeChislo>>kadeGleda;
                r(koeChislo, kadeGleda);

            }else{
                int koeChislo;
                cin>>koeChislo;

                /*for(int j = 0; j < dalzhina; j++){
                    if(naKadeSochi[j] == naKadeSochi[koeChislo]){
                        chisla[j] = nomerche;
                    }
                }*/

                n(koeChislo);

            }
        }

        //cout<<"sled operaciq "<<i<<endl;

        /*for(int j = 0; j < dalzhina; j++){
            cout<<j<<" "<<naKadeSochi[j]<<" "<<chisla[j]<<endl;
        }

        cout<<endl;*/

    }

    for(int i = 0; i < dalzhina; i++){
        cout<<stoinosti[naKadeSochi[i]]<<" ";
    }

    cout<<endl;

    return 0;
}
