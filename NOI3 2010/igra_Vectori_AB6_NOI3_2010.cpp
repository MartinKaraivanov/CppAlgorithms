#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int bitCount(int chislo){
    int broiBitove = 0;
    while(chislo > 0){
        broiBitove++;
        chislo = chislo >> 1;
    }

    return broiBitove;
}

int naTazaiPoziciqKakvoIma(int chislo, int poziciq){
    chislo = chislo >> poziciq;
    int maskirano = 1;
    int kakvoE = chislo & maskirano;

    return kakvoE;
}

int slozhiTamDaETakova(int chislo, int poziciq, int kakvo){
    int maskaZaKakvo = 1 << poziciq;

    int nov;

    if(kakvo == 1){
        nov = chislo | maskaZaKakvo;
    }else{
        maskaZaKakvo = ~maskaZaKakvo;
        nov = chislo & maskaZaKakvo;
    }

    return nov;

    /*int dqsnaMaska = (1 << poziciq) - 1;
    int lqvaMaska = ~dqsnaMaska;

    int dqsnoChislo = chislo & dqsnaMaska;
    int lqvoChislo = chislo & lqvaMaska;

    lqvoChislo = lqvoChislo >> (poziciq + 1);

    lqvoChislo = lqvoChislo << (poziciq + 1);

    int novoLqvo = (lqvoChislo << 1) | kakvo;

    int nov = novoLqvo | dqsnoChislo;

    return nov;*/
}

int vmakniTamTakova(int chislo, int naKoqPoziciq, int kakvo){
    int dqsnaMaska = (1 << naKoqPoziciq) - 1;
    int lqvaMaska = ~dqsnaMaska;

    int dqsnoChislo = chislo & dqsnaMaska;
    int lqvoChislo = chislo & lqvaMaska;

    kakvo = kakvo << naKoqPoziciq;

    int novoLqvo = (lqvoChislo << 1) | kakvo;

    int nov = novoLqvo | dqsnoChislo;

    return nov;
}

int iztriiElementaNaPoziciq(int chislo, int poziciq){
    int dqsnaMaska = (1 << poziciq) - 1;
    int lqvaMaska = ~dqsnaMaska;

    int dqsnoChislo = chislo & dqsnaMaska;
    int lqvoChislo = chislo & lqvaMaska;

    lqvoChislo = lqvoChislo >> (poziciq + 1);
    lqvoChislo = lqvoChislo << poziciq;

    int nov = lqvoChislo | dqsnoChislo;

    return nov;
}

const int Gubeshta = 1;
const int Pechelivsha = 2;
const int Neutralna = 3;
const int Nepopalnena = 0;
// 1 - zagubvashta, 2 - pecheleshta, 3 - neutralna

int priTolkovaKakvaEPromenlivataBezNot[1100000];

int kakvaEPoziciqta(int kamacheta){
    int broiKamacheta = bitCount(kamacheta);
    if(broiKamacheta == 0){
        return Gubeshta;
    }

    if(broiKamacheta == 1){
        return Pechelivsha;
    }

    int priTolkova = priTolkovaKakvaEPromenlivataBezNot[kamacheta];

    if(priTolkova != Nepopalnena){
        return priTolkova;
    }

    bool imaLiPechelivshaPoziciqZaNas = false;
    bool vsichkiLiSaGubeshti = true;

    for(int i = broiKamacheta - 1; i >= 0; i--){
        int kakvoIma = naTazaiPoziciqKakvoIma(kamacheta, i);
        if(kakvoIma == 1){
            int nov = iztriiElementaNaPoziciq(kamacheta, i);

            if(i > 0 && naTazaiPoziciqKakvoIma(nov, i - 1) == 0){
                nov = slozhiTamDaETakova(nov, i - 1, 1);
            }

            int zaDrugiq = kakvaEPoziciqta(nov);

            if(zaDrugiq != Pechelivsha){
                vsichkiLiSaGubeshti = false;
            }

            if(zaDrugiq == Gubeshta){
                imaLiPechelivshaPoziciqZaNas = true;
                break;
            }

            for(int j = broiKamacheta - 1; j >= i; j--){
                int tukKakvoImaZaJ = naTazaiPoziciqKakvoIma(kamacheta, j);
                if(tukKakvoImaZaJ == 1){
                    int poNov = vmakniTamTakova(nov, j, 0);
                    zaDrugiq = kakvaEPoziciqta(poNov);

                    if(zaDrugiq != Pechelivsha){
                        vsichkiLiSaGubeshti = false;
                    }

                    if(zaDrugiq == Gubeshta){
                        imaLiPechelivshaPoziciqZaNas = true;
                        break;
                    }
                }
            }

            if(imaLiPechelivshaPoziciqZaNas){
                break;
            }

        }
    }


    if(imaLiPechelivshaPoziciqZaNas == true){
        priTolkova = Pechelivsha;
    }else{
        if(vsichkiLiSaGubeshti == true){
            priTolkova = Gubeshta;
        }else{
            priTolkova = Neutralna;
        }
    }

    priTolkovaKakvaEPromenlivataBezNot[kamacheta] = priTolkova;

    return priTolkova;
}

int sCycli(int chislo){
    priTolkovaKakvaEPromenlivataBezNot[0] = 1;
    priTolkovaKakvaEPromenlivataBezNot[1] = 2;

    for(int kamacheta = 2; kamacheta <= chislo; kamacheta++){
        int broiKamacheta = bitCount(kamacheta);

        bool imaLiPechelivshaPoziciqZaNas = false;
        bool vsichkiLiSaGubeshti = true;

        for(int i = broiKamacheta - 1; i >= 0; i--){
            int kakvoIma = naTazaiPoziciqKakvoIma(kamacheta, i);
            if(kakvoIma == 1){
                int nov = iztriiElementaNaPoziciq(kamacheta, i);

                if(i > 0 && naTazaiPoziciqKakvoIma(nov, i - 1) == 0){
                    nov = slozhiTamDaETakova(nov, i - 1, 1);
                }

                int zaDrugiq = priTolkovaKakvaEPromenlivataBezNot[nov];

                if(zaDrugiq != Pechelivsha){
                    vsichkiLiSaGubeshti = false;
                }

                if(zaDrugiq == Gubeshta){
                    imaLiPechelivshaPoziciqZaNas = true;
                    break;
                }

                for(int j = broiKamacheta - 1; j >= i; j--){
                    int tukKakvoImaZaJ = naTazaiPoziciqKakvoIma(kamacheta, j);
                    if(tukKakvoImaZaJ == 1){
                        int poNov = vmakniTamTakova(nov, j, 0);
                        zaDrugiq = priTolkovaKakvaEPromenlivataBezNot[poNov];

                        if(zaDrugiq != Pechelivsha){
                            vsichkiLiSaGubeshti = false;
                        }

                        if(zaDrugiq == Gubeshta){
                            imaLiPechelivshaPoziciqZaNas = true;
                            break;
                        }
                    }
                }

                if(imaLiPechelivshaPoziciqZaNas){
                    break;
                }

            }
        }

        int priTolkova;

        if(imaLiPechelivshaPoziciqZaNas == true){
            priTolkova = Pechelivsha;
        }else{
            if(vsichkiLiSaGubeshti == true){
                priTolkova = Gubeshta;
            }else{
                priTolkova = Neutralna;
            }
        }

        priTolkovaKakvaEPromenlivataBezNot[kamacheta] = priTolkova;
    }

    return priTolkovaKakvaEPromenlivataBezNot[chislo];
}

int broiKupchinki;

int vavedeno[25];

vector<int> kupchinki;

vector<int> zakodirani;


int main(){
    cin>>broiKupchinki;

    for(int i = 0; i < broiKupchinki; i++){
        cin>>vavedeno[i];
    }

    sort(vavedeno, vavedeno + broiKupchinki);

    int nomercheZaKamache = -1;
    int predno = -1;

    for(int i = 0; i < broiKupchinki; i++){
        int segashno = vavedeno[i];
        if(segashno != predno){
            nomercheZaKamache++;
        }
        kupchinki.push_back(nomercheZaKamache);
        predno = segashno;
    }

    int chislence = 0;

    for(int i = 0; i < broiKupchinki; i++){
        if(kupchinki[i] > 0){
            if(kupchinki[i] != chislence){
                chislence++;
                zakodirani.push_back(1);
            }else{
                zakodirani.push_back(0);
            }
        }
    }

    int zakodiranoChislo = 0;

    for(unsigned int i = 0; i < zakodirani.size(); i++){
        zakodiranoChislo = vmakniTamTakova(zakodiranoChislo, 0, zakodirani[i]);
    }

    /*for(int i = 0 ; i < broiKupchinki; i++){
        cout<<vavedeno[i]<<" ";
    }

    cout<<endl;

    for(int i : kupchinki){
        cout<<i<<" ";
    }

    cout<<endl;

    for(int i : zakodirani){
        cout<<i;
    }

    cout<<endl;

    int broiBitove = bitCount(zakodiranoChislo);

    for(int i = broiBitove - 1; i >= 0; i--){
        cout<<naTazaiPoziciqKakvoIma(zakodiranoChislo, i);
    }

    cout<<endl;*/

    int kakvaPoziciqtaE = sCycli(zakodiranoChislo);

    if(kakvaPoziciqtaE == Pechelivsha){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }

    return 0;
}
