#include<iostream>
#include<string>
#include<vector>
using namespace std;

string cqlo;
string tarsime;

int kolkoPati;

int daljinaCqlo;
int daljinaTarsime;

vector<int> indexiNaKoitoSeSreshta;

int sTakavaDaljina(int dal){
    int broiOk = 0;
    int posledenIndexOk = 0;

    for(unsigned int j = 0; j < indexiNaKoitoSeSreshta.size(); j++){
        int segIndex = indexiNaKoitoSeSreshta[j];

        if(posledenIndexOk + daljinaTarsime + dal <= segIndex){
            broiOk++;
            posledenIndexOk = indexiNaKoitoSeSreshta[j];
        }
    }

    return broiOk;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>cqlo;
    cin>>tarsime;
    cin>>kolkoPati;

    int segashenIdx = -1;
    bool parvotoLiE = true;

    while(segashenIdx != -1 || parvotoLiE == true){
        int nov = cqlo.find(tarsime, segashenIdx + 1);
        if(nov != -1){
            indexiNaKoitoSeSreshta.push_back(nov);
        }
        segashenIdx = nov;
        parvotoLiE = false;
    }

    daljinaCqlo = cqlo.size();
    daljinaTarsime = tarsime.size();

    int lqvKrai = 0;
    int desenKrai = daljinaCqlo;

    while(lqvKrai + 1 < desenKrai){
        int dal = (lqvKrai + desenKrai)/2;

        int broiOk = sTakavaDaljina(dal);

        if(broiOk < kolkoPati - 1){
            desenKrai = dal;
        }else{
            lqvKrai = dal;
        }
    }

    int otgovor = lqvKrai;

    cout<<otgovor<<endl;

    return 0;
}
