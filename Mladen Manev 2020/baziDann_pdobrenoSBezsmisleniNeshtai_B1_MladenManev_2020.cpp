#include<iostream>
using namespace std;

struct DanniZaOperaciqta{
    int otKade;
    int doKade;
    int x;
    int y;
};

int broiBazi;

//int nachalniStoinostiNaBazite[100010];
//int maximalnaSumaZaBaza[100010];

int ednotoMinusDrugoto[100010];

int broiOperacii;
DanniZaOperaciqta operacii[100010];

int otgovori[100010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiBazi;

    for(int i = 0; i < broiBazi; i++){
        int tuka;
        cin>>tuka;
        ednotoMinusDrugoto[i] = -tuka;
        //scin>>nachalniStoinostiNaBazite[i];
    }

    for(int i = 0; i < broiBazi; i++){
        int tuka;
        cin>>tuka;
        ednotoMinusDrugoto[i] += tuka;
        //cin>>maximalnaSumaZaBaza[i];
    }

    cin>>broiOperacii;

    for(int i = 0; i < broiOperacii; i++){
        cin>>operacii[i].otKade>>operacii[i].doKade>>operacii[i].x>>operacii[i].y;
        operacii[i].otKade --;
        operacii[i].doKade --;
    }

    for(int i = 0; i < broiBazi; i++){
        if(ednotoMinusDrugoto[i] <= 0){
            otgovori[i] = 0;
        }else{
            otgovori[i] = -1;
        }
    }

    for(int i = 0; i < broiOperacii; i++){
        int kolkoPatiPoY = 0;

        for(int j = operacii[i].otKade; j <= operacii[i].doKade; j++){
            if(otgovori[j] == -1){
                ednotoMinusDrugoto[j] -= operacii[i].x + kolkoPatiPoY * operacii[i].y;

                if(ednotoMinusDrugoto[j] <= 0){
                    otgovori[j] = i + 1;
                }
            }

            kolkoPatiPoY++;
        }

    }

    for(int i = 0; i < broiBazi - 1; i++){
        cout<<otgovori[i]<<" ";
    }

    cout<<otgovori[broiBazi - 1];

    cout<<endl;

    return 0;
}
