#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

struct DanniZaTochka{
    double x;
    double y;
};

struct DanniZaOkrajnost{
    DanniZaTochka centar;
    int radius;
};

int broiOkrajnosti;
DanniZaOkrajnost okrajnosti[10010];

int broiTochki;
DanniZaTochka tochki[15];

int broiUdari;
int siliNaUdarite[10010];

vector<double> naiOtdalechenaOtNashtaT;

int dvoichnoTarsene(int radius){
    int lqvKrai = 0;
    int desenKrai = naiOtdalechenaOtNashtaT.size();

    while(lqvKrai < desenKrai){
        int sredata = (lqvKrai + desenKrai)/2;

        if(naiOtdalechenaOtNashtaT[sredata] < radius){
            lqvKrai = sredata + 1;
        }else{
            desenKrai = sredata;
        }
    }

    return lqvKrai;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiOkrajnosti>>broiTochki>>broiUdari;

    for(int i = 0; i < broiOkrajnosti; i++){
        double x;
        double y;
        int radius;
        cin>>x>>y>>radius;

        okrajnosti[i] = {x, y, radius};
    }

    for(int i = 0; i < broiTochki; i++){
        cin>>tochki[i].x>>tochki[i].y;
    }

    for(int i = 0; i < broiUdari; i++){
        cin>>siliNaUdarite[i];
    }

    for(int i = 0; i < broiTochki; i++){
        DanniZaTochka nashtaTochka = tochki[i];

        for(int j = 0; j < broiOkrajnosti; j++){
            DanniZaOkrajnost a = okrajnosti[j];
            double razst = sqrt((nashtaTochka.x - a.centar.x)*(nashtaTochka.x - a.centar.x) +
                (nashtaTochka.y - a.centar.y)*(nashtaTochka.y - a.centar.y)) + a.radius;

            //naiOtdalechenaOtNashtaT[i][j] = razst;
            naiOtdalechenaOtNashtaT.push_back(razst);
        }
    }

    sort(naiOtdalechenaOtNashtaT.begin(), naiOtdalechenaOtNashtaT.end());

    int specheleniTochki = 0;
    int predenroTochki = 0;

    for(int q = 0; q < broiUdari; q++){
        int tekushtaSila = siliNaUdarite[q];
        if(q > 0 && predenroTochki%2 == 0){
            tekushtaSila *= 2;
        }

        int segashenBroiTochki = 0;

        /*for(int m = 0; m < broiTochki; m++){
            segashenBroiTochki += dvoichnoTarsene(m, tekushtaSila);


            /*for(int i = 0; i < naiOtdalechenaOtNashtaT[m].size(); i++){
                if(naiOtdalechenaOtNashtaT[m][i] < tekushtaSila){
                    //cout<<tekushtaOkrajnost.centar.x<<" "<<tekushtaOkrajnost.centar.y<<" "<<tekushtaOkrajnost.radius<<" ";
                    //cout<<i<<endl;
                    //specheleniTochki++;
                    segashenBroiTochki++;
                }else{
                    break;
                }
            }
        }*/

        segashenBroiTochki += dvoichnoTarsene(tekushtaSila);

        specheleniTochki += segashenBroiTochki;
        predenroTochki = segashenBroiTochki;
    }

    cout<<specheleniTochki<<endl;

    return 0;
}
