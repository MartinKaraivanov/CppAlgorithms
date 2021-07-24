#include<iostream>
#include<algorithm>
using namespace std;

int moneti[100005];

int sortirniMoneti[100005];

void zarezhdaneNaSortiraniMoneti(int zaBroi){
    for(int i = 0; i < zaBroi; i++){
        sortirniMoneti[i] = moneti[i];
    }
    sort(sortirniMoneti, sortirniMoneti + zaBroi);
}

bool stavaLi(int zaBroi, int doKolkoCenite){
    zarezhdaneNaSortiraniMoneti(zaBroi);

    int doKoeChisloZapalvame = 0;

    bool hubavoLiE = true;

    for(int i = 0; i < zaBroi; i++){
        if(sortirniMoneti[i] > doKoeChisloZapalvame + 1){
            hubavoLiE = false;
            break;
        }
        doKoeChisloZapalvame += sortirniMoneti[i];
        if(doKoeChisloZapalvame >= doKolkoCenite){
            break;
        }
    }

    if(doKoeChisloZapalvame < doKolkoCenite){
        hubavoLiE = false;
    }

    return hubavoLiE;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int broiTestove;

    cin>>broiTestove;

    for(int t = 0; t < broiTestove; t++){
        int broiMoneti;
        int doKolkoCenite;

        cin>>broiMoneti>>doKolkoCenite;
        for(int i = 0; i < broiMoneti; i++){
            cin>>moneti[i];
        }

        int lqvKrai = 1;
        int desenKrai = broiMoneti;

        while(lqvKrai < desenKrai){
            int sreda = (lqvKrai + desenKrai)/2;

            if(stavaLi(sreda, doKolkoCenite) == true){
                desenKrai = sreda;
            }else{
                lqvKrai = sreda + 1;
            }
        }

        if(stavaLi(lqvKrai, doKolkoCenite) == false){
            cout<<-1<<endl;
        }else{
            cout<<lqvKrai<<endl;
        }

        /*int dobur = -1;

        for(int i = 0; i < broiMoneti; i++){
            if(stavaLi(i + 1, doKolkoCenite) == true){
                dobur = i + 1;
                break;
            }
        }

        cout<<dobur<<endl;*/

    }

    return 0;
}
