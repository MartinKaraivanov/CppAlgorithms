#include<iostream>
using namespace std;

string vhod;

bool palindromLiEOtDo(int otKade, int doKade){
    int daljina = doKade - otKade + 1;

    int sredata = otKade + daljina/2;

    bool palindrom = true;

    for(int i = otKade; i <= sredata; i++){
        if(vhod[i] != vhod[doKade - i + otKade]){
            palindrom = false;
            break;
        }
    }

    return palindrom;
}

int priTolkova[10010];

int minimalenBroiRazdeliteli(int doKade){
    if(doKade == 0){
        return -1;
    }

    if(priTolkova[doKade] > -2){
        return priTolkova[doKade];
    }

    int zaTuk = 10010;

    for(int d = 1; d <= doKade; d++){
        if(palindromLiEOtDo(doKade - d + 1, doKade) == true){
            int tekushto = 1 + minimalenBroiRazdeliteli(doKade - d);

            zaTuk = min(zaTuk, tekushto);
        }
    }

    priTolkova[doKade] = zaTuk;
    return zaTuk;
}

int sCycli(int zaDoKade){
    priTolkova[0] = -1;


    for(int doKade = 1; doKade <= zaDoKade; doKade++){
        int zaTuk = 10010;

        for(int d = 1; d <= doKade; d++){
            if(palindromLiEOtDo(doKade - d + 1, doKade) == true){
                int tekushto = 1 + priTolkova[doKade - d];

                zaTuk = min(zaTuk, tekushto);
            }

            priTolkova[doKade] = zaTuk;
        }
    }

    return priTolkova[zaDoKade];
}

int main(){
    cin>>vhod;

    vhod = " " + vhod;

    /*for(unsigned int i = 0; i <= vhod.size(); i++){
        priTolkova[i] = -2;
    }

    int broiRazdeliteli = minimalenBroiRazdeliteli(vhod.size() - 1);*/
    int broiRazdeliteli = sCycli(vhod.size() - 1);

    cout<<broiRazdeliteli<<endl;

    return 0;
}
