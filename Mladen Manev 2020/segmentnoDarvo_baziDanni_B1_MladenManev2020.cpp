#include<iostream>
#include<vector>
using namespace std;

struct DanniZaVrah{
    long long stoinostDelta;
    long long stupkaDelta;
    int otKoiIndexOhvashta;
    int doKoiIndexObhvashta;
    int lqvoDeteVrahNomer;
    int dqsnoDeteVrahNomer;
};
vector<DanniZaVrah> varhove;
//DanniZaVrah varhove[1800000];
//int broiVarhove;
//int korenNomerNaVrah = -1;

vector<int> koreniNaVersii;

vector<long long> ednotoMinusDrugoto;

int korenNaPoslednaVersiq(){
    return koreniNaVersii[koreniNaVersii.size() - 1];
}

int daiNovVrah(DanniZaVrah vrah){
    varhove.push_back(vrah);
    //varhove[broiVarhove] = vrah;
    //broiVarhove++;
    return varhove.size() - 1;
    //return broiVarhove - 1;
}

int napraviDarvo(int otIndex, int doIndex){
    if(otIndex == doIndex){
        return daiNovVrah({0, 0, otIndex, doIndex, -1, -1});
    }

    int lqvoDeteVrahNomer = napraviDarvo(otIndex, (otIndex + doIndex)/2);
    int dqsnoDeteVraNomer = napraviDarvo((otIndex + doIndex)/2 + 1, doIndex);

    return daiNovVrah({0, 0, otIndex, doIndex, lqvoDeteVrahNomer, dqsnoDeteVraNomer});
}

// a[otIndex]+= sKolko; a[otIndex+1]+= sKolko+sasStupka; a[otIndex+2]+= sKolko+2*sasStupka....
int promqna(int korenNaPoddarvoVrahNomer, int otIndex, int doIndex, long long sKolko, long long sasStupka){
    if(korenNaPoddarvoVrahNomer == -1){
        return korenNaPoddarvoVrahNomer;
    }

    DanniZaVrah celiqVrah = varhove[korenNaPoddarvoVrahNomer];

    if(otIndex > celiqVrah.doKoiIndexObhvashta ||
        doIndex < celiqVrah.otKoiIndexOhvashta)
    {
        return korenNaPoddarvoVrahNomer;
    }

    if(otIndex <= celiqVrah.otKoiIndexOhvashta &&
       doIndex >= celiqVrah.doKoiIndexObhvashta){

        return daiNovVrah({
            celiqVrah.stoinostDelta +
                sKolko + sasStupka*(celiqVrah.otKoiIndexOhvashta - otIndex),
            celiqVrah.stupkaDelta + sasStupka,
            celiqVrah.otKoiIndexOhvashta,
            celiqVrah.doKoiIndexObhvashta,
            celiqVrah.lqvoDeteVrahNomer,
            celiqVrah.dqsnoDeteVrahNomer});
    }

    int lqvoDeteNovo = promqna(celiqVrah.lqvoDeteVrahNomer, otIndex, doIndex, sKolko, sasStupka);
    int dqsnoDeteNovo = promqna(celiqVrah.dqsnoDeteVrahNomer, otIndex, doIndex, sKolko, sasStupka);

    return daiNovVrah({
        celiqVrah.stoinostDelta,
        celiqVrah.stupkaDelta,
        celiqVrah.otKoiIndexOhvashta,
        celiqVrah.doKoiIndexObhvashta,
        lqvoDeteNovo,
        dqsnoDeteNovo});
}

long long kakvoPisheTam(int korenNaPoddarvoVrahNomer, int naKoiIndex){
    if(korenNaPoddarvoVrahNomer == -1){
        return 0;
    }

    DanniZaVrah celiqVrah = varhove[korenNaPoddarvoVrahNomer];

    if(naKoiIndex < celiqVrah.otKoiIndexOhvashta ||
       naKoiIndex > celiqVrah.doKoiIndexObhvashta)
    {
        return 0;
    }

    if(naKoiIndex == celiqVrah.otKoiIndexOhvashta &&
       naKoiIndex == celiqVrah.doKoiIndexObhvashta){
        return celiqVrah.stoinostDelta;
    }

    long long zaTuka =
        celiqVrah.stoinostDelta +
        celiqVrah.stupkaDelta * (naKoiIndex - celiqVrah.otKoiIndexOhvashta);

    zaTuka += kakvoPisheTam(celiqVrah.lqvoDeteVrahNomer, naKoiIndex);
    zaTuka += kakvoPisheTam(celiqVrah.dqsnoDeteVrahNomer, naKoiIndex);

    return zaTuka;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int broiChisla;

    cin>>broiChisla;

    ednotoMinusDrugoto.reserve(broiChisla);

    for(int i = 0; i < broiChisla; i++){
        long long tukChislo;
        cin>>tukChislo;
        ednotoMinusDrugoto.push_back(-tukChislo);
    }

    for(int i = 0; i < broiChisla; i++){
        long long tukMaksKapacitet;
        cin>>tukMaksKapacitet;
        ednotoMinusDrugoto[i] += tukMaksKapacitet;
    }

    koreniNaVersii.push_back(napraviDarvo(0, broiChisla - 1));

    /*for(unsigned int i = 0; i < chisla.size(); i++){
        koreniNaVersii.push_back(promqna(koreniNaVersii[koreniNaVersii.size() - 1], i, i, chisla[i], 0));
    }*/

    int broiUpdatevaniq;
    cin>>broiUpdatevaniq;

    koreniNaVersii.reserve(broiUpdatevaniq+1);
    varhove.reserve(broiChisla + broiUpdatevaniq*17);

    for(int i = 0; i < broiUpdatevaniq; i++){
        int otKade;
        int doKade;
        long long x;
        long long y;
        cin>>otKade>>doKade>>x>>y;
        koreniNaVersii.push_back(promqna(korenNaPoslednaVersiq(), otKade - 1, doKade - 1, x, y));
    }

    for(int j = 0; j < broiChisla; j++){
        int lqvKrai = 0;
        int desenKrai = koreniNaVersii.size() - 1;

        while(lqvKrai < desenKrai){
            int sreden = (lqvKrai + desenKrai)/2;
            if(kakvoPisheTam(koreniNaVersii[sreden], j) >= ednotoMinusDrugoto[j]){
                desenKrai = sreden;
            }else{
                lqvKrai = sreden + 1;
            }
        }

        if(kakvoPisheTam(koreniNaVersii[lqvKrai], j) < ednotoMinusDrugoto[j]){
            cout<<-1<<" ";
        }else{
            cout<<lqvKrai<<" ";
        }

        /*for(unsigned int i = 0; i < koreniNaVersii.size(); i++){
            if(kakvoPisheTam(koreniNaVersii[i], j) >= ednotoMinusDrugoto[j] && izlizatLi[j] == false){
                naKoiHodIzlizat[j] = i;
                izlizatLi[j] = true;
                break;
            }
            //cout<<kakvoPisheTam(koreniNaVersii[i], j)<<" ";
        }*/
        //cout<<endl;
    }

    cout<<endl;

    return 0;
}
