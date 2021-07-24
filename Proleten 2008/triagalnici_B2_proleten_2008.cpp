#include<iostream>
#include<cmath>
using namespace std;

struct DanniZaTochkata{
    int x;
    int y;
};

struct DanniZaTriagalnika{
    DanniZaTochkata a;
    DanniZaTochkata b;
    DanniZaTochkata c;
};

int broiTriagalnici;

int celochisleniLica[1010];
int broiCelochisleniLica;

int sumaNaCelochisleniteLica = 0;

int priTolkova[30000];

/*int naiMalkaRazlikaMezhduSborovete(int indexOtMasiva, int suma){
    if(indexOtMasiva == 0){
        int sasDaGoVzemem = suma + celochisleniLica[indexOtMasiva]  ;
        int bezDaGoVzemem = suma;
        if(abs(polovinataNaSumata - sasDaGoVzemem) < abs(polovinataNaSumata - bezDaGoVzemem)){
            return sasDaGoVzemem;
        }else{
            return bezDaGoVzemem;
        }
    }

    if(priTolkova[indexOtMasiva][suma] > 0){
        return priTolkova[indexOtMasiva][suma];
    }

    int sasDaGoVzemem = naiMalkaRazlikaMezhduSborovete(indexOtMasiva - 1, suma + celochisleniLica[indexOtMasiva]);
    int bezDaGoVzemem = naiMalkaRazlikaMezhduSborovete(indexOtMasiva - 1, suma);

    int zaVrashtane = 0;

    if(abs(polovinataNaSumata - sasDaGoVzemem) < abs(polovinataNaSumata - bezDaGoVzemem)){
        zaVrashtane = sasDaGoVzemem;
    }else{
        zaVrashtane = bezDaGoVzemem;
    }

    priTolkova[indexOtMasiva][suma] = zaVrashtane;
    return zaVrashtane;
}*/


int sCycli(int priKolkoTriagalnika, int priSuma){
    int polovinataNaSumata = sumaNaCelochisleniteLica/2;
    for(int i = 0; i <= sumaNaCelochisleniteLica; i++){
        int sasDaGoVzemem = i + celochisleniLica[0];
        int bezDaGoVzemem = i;
        if(abs(polovinataNaSumata - sasDaGoVzemem) < abs(polovinataNaSumata - bezDaGoVzemem)){
            priTolkova[i] = sasDaGoVzemem;
        }else{
            priTolkova[i] = bezDaGoVzemem;
        }
    }

    for(int indexOtMasiva = 1; indexOtMasiva < broiCelochisleniLica; indexOtMasiva++){
        for(int suma = 0; suma <= sumaNaCelochisleniteLica; suma++){
            int sasDaGoVzemem = priTolkova[suma + celochisleniLica[indexOtMasiva]];
            int bezDaGoVzemem = priTolkova[suma];

            int zaVrashtane = 0;

            if(abs(polovinataNaSumata - sasDaGoVzemem) < abs(polovinataNaSumata - bezDaGoVzemem)){
                zaVrashtane = sasDaGoVzemem;
            }else{
                zaVrashtane = bezDaGoVzemem;
            }

            priTolkova[suma] = zaVrashtane;
        }
    }

    return priTolkova[priSuma];
}

int celochisenoLice(int x1, int y1, int x2, int y2, int x3, int y3){
    if(x1 == x2){
        int ednataStrana = abs(y1 - y2);
        int drugaStrana = abs(x3 - x1);
        if(ednataStrana % 2 == 0 || drugaStrana % 2 == 0){
            int lice = ednataStrana*drugaStrana/2;
            return lice;
        }
    }

    if(x1 == x3){
        int ednataStrana = abs(y1 - y3);
        int drugaStrana = abs(x2 - x1);
        if(ednataStrana % 2 == 0 || drugaStrana % 2 == 0){
            int lice = ednataStrana*drugaStrana/2;
            return lice;
        }
    }

    if(x2 == x3){
        int ednataStrana = abs(y3 - y2);
        int drugaStrana = abs(x2 - x1);
        if(ednataStrana % 2 == 0 || drugaStrana % 2 == 0){
            int lice = ednataStrana*drugaStrana/2;
            return lice;
        }
    }

    if(y1 == y2){
        int ednataStrana = abs(x1 - x2);
        int drugaStrana = abs(y3 - y1);
        if(ednataStrana % 2 == 0 || drugaStrana % 2 == 0){
            int lice = ednataStrana*drugaStrana/2;
            return lice;
        }
    }

    if(y1 == y3){
        int ednataStrana = abs(x1 - x3);
        int drugaStrana = abs(y2 - y1);
        if(ednataStrana % 2 == 0 || drugaStrana % 2 == 0){
            int lice = ednataStrana*drugaStrana/2;
            return lice;
        }
    }

    if(y2 == y3){
        int ednataStrana = abs(x2 - x3);
        int drugaStrana = abs(y3 - y1);
        if(ednataStrana % 2 == 0 || drugaStrana % 2 == 0){
            int lice = ednataStrana*drugaStrana/2;
            return lice;
        }
    }

    return 0;
}

int main(){
    cin>>broiTriagalnici;

    for(int i = 0; i < broiTriagalnici; i++){
        int x1;
        int y1;
        int x2;
        int y2;
        int x3;
        int y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;

        int lice = celochisenoLice(x1, y1, x2, y2, x3, y3);

        if(lice > 0){
            celochisleniLica[broiCelochisleniLica] = lice;
            broiCelochisleniLica++;
            sumaNaCelochisleniteLica += lice;
        }

    }

    int naiBlizkaPoMalka = sCycli(broiCelochisleniLica - 1, 0);
    int naiBlizkaPoGolqma = sumaNaCelochisleniteLica - naiBlizkaPoMalka;

    if(naiBlizkaPoGolqma < naiBlizkaPoMalka){
        swap(naiBlizkaPoGolqma, naiBlizkaPoMalka);
    }

    cout<<naiBlizkaPoMalka<<" "<<sumaNaCelochisleniteLica-naiBlizkaPoMalka<<endl;

    return 0;
}
