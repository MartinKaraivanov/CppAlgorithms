#include<iostream>
using namespace std;

int broiTestove;
int broiChislaVTova;

long long parvaRedica[401000];
long long vtoraRedica[401000];

void nulirane(){
    for(int i = 0; i < broiChislaVTova; i++){
        parvaRedica[i] = 0;
        vtoraRedica[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiTestove;

    for(int v = 0; v < broiTestove; v++){
        cin>>broiChislaVTova;

        long long sborche = 0;

        for(int i = 0; i < broiChislaVTova; i++){
            long long chislo;
            cin>>chislo;

            sborche += chislo;
            parvaRedica[i] = chislo;
        }

        for(int i = 0; i < broiChislaVTova; i++){
            long long chislo;
            cin>>chislo;

            sborche += chislo;
            vtoraRedica[i] = chislo;
        }

        if(sborche%broiChislaVTova != 0){
            cout<<-1<<endl;
            continue;
        }

        int koeR;
        int koeA;

        bool napraviliLiSmeNeshto = false;

        for(int r = 0; r < broiChislaVTova; r++){
            bool parvotoLiE = true;
            long long suma;
            bool vsichkiEdnakviLiSa = true;

            for(int i = 0; i < broiChislaVTova; i++){
                int idxNaVtoroto;
                int idxNaParvoto = i;
                if(i >= r){
                    idxNaVtoroto = i - r;
                }else{
                    idxNaVtoroto = broiChislaVTova + i - r;
                }

                long long chisloOtParvataRedica = parvaRedica[idxNaParvoto];
                long long chisloOtVtorataRedica = vtoraRedica[idxNaVtoroto];

                long long sborNaDvete = chisloOtParvataRedica + chisloOtVtorataRedica;

                if(parvotoLiE){
                    suma = sborNaDvete;
                    parvotoLiE = false;
                }else{
                    if(sborNaDvete == suma){
                        /// nishto ne pravim
                    }else{
                        vsichkiEdnakviLiSa = false;
                        break;
                    }
                }

            }

            if(vsichkiEdnakviLiSa){
                koeR = r;
                koeA = 0 - suma;
                napraviliLiSmeNeshto = true;
                break;
            }

        }

        if(napraviliLiSmeNeshto == false){
            cout<<-1<<endl;
            continue;
        }

        int broiNuzhniNeshta = 0;

        if(koeR != 0){
            broiNuzhniNeshta++;
        }

        if(koeA != 0){
            broiNuzhniNeshta++;
        }

        cout<<broiNuzhniNeshta<<endl;

        if(koeR != 0){
            cout<<"r "<<koeR<<endl;
        }

        if(koeA != 0){
            cout<<"a "<<koeA<<endl;
        }

        nulirane();
    }


    return 0;
}
