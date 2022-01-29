#include<iostream>
#include<vector>
using namespace std;

long long broiMatrici;
long long razmeri[111];

struct DanniZaMatricata{
    long long parviRazmer;
    long long vtoriRazmer;
};

vector<DanniZaMatricata> matrici;

long long priTolkova[1010][1010];

long long naiMalkotoUmnojeniq(long long otKade, long long kolko){
    if(kolko == 1){
        return 0;
    }

    if(kolko == 2){
        return matrici[otKade].parviRazmer*matrici[otKade].vtoriRazmer*matrici[otKade + kolko - 1].vtoriRazmer;
    }

    if(priTolkova[otKade][kolko] > -1){
        return priTolkova[otKade][kolko];
    }

    long long zaTukaNaiMalkoto = 100000000007;

    for(long long i = otKade; i < otKade + kolko - 1; i++){
        long long tukaLqvo = naiMalkotoUmnojeniq(otKade, i - otKade + 1);
        long long tukaDqsno = naiMalkotoUmnojeniq(i + 1, otKade + kolko - 1 - i);
        long long tukaSmetka = matrici[otKade].parviRazmer*matrici[i].vtoriRazmer*matrici[otKade + kolko - 1].vtoriRazmer;
        long long tekushto = tukaLqvo + tukaDqsno + tukaSmetka;
        zaTukaNaiMalkoto = min(zaTukaNaiMalkoto, tekushto);
    }

    priTolkova[otKade][kolko] = zaTukaNaiMalkoto;
    return zaTukaNaiMalkoto;
}

long long sCycli(long long zaOtkade, long long zaKolko){

    for(long long i = 0; i <= zaOtkade + zaKolko - 1; i++){
        priTolkova[2][i] = matrici[i].parviRazmer*matrici[i].vtoriRazmer*matrici[i + 2 - 1].vtoriRazmer;
    }

    for(long long kolko = 3; kolko <= zaKolko; kolko++){
        for(long long otKade = 0; otKade <= zaOtkade + zaKolko - 1; otKade++){
            long long zaTukaNaiMalkoto = 100000000007;

            for(long long i = otKade; i < otKade + kolko - 1; i++){
                long long tukaLqvo = priTolkova[i - otKade + 1][otKade];
                long long tukaDqsno = priTolkova[otKade + kolko - 1 - i][i + 1];
                long long tukaSmetka = matrici[otKade].parviRazmer*matrici[i].vtoriRazmer*matrici[otKade + kolko - 1].vtoriRazmer;
                long long tekushto = tukaLqvo + tukaDqsno + tukaSmetka;
                zaTukaNaiMalkoto = min(zaTukaNaiMalkoto, tekushto);
            }

            priTolkova[kolko][otKade] = zaTukaNaiMalkoto;
        }
    }

    return priTolkova[zaKolko][zaOtkade];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiMatrici;

    for(long long i = 0; i <= broiMatrici; i++){
        cin>>razmeri[i];
    }

    for(long long i = 0; i < broiMatrici; i++){
        matrici.push_back({razmeri[i], razmeri[i + 1]});
    }

    /*for(int i = 0; i <= broiMatrici; i++){
        for(int j = 0; j <= broiMatrici; j++){
            priTolkova[i][j] = -1;
        }
    }*/

    //long long otgovor = naiMalkotoUmnojeniq(0, broiMatrici);
    long long otgovor = sCycli(0, broiMatrici);

    cout<<otgovor<<endl;

    return 0;
}
