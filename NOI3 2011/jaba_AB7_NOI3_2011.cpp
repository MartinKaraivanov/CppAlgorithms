#include<iostream>
#include<vector>
using namespace std;

const int mnogo = 1000000000;

int broiLilii;

int udovolstvieLilia[100010];
int tip[100010];
int razstMaks[100010];

int priTolkova[100010];
bool imameLiPriTolkova[100010];

int maksUdovolstvie(int doKade){
    if(doKade == 1){
        return udovolstvieLilia[doKade];
    }
    if(imameLiPriTolkova[doKade] == true){
        return priTolkova[doKade];
    }

    int tukaMaks = 0;
    int priKoqE = 0;

    for(int i = doKade - 1; i >= 1; i--){
        if(razstMaks[i] + i >= doKade){
            int tekushto = -(doKade - i)*tip[i] + maksUdovolstvie(i);
            if(priKoqE == 0){
                tukaMaks = tekushto;
                priKoqE = i;
            }else{
                if(tekushto > tukaMaks){
                    tukaMaks = tekushto;
                    priKoqE = i;
                }
            }
        }
    }

    tukaMaks += udovolstvieLilia[doKade];

    //cout<<"ot liliq "<<doKade<<" nai dobre se poluchava ako sme skochili ot liliq "<<priKoqE<<" i e "<<tukaMaks<<endl;

    imameLiPriTolkova[doKade] = true;
    priTolkova[doKade] = tukaMaks;
    return tukaMaks;
    //return tukaMaks + udovolstvieLilia[doKade];
}

int sCycli(int doDoKade){
    priTolkova[1] = udovolstvieLilia[1];

    for(int doKade = 2; doKade <= doDoKade; doKade++){
        int tukaMaks = 0;
        int priKoqE = 0;

        for(int i = doKade - 1; i >= 1; i--){
            if(razstMaks[i] + i >= doKade){
                int tekushto = -(doKade - i)*tip[i] + priTolkova[i];
                if(priKoqE == 0){
                    tukaMaks = tekushto;
                    priKoqE = i;
                }else{
                    if(tekushto > tukaMaks){
                        tukaMaks = tekushto;
                        priKoqE = i;
                    }
                }
            }
        }

        tukaMaks += udovolstvieLilia[doKade];

        priTolkova[doKade] = tukaMaks;
    }

    return priTolkova[doDoKade];
}

//////////////////////////////////////////////////////////////////////////////////

struct DanniZaDarvoto{
    int stoinost;
    int otKadeObhvashta;
    int doKadeObhvashta;
    int lqvoDeteNomer;
    int dqsnoDeteNomer;
};

vector<DanniZaDarvoto> darvo[6];
int korenNomer[6] = {-1, -1, -1, -1, -1, -1};

int daiNovVrah(int koeDarvo, DanniZaDarvoto novVrah){
    darvo[koeDarvo].push_back(novVrah);
    return darvo[koeDarvo].size() - 1;
}

int postroiDarvo(int koeDarvo, int otKade, int doKade){
    if(otKade == doKade){
        return daiNovVrah(koeDarvo, {-mnogo, otKade, doKade, -1, -1});
    }

    int lqvoDeteNomer = postroiDarvo(koeDarvo, otKade, (otKade + doKade)/2);
    int dqsnoDeteNomer = postroiDarvo(koeDarvo, (otKade + doKade)/2 + 1, doKade);

    return daiNovVrah(koeDarvo, {-mnogo, otKade, doKade, lqvoDeteNomer, dqsnoDeteNomer});
}

void updateDarvo(int koeDarvo, int segashenVrah, int koiIndex, int novaStoinost){
    if(segashenVrah == -1 || darvo[koeDarvo][segashenVrah].otKadeObhvashta > koiIndex || darvo[koeDarvo][segashenVrah].doKadeObhvashta < koiIndex){
        return ;
    }

    if(koiIndex == darvo[koeDarvo][segashenVrah].otKadeObhvashta && koiIndex == darvo[koeDarvo][segashenVrah].doKadeObhvashta){
        darvo[koeDarvo][segashenVrah].stoinost = novaStoinost;
        return ;
    }

    updateDarvo(koeDarvo, darvo[koeDarvo][segashenVrah].lqvoDeteNomer, koiIndex, novaStoinost);
    updateDarvo(koeDarvo, darvo[koeDarvo][segashenVrah].dqsnoDeteNomer, koiIndex, novaStoinost);

    int lqvoDeteStoinost = -mnogo;
    if(darvo[koeDarvo][segashenVrah].lqvoDeteNomer != -1){
        lqvoDeteStoinost = darvo[koeDarvo][darvo[koeDarvo][segashenVrah].lqvoDeteNomer].stoinost;
    }
    int dqsnoDeteStoinost = -mnogo;
    if(darvo[koeDarvo][segashenVrah].dqsnoDeteNomer != -1){
        dqsnoDeteStoinost = darvo[koeDarvo][darvo[koeDarvo][segashenVrah].dqsnoDeteNomer].stoinost;
    }

    darvo[koeDarvo][segashenVrah].stoinost = max(lqvoDeteStoinost, dqsnoDeteStoinost);
}

void update(int koeDarvo, int poziciq, int stoinost){
    updateDarvo(koeDarvo, korenNomer[koeDarvo], poziciq, stoinost);
}

int queryDarvo(int koeDarvo, int segashenVrah, int otIndex, int doIndex){
    if(segashenVrah == -1 || otIndex > darvo[koeDarvo][segashenVrah].doKadeObhvashta || doIndex < darvo[koeDarvo][segashenVrah].otKadeObhvashta){
        return -mnogo;
    }

    if(otIndex <= darvo[koeDarvo][segashenVrah].otKadeObhvashta && doIndex >= darvo[koeDarvo][segashenVrah].doKadeObhvashta){
        return darvo[koeDarvo][segashenVrah].stoinost;
    }

    return max(queryDarvo(koeDarvo, darvo[koeDarvo][segashenVrah].lqvoDeteNomer, otIndex, doIndex),
                queryDarvo(koeDarvo, darvo[koeDarvo][segashenVrah].dqsnoDeteNomer, otIndex, doIndex));
}

int query(int koeDarvo, int poziciq){
    return queryDarvo(koeDarvo, korenNomer[koeDarvo], poziciq, broiLilii);
}

int nameriOtg(){

    for(int i = 1; i <= 5; i++){
        korenNomer[i] = postroiDarvo(i, 1, broiLilii);
    }

    int otg = udovolstvieLilia[broiLilii];
    for(int t = 1; t <= 5; t++){
        update(t, broiLilii, otg + t);
    }
    cout<<"updatenahme purvonachalno"<<endl;

    for(int i = broiLilii - 1; i >= 1; i--){
        int otKade = i + razstMaks[i];
        if(otKade > broiLilii){
            otKade = broiLilii;
        }
        otg = udovolstvieLilia[i] + query(tip[i], otKade) - (broiLilii - i + 1)*tip[i];
        cout<<"vurnahme se ot queryto"<<endl;
        for(int t = 1; t <= 5; t++){
            update(t, i, otg + t*(broiLilii - i + 1));
        }
    }

    return otg;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiLilii;

    for(int i = 1; i <= broiLilii; i++){
        cin>>udovolstvieLilia[i]>>tip[i]>>razstMaks[i];
    }

    //int otgovor = maksUdovolstvie(broiLilii);
    //int otgovor = sCycli(broiLilii);
    int otgovor = nameriOtg();

    cout<<otgovor<<endl;

    return 0;
}
