#include<iostream>
#include<cmath>
using namespace std;

long long dveNaTriista=pow(2, 30);

long long gramoveRodena;
long long gramoveZaStigane;
long long gramovePriQdene;
long long gramoveZagubaPriAkane;
long long brNchini[11000][3];

void zapalvane(){
    for(int i=0;i<=11000;i++){
        for(int p=0;p<3;p++){
            brNchini[i][p]=-1;
        }
    }
}

/*long long broiNachini(long long otGramove, long long doGramove, long long chrezDeistvie){
    /// 1 - papane
    /// 2 - akane

    if(brNchini[doGramove][chrezDeistvie]!=-1){
        return brNchini[doGramove][chrezDeistvie];
    }

    if(doGramove<otGramove){
        return 0;
    }

    if(doGramove==otGramove){
        if(chrezDeistvie==1){
            return 1;
        }else{
            return 0;
        }
    }


    long long brNachini=0;

    if(chrezDeistvie==1){
        long long tegloPrediQadene=doGramove-gramovePriQdene;
        brNachini=(broiNachini(otGramove, tegloPrediQadene, 2)+broiNachini(otGramove, tegloPrediQadene, 1))% dveNaTriista;
    }else{
        long long tegloPrediAkane = doGramove+gramoveZagubaPriAkane;
        if (tegloPrediAkane < gramoveZaStigane){
            brNachini = broiNachini(otGramove, tegloPrediAkane, 1);
        }
    }

    brNchini[doGramove][chrezDeistvie]=brNachini;
    return brNachini;
}*/

long long broiNachini2(long long otGramove, long long doGramove, long long chrezDeistvie){
    /// 1 - papane
    /// 2 - akane

    if(brNchini[otGramove][chrezDeistvie]!=-1){
        return brNchini[otGramove][chrezDeistvie];
    }

    if(doGramove<=otGramove){
        if (chrezDeistvie==1){
            return 1;
        }else{
            return 0;
        }
    }

    long long brNachini=0;

    if(chrezDeistvie==1){
        long long tegloSledQadene=otGramove+gramovePriQdene;
        brNachini=(broiNachini2(tegloSledQadene, doGramove, 2)+broiNachini2(tegloSledQadene, doGramove, 1))% dveNaTriista;
    }else{
        long long tegloSledAkane = otGramove-gramoveZagubaPriAkane;
        brNachini = broiNachini2(tegloSledAkane, doGramove, 1);
    }

    brNchini[otGramove][chrezDeistvie]=brNachini;
    return brNachini;
}

int main(){
    zapalvane();
    cin>>gramoveRodena>>gramoveZaStigane>>gramovePriQdene>>gramoveZagubaPriAkane;

    long long kolkoNachini= 0;


    kolkoNachini=broiNachini2(gramoveRodena, gramoveZaStigane , 1);

    cout<<kolkoNachini<<endl;

    return 0;
}
