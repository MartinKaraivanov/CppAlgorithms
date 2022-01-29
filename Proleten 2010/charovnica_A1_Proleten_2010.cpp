#include<iostream>
#include<string>
using namespace std;

int broiPosledovatelnosti;

string posledovatelnosti[64];

string dnkEli;

int priTolkova[1024];

int naiMnogoPosledovatelnosti(int doKade){
    if(doKade == 0){
        return 0;
    }

    if(priTolkova[doKade] > -1){
        return priTolkova[doKade];
    }

    int zaTuka = naiMnogoPosledovatelnosti(doKade - 1);


    for(int i = 0; i < broiPosledovatelnosti; i++){
        int daljinaNaTozi = posledovatelnosti[i].size();
        if(dnkEli[doKade] == posledovatelnosti[i][daljinaNaTozi - 1] && daljinaNaTozi <= doKade){
            if(dnkEli.substr(doKade - daljinaNaTozi + 1, daljinaNaTozi) == posledovatelnosti[i]){
                int tekushto = 1 + naiMnogoPosledovatelnosti(doKade - daljinaNaTozi);

                zaTuka = max(zaTuka, tekushto);
            }
        }
    }

    priTolkova[doKade] = zaTuka;
    return zaTuka;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiPosledovatelnosti;

    cin>>dnkEli;

    for(int i = 0; i < broiPosledovatelnosti; i++){
        string tukaPosl;
        cin>>tukaPosl;

        posledovatelnosti[i] = tukaPosl;
    }

    dnkEli = 'a' + dnkEli;

    int daljinaDnk = dnkEli.size() - 1;

    for(int i = 0; i <= daljinaDnk; i++){
        priTolkova[i] = -1;
    }

    int otgovor = naiMnogoPosledovatelnosti(daljinaDnk);

    cout<<otgovor<<endl;

    return 0;
}
