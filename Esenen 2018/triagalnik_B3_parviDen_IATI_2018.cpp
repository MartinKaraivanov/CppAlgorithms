#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct DanniZaTochka{
    double x;
    double y;
};

struct DanniZaPovecheTochka{
    DanniZaTochka tochkata;
    bool dopalnitelnaLiE;
    int originalenNomer;
};

int broiDaddeniTochki;
int broiDopalnitelniTochki;

DanniZaPovecheTochka tochki[2005];
DanniZaPovecheTochka vtoriTochki[2005];

DanniZaTochka otKude;

bool poBlizkoLiE(DanniZaPovecheTochka a, DanniZaPovecheTochka b){
    double razstA =
        (a.tochkata.x - otKude.x)*(a.tochkata.x - otKude.x) + (a.tochkata.y - otKude.y)*(a.tochkata.y - otKude.y);
    double razstB =
        (b.tochkata.x - otKude.x)*(b.tochkata.x - otKude.x) + (b.tochkata.y - otKude.y)*(b.tochkata.y - otKude.y);

    return razstA < razstB;
}

double razstMezhduDveTochki(){

}

int otgovori[2005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiDaddeniTochki>>broiDopalnitelniTochki;

    for(int i = 0; i < broiDaddeniTochki; i++){
        double tukX;
        double tukY;
        cin>>tukX>>tukY;
        tochki[i] = {{tukX, tukY}, false, i};
        vtoriTochki[i] = {{tukX, tukY}, false, i};
    }

    for(int i = 0; i < broiDopalnitelniTochki; i++){
        double tukX;
        double tukY;
        cin>>tukX>>tukY;
        tochki[broiDaddeniTochki + i] = {{tukX, tukY}, true, broiDaddeniTochki + i};
        vtoriTochki[broiDaddeniTochki + i] = {{tukX, tukY}, true, broiDaddeniTochki + i};
    }



    for(int i = 0; i < broiDaddeniTochki + broiDopalnitelniTochki; i++){
        otKude = tochki[i].tochkata;
        sort(vtoriTochki, vtoriTochki + broiDaddeniTochki + broiDopalnitelniTochki, poBlizkoLiE);

        bool imameLiDopalnitelna = false;
        int koqEDopalnitelnata = -1;

        if(tochki[i].dopalnitelnaLiE == true){
            imameLiDopalnitelna = true;
            koqEDopalnitelnata = i;
        }

        for(int j = 0; j < broiDaddeniTochki + broiDopalnitelniTochki; j++){
            if(vtoriTochki[j].originalenNomer != i){

                if(imameLiDopalnitelna == true && vtoriTochki[j].dopalnitelnaLiE == true){
                    continue;
                }

                double razstDoTazi =
                    sqrt((tochki[i].tochkata.x - vtoriTochki[j].tochkata.x)*(tochki[i].tochkata.x - vtoriTochki[j].tochkata.x) +
                         (tochki[i].tochkata.y - vtoriTochki[j].tochkata.y)*(tochki[i].tochkata.y - vtoriTochki[j].tochkata.y));

                if(imameLiDopalnitelna == false){
                    if(vtoriTochki[j].dopalnitelnaLiE == true){
                        imameLiDopalnitelna = true;
                        koqEDopalnitelnata = vtoriTochki[j].originalenNomer;
                    }
                }

                for(int k = j + 1; k < broiDaddeniTochki + broiDopalnitelniTochki; k++){
                    //cout<<i<<" "<<vtoriTochki[j].originalenNomer<<" "<<vtoriTochki[k].originalenNomer<<endl;
                    double razstDoTaziVtoro =
                        sqrt((tochki[i].tochkata.x - vtoriTochki[k].tochkata.x)*(tochki[i].tochkata.x - vtoriTochki[k].tochkata.x) +
                             (tochki[i].tochkata.y - vtoriTochki[k].tochkata.y)*(tochki[i].tochkata.y - vtoriTochki[k].tochkata.y));

                    if(abs(razstDoTaziVtoro - razstDoTazi) > 0.0001){
                        break;
                    }

                    if(imameLiDopalnitelna == true && vtoriTochki[k].dopalnitelnaLiE == true){
                        continue;
                    }

                    if(imameLiDopalnitelna == false){
                        if(vtoriTochki[k].dopalnitelnaLiE == true){
                            imameLiDopalnitelna = true;
                            koqEDopalnitelnata = vtoriTochki[k].originalenNomer;
                        }
                    }

                    //cout<<imameLiDopalnitelna<<endl;

                    //cout<<i<<" "<<vtoriTochki[j].originalenNomer<<" "<<vtoriTochki[k].originalenNomer<<endl;

                    if(imameLiDopalnitelna == true){
                        //cout<<koqEDopalnitelnata<<endl;
                        otgovori[koqEDopalnitelnata]++;
                    }

                }
            }
        }
    }

    for(int i = broiDaddeniTochki; i < broiDaddeniTochki + broiDopalnitelniTochki; i++){
        cout<<otgovori[i]<<endl;
    }


    return 0;
}
