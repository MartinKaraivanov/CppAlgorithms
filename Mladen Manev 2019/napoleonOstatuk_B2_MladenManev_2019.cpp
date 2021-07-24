#include<iostream>
#include<map>
using namespace std;

long long broiNachalniArmii;

map<long long, long long> broiSTakavaGolemina;

int broiZaqvki;

long long otgovor[100010];
int broiOtgovori;

long long maximalenBroiHoraVArmiqta;

long long kolkoSheOstanat(int horaVGvardiqta, int kolkoPariImame){
    long long cqloPari = kolkoPariImame / horaVGvardiqta;
    return kolkoPariImame - (cqloPari*horaVGvardiqta);
}

int main(){
    cin>>broiNachalniArmii;

    for(int i = 0; i < broiNachalniArmii; i++){
        long long golemina;
        long long broiTakiva;
        cin>>golemina>>broiTakiva;
        broiSTakavaGolemina[golemina] += broiTakiva;
        maximalenBroiHoraVArmiqta = max(maximalenBroiHoraVArmiqta, golemina);
    }

    cin>>broiZaqvki;

    for(int i = 0; i < broiZaqvki; i++){
        char tip;
        long long stoinost;
        cin>>tip>>stoinost;
        if(tip == '+'){
            broiSTakavaGolemina[stoinost]++;
            maximalenBroiHoraVArmiqta = max(maximalenBroiHoraVArmiqta, stoinost);
        }else{
            if(tip == '-'){
                if(broiSTakavaGolemina[stoinost] > 1){
                    broiSTakavaGolemina[stoinost]--;
                }else{
                    broiSTakavaGolemina.erase(stoinost);
                }
            }else{
                long long broiZaGeneralite = 0;
                for(auto j : broiSTakavaGolemina){
                    if(j.second == 0){
                        continue;
                    }
                    long long zasega = (j.second * kolkoSheOstanat(j.first, stoinost));
                    broiZaGeneralite += zasega;
                }

                otgovor[broiOtgovori] = broiZaGeneralite;
                broiOtgovori++;
            }
        }
    }

    for(int i = 0; i < broiOtgovori; i++){
        cout<<otgovor[i]<<endl;
    }

    return 0;
}
