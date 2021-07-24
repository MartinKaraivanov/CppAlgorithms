#include<iostream>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

struct DanniZaTochka{
    double x;
    double y;

    bool operator<(const DanniZaTochka& a) const
    {
        if(x < a.x){
            return true;
        }else{
            if(x > a.x){
                return false;
            }else{
                return y < a.y;
            }
        }
    }
};

struct DanniZaPrava{
    double a;
    double b;
};

int broiTochki;
int dalzhinaZaOtsechkata;

DanniZaTochka tochki[100010];

int naiDesenX = -100000000;
int koiESNaiDesenX = -1;

int naiLqvX = 100000000;
int koiENaiLqvX = -1;

vector<int> edniTochki;
vector<int> drugiTochki;

map<DanniZaTochka, map<DanniZaTochka, bool> > imameLiTaziOtsechka;

DanniZaPrava pravaOtDveTochki(DanniZaTochka parva, DanniZaTochka vtora){
    double a = (vtora.y - parva.y)/(vtora.x - parva.x);
    double b = parva.y - a*parva.x;
    return {a, b};
}

double yNaFunkciqta(DanniZaPrava pravata, double x){
    return pravata.a*x + pravata.b;
}

bool usporedniLiSaPravite(DanniZaPrava parva, DanniZaPrava Dolna){
    return (parva.a - Dolna.a < 0.000001) && (parva.a - Dolna.a > -0.000001);
}

long long broiOtsechkiSTakavaDalzhina(int dalzhinaDNaOtsechkata){
    DanniZaTochka leviqKraiNaParvata = tochki[edniTochki[0]];
    DanniZaTochka desniqKraiNaParvata = tochki[edniTochki[1]];

    DanniZaTochka leviqKraiNaDolnata = tochki[drugiTochki[0]];
    DanniZaTochka desniqKraiNaDolnata = tochki[drugiTochki[1]];

    int segashnoGorna = 1;
    int segashnoDolna = 1;

    long long broiTakivaPravi = 0;

    bool bezbroiLiSa = false;

    while(true){
        DanniZaTochka lqvKraiGorna = leviqKraiNaParvata;
        DanniZaTochka lqvKraiDolna = leviqKraiNaDolnata;

        DanniZaTochka desenKraiGorna = desniqKraiNaParvata;
        DanniZaTochka desenKraiDolna = desniqKraiNaDolnata;

        //double aNaGornata = (double)(lqvKraiGorna.y - desenKraiGorna.y)/(double)(lqvKraiGorna.x - desenKraiGorna.x);
        //double bNaGornata = (double)lqvKraiGorna.y - aNaGornata * lqvKraiGorna.x;

        //double aNaDolnata = (double)(lqvKraiDolna.y - desenKraiDolna.y)/(double)(lqvKraiDolna.x - desenKraiDolna.x);
        //double bNaDolnata = (double)lqvKraiDolna.y - aNaDolnata * lqvKraiDolna.x;

        DanniZaPrava pravaNaParvata = pravaOtDveTochki(lqvKraiGorna, desenKraiGorna);
        DanniZaPrava pravaNaDolnata = pravaOtDveTochki(lqvKraiDolna, desenKraiDolna);

        /*cout<<"gornata: "<<endl<<lqvKraiGorna.x<<" "<<lqvKraiGorna.y<<endl;
        cout<<desenKraiGorna.x<<" "<<desenKraiGorna.y<<endl;
        cout<<"a na pravata "<<pravaNaParvata.a<<" b na parvata "<<pravaNaParvata.b<<endl;
        cout<<"dolnata: "<<endl<<lqvKraiDolna.x<<" "<<lqvKraiDolna.y<<endl;
        cout<<desenKraiDolna.x<<" "<<desenKraiDolna.y<<endl;
        cout<<"a na Dolnata "<<pravaNaDolnata.a<<" b na Dolnata "<<pravaNaDolnata.b<<endl<<endl;*/

        if(lqvKraiGorna.x < lqvKraiDolna.x){
            lqvKraiGorna.x = lqvKraiDolna.x;
            lqvKraiGorna.y = pravaNaParvata.a*lqvKraiGorna.x + pravaNaParvata.b;
        }else{
            if(lqvKraiGorna.x > lqvKraiDolna.x){
                lqvKraiDolna.x = lqvKraiGorna.x;
                lqvKraiDolna.y = pravaNaDolnata.a*lqvKraiDolna.x + pravaNaDolnata.b;
            }
        }

        if(desenKraiGorna.x < desenKraiDolna.x){
            desenKraiDolna.x = desenKraiGorna.x;
            desenKraiDolna.y = pravaNaDolnata.a*desenKraiDolna.x + pravaNaDolnata.b;
        }else{
            if(desenKraiGorna.x > desenKraiDolna.x){
                desenKraiGorna.x = desenKraiDolna.x;
                desenKraiGorna.y = pravaNaParvata.a*desenKraiGorna.x + pravaNaParvata.b;
            }
        }

        //cout<<aNaGornata<<" "<<bNaGornata<<" "<<aNaDolnata<<" "<<bNaDolnata<<endl;

        /*cout<<endl<<lqvKraiGorna.x<<" "<<lqvKraiGorna.y<<endl;
        cout<<desenKraiGorna.x<<" "<<desenKraiGorna.y<<endl;
        cout<<lqvKraiDolna.x<<" "<<lqvKraiDolna.y<<endl;
        cout<<desenKraiDolna.x<<" "<<desenKraiDolna.y<<endl;*/

        double ednaDalzhina = abs(lqvKraiGorna.y - lqvKraiDolna.y);
        double drugaDalzhina = abs(desenKraiGorna.y - desenKraiDolna.y);

        //cout<<ednaDalzhina<<" "<<drugaDalzhina<<endl;

        if((usporedniLiSaPravite(pravaNaParvata, pravaNaDolnata) == true) &&
            (abs(pravaNaParvata.b - pravaNaDolnata.b) - dalzhinaDNaOtsechkata < 0.000001 &&
            abs(pravaNaParvata.b - pravaNaDolnata.b) - dalzhinaDNaOtsechkata > -0.000001) &&
            (desenKraiGorna.x > lqvKraiDolna.x ||
             lqvKraiDolna.x > desenKraiGorna.x ||
             desenKraiDolna.x > lqvKraiDolna.x ||
             lqvKraiGorna.x > desenKraiDolna.x))
        {
            //cout<<pravaNaParvata.a<<" "<<pravaNaParvata.b<<endl;
            //cout<<pravaNaDolnata.a<<" "<<pravaNaDolnata.b<<endl;
            bezbroiLiSa = true;
            break;
        }else{
            if(max(ednaDalzhina, drugaDalzhina) > dalzhinaDNaOtsechkata &&
               min(ednaDalzhina, drugaDalzhina) < dalzhinaDNaOtsechkata)
            {
                broiTakivaPravi++;
            }else{
                if(ednaDalzhina - dalzhinaDNaOtsechkata < 0.000001 && ednaDalzhina - dalzhinaDNaOtsechkata > -0.000001){
                    if(imameLiTaziOtsechka[lqvKraiDolna][lqvKraiGorna] == false){
                        imameLiTaziOtsechka[lqvKraiDolna][lqvKraiGorna] = true;
                        imameLiTaziOtsechka[lqvKraiGorna][lqvKraiDolna] = true;
                        broiTakivaPravi++;
                    }
                }else{
                    if(drugaDalzhina - dalzhinaDNaOtsechkata < 0.000001 && drugaDalzhina - dalzhinaDNaOtsechkata > -0.000001){
                        if(imameLiTaziOtsechka[desenKraiDolna][desenKraiGorna] == false){
                            imameLiTaziOtsechka[desenKraiDolna][desenKraiGorna] = true;
                            imameLiTaziOtsechka[desenKraiGorna][desenKraiDolna] = true;
                            broiTakivaPravi++;
                        }
                    }
                }
            }
        }

        if(desniqKraiNaParvata.x < desniqKraiNaDolnata.x){
            segashnoGorna++;
            if((unsigned)segashnoGorna >= edniTochki.size()){
                break;
            }

            leviqKraiNaParvata = desniqKraiNaParvata;
            desniqKraiNaParvata = tochki[edniTochki[segashnoGorna]];
        }else{
            segashnoDolna++;
            if((unsigned)segashnoDolna >= drugiTochki.size()){
                break;
            }

            leviqKraiNaDolnata = desniqKraiNaDolnata;
            desniqKraiNaDolnata = tochki[drugiTochki[segashnoDolna]];
        }

    }

    if(bezbroiLiSa == true){
        return -1;
    }

    return broiTakivaPravi;
}

int main(){
    cin>>broiTochki>>dalzhinaZaOtsechkata;

    for(int i = 0; i < broiTochki; i++){
        cin>>tochki[i].x>>tochki[i].y;
    }

    for(int i = 0; i < broiTochki; i++){
        if(tochki[i].x > naiDesenX){
            naiDesenX = tochki[i].x;
            koiESNaiDesenX = i;
        }
        if(tochki[i].x < naiLqvX){
            naiLqvX = tochki[i].x;
            koiENaiLqvX = i;
        }
    }


    int segashno = koiENaiLqvX;

    while(true){
        if(segashno < 0){
            segashno = broiTochki - 1;
        }
        edniTochki.push_back(segashno);
        if(segashno == koiESNaiDesenX){
            break;
        }
        segashno--;
    }

    segashno = koiENaiLqvX;

    while(true){
        if(segashno >= broiTochki){
            segashno = 0;
        }
        drugiTochki.push_back(segashno);
        if(segashno == koiESNaiDesenX){
            break;
        }
        segashno++;
    }

    long long broiPraviSTakavaDazhina = broiOtsechkiSTakavaDalzhina(dalzhinaZaOtsechkata);

    if(broiPraviSTakavaDazhina == -1){
        cout<<"Infinity"<<endl;
    }else{
        cout<<broiPraviSTakavaDazhina<<endl;
    }

    return 0;
}
