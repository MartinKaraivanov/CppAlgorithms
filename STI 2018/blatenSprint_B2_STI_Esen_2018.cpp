#include<iostream>
#include<vector>
#include<queue>
using namespace std;

long long broiOstrovcheta;
long long broiPatechki;

long long start;
long long finish;

struct Danni{
    long long doOstrovche;
    long long razstoqnie;
};

vector<Danni> zaeshkoSasedstvo[10100];
vector<Danni> kostenurskoSasedstvo[10100];

long long naiKasZaehkiPat[10100];
bool zaeshkoVisited[10100];
long long zaeshkiRoditel[10100];
bool minavaLiOtTukZaicheto[10100];

long long naiKasKostenurskiPat[10100];
bool kostenurskoVisited[10100];
long long kostenurskiRoditel[10100];
bool minavaLiOtTukKostenurcheto[10100];

struct DanniZaOpashkata{
    long long doOstrovche;
    long long razstoqnie;
    long long roditel;

    DanniZaOpashkata(long long doOstrovche, long long razstoqnie, long long roditel)
        : doOstrovche(doOstrovche), razstoqnie(razstoqnie), roditel(roditel)
    {

    }
};

struct KoiEPoNablizo{
    bool operator()(DanniZaOpashkata const& a, DanniZaOpashkata const& b)
    {
        return a.razstoqnie > b.razstoqnie;
    }
};

long long namiraneNaZaeshkiPat(){
    priority_queue<DanniZaOpashkata, vector<DanniZaOpashkata>, KoiEPoNablizo> q;

    q.push({start, 0, 0});

    long long otgovor = -1;

    while(q.empty() == false){
        DanniZaOpashkata naiOtgore = q.top();
        q.pop();

        if(zaeshkoVisited[naiOtgore.doOstrovche] == true){
            continue;
        }

        zaeshkoVisited[naiOtgore.doOstrovche] = true;
        naiKasZaehkiPat[naiOtgore.doOstrovche] = naiOtgore.razstoqnie;
        zaeshkiRoditel[naiOtgore.doOstrovche] = naiOtgore.roditel;

        if(naiOtgore.doOstrovche == finish){
            otgovor = naiOtgore.razstoqnie;
            break;
        }

        for(unsigned long long i = 0; i < zaeshkoSasedstvo[naiOtgore.doOstrovche].size(); i++){
            Danni sledvasht = zaeshkoSasedstvo[naiOtgore.doOstrovche][i];
            if(zaeshkoVisited[sledvasht.doOstrovche] == false){
                q.push({sledvasht.doOstrovche, naiOtgore.razstoqnie + sledvasht.razstoqnie, naiOtgore.doOstrovche});
            }
        }
    }

    return otgovor;
}

long long namiraneNaKostenurskiPat(){
    priority_queue<DanniZaOpashkata, vector<DanniZaOpashkata>, KoiEPoNablizo> q;

    q.push({start, 0, 0});

    long long otgovor = -1;

    while(q.empty() == false){
        DanniZaOpashkata naiOtgore = q.top();
        q.pop();

        if(kostenurskoVisited[naiOtgore.doOstrovche] == true){
            continue;
        }

        kostenurskoVisited[naiOtgore.doOstrovche] = true;
        naiKasKostenurskiPat[naiOtgore.doOstrovche] = naiOtgore.razstoqnie;
        kostenurskiRoditel[naiOtgore.doOstrovche] = naiOtgore.roditel;

        if(naiOtgore.doOstrovche == finish){
            otgovor = naiOtgore.razstoqnie;
            break;
        }

        for(unsigned long long i = 0; i < kostenurskoSasedstvo[naiOtgore.doOstrovche].size(); i++){
            Danni sledvasht = kostenurskoSasedstvo[naiOtgore.doOstrovche][i];
            if(kostenurskoVisited[sledvasht.doOstrovche] == false){
                q.push({sledvasht.doOstrovche, naiOtgore.razstoqnie + sledvasht.razstoqnie, naiOtgore.doOstrovche});
            }
        }
    }

    return otgovor;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiOstrovcheta;
    cin>>broiPatechki;

    for(long long i = 0; i < broiPatechki; i++){
        long long otOst;
        long long doOst;
        long long razst;
        long long vid;

        cin>>otOst>>doOst>>razst>>vid;

        Danni zaDobKamOTkostenurka = {doOst, razst*(long long)2};
        Danni zaDobKamDOkostenurka = {otOst, razst*(long long)2};

        kostenurskoSasedstvo[otOst].push_back(zaDobKamOTkostenurka);
        kostenurskoSasedstvo[doOst].push_back(zaDobKamDOkostenurka);

        if(vid == 1){
            Danni otZaikovci = {doOst, razst};
            Danni doZaikovci = {otOst, razst};

            zaeshkoSasedstvo[otOst].push_back(otZaikovci);
            zaeshkoSasedstvo[doOst].push_back(doZaikovci);
        }

    }

    cin>>start>>finish;

    long long zaeshkiOtgovor = namiraneNaZaeshkiPat();

    long long kostenurskiOtgovor = namiraneNaKostenurskiPat();

    for(long long i = finish; i != start; i = zaeshkiRoditel[i]){
        minavaLiOtTukZaicheto[i] = true;
    }

    for(long long i = finish; i != start; i = kostenurskiRoditel[i]){
        minavaLiOtTukKostenurcheto[i] = true;
    }

    long long broiZasichaniq = 0;

    for(long long i = 1; i <= broiOstrovcheta; i++){
        if(minavaLiOtTukZaicheto[i] == true && minavaLiOtTukKostenurcheto[i] == true){
            if(naiKasZaehkiPat[i] == naiKasKostenurskiPat[i]){
                broiZasichaniq++;
            }
        }
    }

    if(zaeshkiOtgovor < kostenurskiOtgovor){
        cout<<"Rabbit"<<endl;
        cout<<zaeshkiOtgovor<<endl;
    }else{
        if(kostenurskiOtgovor < zaeshkiOtgovor){
            cout<<"Tortoise"<<endl;
            cout<<kostenurskiOtgovor<<endl;
        }else{
            cout<<"Tie"<<endl;
            cout<<zaeshkiOtgovor<<endl;
            broiZasichaniq--;
        }
    }

    cout<<broiZasichaniq<<endl;

    return 0;
}
