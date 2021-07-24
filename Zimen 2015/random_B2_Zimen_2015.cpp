#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct DanniZaChastta{
    int naiMalakElement;
    int naiGolqmElement;
};

const int mnogo = 1000000001;

int redichka[5000010];

DanniZaChastta podredichki[6000010];

inline int broiNaChislataVEndaPodredichka(int naiMalko, int naiGolqmo, int broiNaChislataVRedichkata){
    return (naiGolqmo - naiMalko)/(broiNaChislataVRedichkata - 1);
}

inline int vKoqPodredichkaE(int chislo, int naiMalko, int broiVEdnaPodredichka){
    return (chislo - naiMalko)/broiVEdnaPodredichka;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int broiTestove;

    cin>>broiTestove;

    for(int t = 0; t < broiTestove; t++){
        int broiChislaVRedichkata;
        int a;
        int b;
        int c;
        int xNula;

        a%=c;
        b%=c;

        cin>>broiChislaVRedichkata>>a>>b>>c>>xNula;

        redichka[0] = xNula;

        for(int i = 1; i < broiChislaVRedichkata; i++){
            int sledvahsto = (((long long)a * redichka[i - 1]) % c + b)%c;
            redichka[i] = sledvahsto;
        }

        int naiMalkoChislo = mnogo;
        int naiGolqmoChislo = 0;

        for(int i = 0; i < broiChislaVRedichkata; i++){
            naiMalkoChislo = min(naiMalkoChislo, redichka[i]);
            naiGolqmoChislo = max(naiGolqmoChislo, redichka[i]);
        }

        if(naiGolqmoChislo == naiMalkoChislo){
            cout<<0<<endl;
            continue;
        }

        //cout<<naiGolqmoChislo<<" "<<naiMalkoChislo<<endl;

        int broiVEdnaPodredichka = broiNaChislataVEndaPodredichka(naiMalkoChislo, naiGolqmoChislo, broiChislaVRedichkata);

        //cout<<"broqt v edna podredichka e "<<broiVEdnaPodredichka<<endl;

        int broiPodredichki = vKoqPodredichkaE(naiGolqmoChislo, naiMalkoChislo, broiVEdnaPodredichka) + 1;

        //cout<<"broq na podredickite e "<<broiPodredichki<<endl;

        for(int i = 0; i < broiPodredichki; i++){
            podredichki[i].naiGolqmElement = -1;
            podredichki[i].naiMalakElement = mnogo;
        }

        for(int i = 0; i < broiChislaVRedichkata; i++){
            int vKoqPodredichkaETozi =
                vKoqPodredichkaE(redichka[i], naiMalkoChislo, broiVEdnaPodredichka);

            //cout<<redichka[i]<<" "<<vKoqPodredichkaETozi<<endl;

            podredichki[vKoqPodredichkaETozi].naiMalakElement =
                min(podredichki[vKoqPodredichkaETozi].naiMalakElement, redichka[i]);
            podredichki[vKoqPodredichkaETozi].naiGolqmElement =
                max(podredichki[vKoqPodredichkaETozi].naiGolqmElement, redichka[i]);
        }

        int naiGolqmaRazkrachenost = podredichki[0].naiGolqmElement - podredichki[0].naiMalakElement;

        int prednoto = podredichki[0].naiGolqmElement;

        for(int i = 1; i < broiPodredichki; i++){
            if(podredichki[i].naiGolqmElement == -1){
                continue;
            }

            naiGolqmaRazkrachenost = max(naiGolqmaRazkrachenost, podredichki[i].naiMalakElement - prednoto);
            prednoto = podredichki[i].naiGolqmElement;
        }

        //cout<<"broqt na chislata v intervalite obshto e "<<sumarenBroiNaChislataVIntervalite<<endl;

        cout<<naiGolqmaRazkrachenost<<endl;
    }
    return 0;
}
