#include<iostream>
#include<vector>
using namespace std;

const long long mnogo = 1000000007;

struct DanniZaVarha{
    long long nomerNaVarha;
    char bukvichka;
    long long kolkoSvarshvatTuk;
    vector<long long> decaNaTozi;
    long long kolkoOtDecataSaSEdno;
};

vector<DanniZaVarha> varhove;

void dobaviNov(char kluch[2010]){
    long long index = 0;
    long long segashen = 0;

    while(kluch[index] != '\0'){
        long long nov = -1;

        for(unsigned long long i = 0; i < varhove[segashen].decaNaTozi.size(); i++){
            long long tovaDete = varhove[segashen].decaNaTozi[i];
            if(varhove[tovaDete].bukvichka == kluch[index]){
                nov = varhove[tovaDete].nomerNaVarha;
                break;
            }
        }

        if(nov == -1){
            varhove.push_back({(signed long long)varhove.size(), kluch[index], 0, {}, 0});
            varhove[segashen].decaNaTozi.push_back((signed long long)varhove.size() - 1);
            nov = (signed long long)varhove.size() - 1;
        }

        //cout<<"sega sme na index "<<index<<" segashniq vrah e "<<segashen<<" a noviq e "<<nov<<endl;

        segashen = nov;

        index++;
    }

    //cout<<"sega nakraq sme v "<<segashen<<endl;
    varhove[segashen].kolkoSvarshvatTuk++;
}

long long podgotvqneNaDfsto(long long segashen){
    long long broiTuk = 0;

    for(unsigned long long i = 0; i < varhove[segashen].decaNaTozi.size(); i++){
        long long tovaDete = varhove[segashen].decaNaTozi[i];
        broiTuk = (broiTuk + podgotvqneNaDfsto(varhove[tovaDete].nomerNaVarha))%mnogo;
    }

    varhove[segashen].kolkoOtDecataSaSEdno = broiTuk;

    return (broiTuk + varhove[segashen].kolkoSvarshvatTuk)%mnogo;
}

long long dfsZaOtgovor(long long segashen){
    long long zaTuk = 0;

    for(unsigned long long i = 0; i < varhove[segashen].decaNaTozi.size(); i++){
        long long tovaDete = varhove[segashen].decaNaTozi[i];
        zaTuk = (zaTuk + dfsZaOtgovor(varhove[tovaDete].nomerNaVarha))%mnogo;
    }

    if(varhove[segashen].kolkoSvarshvatTuk >= 1){
       zaTuk = (zaTuk + varhove[segashen].kolkoSvarshvatTuk*varhove[segashen].kolkoOtDecataSaSEdno)%mnogo;
    }

    if(varhove[segashen].kolkoSvarshvatTuk > 1){
        zaTuk = (zaTuk + varhove[segashen].kolkoSvarshvatTuk*(varhove[segashen].kolkoSvarshvatTuk - 1)/2)%mnogo;
    }

    return zaTuk;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char kluch[2010];

    varhove.push_back({0, '0', 0, {}, 0});

    while(cin>>kluch){
        dobaviNov(kluch);
    }

    podgotvqneNaDfsto(0);

    /*for(long long i = 0; i < varhove.size(); i++){
        cout<<varhove[i].nomerNaVarha<<" "<<varhove[i].bukvichka<<" "<<varhove[i].kolkoSvarshvatTuk<<endl;
        for(auto j : varhove[i].decaNaTozi){
            cout<<j<<" ";
        }
        cout<<endl;
        cout<<varhove[i].kolkoOtDecataSaSEdno<<endl<<endl;
    }*/

    long long otgovor = dfsZaOtgovor(0);

    cout<<otgovor<<endl;

    return 0;
}
