#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Danni{
    int otVrah;
    int doVrah;
    int rastoqnie;
};

int broiStancii;

Danni razstoqnie[1050];
int broiPatq;

int otKoqComponentaE[1050];
int broiComponenti = 1;

bool otgovori[1050][1050];
int broiOtgovori[1050];

bool poMalkoLiE(Danni a, Danni b){
    return a.rastoqnie < b.rastoqnie;
}

int main(){
    cin>>broiStancii;

    for(int i = 1; i <= broiStancii; i++){
        for(int j = i + 1; j <= broiStancii; j++){
            int razst;
            cin>>razst;

            razstoqnie[broiPatq].otVrah = i;
            razstoqnie[broiPatq].doVrah = j;
            razstoqnie[broiPatq].rastoqnie = razst;
            broiPatq++;
        }
    }

    sort(razstoqnie, razstoqnie + broiPatq, poMalkoLiE);

    int brPt = 0;

    for(int i = 0; i < broiPatq; i++){
        if(brPt == broiStancii - 1){
            break;
        }
        if(otKoqComponentaE[razstoqnie[i].otVrah] == 0 && otKoqComponentaE[razstoqnie[i].doVrah] == 0){
            otgovori[razstoqnie[i].otVrah][razstoqnie[i].doVrah] = true;
            otgovori[razstoqnie[i].doVrah][razstoqnie[i].otVrah] = true;
            otKoqComponentaE[razstoqnie[i].otVrah] = broiComponenti;
            otKoqComponentaE[razstoqnie[i].doVrah] = broiComponenti;
            broiComponenti++;
            brPt++;
        }else{
            if(otKoqComponentaE[razstoqnie[i].otVrah] > 0 &&
                otKoqComponentaE[razstoqnie[i].otVrah] == otKoqComponentaE[razstoqnie[i].doVrah] ||
                otKoqComponentaE[razstoqnie[i].doVrah] > 0 &&
                otKoqComponentaE[razstoqnie[i].otVrah] == otKoqComponentaE[razstoqnie[i].doVrah]){
                    /// nishto ne praime
            }else{
                if(otKoqComponentaE[razstoqnie[i].otVrah] > 0 &&
                    otKoqComponentaE[razstoqnie[i].doVrah] > 0 &&
                    otKoqComponentaE[razstoqnie[i].otVrah] != otKoqComponentaE[razstoqnie[i].doVrah]){

                    otgovori[razstoqnie[i].otVrah][razstoqnie[i].doVrah] = true;
                    otgovori[razstoqnie[i].doVrah][razstoqnie[i].otVrah] = true;

                    int k = otKoqComponentaE[razstoqnie[i].doVrah];

                    for(int i = 1; i <= broiStancii; i++){
                        if(otKoqComponentaE[i] == k){
                            otKoqComponentaE[i] = otKoqComponentaE[razstoqnie[i].otVrah];
                        }
                    }

                    brPt++;

                }else{
                    if((otKoqComponentaE[razstoqnie[i].otVrah] == 0 &&
                        otKoqComponentaE[razstoqnie[i].otVrah] != otKoqComponentaE[razstoqnie[i].doVrah]) ||
                        (otKoqComponentaE[razstoqnie[i].doVrah] == 0 &&
                        otKoqComponentaE[razstoqnie[i].otVrah] != otKoqComponentaE[razstoqnie[i].doVrah])){

                        otgovori[razstoqnie[i].otVrah][razstoqnie[i].doVrah] = true;
                        otgovori[razstoqnie[i].doVrah][razstoqnie[i].otVrah] = true;

                        if(otKoqComponentaE[razstoqnie[i].otVrah] == 0){
                            otKoqComponentaE[razstoqnie[i].otVrah] = otKoqComponentaE[razstoqnie[i].doVrah];
                        }else{
                            otKoqComponentaE[razstoqnie[i].doVrah] = otKoqComponentaE[razstoqnie[i].otVrah];
                        }

                        brPt++;
                    }
                }
            }
        }
    }

    for(int i = 1; i <= broiStancii; i++){
        for(int j = 1; j <= broiStancii; j++){
            if(otgovori[i][j]){
                broiOtgovori[i]++;
            }
        }
    }

    for(int i = 1; i <= broiStancii; i++){
        cout<<broiOtgovori[i]<<" ";
        for(int j = 1; j <= broiStancii; j++){
            if(otgovori[i][j]){
                cout<<j;
                if(j < broiStancii){
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }

    return 0;
}
