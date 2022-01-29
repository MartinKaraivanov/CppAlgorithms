#include<iostream>
using namespace std;

long long broiZaqvki;

struct DanniZaSnejenChovek{
    long long otKoiSePoluchi;
    long long naiGornaTopka;
    long long cqloTeglo;
};

DanniZaSnejenChovek snejniChoveci[1000010];

int main(){

    cin>>broiZaqvki;

    snejniChoveci[0] = {0, 0, 0};

    long long obshtoTeglo = 0;

    for(long long i = 1; i <= broiZaqvki; i++){
        long long otKoiChovek;
        long long gornaTopkaTip;

        cin>>otKoiChovek>>gornaTopkaTip;

        if(gornaTopkaTip > 0){
            snejniChoveci[i] = {otKoiChovek, gornaTopkaTip, snejniChoveci[otKoiChovek].cqloTeglo + gornaTopkaTip};
        }else{
            snejniChoveci[i] =
                {otKoiChovek,
                    snejniChoveci[snejniChoveci[otKoiChovek].otKoiSePoluchi].naiGornaTopka,
                    snejniChoveci[otKoiChovek].cqloTeglo - snejniChoveci[otKoiChovek].naiGornaTopka};
        }

        obshtoTeglo += snejniChoveci[i].cqloTeglo;
    }

    cout<<obshtoTeglo<<endl;

    return 0;
}
