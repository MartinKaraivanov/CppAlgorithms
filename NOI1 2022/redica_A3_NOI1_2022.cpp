#include<iostream>
using namespace std;

int broiTestove;

int parvoChislo;
int koeChislo;
int kolkoCHisla;

int sumaOtKvadrNCifriNa(int chislo){

    int suma = 0;

    int kopieChislo = chislo;

    while(kopieChislo > 0){
        int cifra = kopieChislo%10;

        suma += cifra*cifra;

        kopieChislo /= 10;
    }

    return suma;
}

int tovaKadeSmeGoSresh[100024];
int kolkoPatiSreshtameVDo[100024];

void nulirai(){
    for(int i = 0; i < 100024; i++){
        tovaKadeSmeGoSresh[i] = 0;
        kolkoPatiSreshtameVDo[i] = 0;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiTestove;

    for(int t = 0; t < broiTestove; t++){
        cin>>parvoChislo>>koeChislo>>kolkoCHisla;

        nulirai();

        int segashnoChislo = parvoChislo;

        int nachaloNaCikal = -1;
        int kraiNaCikal = -1;

        for(int i = 1; i < kolkoCHisla; i++){
            segashnoChislo = sumaOtKvadrNCifriNa(segashnoChislo);

            //cout<<"na ndex "<<i<<" "<<segashnoChislo<<" a iskame "<<koeChislo<<endl;

            if(tovaKadeSmeGoSresh[segashnoChislo] > 0){
                nachaloNaCikal = tovaKadeSmeGoSresh[segashnoChislo];
                kraiNaCikal = i - 1;
                break;
            }else{
                tovaKadeSmeGoSresh[segashnoChislo] = i;
                kolkoPatiSreshtameVDo[i] = kolkoPatiSreshtameVDo[i - 1];
                if(segashnoChislo == koeChislo){
                    kolkoPatiSreshtameVDo[i]++;
                }
            }
        }

        int sreshtniqPrediCikala = kolkoPatiSreshtameVDo[nachaloNaCikal - 1];
        int sreshtaniqPoVremeNa = kolkoPatiSreshtameVDo[kraiNaCikal] - sreshtniqPrediCikala;
        int daljinaNaCikala = kraiNaCikal - nachaloNaCikal + 1;

        //cout<<"cikala zapocha na index "<<nachaloNaCikal<<" i svarshva na "<<kraiNaCikal<<" i e s daljina "<<daljinaNaCikala<<endl;

        //cout<<"predi cikala chisloto se sreshta "<<sreshtniqPrediCikala<<" a po vreme na nego na "<<sreshtaniqPoVremeNa<<endl;

        int novaDaljinaNaCqloto = kolkoCHisla - nachaloNaCikal;

        int kolkoPatiCeliqCikal = novaDaljinaNaCqloto/daljinaNaCikala;
        int kakvaChastOstava = novaDaljinaNaCqloto%daljinaNaCikala;

        //cout<<"dajinata na cqloto kato mahnem predi cikala e "<<novaDaljinaNaCqloto<<endl;
        //cout<<"ceiq cikal se izalnqva "<<kolkoPatiCeliqCikal<<" i nakraq ostava "<<kakvaChastOstava<<endl;

        //cout<<nachaloNaCikal<<" "<<kraiNaCikal<<" "<<novaDaljinaNaCqloto<<" "<<kolkoPatiCeliqCikal<<" "<<kakvaChastOstava<<endl;

        int broiPatiVOstataka = kolkoPatiSreshtameVDo[kraiNaCikal - daljinaNaCikala + kakvaChastOstava] - sreshtniqPrediCikala;

        int broiTuka = sreshtniqPrediCikala + sreshtaniqPoVremeNa*kolkoPatiCeliqCikal + broiPatiVOstataka;

        if(parvoChislo == koeChislo){
            broiTuka++;
        }

        cout<<broiTuka<<endl;

    }

    return 0;
}
