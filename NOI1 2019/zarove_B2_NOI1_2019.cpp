#include<iostream>
using namespace std;

int broiHvarlqniq;

bool stavaLiSTolkova[10010];

bool tovaChisloVazmozhnoLiE(int dadeno, int promenenoto){
    int okLiE = 0;

    while(promenenoto > 0){
        if(dadeno <= 0){
            okLiE = 0;
            break;
        }

        int cifraNaDadenoto = dadeno%10;
        int cifraNaPromenenoto = promenenoto%10;

        if(cifraNaPromenenoto == cifraNaDadenoto){
            okLiE++;
        }

        dadeno /= 10;
        promenenoto /= 10;
    }

    if(dadeno > 0){
        okLiE = 0;
    }

    if(okLiE == 1){
        return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiHvarlqniq;

    for(int i = 0; i <= 10000; i++){
        stavaLiSTolkova[i] = true;
    }

    int broiSKoitoNeStava = 0;

    for(int t = 0; t < broiHvarlqniq; t++){
        //cout<<"-----------------------------------------------------"<<endl;

        int parvoVqrno;
        cin>>parvoVqrno;

        int vtoroNevqrno;
        cin>>vtoroNevqrno;

        for(int i = parvoVqrno + 1; i <= 10000; i++){
            if(stavaLiSTolkova[i] == true){
                stavaLiSTolkova[i] = false;
                broiSKoitoNeStava++;
            }
        }

        for(int z = 1; z <= 10000; z++){
            int ostavashtoZaVtoroto = 7*z - parvoVqrno;

            if(tovaChisloVazmozhnoLiE(ostavashtoZaVtoroto, vtoroNevqrno) == false || z > ostavashtoZaVtoroto){
                if(stavaLiSTolkova[z] == true){
                    stavaLiSTolkova[z] = false;
                    broiSKoitoNeStava++;
                }
            }else{
                if(stavaLiSTolkova[z] == true){
                    //cout<<z<<" "<<ostavashtoZaVtoroto<<" "<<vtoroNevqrno<<endl;
                }
            }
        }
    }

    int broiSKoitoStava = 10000 - broiSKoitoNeStava;

    cout<<broiSKoitoStava<<endl;

    for(int i = 1; i <= 10000; i++){
        if(stavaLiSTolkova[i] == true){
            cout<<i<<" ";
        }
    }

    cout<<endl;

    return 0;
}
