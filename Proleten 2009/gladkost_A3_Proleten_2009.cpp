#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

long long broiOtsechki;
long long daljinaKashta;

long long visochiniOtsechki[1000010];




multiset<long long> leviChisla;
multiset<long long> desniChisla;
long long sredenElement = -1;

long long sborLevi;
long long sborDesni;



void dobaviElement(long long novElement){
    if(leviChisla.size() == 0 && desniChisla.size() == 0 && sredenElement == -1){
        sredenElement = novElement;
        return ;
    }
    if(leviChisla.size() == 0 && desniChisla.size() == 0 && sredenElement > -1){
        leviChisla.insert(min(novElement, sredenElement));
        desniChisla.insert(max(novElement, sredenElement));
        sborLevi += min(novElement, sredenElement);
        sborDesni += max(novElement, sredenElement);
        sredenElement = -1;
        return ;
    }

    long long naiGolqmLqv = *leviChisla.rbegin();
    long long naiMalakDesen = *desniChisla.begin();

    if(sredenElement == -1){
        if(novElement >= naiGolqmLqv && novElement <= naiMalakDesen){
            sredenElement = novElement;
        }else{
            if(novElement < naiGolqmLqv){
                //leviChisla.erase(naiGolqmLqv);
                leviChisla.erase(leviChisla.find(naiGolqmLqv));
                leviChisla.insert(novElement);
                sredenElement = naiGolqmLqv;
                sborLevi -= naiGolqmLqv;
                sborLevi += novElement;
            }else{
                //desniChisla.erase(naiMalakDesen);
                desniChisla.erase(desniChisla.find(naiMalakDesen));
                desniChisla.insert(novElement);
                sredenElement = naiMalakDesen;
                sborDesni -= naiMalakDesen;
                sborDesni += novElement;
            }
        }
    }else{
        if(novElement <= sredenElement){
            leviChisla.insert(novElement);
            desniChisla.insert(sredenElement);
            sborLevi += novElement;
            sborDesni += sredenElement;
        }else{
            leviChisla.insert(sredenElement);
            desniChisla.insert(novElement);
            sborLevi += sredenElement;
            sborDesni += novElement;
        }

        sredenElement = -1;
    }

}

void mahniElement(long long koiElement){
    if(leviChisla.size() == 0 && desniChisla.size() == 0 && sredenElement > -1){
        sredenElement = -1;
        return ;
    }

    long long naiGolqmLqv = *leviChisla.rbegin();
    long long naiMalakDesen = *desniChisla.begin();

    if(sredenElement == -1){
        if(koiElement <= naiGolqmLqv){
            //leviChisla.erase(koiElement);
            leviChisla.erase(leviChisla.find(koiElement));
            //desniChisla.erase(naiMalakDesen);
            desniChisla.erase(desniChisla.find(naiMalakDesen));
            sredenElement = naiMalakDesen;
            sborLevi -= koiElement;
            sborDesni -= naiMalakDesen;
        }else{
            //desniChisla.erase(koiElement);
            desniChisla.erase(desniChisla.find(koiElement));
            //leviChisla.erase(naiGolqmLqv);
            leviChisla.erase(leviChisla.find(naiGolqmLqv));
            sredenElement = naiGolqmLqv;
            sborDesni -= koiElement;
            sborLevi -= naiGolqmLqv;
        }
    }else{
        if(koiElement == sredenElement){

        }else{
            if(koiElement <= naiGolqmLqv){
                //leviChisla.erase(koiElement);
                leviChisla.erase(leviChisla.find(koiElement));
                leviChisla.insert(sredenElement);
                sborLevi -= koiElement;
                sborLevi += sredenElement;
            }else{
                //desniChisla.erase(koiElement);
                desniChisla.erase(desniChisla.find(koiElement));
                desniChisla.insert(sredenElement);
                sborDesni -= koiElement;
                sborDesni += sredenElement;
            }
        }

        sredenElement = -1;
    }

}

int main(){

    cin>>broiOtsechki>>daljinaKashta;

    for(long long i = 0; i < broiOtsechki; i++){
        cin>>visochiniOtsechki[i];
    }

    for(long long i = 0; i < daljinaKashta; i++){
        dobaviElement(visochiniOtsechki[i]);
    }

    long long minimalnaCena = sborDesni - sborLevi;
    long long starta = 1;

    for(long long i = daljinaKashta; i < broiOtsechki; i++){
        mahniElement(visochiniOtsechki[i - daljinaKashta]);
        dobaviElement(visochiniOtsechki[i]);

        long long tuka = sborDesni - sborLevi;
        if(tuka < minimalnaCena){
            minimalnaCena = tuka;
            starta = i - daljinaKashta + 1 + 1;
        }
    }

    cout<<minimalnaCena<<endl;
    cout<<starta<<endl;

    return 0;
}
