#include<iostream>
using namespace std;

int broiChisla;
int naKoeChisloDaSeDel;

int redica[1005];

int priTolkova[1005][1005];

void nulirvane(){
    for(int i = 0; i < broiChisla; i++){
        for(int j = 0; j < naKoeChisloDaSeDel; j++){
            priTolkova[i][j] = -1;
        }
    }
}

int naiDalgaPodredicaDavashtaOstatak(int maximalnoIndexche, int ostatuche){
    if(maximalnoIndexche == 0){
        if(redica[maximalnoIndexche]%naKoeChisloDaSeDel == ostatuche){
            return 1;
        }

        if(ostatuche == 0){
            return 0;
        }

        return -10000000;
    }

    if(priTolkova[maximalnoIndexche][ostatuche] > -1){
        return priTolkova[maximalnoIndexche][ostatuche];
    }

    int naiDobroto = -10000000;

    if(ostatuche == 0){
        naiDobroto = 0;
    }



    int novichko = (ostatuche + naKoeChisloDaSeDel - (redica[maximalnoIndexche]%naKoeChisloDaSeDel))%naKoeChisloDaSeDel;

    int daGoVzema = 1 + naiDalgaPodredicaDavashtaOstatak(maximalnoIndexche - 1, novichko);
    int daNeGoVzema = naiDalgaPodredicaDavashtaOstatak(maximalnoIndexche - 1, ostatuche);

    naiDobroto = max(naiDobroto, max(daGoVzema, daNeGoVzema));

    priTolkova[maximalnoIndexche][ostatuche] = naiDobroto;
    return naiDobroto;
}

void podgotvqne(int maximalnoIndexche){
    for(int ost = 0; ost < naKoeChisloDaSeDel; ost++){
        if(ost == redica[0]%naKoeChisloDaSeDel){
            priTolkova[0][ost] = 1;
        }else{
            if(ost == 0){
                priTolkova[0][ost] = 0;
            }else{
                priTolkova[0][ost] = -10000000;
            }
        }
    }

    for(int i = 1; i <= maximalnoIndexche; i++){
        for(int ost = 0; ost < naKoeChisloDaSeDel; ost++){
            int naiDobroto = -10000000;
            if(ost == 0){
                naiDobroto = 0;
            }

            int novichko = (ost + naKoeChisloDaSeDel - (redica[i]%naKoeChisloDaSeDel))%naKoeChisloDaSeDel;

            int daGoVzema = 1 + priTolkova[i - 1][novichko];
            int daNeGoVzema = priTolkova[i - 1][ost];

            naiDobroto = max(naiDobroto, max(daGoVzema, daNeGoVzema));

            priTolkova[i][ost] = naiDobroto;
        }
    }

}

int sCikli(int maximalnoIndexche, int ostatuche){
    podgotvqne(maximalnoIndexche);
    return priTolkova[maximalnoIndexche][ostatuche];
}

int main(){
    cin>>broiChisla>>naKoeChisloDaSeDel;

    for(int i = 0; i < broiChisla; i++){
        int chislo;
        cin>>chislo;
        redica[i] = chislo;
    }

    //snulirvane();

    int naiDalgichkaRedichka = sCikli(broiChisla - 1, 0);

    cout<<naiDalgichkaRedichka<<endl;

    return 0;
}
