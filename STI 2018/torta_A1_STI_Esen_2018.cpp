#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

const double epsilon = 0.0001;

struct Koordinati{
    double y;
    double x;
};

int broiTochki;

vector<Koordinati> tochki;

struct DanniZaVrashtane{
    double ednotoLice;
    double drugotoLice;
};

double kolkoEXNaPresechnataT(Koordinati parvaTochka, Koordinati vtoraTochka, double dadenY){
    double a = dadenY - parvaTochka.y;
    double b = vtoraTochka.y - dadenY;

    double x3 = (a*vtoraTochka.x + b*parvaTochka.x)/(a + b);

    return x3;
}

DanniZaVrashtane triagalniteLica(Koordinati parvaTochka, Koordinati vtoraTochka, double dadenY){
    double x3 = kolkoEXNaPresechnataT(parvaTochka, vtoraTochka, dadenY);

    double parvotoLice = (x3 - parvaTochka.x)*(parvaTochka.y - dadenY);

    double vtorotoLice = (vtoraTochka.x - x3)*(vtoraTochka.y - dadenY);

    return {parvotoLice, vtorotoLice};
}

double liceNaTrapecPri(Koordinati parvaTochka, Koordinati vtoraTochka, double sprqmoY){
    double lice = ((parvaTochka.y - sprqmoY) + (vtoraTochka.y - sprqmoY))*(vtoraTochka.x - parvaTochka.x);

    return lice;
}

double sborNaDveteLicaPri(double segaY){
    double sborNaGornoLice = 0;
    double sborNaDolnoLice = 0;

    //cout<<"sega sme na "<<segaY<<endl;

    for(int i = 0; i < (int)tochki.size(); i++){
        Koordinati parvaTochka = tochki[i];
        Koordinati vtoraTochka;

        if(i + 1 == tochki.size()){
            vtoraTochka = tochki[0];
        }else{
            vtoraTochka = tochki[i + 1];
        }

        //cout<<"sega tochkite sa "<<parvaTochka.x<<" "<<parvaTochka.y<<" i "<<vtoraTochka.x<<" "<<vtoraTochka.y<<endl;

        if((parvaTochka.y < segaY && vtoraTochka.y < segaY) || (parvaTochka.y > segaY && vtoraTochka.y > segaY)){
            double tukaLice = liceNaTrapecPri(parvaTochka, vtoraTochka, segaY);

            //cout<<"ot edna strana sa i liceto e "<<tukaLice<<endl;

            if(parvaTochka.y < segaY){
                sborNaDolnoLice += tukaLice;
            }else{
                sborNaGornoLice += tukaLice;
            }
        }else{
            DanniZaVrashtane tukaLice = triagalniteLica(parvaTochka, vtoraTochka, segaY);

            //cout<<"ot razlichni strani sa i licata sa "<<tukaLice.ednotoLice<<" i "<<tukaLice.drugotoLice<<endl;

            if(parvaTochka.y < vtoraTochka.y){
                sborNaDolnoLice += tukaLice.ednotoLice;
                sborNaGornoLice += tukaLice.drugotoLice;
            }else{
                sborNaDolnoLice += tukaLice.drugotoLice;
                sborNaGornoLice += tukaLice.ednotoLice;
            }
        }

        //cout<<"gornoto lice sega e "<<sborNaGornoLice<<" a dolnoto lice sega e "<<sborNaDolnoLice<<endl<<endl;
    }

    double razlikataIm = sborNaGornoLice - sborNaDolnoLice;

    return razlikataIm;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiTochki;

    for(int i = 0; i < broiTochki; i++){
        double tukaY;
        double tukaX;

        cin>>tukaY>>tukaX;

        double prenapravenY = tukaY;
        double prenapravenX = tukaX;

        tochki.push_back({prenapravenY, prenapravenX});
    }

    double maxY = tochki[0].y;
    double minY = tochki[0].y;

    for(int i = 0; i < broiTochki; i++){
        maxY = max(maxY, tochki[i].y);
        minY = min(minY, tochki[i].y);
    }

    double lqvKrai = minY;
    double desenKrai = maxY;

    while(lqvKrai + epsilon < desenKrai){
        double poSredata = (lqvKrai + desenKrai)/2;

        double tukaPolucheno = sborNaDveteLicaPri(poSredata);

        //cout<<poSredata<<" "<<tukaPolucheno<<endl;

        if(tukaPolucheno < epsilon && tukaPolucheno > -epsilon){
            lqvKrai = poSredata;
            break;
        }

        if(tukaPolucheno > 0){
            lqvKrai = poSredata + epsilon;
        }else{
            desenKrai = poSredata;
        }
    }

    double rezultat = lqvKrai;

    cout<<fixed<<setprecision(3)<<rezultat<<endl;

    return 0;
}
