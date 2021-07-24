#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

struct DanniZaElementa{
    int stoinost;
    int naKoiIndex;
};

int broiElementiVParvaRedia;
DanniZaElementa elementivparvaRedica[100010];

int broiElementiVavVtoraRedica;
DanniZaElementa elementiVavVtoraRedica[100010];

int broiKoitoGiImaIVDvete;
DanniZaElementa teziKoitoGiImaIVDveteParva[100010];
DanniZaElementa teziKoitoGiImaIVDveteVtora[100010];

bool sortiranePoStoinost(DanniZaElementa a, DanniZaElementa b){
    return a.stoinost < b.stoinost;
}

bool sortiranePoIndex(DanniZaElementa a, DanniZaElementa b){
    return a.naKoiIndex < b.naKoiIndex;
}

void nulirane(){
    for(int i = 0; i < max(broiElementiVavVtoraRedica, broiElementiVParvaRedia); i++){
        elementivparvaRedica[i] = {0, 0};
        elementiVavVtoraRedica[i] = {0, 0};
    }
    for(int i = 0; i < broiKoitoGiImaIVDvete; i++){
        teziKoitoGiImaIVDveteParva[i] = {0, 0};
        teziKoitoGiImaIVDveteVtora[i] = {0, 0};
    }

    broiElementiVavVtoraRedica = 0;
    broiElementiVParvaRedia = 0;
    broiKoitoGiImaIVDvete = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int t = 1; t <= 5; t++){
        nulirane();

        cin>>broiElementiVParvaRedia;

        for(int i = 0; i < broiElementiVParvaRedia; i++){
            int stoinost;
            cin>>stoinost;
            elementivparvaRedica[i].stoinost = stoinost;
            elementivparvaRedica[i].naKoiIndex = i;
        }

        cin>>broiElementiVavVtoraRedica;

        for(int i = 0; i < broiElementiVavVtoraRedica; i++){
            int stoinost;
            cin>>stoinost;
            elementiVavVtoraRedica[i].stoinost = stoinost;
            elementiVavVtoraRedica[i].naKoiIndex = i;
        }

        sort(elementivparvaRedica, elementivparvaRedica + broiElementiVParvaRedia, sortiranePoStoinost);
        sort(elementiVavVtoraRedica, elementiVavVtoraRedica + broiElementiVavVtoraRedica, sortiranePoStoinost);

        int indexParva = 0;
        int indexVtora = 0;

        while(indexParva < broiElementiVParvaRedia && indexVtora < broiElementiVavVtoraRedica){
            if(elementivparvaRedica[indexParva].stoinost == elementiVavVtoraRedica[indexVtora].stoinost){
                teziKoitoGiImaIVDveteParva[broiKoitoGiImaIVDvete] = elementivparvaRedica[indexParva];
                teziKoitoGiImaIVDveteVtora[broiKoitoGiImaIVDvete] = elementiVavVtoraRedica[indexVtora];
                broiKoitoGiImaIVDvete++;
            }

            if(elementivparvaRedica[indexParva].stoinost < elementiVavVtoraRedica[indexVtora].stoinost){
                indexParva++;
            }else{
                indexVtora++;
            }
        }

        sort(teziKoitoGiImaIVDveteParva, teziKoitoGiImaIVDveteParva + broiKoitoGiImaIVDvete, sortiranePoIndex);
        sort(teziKoitoGiImaIVDveteVtora, teziKoitoGiImaIVDveteVtora + broiKoitoGiImaIVDvete, sortiranePoIndex);

        int okLiE = 1;

        for(int i = 0; i < broiKoitoGiImaIVDvete; i++){
            if(teziKoitoGiImaIVDveteParva[i].stoinost != teziKoitoGiImaIVDveteVtora[i].stoinost){
                okLiE = 0;
                break;
            }
        }

        cout<<okLiE;

    }

    cout<<endl;

    return 0;
}
