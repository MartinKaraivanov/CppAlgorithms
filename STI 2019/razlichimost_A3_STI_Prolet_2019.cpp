#include<iostream>
#include<algorithm>
using namespace std;

const int razmer = 20000010;

int broiVarhove;

struct DanniZaDete{
    int vrah;
    int predishno;
};

DanniZaDete deca[razmer];

int poslednoDete[razmer];

int roditel[razmer];
int stepen[razmer];

int redSEdnakvaDalb[razmer];
int indexDalb;
int vremenen[razmer];

int cvqt[razmer];

int broiOtToziCvqt[razmer];

void daiSledvashtiqRedPoDalb(){

    if(indexDalb == 0){
        for(int i = 1; i <= broiVarhove; i++){
            if(stepen[i] == 0){
                redSEdnakvaDalb[indexDalb] = i;
                indexDalb++;
            }
        }
    }else{
        int indexVremenen = 0;
        for(int i = 0; i < indexDalb; i++){
            int parent = roditel[redSEdnakvaDalb[i]];
            stepen[parent]--;
            if(stepen[parent] == 0){
                vremenen[indexVremenen] = parent;
                indexVremenen++;
            }
        }
        indexDalb = indexVremenen;
        for(int i = 0; i < indexVremenen; i++){
            redSEdnakvaDalb[i] = vremenen[i];
        }
    }

}

int sravniPodDarveta(int parvoKoren, int vtoroKoren){

    int parvo = poslednoDete[parvoKoren];
    int vtoro = poslednoDete[vtoroKoren];

    while(parvo > 0 && vtoro > 0){

        int naParvoto = deca[parvo].vrah;
        int naVtoroto = deca[vtoro].vrah;

        if(cvqt[naParvoto] < cvqt[naVtoroto]){
            return -1;
        }
        if(cvqt[naParvoto] > cvqt[naVtoroto]){
            return 1;
        }

        parvo = deca[parvo].predishno;
        vtoro = deca[vtoro].predishno;
    }

    if(parvo == 0 && vtoro != 0){
        return -1;
    }
    if(parvo != 0 && vtoro == 0){
        return 1;
    }

    return 0;
}

bool sravni(int a, int b){
    return sravniPodDarveta(a, b) == -1;
}

int main(){

    cin>>broiVarhove;

    for(int i = 1; i < broiVarhove; i++){
        int otKoi;
        int doKoi;

        cin>>otKoi>>doKoi;

        deca[i].vrah = doKoi;
        deca[i].predishno = poslednoDete[otKoi];
        poslednoDete[otKoi] = i;
        roditel[doKoi] = otKoi;
        stepen[otKoi]++;
    }

    indexDalb = 0;
    daiSledvashtiqRedPoDalb();

    int nomerche = 0;

    while(indexDalb != 0){

        sort(redSEdnakvaDalb, redSEdnakvaDalb + indexDalb, sravni);

        cvqt[redSEdnakvaDalb[0]] = nomerche;
        nomerche++;

        for(int i = 1; i < indexDalb; i++){
            if(sravniPodDarveta(redSEdnakvaDalb[i-1], redSEdnakvaDalb[i]) != 0){
                cvqt[redSEdnakvaDalb[i]] = nomerche;
                nomerche++;
            }else{
                cvqt[redSEdnakvaDalb[i]] = nomerche - 1;
            }
        }

        daiSledvashtiqRedPoDalb();
    }

    for(int i = 1; i <= broiVarhove; i++){
        broiOtToziCvqt[cvqt[i]]++;
    }

    cout<<nomerche<<endl;

    for(int i = 1; i <= broiVarhove; i++){
        cout<<broiOtToziCvqt[cvqt[i]]<<" ";
    }
    cout<<endl;

    return 0;
}
