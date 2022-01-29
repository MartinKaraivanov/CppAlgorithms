#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int broiChisla;

int chisla[2048];

int cenaPriVisochina(int visochina){

    int tukaCena = 0;

    for(int j = 0; j < broiChisla; j++){
        tukaCena += abs(chisla[j] - visochina);
    }

    return tukaCena;
}


int main(){

    cin>>broiChisla;

    for(int i = 0; i < broiChisla; i++){
        cin>>chisla[i];
    }

    sort(chisla, chisla + broiChisla);

    int naiNiskoto = chisla[0];
    int naiVisokoto = chisla[broiChisla - 1];
    int sborNaVsichkite = 0;

    for(int i = 0; i < broiChisla; i++){
        sborNaVsichkite += chisla[i];
    }

    int naiEvtinoto = INT_MAX;
    int priKakavVisochina = -1;

    for(int i = naiNiskoto; i <= naiVisokoto; i++){
        int tukaCena = cenaPriVisochina(i);

        if(tukaCena < naiEvtinoto){
            naiEvtinoto = tukaCena;
            priKakavVisochina = i;
        }
    }

    int medianata = -1;

    if(broiChisla%2 == 1){
        medianata = chisla[broiChisla/2];
    }else{
        medianata = (chisla[broiChisla/2 - 1]+chisla[broiChisla/2])/2;
    }

    cout<<"nai malka e cenata: "<<naiEvtinoto<<" pri izravnqvane na visochina "<<priKakavVisochina<<endl;

    cout<<"medianata e "<<medianata<<" i pri neq "<<cenaPriVisochina(medianata)<<endl;
    cout<<"pri 1 po golqmo "<<cenaPriVisochina(medianata + 1)<<endl;
    cout<<"pri 1 po malko "<<cenaPriVisochina(medianata - 1)<<endl<<endl;

    cout<<"sresdno aritmetichnoto e "<<(double)sborNaVsichkite/broiChisla<<" i pri nego se poluchava "<<cenaPriVisochina(sborNaVsichkite/broiChisla)<<endl;
    cout<<"pri 1 po malko ("<<sborNaVsichkite/broiChisla-1<<") e "<<cenaPriVisochina(sborNaVsichkite/broiChisla - 1)<<endl;
    cout<<"pri 1 po golqmo ("<<sborNaVsichkite/broiChisla+1<<") e "<<cenaPriVisochina(sborNaVsichkite/broiChisla + 1)<<endl;

    return 0;
}
