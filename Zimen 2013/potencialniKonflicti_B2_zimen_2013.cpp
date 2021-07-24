#include<iostream>
#include<map>
#include<cmath>
using namespace std;

struct DanniZaNavigTochka{
    double x;
    double y;
};

struct DanniZaPolet{
    double vremeNaVhod;
    double skorost;
    double visochinaNaPoleta;
};

struct DanniZaTochka{
    double x;
    double y;
    double z;
};

int broiNavigacionniTochki;
int broiAktivirashtiSaobshteniq;
int kritichnoRazstoqnie;

map<string, DanniZaNavigTochka> navigTochki;

string nachalnaTochkaNaPolet[30];
DanniZaPolet poleti[30];
string krainaTochkaNaPolet[30];
double dalzhinaNaPoleta[30];

bool imameLiMezhduTezi[30][30];

bool trqbvaLiDaDobavqm40(int copie){
    int poslednaCifra = copie%10;
    copie /= 10;
    int predposlednaCifra = copie % 10;
    if(poslednaCifra + 10*predposlednaCifra == 60){
        return true;
    }
    return false;
}

int minutaPriTakivaMinuti(int chislo){
    //cout<<"davat mi "<<chislo<<" ";
    int posledno = chislo%10;
    chislo/=10;
    int predposledno = chislo%10;
    chislo/=10;

    int vreme = 60*chislo + 10*predposledno + posledno;

    //cout<<"poluchava se che sa izminali "<<vreme<<endl;

    return vreme;
}

int kolkoMinuti(int segashenChas, int nachalenChas){
    if(segashenChas < nachalenChas){
        return -1;
    }

    int poslednaCifraPurvi = segashenChas%10;
    segashenChas /= 10;
    int predposlednaCifraParvi = segashenChas%10;
    segashenChas /= 10;

    int chasNaParvi = segashenChas;
    int minutiNaParvi = 10*predposlednaCifraParvi + poslednaCifraPurvi;

    int poslednaCifraVtori = nachalenChas % 10;
    nachalenChas /= 10;
    int predposlednaCifraVtori = nachalenChas % 10;
    nachalenChas /= 10;

    int chasVtori = nachalenChas;
    int minutiNaVtori = 10*predposlednaCifraVtori + poslednaCifraVtori;

    //cout<<chasNaParvi<<" "<<minutiNaParvi<<endl<<chasVtori<<" "<<minutiNaVtori<<endl;

    int razlikaVChasovete = chasNaParvi - chasVtori;
    int razlikaVMinutite = minutiNaParvi - minutiNaVtori;

    int minuti = razlikaVChasovete * 60 + razlikaVMinutite;

    return minuti;
}

DanniZaTochka kudeESamoletaVMoment(int koiSamolet, int vKoiMoment){
    double izminatoRazstoqnie =
        (poleti[koiSamolet].skorost / 60) * (kolkoMinuti(vKoiMoment, poleti[koiSamolet].vremeNaVhod));
    if(izminatoRazstoqnie < 0){
        return {-1, -1, -1};
    }

    double kakvaChastOtCqloto = izminatoRazstoqnie / dalzhinaNaPoleta[koiSamolet];

    //cout<<"izminato e "<<izminatoRazstoqnie<<" chastta ot cqloto e "<<kakvaChastOtCqloto<<endl;

    double razlikaVXa =
        abs((navigTochki[nachalnaTochkaNaPolet[koiSamolet]].x - navigTochki[krainaTochkaNaPolet[koiSamolet]].x)) * kakvaChastOtCqloto;

    double razlikaVYa =
        abs(navigTochki[nachalnaTochkaNaPolet[koiSamolet]].y - navigTochki[krainaTochkaNaPolet[koiSamolet]].y) * kakvaChastOtCqloto;

    DanniZaTochka zaVrasht;

    if(navigTochki[nachalnaTochkaNaPolet[koiSamolet]].x > navigTochki[krainaTochkaNaPolet[koiSamolet]].x){
        if(navigTochki[nachalnaTochkaNaPolet[koiSamolet]].y > navigTochki[krainaTochkaNaPolet[koiSamolet]].y){
            zaVrasht =
                {navigTochki[nachalnaTochkaNaPolet[koiSamolet]].x - razlikaVXa, navigTochki[nachalnaTochkaNaPolet[koiSamolet]].y - razlikaVYa, poleti[koiSamolet].visochinaNaPoleta};
        }else{
            zaVrasht =
                {navigTochki[nachalnaTochkaNaPolet[koiSamolet]].x - razlikaVXa, navigTochki[nachalnaTochkaNaPolet[koiSamolet]].y + razlikaVYa, poleti[koiSamolet].visochinaNaPoleta};
        }
    }else{
        if(navigTochki[nachalnaTochkaNaPolet[koiSamolet]].y > navigTochki[krainaTochkaNaPolet[koiSamolet]].y){
            zaVrasht =
                {navigTochki[nachalnaTochkaNaPolet[koiSamolet]].x + razlikaVXa, navigTochki[nachalnaTochkaNaPolet[koiSamolet]].y - razlikaVYa, poleti[koiSamolet].visochinaNaPoleta};
        }else{
            zaVrasht =
                {navigTochki[nachalnaTochkaNaPolet[koiSamolet]].x + razlikaVXa, navigTochki[nachalnaTochkaNaPolet[koiSamolet]].y + razlikaVYa, poleti[koiSamolet].visochinaNaPoleta};
        }
    }

    return zaVrasht;
}

bool naKritichnoRaztoqnieEdnaOtDrugaLiSa(DanniZaTochka parva, DanniZaTochka vtora){
    if(parva.x < 0 || parva.y < 0 || parva.z < 0 || vtora.x < 0 || vtora.y < 0 || vtora.z < 0){
        return false;
    }

    //cout<<"dadoha mi "<<parva.x<<" "<<parva.y<<" "<<parva.z<<" "<<vtora.x<<" "<<vtora.y<<" "<<vtora.z;

    double razstoqnie =
        sqrt((parva.x-vtora.x)*(parva.x-vtora.x) + (parva.y-vtora.y)*(parva.y-vtora.y) + (parva.z-vtora.z)*(parva.z-vtora.z));

    //cout<<" razstoqnieto e "<<razstoqnie<<endl;

    if(razstoqnie - kritichnoRazstoqnie < 0.0001){
        //cout<<"TUK SE POLUCHAVA POTENCIALEN SBLASAK!!!"<<endl;
        return true;
    }else{
        return false;
    }
}

int main(){
    cin>>broiNavigacionniTochki>>broiAktivirashtiSaobshteniq>>kritichnoRazstoqnie;

    kritichnoRazstoqnie /= 1000;

    for(int i = 0; i < broiNavigacionniTochki; i++){
        string ime;
        double x;
        double y;
        cin>>ime>>x>>y;

        navigTochki[ime] = {x, y};
    }

    for(int i = 0; i < broiAktivirashtiSaobshteniq; i++){
        string imeNaPolet;
        string nachalnaTochka;
        double vremeNaVhoda;
        double skorost;
        double visochinaNaPoleta;
        string krainaTochka;
        cin>>imeNaPolet>>nachalnaTochka>>vremeNaVhoda>>skorost>>visochinaNaPoleta>>krainaTochka;

        visochinaNaPoleta /= 1000;

        nachalnaTochkaNaPolet[i] = nachalnaTochka;
        poleti[i] = {vremeNaVhoda, skorost, visochinaNaPoleta};
        krainaTochkaNaPolet[i] = krainaTochka;
    }

    for(int i = 0; i < broiAktivirashtiSaobshteniq; i++){
        double dalzhinka =
            sqrt((navigTochki[nachalnaTochkaNaPolet[i]].x - navigTochki[krainaTochkaNaPolet[i]].x) *
                 (navigTochki[nachalnaTochkaNaPolet[i]].x - navigTochki[krainaTochkaNaPolet[i]].x) +
                 (navigTochki[nachalnaTochkaNaPolet[i]].y - navigTochki[krainaTochkaNaPolet[i]].y) *
                 (navigTochki[nachalnaTochkaNaPolet[i]].y - navigTochki[krainaTochkaNaPolet[i]].y));
        dalzhinaNaPoleta[i] = dalzhinka;
    }

    int broiPotencialniKonflicti = 0;

    int minuta = 0;

    while(minuta < 2400){
        if(trqbvaLiDaDobavqm40(minuta) == true){
            minuta += 40;
        }

        //cout<<minuta<<endl;

        DanniZaTochka mestopolozhenieNaSmaoletite[30];

        for(int i = 0; i < broiAktivirashtiSaobshteniq; i++){
            mestopolozhenieNaSmaoletite[i] = kudeESamoletaVMoment(i, minuta);
        }

        for(int i = 0; i < broiAktivirashtiSaobshteniq; i++){
            for(int j = i + 1; j < broiAktivirashtiSaobshteniq; j++){
                if(naKritichnoRaztoqnieEdnaOtDrugaLiSa(mestopolozhenieNaSmaoletite[i], mestopolozhenieNaSmaoletite[j])){
                    if(imameLiMezhduTezi[i][j] == false){
                        broiPotencialniKonflicti++;
                        imameLiMezhduTezi[i][j] = true;
                    }
                }
            }
        }

        minuta++;
    }

    cout<<broiPotencialniKonflicti<<endl;

    return 0;
}
