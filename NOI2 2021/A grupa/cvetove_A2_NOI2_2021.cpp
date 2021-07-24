#include<iostream>
using namespace std;

long long broiKamacheta;
long long broiStoinosti;

long long kamacheta[500010];

const long long mnogo = 1000000007;

long long priTolkova[500010][4];

long long broiKombinaciiZaToziInterval(long long daljina, long long okoloNego){
    /// 0 - nqma nishto okolo nego; 1 - edno kamache; 2 - dve ednakvi kamacheta; 3 - dve razlichni kamacheta

    if(daljina == 0){
        return 1;
    }

    if(daljina == 1){
        if(okoloNego == 0){
            return broiStoinosti;
        }
        if(okoloNego == 1){
            return broiStoinosti - 1;
        }
        if(okoloNego == 2){
            return broiStoinosti - 1;
        }
        if(okoloNego == 3){
            return broiStoinosti - 2;
        }
    }

    if(priTolkova[daljina][okoloNego] > 0){
        return priTolkova[daljina][okoloNego];
    }

    long long zaTuk = 0;

    if(okoloNego == 0){
        zaTuk = (broiStoinosti * broiKombinaciiZaToziInterval(daljina - 1, 1))%mnogo;
    }else{
        if(okoloNego == 1){
            zaTuk = ((broiStoinosti - 1) * broiKombinaciiZaToziInterval(daljina - 1, 1))%mnogo;
        }else{
            if(okoloNego == 2){
                zaTuk = ((broiStoinosti - 1) * broiKombinaciiZaToziInterval(daljina - 1, 3))%mnogo;
            }else{
                zaTuk =
                    ((broiStoinosti - 2)*broiKombinaciiZaToziInterval(daljina - 1, 3) +
                        broiKombinaciiZaToziInterval(daljina - 1, 2))%mnogo;
            }
        }
    }

    long long zaVrasht = zaTuk%mnogo;

    priTolkova[daljina][okoloNego] = zaVrasht;
    return zaVrasht;
}

long long otgovor(){
    long long lqvKrai = 0;

    bool vlezliLiSme = false;

    long long stoinost = 0;

    for(long long i = 1; i <= broiKamacheta; i++){
        if(kamacheta[i] > 0){
            long long desenKrai = i;

            long long daljina = desenKrai - lqvKrai - 1;

            if(lqvKrai == 0){
                stoinost = broiKombinaciiZaToziInterval(daljina, 1)%mnogo;
            }else{
                if(kamacheta[lqvKrai] == kamacheta[i]){
                    stoinost = (stoinost * broiKombinaciiZaToziInterval(daljina, 2))%mnogo;
                }else{
                    stoinost = (stoinost * broiKombinaciiZaToziInterval(daljina, 3))%mnogo;
                }
            }

            lqvKrai = desenKrai;
            vlezliLiSme = true;
        }
    }

    if(vlezliLiSme == 0){
        stoinost = broiKombinaciiZaToziInterval(broiKamacheta, 0)%mnogo;
    }else{
        if(lqvKrai < broiKamacheta){
            stoinost = (stoinost * broiKombinaciiZaToziInterval(broiKamacheta - lqvKrai , 1))%mnogo;
        }
    }

    return stoinost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiKamacheta>>broiStoinosti;

    for(long long i = 1; i <= broiKamacheta; i++){
        cin>>kamacheta[i];
    }

    long long otg = otgovor()%mnogo;

    cout<<otg<<endl;

    return 0;
}
