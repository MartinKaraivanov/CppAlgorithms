#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

bool koiEPoNapred(DanniZaTochka a, DanniZaTochka b){
    if(a.y > b.y){
        return true;
    }
    if(a.y < b.y){
        return false;
    }
    return a.x < b.x;
}

int broiNujniVarhove;

void nameriBroiNujniVarhove(int broiTochki){
    for(int i = 1; true; i *= 2){
        if(i >= broiTochki){
            broiNujniVarhove = i*2;
            break;
        }
    }
}

int daiListo(int index){
    return index + broiNujniVarhove/2;
}

int segmentnoDarvo[4000010];

void update(int kade, int delta){
    int segashenIndex = daiListo(kade);

    while(segashenIndex > 0){
        segmentnoDarvo[segashenIndex] += delta;
        segashenIndex /= 2;
    }
}

int query(int otKade, int doKade){
    int lqvIndex = daiListo(otKade);
    int desenIndex = daiListo(doKade);

    if(lqvIndex > desenIndex){
        return -1;
    }

    if(lqvIndex == desenIndex){
        return segmentnoDarvo[lqvIndex];
    }

    int suma = 0;

    suma += segmentnoDarvo[lqvIndex];
    suma += segmentnoDarvo[desenIndex];

    while(lqvIndex + 1 < desenIndex){
        if(lqvIndex%2 == 0){
            suma += segmentnoDarvo[lqvIndex + 1];
        }
        if(desenIndex%2 == 1){
            suma += segmentnoDarvo[desenIndex - 1];
        }

        lqvIndex /= 2;
        desenIndex /= 2;
    }

    return suma;
}

int kadeETaziEdinica(int koqEdinica, int broiTochki){

    //cout<<"tarsime "<<koqEdinica<<"edinica"<<endl;

    int koqTarsime = koqEdinica;

    int segashenVrah = 1;

    while(segashenVrah < broiNujniVarhove/2){
        int broiVLqvoto = segmentnoDarvo[segashenVrah*2];

        if(broiVLqvoto >= koqTarsime){
            segashenVrah = segashenVrah*2;
        }else{
            segashenVrah = segashenVrah*2 + 1;
            koqTarsime -= broiVLqvoto;
        }
    }

    return min(max(segashenVrah - broiNujniVarhove/2, 1), broiTochki);
}

int kadeEToziNqlqvo(int otKade, int koiNomer){

    /*int lqvKrai = 1;
    int desenKrai = otKade;

    while(lqvKrai < desenKrai){
        int sredata = (lqvKrai + desenKrai)/2;

        int tuka = query(sredata, otKade);

        //cout<<"pitame za ot "<<sredata<<" do "<<otKade<<" i poluchavame "<<tuka<<endl;

        if(tuka < koiNomer){
            desenKrai = sredata;
        }else{
            lqvKrai = sredata + 1;
        }
    }

    if(query(lqvKrai, otKade) < koiNomer){
        lqvKrai--;
    }

    return max(lqvKrai, 1);*/

    int kolkoImameDotuk = query(1, otKade);
    int koqEdinicaTarsime = kolkoImameDotuk - koiNomer + 1;

    return kadeETaziEdinica(koqEdinicaTarsime, otKade);
}

int kadeEToziNadqsno(int otKade, int koiNomer, int broiTochki){

    /*int lqvKrai = otKade;
    int desenKrai = broiTochki;

    while(lqvKrai < desenKrai){
        int sredata = (lqvKrai + desenKrai)/2;

        int tuka = query(otKade, sredata);

        if(tuka < koiNomer){
            lqvKrai = sredata + 1;
        }else{
            desenKrai = sredata;
        }
    }

    if(query(otKade, lqvKrai) < koiNomer){
        lqvKrai++;
    }

    return min(lqvKrai, broiTochki);*/


    int kolkoImameDotuk = query(1, otKade);
    int koqEdinicaTarsime = kolkoImameDotuk + koiNomer;

    return kadeETaziEdinica(koqEdinicaTarsime, broiTochki);
}

int kadeEPosledniqKoitoVlizaVIntervala(vector<int> &zaDobavqne, int kakvoTarsim){
    /*int kadeE = zaDobavqne.size();

    for(int j = 0; j < zaDobavqne.size(); j++){
        if(zaDobavqne[j] >= kakvoTarsim){
            kadeE = j;
            break;
        }
    }

    return kadeE;*/

    int lqvKrai = 0;
    int desenKrai = zaDobavqne.size();

    while(lqvKrai < desenKrai){
        int sredata = (lqvKrai + desenKrai)/2;

        if(zaDobavqne[sredata] >= kakvoTarsim){
            desenKrai = sredata;
        }else{
            lqvKrai = sredata + 1;
        }
    }

    return lqvKrai;
}

long long init(vector<int> h, int K){

    vector<DanniZaTochka> tochki;

    for(int i = 0; i < (int)h.size(); i++){
        tochki.push_back({i + 1, h[i]});
    }

    sort(tochki.begin(), tochki.end(), koiEPoNapred);

    nameriBroiNujniVarhove(tochki.size());

    long long broiDvoiki = 0;

    vector<int> zaDobavqne;

    int predenY = 0;

    for(int i = 0; i < tochki.size(); i++){
        if(predenY != tochki[i].y){
            while(zaDobavqne.empty() == false){
                update(zaDobavqne.back(), 1);
                zaDobavqne.pop_back();
            }
        }

        int doKadeNalqvo = kadeEToziNqlqvo(tochki[i].x, K);
        int broiNalqvo = query(doKadeNalqvo, tochki[i].x);
        int doKadeNadqsno = kadeEToziNadqsno(tochki[i].x, K, tochki.size());
        int broiNadqsno = query(tochki[i].x, doKadeNadqsno);

        //cout<<"ot "<<tochki[i].x<<" moje do "<<doKadeNalqvo<<" i do "<<doKadeNadqsno<<endl;

        broiDvoiki += (tochki[i].x - doKadeNalqvo - broiNalqvo) + (doKadeNadqsno - tochki[i].x - broiNadqsno);

        long long kolkoMahame = zaDobavqne.size() - kadeEPosledniqKoitoVlizaVIntervala(zaDobavqne, doKadeNalqvo);

        broiDvoiki -= kolkoMahame;


        predenY = tochki[i].y;
        zaDobavqne.push_back(tochki[i].x);
    }


    return broiDvoiki;
}
