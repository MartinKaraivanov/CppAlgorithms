#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

long long broiDupki;
long long broiBageri;
long long vremeMezhduDupki;
long long vremeZaKopaene;

long long nachalniPozicii[100010];

bool dobtoLiE(long long vreme){
    long long koqDupkaTursimDaKopaem = 1;

    //cout<<vreme<<endl;

    for(long long i = 0; i < broiBageri; i++){
        if(koqDupkaTursimDaKopaem > broiDupki){
            break;
        }

        if(nachalniPozicii[i] <= koqDupkaTursimDaKopaem){
            long long vremeZaDaStignemDoNach = abs(nachalniPozicii[i] - koqDupkaTursimDaKopaem)*vremeMezhduDupki;
            long long ostVreme = vreme - vremeZaDaStignemDoNach;

            if(ostVreme <= 0){
                continue;
            }

            int kolkoDupkiShteUspeemDaIzkopaem = ostVreme/(vremeZaKopaene + vremeMezhduDupki);

            if(ostVreme%(vremeZaKopaene + vremeMezhduDupki) >= vremeZaKopaene){
                kolkoDupkiShteUspeemDaIzkopaem++;
            }

            koqDupkaTursimDaKopaem += kolkoDupkiShteUspeemDaIzkopaem;

        }else{
            long long vremeZaDaStignemDoNach = abs(nachalniPozicii[i] - koqDupkaTursimDaKopaem)*vremeMezhduDupki;
            long long ostVreme = vreme - vremeZaDaStignemDoNach;

            if(ostVreme <= 0){
                break;
            }

            long long kolkoDupkiMozhemDaIzkopaem = ostVreme/vremeZaKopaene;

            if(kolkoDupkiMozhemDaIzkopaem <= 0){
                break;
            }

            if(kolkoDupkiMozhemDaIzkopaem <= abs(nachalniPozicii[i] - koqDupkaTursimDaKopaem) + 1){
                koqDupkaTursimDaKopaem += kolkoDupkiMozhemDaIzkopaem;
                continue;
            }

            ostVreme -= (abs(nachalniPozicii[i] - koqDupkaTursimDaKopaem) + 1)*vremeZaKopaene;

            long long zaNadqsno = ostVreme/(vremeZaKopaene + 2*vremeMezhduDupki);

            if(zaNadqsno == 0){
                koqDupkaTursimDaKopaem = nachalniPozicii[i] + 1;
                continue;
            }

            long long parviVariantKolkoDupkiShteIzkopaem = (abs(nachalniPozicii[i] - koqDupkaTursimDaKopaem) + 1) + zaNadqsno;

            long long vtoroVreme =
                vreme -
                (abs(nachalniPozicii[i] - koqDupkaTursimDaKopaem)*(2*vremeMezhduDupki + vremeZaKopaene) + vremeZaKopaene);

            if(vtoroVreme <= 0){
                koqDupkaTursimDaKopaem += parviVariantKolkoDupkiShteIzkopaem;
                continue;
            }

            long long vtoroZaNadqsno = vtoroVreme/(vremeZaKopaene + vremeMezhduDupki);

            long long vtoriVariantKolkoShteIzkopaem = (abs(nachalniPozicii[i] - koqDupkaTursimDaKopaem) + 1) + vtoroZaNadqsno;

            koqDupkaTursimDaKopaem += max(parviVariantKolkoDupkiShteIzkopaem, vtoriVariantKolkoShteIzkopaem);

        }

        //cout<<"sled bager "<<i<<" "<<koqDupkaTursimDaKopaem<<endl;
    }

    if(koqDupkaTursimDaKopaem > broiDupki){
        return true;
    }

    return false;
}
int main(){
    cin>>broiDupki>>broiBageri;
    cin>>vremeMezhduDupki>>vremeZaKopaene;

    for(long long i = 0; i < broiBageri; i++){
        cin>>nachalniPozicii[i];
    }

    sort(nachalniPozicii, nachalniPozicii + broiBageri);

    /*for(long long vreme = vremeZaKopaene; true; vreme++){
        if(dobtoLiE(vreme)){
            cout<<vreme<<endl;
            break;
        }
    }*/

    long long lqvKrai = vremeZaKopaene;
    long long desenKrai = broiDupki*(vremeZaKopaene + 2*vremeMezhduDupki);

    while(lqvKrai < desenKrai){
        long long sreden = (lqvKrai + desenKrai)/2;
        if(dobtoLiE(sreden) == false){
            lqvKrai = sreden + 1;
        }else{
            desenKrai = sreden;
        }
    }

    cout<<lqvKrai<<endl;

    return 0;
}
