#include<iostream>
#include<queue>
using namespace std;

int maxX;
int maxY;

struct Saobshteniq{
    int xNaGorenLqvAgal;
    int yNaGorenLqvAgal;
    int nagore;
    int nastrani;
};

struct TochkiNaPravoagalnicite{
    int xGoreVLqvo;
    int yGoreVLqvo;
    int xDoluVDqsno;
    int yDoluVDqsno;
};

int zasichatLiSePravoagalnicite(int xGorenLqvParvi, int yGorenLqvParvi, int xDolenDesenParvi, int yDolenDesenParvi,
    int xGorenLqvVtori, int yGorenLqvVtori, int xDolenDesenVtori, int yDolenDesenVtori)
{
   if(((xGorenLqvVtori<=xGorenLqvParvi) && (xGorenLqvVtori>=xDolenDesenParvi) &&
        (yGorenLqvVtori<=yGorenLqvParvi) && (yGorenLqvVtori>=yDolenDesenParvi)))
    {
        return -1;
    }else{
        if((xDolenDesenVtori<xGorenLqvParvi) || (xGorenLqvVtori>xDolenDesenParvi) ||
           (yDolenDesenVtori<yGorenLqvParvi) || (yGorenLqvVtori>yDolenDesenParvi))
        {
            return 0;
        }else{
            return 1;
        }
    }
}

queue<TochkiNaPravoagalnicite> pravlagalnici;

void praveneNaPravoagalnici(Saobshteniq a){
    int xGorenLqvPalen=a.xNaGorenLqvAgal;
    int yGorenLqvPalen=a.yNaGorenLqvAgal;
    int xDolenDesenPalen=a.xNaGorenLqvAgal+a.nastrani-1;
    int yDolenDesenPalen=a.yNaGorenLqvAgal+a.nagore-1;

    int dalzhinaZaVartene=pravlagalnici.size();

    for(int i=0;i<dalzhinaZaVartene;i++){
        TochkiNaPravoagalnicite p=pravlagalnici.front();
        pravlagalnici.pop();

        int resultat=zasichatLiSePravoagalnicite(p.xGoreVLqvo, p.yGoreVLqvo, p.xDoluVDqsno, p.yDoluVDqsno,
            xGorenLqvPalen, yGorenLqvPalen, xDolenDesenPalen, yDolenDesenPalen);

        if(resultat==1){
            if(yGorenLqvPalen>p.yGoreVLqvo){
                TochkiNaPravoagalnicite novoZaPodavane={p.xGoreVLqvo, p.yGoreVLqvo, p.xDoluVDqsno,yGorenLqvPalen-1};
                pravlagalnici.push(novoZaPodavane);
            }
            if(yDolenDesenPalen<p.yDoluVDqsno){
                TochkiNaPravoagalnicite novoZaPodavane={p.xGoreVLqvo, yDolenDesenPalen+1, p.xDoluVDqsno, p.yDoluVDqsno};
                pravlagalnici.push(novoZaPodavane);
            }
            if(xGorenLqvPalen>p.xGoreVLqvo){
                TochkiNaPravoagalnicite novoZaPodavane={p.xGoreVLqvo, p.yGoreVLqvo, xGorenLqvPalen-1, p.yDoluVDqsno};
                pravlagalnici.push(novoZaPodavane);
            }
            if(xDolenDesenPalen<p.xDoluVDqsno){
                TochkiNaPravoagalnicite novoZaPodavane={xDolenDesenPalen+1, p.yGoreVLqvo, p.xDoluVDqsno, p.yDoluVDqsno};
                pravlagalnici.push(novoZaPodavane);
            }
        }else{
            if(resultat==0){
                pravlagalnici.push(p);
            }
        }
    }
}

int main(){
    cin>>maxX>>maxY;

    int broiSaobshteniq;

    cin>>broiSaobshteniq;

    Saobshteniq salpshteniq[broiSaobshteniq];

    for(int i=0;i<broiSaobshteniq;i++){
        cin>>salpshteniq[i].xNaGorenLqvAgal>>salpshteniq[i].yNaGorenLqvAgal>>salpshteniq[i].nastrani>>salpshteniq[i].nagore;
    }

    TochkiNaPravoagalnicite nachalno={0, 0, maxX-1, maxY-1};
    pravlagalnici.push(nachalno);

    for(int i=0;i<broiSaobshteniq;i++){
        praveneNaPravoagalnici(salpshteniq[i]);
    }

    int naiGolqmoLice=0;

    //cout<<pravlagalnici.size()<<endl;

    while(pravlagalnici.empty()==false){
        TochkiNaPravoagalnicite n=pravlagalnici.front();
        pravlagalnici.pop();
        //cout<<n.xGoreVLqvo<<" "<<n.yGoreVLqvo<<" "<<n.xDoluVDqsno<<" "<<n.yDoluVDqsno<<endl;
        int lice=(n.xDoluVDqsno-n.xGoreVLqvo+1)*(n.yDoluVDqsno-n.yGoreVLqvo+1);
        if(lice>naiGolqmoLice){
            naiGolqmoLice=lice;
        }
    }

    cout<<naiGolqmoLice<<endl;

    return 0;
}
