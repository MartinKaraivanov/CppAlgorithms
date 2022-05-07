#include<iostream>
#include<vector>
using namespace std;

const long long mnogo = 1000000007;

long long broiChisla;

long long chisla[1000010];

long long kadeSmeSreshtaliTova[1000010];
long long broiPatiSreshtano[1000010];

long long deistvitelnaRedicaSig[1000010];
bool tovaSlojenoLiE[1000010];

bool toziKoleblivLiE[1000010];
bool polzvanLiEVeche[1000010];

long long broiLipsvashtiChisla;

long long broiLipsvFaktoriel = 1;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiChisla;

    for(long long i = 1; i <= broiChisla; i++){
        cin>>chisla[i];
    }

    bool okLiE = true;

    for(long long i = 1; i <= broiChisla; i++){
        if(kadeSmeSreshtaliTova[chisla[i]] == 0){
            kadeSmeSreshtaliTova[chisla[i]] = i;
        }else{
            if(i - kadeSmeSreshtaliTova[chisla[i]] != 2 || broiPatiSreshtano[chisla[i]] == 2){
                okLiE = false;
                break;
            }else{
                broiLipsvashtiChisla++;
            }
        }

        broiPatiSreshtano[chisla[i]]++;
    }

    if(okLiE == false){
        cout<<0<<endl;
        return 0;
    }

    //cout<<"broq izpusnati e "<<broiLipsvashtiChisla<<endl;

    deistvitelnaRedicaSig[2] = chisla[1];
    deistvitelnaRedicaSig[broiChisla - 1] = chisla[broiChisla];
    tovaSlojenoLiE[chisla[1]] = true;
    tovaSlojenoLiE[chisla[broiChisla]] = true;

    for(long long i = 3; i <= broiChisla; i++){
        if(chisla[i] == chisla[i - 2]){
            deistvitelnaRedicaSig[i - 1] = chisla[i];
            tovaSlojenoLiE[chisla[i]] = true;
        }
    }

    for(long long i = 2; i <= broiChisla - 1; i++){
        if(tovaSlojenoLiE[chisla[i]] == true){
            continue;
        }

        if(deistvitelnaRedicaSig[i - 1] > 0 && deistvitelnaRedicaSig[i - 1] != chisla[i] && deistvitelnaRedicaSig[i + 1] == 0){
            deistvitelnaRedicaSig[i + 1] = chisla[i];
            tovaSlojenoLiE[chisla[i]] = true;
        }

        if(deistvitelnaRedicaSig[i + 1] > 0 && deistvitelnaRedicaSig[i + 1] != chisla[i] && deistvitelnaRedicaSig[i - 1] == 0){
            deistvitelnaRedicaSig[i - 1] = chisla[i];
            tovaSlojenoLiE[chisla[i]] = true;
        }
    }

    for(long long i = broiChisla - 1; i >= 2; i--){
        if(tovaSlojenoLiE[chisla[i]] == true){
            continue;
        }

        if(deistvitelnaRedicaSig[i - 1] > 0 && deistvitelnaRedicaSig[i - 1] != chisla[i] && deistvitelnaRedicaSig[i + 1] == 0){
            deistvitelnaRedicaSig[i + 1] = chisla[i];
            tovaSlojenoLiE[chisla[i]] = true;
        }

        if(deistvitelnaRedicaSig[i + 1] > 0 && deistvitelnaRedicaSig[i + 1] != chisla[i] && deistvitelnaRedicaSig[i - 1] == 0){
            deistvitelnaRedicaSig[i - 1] = chisla[i];
            tovaSlojenoLiE[chisla[i]] = true;
        }
    }

    for(long long i = 2; i < broiChisla; i++){
        if(deistvitelnaRedicaSig[i - 1] != chisla[i] && deistvitelnaRedicaSig[i - 1] > 0 &&
            deistvitelnaRedicaSig[i + 1] != chisla[i] && deistvitelnaRedicaSig[i + 1]  > 0)
        {
            cout<<0<<endl;
            return 0;
        }
    }

    /*cout<<"originalnata redica e pone: "<<endl;
    for(int i = 1; i <= broiChisla; i++){
        cout<<deistvitelnaRedicaSig[i]<<" ";
    }
    cout<<endl;*/

    for(long long i = 2; i < broiChisla; i++){
        if(broiPatiSreshtano[chisla[i]] == 1 && tovaSlojenoLiE[chisla[i]] == false){
            toziKoleblivLiE[i] = true;
        }
    }

    long long kolkoRazpredeleniqNaKoleb = 1;

    long long broiPoredniChetni = 0;
    long long broiPoredniNechetni = 0;

    for(long long i = 1; i <= broiChisla; i++){
        if(i%2 == 1){
            if(toziKoleblivLiE[i] == true){
                broiPoredniNechetni++;
            }else{
                kolkoRazpredeleniqNaKoleb = (kolkoRazpredeleniqNaKoleb * (broiPoredniNechetni + 1))%mnogo;
                broiPoredniNechetni = 0;
            }
        }else{
            if(toziKoleblivLiE[i] == true){
                broiPoredniChetni++;
            }else{
                kolkoRazpredeleniqNaKoleb = (kolkoRazpredeleniqNaKoleb * (broiPoredniChetni + 1))%mnogo;
                broiPoredniChetni = 0;
            }
        }
    }
    kolkoRazpredeleniqNaKoleb = (kolkoRazpredeleniqNaKoleb * (broiPoredniNechetni + 1))%mnogo;
    kolkoRazpredeleniqNaKoleb = (kolkoRazpredeleniqNaKoleb * (broiPoredniChetni + 1))%mnogo;

    for(long long i = 1; i <= broiLipsvashtiChisla; i++){
        broiLipsvFaktoriel = (broiLipsvFaktoriel * i)%mnogo;
    }

    //cout<<"faktoriela e "<<broiLipsvFaktoriel<<endl;
    //long long kolkoRazpredeleniqNaKoleb = sCycli(indexiNaKoleblivi.size() - 1, broiChisla);

    long long otgovor = (kolkoRazpredeleniqNaKoleb * broiLipsvFaktoriel)%mnogo;

    cout<<otgovor<<endl;

    return 0;
}
