#include<iostream>
using namespace std;

string vhod;

long long chislenca[10010];
long long priDelenieNaKolko;
long long modulKakvo;

long long priTolkova[2][1005];

long long broiPodredici(long long doKade, long long kakavOstatak){
    long long tukaCifra = chislenca[doKade];

    if(doKade == 0){
        if(kakavOstatak == 0){
            return 1;
        }else{
            return 0;
        }
    }

    if(priTolkova[doKade][kakavOstatak] > -1){
        return priTolkova[doKade][kakavOstatak];
    }

    long long zaTuk = broiPodredici(doKade - 1, kakavOstatak);

    for(long long i = 0; i < priDelenieNaKolko; i++){
        if((10*i + tukaCifra)%priDelenieNaKolko == kakavOstatak){
            //cout<<"cifrata: "<<tukaCifra<<" indexa: "<<doKade<<" ost: "<<kakavOstatak<<" cikul ost: "<<i<<endl;
            zaTuk = (zaTuk + broiPodredici(doKade - 1, i))%modulKakvo;
        }
    }

    priTolkova[doKade][kakavOstatak] = zaTuk;
    return zaTuk;
}

long long sCycli(long long zaDoKade, long long zaKakavOstatak){
    priTolkova[0][0] = 1;

    for(long long doKade = 0; doKade < zaDoKade; doKade++){
        for(long long i = 0; i < priDelenieNaKolko; i++){
            priTolkova[(doKade + 1)%2][i] = 0;
        }

        for(long long kakavOstatak = 0; kakavOstatak < priDelenieNaKolko; kakavOstatak++){
            long long tukaCifra = chislenca[doKade + 1];

            priTolkova[(doKade+1)%2][kakavOstatak] =
                (priTolkova[(doKade+1)%2][kakavOstatak] + priTolkova[doKade%2][kakavOstatak])%modulKakvo;

            long long novkakavOstatak = (10*kakavOstatak + tukaCifra)%priDelenieNaKolko;
            priTolkova[(doKade+1)%2][novkakavOstatak] =
                (priTolkova[(doKade+1)%2][novkakavOstatak] + priTolkova[doKade%2][kakavOstatak])%modulKakvo;
        }
    }

    return priTolkova[zaDoKade%2][zaKakavOstatak];
}

int main(){
    cin>>vhod;

    cin>>priDelenieNaKolko>>modulKakvo;

    for(unsigned long long i = 0; i < vhod.size(); i++){
        chislenca[i + 1] = vhod[i] - '0';
    }

    /*for(unsigned long long i = 0; i <= vhod.size(); i++){
        for(long long j = 0; j <= priDelenieNaKolko; j++){
            priTolkova[i][j] = -1;
        }
    }*/

    //long long broi = broiPodredici(vhod.size(), 0) - 1;
    long long broi = sCycli(vhod.size(), 0) - 1;

    cout<<broi<<endl;

    return 0;
}
