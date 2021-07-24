#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int broiZoni;
    cin>>broiZoni;

    string vidZona[broiZoni];
    int gorenLqvX[broiZoni];
    int gorenLqvY[broiZoni];
    int dalzhinaNaStrani[broiZoni];
    int shirinaNaDolu[broiZoni];
    double cenaZaMinuta[broiZoni];

    for(int i=0;i<broiZoni;i++){
        cin>>vidZona[i]>>gorenLqvX[i]>>gorenLqvY[i]>>dalzhinaNaStrani[i]>>shirinaNaDolu[i]>>cenaZaMinuta[i];
    }

    int broiSvobodniMesta;
    cin>>broiSvobodniMesta;

    int xNaSvobodnoMqsto[broiSvobodniMesta];
    int yNaSvobodnoMqsto[broiSvobodniMesta];

    for(int i=0;i<broiSvobodniMesta;i++){
        cin>>xNaSvobodnoMqsto[i]>>yNaSvobodnoMqsto[i];
    }

    int xNaTarget;
    int yNaTarget;

    cin>>xNaTarget>>yNaTarget;

    int vremeZaPreminavanePrezBlokche;

    cin>>vremeZaPreminavanePrezBlokche;

    int vremePrestoi[broiSvobodniMesta];

    for(int i=0;i<broiSvobodniMesta;i++){
        int razstoqnieVDvetePosokiZaIzminavane=(abs(xNaTarget-xNaSvobodnoMqsto[i])+abs(yNaTarget-yNaSvobodnoMqsto[i]))*2;
        double vreme=(razstoqnieVDvetePosokiZaIzminavane*vremeZaPreminavanePrezBlokche)/60;
        int vrPrest=ceil(vreme);
        vremePrestoi[i]=vrPrest;
    }

    double cenaZaPrestoi[broiSvobodniMesta];
    string zonichki[broiSvobodniMesta];

    for(int svMqsto=0;svMqsto<broiSvobodniMesta;svMqsto++){
        for(int zona=0;zona<broiZoni;zona++){
            if( (xNaSvobodnoMqsto[svMqsto]>=gorenLqvX[zona]) &&
                (xNaSvobodnoMqsto[svMqsto]<gorenLqvX[zona]+dalzhinaNaStrani[zona]) &&
                (yNaSvobodnoMqsto[svMqsto]>=gorenLqvY[zona]) &&
                (yNaSvobodnoMqsto[svMqsto]<gorenLqvY[zona]+shirinaNaDolu[zona]))
            {
                double cenata=vremePrestoi[svMqsto]*cenaZaMinuta[zona];
                cenaZaPrestoi[svMqsto]=cenata;
                zonichki[svMqsto]=vidZona[zona];
            }
        }
    }

    string zonaNaNaiDobroto;
    int xNaNaiDobroto;
    int yNaNaiDobroto;
    double cenaNaNaiDobroto=1000000;

    for(int i=0;i<broiSvobodniMesta;i++){
        if(cenaZaPrestoi[i]<cenaNaNaiDobroto){
            cenaNaNaiDobroto=cenaZaPrestoi[i];
            xNaNaiDobroto=xNaSvobodnoMqsto[i];
            yNaNaiDobroto=yNaSvobodnoMqsto[i];
            zonaNaNaiDobroto=zonichki[i];
        }
    }

    cout<<"Zone type: "<<zonaNaNaiDobroto<<"; X: "<<xNaNaiDobroto<<"; Y: "<<yNaNaiDobroto<<"; Price: "<<cenaNaNaiDobroto<<endl;

    return 0;
}
