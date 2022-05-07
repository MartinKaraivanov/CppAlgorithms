#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

const long long mnogo = 1000000007;

long long broiVarhove;
long long broiRebra;

vector<long long> podchineni[1000010];
bool imaLiShef[1000010];
long long maxDalbochinaStignato[1000010];
long long bashta[1000010];

vector<long long> deca[1000010];
long long broiVPoddarvotoNa[1000010];

void dfsOprostqvane(long long segashenVrah, long long otKadeIdvame, long long segDalbochina){
    if(maxDalbochinaStignato[segashenVrah] < segDalbochina){
        maxDalbochinaStignato[segashenVrah] = segDalbochina;
        bashta[segashenVrah] = otKadeIdvame;
    }else{
        return ;
    }

    for(long long i = 0; i < (long long)podchineni[segashenVrah].size(); i++){
        dfsOprostqvane(podchineni[segashenVrah][i], segashenVrah, segDalbochina + 1);
    }
}

void nameriBroiPoddarvo(long long segashenVrah){

    for(long long i = 0; i < (long long)deca[segashenVrah].size(); i++){
        nameriBroiPoddarvo(deca[segashenVrah][i]);
        broiVPoddarvotoNa[segashenVrah] += broiVPoddarvotoNa[deca[segashenVrah][i]];
    }

    broiVPoddarvotoNa[segashenVrah]++;

}

long long umnoji(long long a, long long b){
    return (a*b)%mnogo;
}

long long stepenuvai(long long chislo, long long naKoqStepen){
    long long zaVrasht = 1;

    while(naKoqStepen > 0){
        if((naKoqStepen & 1) == 1){
            zaVrasht = umnoji(zaVrasht, chislo);
        }
        chislo = umnoji(chislo, chislo);

        naKoqStepen >>= 1;
    }

    return zaVrasht;
}

long long faktoriel[100010];
long long reciprochni[100010];

void nameriFaktorielite(){
    faktoriel[0] = 1;
    reciprochni[0] = stepenuvai(faktoriel[0], mnogo-2);
    for(long long i = 1; i <= broiVarhove; i++){
        faktoriel[i] = umnoji(faktoriel[i - 1], i);
        reciprochni[i] = stepenuvai(faktoriel[i], mnogo-2);
        //cout<<i<<" faktoriel "<<faktoriel[i]<<endl;
    }
}

long long razdeli(long long a, long long b){
    return umnoji(a, stepenuvai(b, mnogo - 2));
}

long long daiKombinaciq(long long otKolko, int kolko){
    return umnoji(umnoji(faktoriel[otKolko], reciprochni[kolko]), reciprochni[otKolko - kolko]);
}

long long broiNachiniPodredba(long long segashenVrah){

    long long zaTuka = 1;

    long long broqVDecata = broiVPoddarvotoNa[segashenVrah] - 1;

    for(long long i = 0; i < (long long)deca[segashenVrah].size(); i++){
        long long otgovorTozi = broiNachiniPodredba(deca[segashenVrah][i]);
        long long vPoddarvNaSledv = broiVPoddarvotoNa[deca[segashenVrah][i]];
        zaTuka = umnoji(zaTuka,otgovorTozi);
        //cout<<"umnojavame po otgovor "<<otgovorTozi<<" i za tuka stava ravno na "<<zaTuka<<endl;
        long long kombinaciqta = daiKombinaciq(broqVDecata, vPoddarvNaSledv);
        zaTuka = umnoji(zaTuka, kombinaciqta);
        //cout<<"umnojavame po kombinaciq "<<kombinaciqta<<" i za tuka stava ravno na "<<zaTuka<<endl;
        broqVDecata -= vPoddarvNaSledv;
    }

    return zaTuka;
}

int main(){

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    //cin>>broiVarhove>>broiRebra;

    scanf("%ld %ld", &broiVarhove, &broiRebra);

    for(long long i = 0; i < broiRebra; i++){
        long long shefa;
        long long podchineniq;
        //cin>>shefa>>podchineniq;

        scanf("%ld %ld", &shefa, &podchineniq);

        podchineni[shefa].push_back(podchineniq);
        imaLiShef[podchineniq] = true;
    }

    for(long long i = 1; i <= broiVarhove; i++){
        if(imaLiShef[i] == false){
            dfsOprostqvane(i, 0, 1);
        }
    }

    //cout<<"aaaaaaa"<<endl;

    for(long long i = 1; i <= broiVarhove; i++){
        deca[bashta[i]].push_back(i);
    }

    nameriBroiPoddarvo(0);

    nameriFaktorielite();

    long long otgovor = broiNachiniPodredba(0);

    //cout<<otgovor<<endl;
    printf("%ld \n", otgovor);

    return 0;
}
