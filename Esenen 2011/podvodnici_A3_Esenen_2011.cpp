#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int broiPodvodnici;
int broiKomandi;

int dalbochini[10000010];

int komandi[1000010];

int nachalnoBroiPolucheni[10000010];

struct DanniZaDarvoto{
    int maxStoinost;
    int sborStoinost;
};

DanniZaDarvoto darvo[20000010];
int broiNujniVarhove;

void nameriBroiNujniVarhove(){
    for(int i = 1; true; i *= 2){
        if(i >= broiPodvodnici){
            broiNujniVarhove = i*2;
            break;
        }
    }
}

int daiListo(int index){
    return index + broiNujniVarhove/2;
}

void napraviDarvoto(){
    nameriBroiNujniVarhove();

    for(int i = 1; i <= broiPodvodnici; i++){
        darvo[daiListo(i - 1)] = {nachalnoBroiPolucheni[i], nachalnoBroiPolucheni[i]};
    }

    for(int i = daiListo(0) - 1; i >= 0; i--){
        darvo[i] = {max(darvo[i * 2].maxStoinost, darvo[i * 2 + 1].maxStoinost), darvo[i * 2].sborStoinost + darvo[i * 2 + 1].sborStoinost};
    }
}

void update(int koiIndex, int novo){
    darvo[daiListo(koiIndex - 1)] = {novo, novo};

    for(int i = daiListo(koiIndex - 1)/2; i > 0; i /= 2){
        darvo[i] = {max(darvo[i * 2].maxStoinost, darvo[i * 2 + 1].maxStoinost), darvo[i * 2].sborStoinost + darvo[i * 2 + 1].sborStoinost};
    }
}

DanniZaDarvoto query(int otKade, int doKade){
    int lqvIndex = daiListo(otKade - 1);
    int desenIndex = daiListo(doKade - 1);

    if(lqvIndex == desenIndex){
        return {darvo[lqvIndex].maxStoinost, darvo[lqvIndex].sborStoinost};
    }

    DanniZaDarvoto resultat = {max(darvo[lqvIndex].maxStoinost, darvo[desenIndex].maxStoinost), darvo[lqvIndex].sborStoinost + darvo[desenIndex].sborStoinost};

    while(lqvIndex + 1 < desenIndex){
        if(lqvIndex % 2 == 0){
            resultat = {max(resultat.maxStoinost, darvo[lqvIndex + 1].maxStoinost), resultat.sborStoinost + darvo[lqvIndex + 1].sborStoinost};
        }

        if(desenIndex % 2 == 1){
            resultat = {max(resultat.maxStoinost, darvo[desenIndex - 1].maxStoinost), resultat.sborStoinost + darvo[desenIndex - 1].sborStoinost};
        }

        lqvIndex /= 2;
        desenIndex /= 2;
    }

    return resultat;
}

int dalbokoDarvo[20000010];

void napraviDalbokotoDarvo(){

    for(int i = 1; i <= broiPodvodnici; i++){
        dalbokoDarvo[daiListo(i - 1)] = dalbochini[i];
    }

    for(int i = daiListo(0) - 1; i >= 0; i--){
        dalbokoDarvo[i] = max(dalbokoDarvo[i * 2], dalbokoDarvo[i * 2 + 1]);
    }
}

void updateDalboko(int koiIndex, int novo){
    dalbokoDarvo[daiListo(koiIndex - 1)] = novo;

    for(int i = daiListo(koiIndex - 1)/2; i > 0; i /= 2){
        dalbokoDarvo[i] = max(dalbokoDarvo[i * 2], dalbokoDarvo[i * 2 + 1]);
    }
}

int queryDalboko(int otKade, int doKade){
    int lqvIndex = daiListo(otKade - 1);
    int desenIndex = daiListo(doKade - 1);

    int resultat = max(dalbokoDarvo[lqvIndex], dalbokoDarvo[desenIndex]);

    while(lqvIndex + 1 < desenIndex){
        if(lqvIndex % 2 == 0){
            resultat = max(resultat, dalbokoDarvo[lqvIndex + 1]);
        }

        if(desenIndex % 2 == 1){
            resultat = max(resultat, dalbokoDarvo[desenIndex - 1]);
        }

        lqvIndex /= 2;
        desenIndex /= 2;
    }

    return resultat;
}

int sledvashtiqPoNisukOt(int otKoi, int start){

    int lqvKrai = start;
    int desenkrai = broiPodvodnici;

    while(lqvKrai < desenkrai){
        int sredata = (lqvKrai + desenkrai)/2;

        int tuka = queryDalboko(start, sredata);

        if(tuka > queryDalboko(otKoi, otKoi)){
            desenkrai = sredata;
        }else{
            lqvKrai = sredata + 1;
        }
    }

    if(queryDalboko(lqvKrai, lqvKrai) > queryDalboko(otKoi, otKoi)){
        return lqvKrai;
    }

    /*for(int i = start; i <= broiPodvodnici; i++){
        if(dalbochini[i] > dalbochini[otKoi]){
            return i;
        }
    }*/

    return 0;
}

int parviqNalqvoPoDalbokOt(int otKoi, int start){

    int lqvKrai = 1;
    int desenKrai = start;

    while(lqvKrai < desenKrai){

        int sredata = (lqvKrai + desenKrai)/2;

        int tuka = queryDalboko(sredata, start);

        //cout<<"sredata e "<<sredata<<" i nai visokata do neq e "<<tuka<<endl;

        if(tuka >= queryDalboko(otKoi, otKoi)){
            //cout<<"skasqvame kum nas"<<endl;
            lqvKrai = sredata + 1;
        }else{
            desenKrai = sredata;
            //cout<<"otdalechavame ot nas"<<endl;
        }
    }

    //cout<<"leviq krai e "<<lqvKrai<<endl;

    if(queryDalboko(lqvKrai, lqvKrai) > queryDalboko(otKoi, otKoi)){
        return lqvKrai;
    }

    if(queryDalboko(lqvKrai - 1, lqvKrai - 1) > queryDalboko(otKoi, otKoi)){
        return lqvKrai - 1;
    }

    return 0;
}

void promqnaNaIndex(int index){
    int leviq = index;

    /////// todo: proverka za ravno => nishto da ne pravim ako sa ravni

    if(dalbochini[leviq] == dalbochini[leviq + 1]){
        return ;
    }

    int broiVLqvoto = query(leviq, leviq).maxStoinost;
    int broiVDqsnoto = query(leviq + 1, leviq + 1).maxStoinost;

    int novBroiLqvo = -1;
    int novBroiDqsno = -1;

    //cout<<"zavartame "<<leviq<<" i "<<leviq + 1<<endl;

    if(dalbochini[leviq] > dalbochini[leviq + 1]){

        //cout<<"sega lecviq e po nisuk ot desniq"<<endl;

        int vKoi = sledvashtiqPoNisukOt(leviq + 1, leviq + 2);

        if(vKoi != 0){
            update(vKoi, query(vKoi, vKoi).maxStoinost - 1);

            //cout<<"na "<<vKoi<<" mu mahnahme 1"<<endl;
        }

        int dokadeVartim = parviqNalqvoPoDalbokOt(leviq + 1, leviq - 1);

        /*int naiNiskataDalbPr = 0;
        novBroiLqvo = broiVDqsnoto;

        for(int j = leviq - 1; j > dokadeVartim; j--){

            if(dalbochini[j] > naiNiskataDalbPr){
                naiNiskataDalbPr = dalbochini[j];

                if(naiNiskataDalbPr < dalbochini[leviq + 1]){
                    novBroiLqvo++;
                    //cout<<"okazva se che "<<j<<" she prashta kum noviq lqv"<<endl;
                }
            }
        }*/

        //cout<<"dokadeVartim e "<<dokadeVartim<<" a dqsnata granica e "<<leviq<<endl;

        //cout<<"pri bavnoto e "<<novBroiLqvo<<endl;


        //cout<<"mejdu "<<dokadeVartim<<" i "<<leviq<<" ima "<<query(dokadeVartim + 1, leviq - 1).sborStoinost<<" vlizashti"<<endl;

        if(dokadeVartim + 1 <= leviq - 1){
            //cout<<"pri umnoto e "<<(leviq - dokadeVartim - 1) - (query(dokadeVartim + 1, leviq - 1).sborStoinost)<<endl;
            novBroiLqvo = (leviq - dokadeVartim - 1) - (query(dokadeVartim + 1, leviq - 1).sborStoinost);
        }else{

            novBroiLqvo = 0;
            //cout<<"pri umnoto e "<<0<<endl;
        }

        //cout<<endl;

        novBroiDqsno = broiVDqsnoto + broiVLqvoto - novBroiLqvo + 1;

    }else{

        novBroiLqvo = broiVLqvoto + broiVDqsnoto - 1;
        novBroiDqsno = 0;

        int vKoi = sledvashtiqPoNisukOt(leviq, leviq + 2);

        if(vKoi != 0){
            update(vKoi, query(vKoi, vKoi).maxStoinost + 1);
            //cout<<vKoi<<" poluchi bonusche"<<endl;
        }

    }

    //cout<<"novite stoinosti sa "<<novBroiLqvo<<" "<<novBroiDqsno<<endl;

    update(leviq, novBroiLqvo);
    update(leviq + 1, novBroiDqsno);

    swap(dalbochini[leviq], dalbochini[leviq + 1]);
    updateDalboko(leviq, dalbochini[leviq]);
    updateDalboko(leviq + 1, dalbochini[leviq + 1]);

    /*for(int i = 1; i <= broiPodvodnici; i++){
        cout<<dalbochini[i]<<" ";
    }
    cout<<endl<<endl;*/

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiPodvodnici>>broiKomandi;

    for(int i = 1; i <= broiPodvodnici; i++){
        cin>>dalbochini[i];
    }

    for(int i = 0; i < broiKomandi; i++){
        cin>>komandi[i];
    }

    stack<int> s;

    for(int j = 1; j <= broiPodvodnici; j++){
        int taziKolkoPoluchava = 0;

        while(s.empty() == false){
            if(dalbochini[s.top()] < dalbochini[j]){
                taziKolkoPoluchava++;

                //cout<<"slojihme che "<<s.top()<<" prashta do "<<j<<endl;

                s.pop();
            }else{
                break;
            }
        }

        s.push(j);

        nachalnoBroiPolucheni[j] = taziKolkoPoluchava;
    }


    napraviDarvoto();
    napraviDalbokotoDarvo();

    for(int i = 0; i < broiKomandi; i++){
        if(komandi[i] > 0){

            promqnaNaIndex(komandi[i]);

        }else{
            cout<<query(1, broiPodvodnici).maxStoinost<<endl;
        }
    }


    return 0;
}
