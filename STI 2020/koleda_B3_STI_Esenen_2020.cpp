#include<iostream>
using namespace std;

struct DanniZaIziskvaneOtTip2{
    int otKade;
    int doKade;
};

int dalzhina;
int broiIziskvaniq;

int nomercheTuk[500010];

int tukKolkoOtvarqshtiIma[500010];
int tukKolkoZatvarqshtiIma[500010];
int naiMalkaTochkaotTip1 = 500000;
int naiGolqmaTochkaOtTip1 = 0;

DanniZaIziskvaneOtTip2 dopalnitelniIskaniq[500010];
int broiDopalnitelniIziskvaniq;

char notTova(char segasnaBukv){
    if(segasnaBukv == 'Y'){
        return 'G';
    }
    return 'Y';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>dalzhina>>broiIziskvaniq;

    for(int i = 0; i < broiIziskvaniq; i++){
        int otKade;
        int doKade;
        int kolkoDaIma;

        cin>>otKade>>doKade>>kolkoDaIma;

        if(kolkoDaIma == 1){
            tukKolkoOtvarqshtiIma[otKade]++;
            tukKolkoZatvarqshtiIma[doKade]++;
            naiGolqmaTochkaOtTip1 = max(naiGolqmaTochkaOtTip1, doKade);
            naiMalkaTochkaotTip1 = min(naiMalkaTochkaotTip1, otKade);
        }else{
            dopalnitelniIskaniq[broiDopalnitelniIziskvaniq] = {otKade, doKade};
            broiDopalnitelniIziskvaniq++;
        }
    }

    int broiVKoitoSmeVmomenta = 0;
    int nomerche = 1;

    for(int i = naiMalkaTochkaotTip1; i <= naiGolqmaTochkaOtTip1; i++){
        broiVKoitoSmeVmomenta += tukKolkoOtvarqshtiIma[i];

        if(broiVKoitoSmeVmomenta > 0){
            nomercheTuk[i] = nomerche;
        }else{
            nomerche++;
        }

        broiVKoitoSmeVmomenta -= tukKolkoZatvarqshtiIma[i];
    }

    bool stavaLi = true;

    for(int i = 0; i < broiDopalnitelniIziskvaniq; i++){
        int otKade = dopalnitelniIskaniq[i].otKade;
        int doKade = dopalnitelniIskaniq[i].doKade;

        if((nomercheTuk[otKade] == nomercheTuk[doKade] && nomercheTuk[otKade] != 0) || (doKade - otKade + 1 < 2)){
            stavaLi = false;
            break;
        }
    }

    if(stavaLi == false){
        cout<<0<<endl;
    }else{
        cout<<1<<endl;

        cout<<"Y";
        char predno = 'Y';

        for(int i = 1; i < dalzhina; i++){
            if(nomercheTuk[i] == 0){
                char seg = notTova(predno);
                cout<<seg;
                predno = seg;
            }else{
                if(nomercheTuk[i - 1] != nomercheTuk[i]){
                    char seg = notTova(predno);
                    cout<<seg;
                    predno = seg;
                }else{
                    cout<<predno;
                }
            }
        }

        cout<<endl;
    }

    return 0;
}
