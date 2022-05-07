#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

set<int> priTolkova[100010];

set<int> koiMojeDaSeNapravi(int otChislo){

    if(priTolkova[otChislo].size() > 0){
        return priTolkova[otChislo];
    }

    priTolkova[otChislo].insert(otChislo);
    priTolkova[otChislo].insert(-otChislo);

    int desetNaStepen = 10;

    while(otChislo/desetNaStepen > 0){

        int lqvoChislo = otChislo/desetNaStepen;
        int dqsnoChislo = otChislo%desetNaStepen;

        set<int> naLqvoto = koiMojeDaSeNapravi(lqvoChislo);
        set<int> naDqsnoto = koiMojeDaSeNapravi(dqsnoChislo);

        for(set<int>::iterator i = naLqvoto.begin(); i != naLqvoto.end(); i++){
            for(set<int>::iterator j = naDqsnoto.begin(); j != naDqsnoto.end(); j++){
                priTolkova[otChislo].insert(*i + *j);
                priTolkova[otChislo].insert(*i - *j);
                priTolkova[otChislo].insert(*i * *j);
                if(*j != 0 && *i % *j == 0){
                    priTolkova[otChislo].insert(*i / *j);
                }
                priTolkova[otChislo].insert(-(*i + *j));
                priTolkova[otChislo].insert(-(*i - *j));
                priTolkova[otChislo].insert(-(*i * *j));
                if(*j != 0 && *i % *j == 0){
                    priTolkova[otChislo].insert(-(*i / *j));
                }
            }
        }

        desetNaStepen *= 10;
    }

    return priTolkova[otChislo];
}

bool mojeLiOtTova(int otKoe, int kolkoDaPravi){

    set<int> vazmojni = koiMojeDaSeNapravi(otKoe);

    set<int>::iterator kadeE = vazmojni.find(kolkoDaPravi);

    if(kadeE != vazmojni.end()){
        return true;
    }

    return false;
}

int kolkoCifriIma(int koeChislo){
    int broi = 0;

    while(koeChislo > 0){
        broi++;
        koeChislo /= 10;
    }

    return broi;
}

int sCycli(int zaOtChislo, int kolkoDaPravi){

    int broiShtastlivi = 0;

    int broiCifriNaGolqmoto = kolkoCifriIma(zaOtChislo);

    int doKadeParviqCikal = 1;

    for(int i = 0; i < broiCifriNaGolqmoto - 1; i++){
        doKadeParviqCikal *= 10;
    }

    for(int otChislo = 0; otChislo < doKadeParviqCikal; otChislo++){
        bool priTovaImaLi = false;

        priTolkova[otChislo].insert(otChislo);
        if(otChislo == kolkoDaPravi){
            priTovaImaLi = true;
        }

        priTolkova[otChislo].insert(-otChislo);
        if(-otChislo == kolkoDaPravi){
            priTovaImaLi = true;
        }

        int desetNaStepen = 10;

        while(otChislo/desetNaStepen > 0){

            int lqvoChislo = otChislo/desetNaStepen;
            int dqsnoChislo = otChislo%desetNaStepen;

            //set<int> naLqvoto = priTolkova[lqvoChislo];
            //set<int> naDqsnoto = priTolkova[dqsnoChislo];

            for(set<int>::iterator i = priTolkova[lqvoChislo].begin(); i != priTolkova[lqvoChislo].end(); i++){

                //if(*i + *j == kolkoDaPravi){
                if(priTolkova[dqsnoChislo].find(kolkoDaPravi - *i) != priTolkova[dqsnoChislo].end()){
                    priTovaImaLi = true;
                }
                //if(*i - *j == kolkoDaPravi){
                if(priTolkova[dqsnoChislo].find(*i - kolkoDaPravi) != priTolkova[dqsnoChislo].end()){
                    priTovaImaLi = true;
                }
                //if(*i * *j == kolkoDaPravi){
                if(*i == 0 && kolkoDaPravi == 0){
                    priTovaImaLi = true;
                }
                if(*i != 0 && kolkoDaPravi % *i == 0){
                    if(priTolkova[dqsnoChislo].find(kolkoDaPravi / *i) != priTolkova[dqsnoChislo].end()){
                        priTovaImaLi = true;
                    }
                }
                ///
                if(kolkoDaPravi == 0 && priTolkova[dqsnoChislo].find(0) != priTolkova[dqsnoChislo].end()){
                    priTovaImaLi = true;
                }
                if(kolkoDaPravi != 0 && *i % kolkoDaPravi == 0 && *i != 0){
                    //if(*i / *j == kolkoDaPravi){
                    if(priTolkova[dqsnoChislo].find(*i / kolkoDaPravi) != priTolkova[dqsnoChislo].end()){
                        priTovaImaLi = true;
                    }
                }
                //if(-(*i + *j) == kolkoDaPravi){
                if(priTolkova[dqsnoChislo].find(-kolkoDaPravi - *i) != priTolkova[dqsnoChislo].end()){
                    priTovaImaLi = true;
                }
                //if(-(*i - *j) == kolkoDaPravi){
                if(priTolkova[dqsnoChislo].find(kolkoDaPravi + *i) != priTolkova[dqsnoChislo].end()){
                    priTovaImaLi = true;
                }
                //if(-(*i * *j) == kolkoDaPravi){
                if(*i != 0 && -kolkoDaPravi % *i == 0){
                    if(priTolkova[dqsnoChislo].find(-kolkoDaPravi / *i) != priTolkova[dqsnoChislo].end()){
                        priTovaImaLi = true;
                    }
                }
                if(kolkoDaPravi != 0 && *i % -kolkoDaPravi == 0 && *i != 0){
                    //if(-(*i / *j) == kolkoDaPravi){
                    if(priTolkova[dqsnoChislo].find(*i / -kolkoDaPravi) != priTolkova[dqsnoChislo].end()){
                        priTovaImaLi = true;
                    }
                }

                for(set<int>::iterator j = priTolkova[dqsnoChislo].begin(); j != priTolkova[dqsnoChislo].end(); j++){
                    priTolkova[otChislo].insert(*i + *j);
                    priTolkova[otChislo].insert(*i - *j);
                    priTolkova[otChislo].insert(*i * *j);
                    if(*j != 0 && *i % *j == 0){
                        priTolkova[otChislo].insert(*i / *j);
                    }
                    priTolkova[otChislo].insert(-(*i + *j));
                    priTolkova[otChislo].insert(-(*i - *j));
                    priTolkova[otChislo].insert(-(*i * *j));
                    if(*j != 0 && *i % *j == 0){
                       priTolkova[otChislo].insert(-(*i / *j));
                    }

                }
            }

            desetNaStepen *= 10;
        }

        /////////priTovaImaLi = (priTolkova[otChislo].find(kolkoDaPravi) != priTolkova[otChislo].end());

        if(priTovaImaLi == true){
           ////// cout<<otChislo<<" moje "<<endl;
            broiShtastlivi++;
        }
    }

    for(int otChislo = doKadeParviqCikal; otChislo <= zaOtChislo; otChislo++){
        bool priTovaImaLi = false;

        if(otChislo == kolkoDaPravi){
            priTovaImaLi = true;
        }
        if(-otChislo == kolkoDaPravi){
            priTovaImaLi = true;
        }

        int desetNaStepen = 10;

        while(otChislo/desetNaStepen > 0){

            int lqvoChislo = otChislo/desetNaStepen;
            int dqsnoChislo = otChislo%desetNaStepen;

            //set<int> naLqvoto = priTolkova[lqvoChislo];
            //set<int> naDqsnoto = priTolkova[dqsnoChislo];

            if(priTolkova[lqvoChislo].size() < priTolkova[dqsnoChislo].size()){
                for(set<int>::iterator i = priTolkova[lqvoChislo].begin(); i != priTolkova[lqvoChislo].end(); i++){

                    //if(*i + *j == kolkoDaPravi){
                    if(priTolkova[dqsnoChislo].find(kolkoDaPravi - *i) != priTolkova[dqsnoChislo].end()){
                        priTovaImaLi = true;
                    }
                    //if(*i - *j == kolkoDaPravi){
                    if(priTolkova[dqsnoChislo].find(*i - kolkoDaPravi) != priTolkova[dqsnoChislo].end()){
                        priTovaImaLi = true;
                    }
                    //if(*i * *j == kolkoDaPravi){
                    if(*i == 0 && kolkoDaPravi == 0){
                        priTovaImaLi = true;
                    }
                    if(*i != 0 && kolkoDaPravi % *i == 0){
                        if(priTolkova[dqsnoChislo].find(kolkoDaPravi / *i) != priTolkova[dqsnoChislo].end()){
                            priTovaImaLi = true;
                        }
                    }
                    ///
                    if(kolkoDaPravi == 0 && priTolkova[dqsnoChislo].find(0) != priTolkova[dqsnoChislo].end()){
                        priTovaImaLi = true;
                    }
                    if(kolkoDaPravi != 0 && *i % kolkoDaPravi == 0 && *i != 0){
                        //if(*i / *j == kolkoDaPravi){
                        if(priTolkova[dqsnoChislo].find(*i / kolkoDaPravi) != priTolkova[dqsnoChislo].end()){
                            priTovaImaLi = true;
                        }
                    }
                    //if(-(*i + *j) == kolkoDaPravi){
                    if(priTolkova[dqsnoChislo].find(-kolkoDaPravi - *i) != priTolkova[dqsnoChislo].end()){
                        priTovaImaLi = true;
                    }
                    //if(-(*i - *j) == kolkoDaPravi){
                    if(priTolkova[dqsnoChislo].find(kolkoDaPravi + *i) != priTolkova[dqsnoChislo].end()){
                        priTovaImaLi = true;
                    }
                    //if(-(*i * *j) == kolkoDaPravi){
                    if(*i != 0 && -kolkoDaPravi % *i == 0){
                        if(priTolkova[dqsnoChislo].find(-kolkoDaPravi / *i) != priTolkova[dqsnoChislo].end()){
                            priTovaImaLi = true;
                        }
                    }
                    if(kolkoDaPravi != 0 && *i % -kolkoDaPravi == 0 && *i != 0){
                        //if(-(*i / *j) == kolkoDaPravi){
                        if(priTolkova[dqsnoChislo].find(*i / -kolkoDaPravi) != priTolkova[dqsnoChislo].end()){
                            priTovaImaLi = true;
                        }
                    }
                }
            }else{
                for(set<int>::iterator i = priTolkova[dqsnoChislo].begin(); i != priTolkova[dqsnoChislo].end(); i++){

                    //if(*i + *j == kolkoDaPravi){
                    if(priTolkova[lqvoChislo].find(kolkoDaPravi - *i) != priTolkova[lqvoChislo].end()){
                        priTovaImaLi = true;
                    }
                    //if(*i - *j == kolkoDaPravi){
                    if(priTolkova[lqvoChislo].find(*i - kolkoDaPravi) != priTolkova[lqvoChislo].end()){
                        priTovaImaLi = true;
                    }
                    //if(*i * *j == kolkoDaPravi){
                    if(*i == 0 && kolkoDaPravi == 0){
                        priTovaImaLi = true;
                    }
                    if(*i != 0 && kolkoDaPravi % *i == 0){
                        if(priTolkova[lqvoChislo].find(kolkoDaPravi / *i) != priTolkova[lqvoChislo].end()){
                            priTovaImaLi = true;
                        }
                    }
                    ///
                    if(kolkoDaPravi == 0 && priTolkova[lqvoChislo].find(0) != priTolkova[lqvoChislo].end()){
                        priTovaImaLi = true;
                    }
                    if(kolkoDaPravi != 0 && *i % kolkoDaPravi == 0 && *i != 0){
                        //if(*i / *j == kolkoDaPravi){
                        if(priTolkova[lqvoChislo].find(*i / kolkoDaPravi) != priTolkova[lqvoChislo].end()){
                            priTovaImaLi = true;
                        }
                    }
                    //if(-(*i + *j) == kolkoDaPravi){
                    if(priTolkova[lqvoChislo].find(-kolkoDaPravi - *i) != priTolkova[lqvoChislo].end()){
                        priTovaImaLi = true;
                    }
                    //if(-(*i - *j) == kolkoDaPravi){
                    if(priTolkova[lqvoChislo].find(kolkoDaPravi + *i) != priTolkova[lqvoChislo].end()){
                        priTovaImaLi = true;
                    }
                    //if(-(*i * *j) == kolkoDaPravi){
                    if(*i != 0 && -kolkoDaPravi % *i == 0){
                        if(priTolkova[lqvoChislo].find(-kolkoDaPravi / *i) != priTolkova[lqvoChislo].end()){
                            priTovaImaLi = true;
                        }
                    }
                    if(kolkoDaPravi != 0 && *i % -kolkoDaPravi == 0 && *i != 0){
                        //if(-(*i / *j) == kolkoDaPravi){
                        if(priTolkova[lqvoChislo].find(*i / -kolkoDaPravi) != priTolkova[lqvoChislo].end()){
                            priTovaImaLi = true;
                        }
                    }
                }
            }

            desetNaStepen *= 10;
        }

        /////////priTovaImaLi = (priTolkova[otChislo].find(kolkoDaPravi) != priTolkova[otChislo].end());

        if(priTovaImaLi == true){
           ////// cout<<otChislo<<" moje "<<endl;
            broiShtastlivi++;
        }
    }

    return broiShtastlivi;
}

int main(){
    int naiMnogoKoe;
    int kolkoDaPravi;

    cin>>naiMnogoKoe>>kolkoDaPravi;

    //int start = abs(kolkoDaPravi);

    int broiShatstlivi = 0;

    /*if(abs(kolkoDaPravi) <= naiMnogoKoe){
        broiShatstlivi++;
    }*/

    broiShatstlivi = sCycli(naiMnogoKoe, kolkoDaPravi);

    /*for(int i = 0; i <= naiMnogoKoe; i++){
        if(mojeLiOtTova(i, kolkoDaPravi) == true){
            broiShatstlivi++;
            //cout<<"s "<<i<<" moje "<<endl;
        }
    }*/

    cout<<broiShatstlivi<<endl;

    return 0;
}
