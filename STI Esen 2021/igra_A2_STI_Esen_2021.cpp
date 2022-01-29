#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

int parvonachalnaDaljina;
int daljinaPodredica;

vector<int> parvonachalnaRedica;

map<vector<int>, int> priTolkova;

long long daiHash(vector<int> &redica){
    long long obshtoHash = 0;

    for(int i = 0; i < (int)redica.size(); i++){
        obshtoHash = (obshtoHash + ((long long)redica[i]*100007 + 2000)*(redica[i]*100007 + 3000)%100000000000007 + ((long long)i*100007+100)*(i*100007+200)*(i*100007+300)%100000000000007)%100000000000007;
    }

    return obshtoHash;
}

int naiDobriqOtgovor(set<int> &aktivniIndexi){
    if(aktivniIndexi.size() < daljinaPodredica){
        return 0;
    }

    //long long tukaHash = daiHash(redica);

    /*if(priTolkova.find(redica) != priTolkova.end()){
        return priTolkova[redica];
    }*/

    int naiDobroto = -1000000001;

    int sredenSbor = 0;

    queue<int> mahnatiTukaIndexi;

    set<int>::iterator iter = aktivniIndexi.begin();
    iter++;

    int broiIzbroeni = 0;

    while(broiIzbroeni < daljinaPodredica - 2){
        sredenSbor += parvonachalnaRedica[*iter];
        mahnatiTukaIndexi.push(*iter);
        iter = aktivniIndexi.erase(iter);
        broiIzbroeni++;
    }

    int broiMinatiIndexi = 0;
    int doKolkoVartim = (int)aktivniIndexi.size() - daljinaPodredica + 1;

    set<int>::iterator i = aktivniIndexi.begin();
    set<int>::iterator dalechenI = aktivniIndexi.begin();

    int kolkoVratki = 0;

    while(kolkoVratki < daljinaPodredica){
        dalechenI++;
        kolkoVratki++;
    }

    while(broiMinatiIndexi < doKolkoVartim){

        int tekushtSbor = -parvonachalnaRedica[*i]*parvonachalnaRedica[*dalechenI];

        if(broiMinatiIndexi == 0){

        }else{
            sredenSbor -= parvonachalnaRedica[*i];
            sredenSbor += parvonachalnaRedica[*dalechenI];
        }

        tekushtSbor += sredenSbor;

        int nadolu = naiDobriqOtgovor(aktivniIndexi);

        tekushtSbor += nadolu;

        naiDobroto = max(naiDobroto, tekushtSbor);

        i++;
        dalechenI++;
        broiMinatiIndexi++;
    }



    /*for(int i = 0; i < (int)aktivniIndexi.size() - daljinaPodredica + 1; i++){

        int tekushtSbor = -parvonachalnaRedica[aktivniIndexi[i]]*parvonachalnaRedica[aktivniIndexi[i + daljinaPodredica - 1]];

        //cout<<"nachalnioq teusht sbor e "<<tekushtSbor<<endl;

        if(i == 0){

        }else{
            sredenSbor -= parvonachalnaRedica[aktivniIndexi[i]];
            sredenSbor += parvonachalnaRedica[aktivniIndexi[i + daljinaPodredica - 2]];
        }

        tekushtSbor += sredenSbor;

        /*cout<<"seg asum v redica ";
        for(int a : redica){
            cout<<a<<" ";
        }

        cout<<"i gledam za ot index "<<i<<" do "<<i + daljinaPodredica - 1<<" i tekushtiqt sbor e "<<tekushtSbor<<endl;*/

        /*vector<int> novataRedica;

        for(int j = 0; j <= i; j++){
            novataRedica.push_back(redica[j]);
        }
        for(int j = i + daljinaPodredica - 1; j < (int)redica.size(); j++){
            novataRedica.push_back(redica[j]);
        }*/

        /*cout<<"novata redica za nadolu e ";

        for(int a : novataRedica){
            cout<<a<<" ";
        }
        cout<<endl;*/

    /*    int nadolu = naiDobriqOtgovor(aktivniIndexi);

        tekushtSbor += nadolu;

        naiDobroto = max(naiDobroto, tekushtSbor);
    }*/

    /*cout<<"za redica ";
    for(int a : redica){
        cout<<a<<" ";
    }
    cout<<"vrashtame "<<naiDobroto<<endl;*/

    //priTolkova[redica] = naiDobroto;

    return naiDobroto;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>parvonachalnaDaljina>>daljinaPodredica;

    for(int i = 0; i < parvonachalnaDaljina; i++){
        int tuka;
        cin>>tuka;

        parvonachalnaRedica.push_back(tuka);
    }

    set<int> aktivniIndexi;

    for(int i = 1; i <= parvonachalnaDaljina; i++){
        aktivniIndexi.insert(i);
    }

    cout<<naiDobriqOtgovor(aktivniIndexi)<<endl;

    return 0;
}
