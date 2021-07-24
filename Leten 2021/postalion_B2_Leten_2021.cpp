#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

long long maxY;
long long maxX;

struct Coordinati{
    long long y;
    long long x;
};

long long broiKrastovishta;
Coordinati krastovishta[100010];

bool poMalkoPoX(Coordinati a, Coordinati b){
    return a.x < b.x;
}

bool poMalkoPoY(Coordinati a, Coordinati b){
    return a.y < b.y;
}

long long razstoqnie(Coordinati otKade, Coordinati doKade){
    return abs(doKade.x - otKade.x) + abs(doKade.y - otKade.y);
}

int main(){
    cin>>maxY>>maxX;

    cin>>broiKrastovishta;

    for(long long i = 0; i < broiKrastovishta; i++){
        cin>>krastovishta[i].y>>krastovishta[i].x;
    }

    sort(krastovishta, krastovishta + broiKrastovishta, poMalkoPoX);

    long long ofisMinX = 0;
    long long ofisMaxX = 0;
    long long ofisMinY = 0;
    long long ofisMaxY = 0;

    if(broiKrastovishta % 2 == 1){
        ofisMinX = krastovishta[broiKrastovishta/2].x;
        ofisMaxX = ofisMinX;
    }else{
        ofisMinX = krastovishta[broiKrastovishta/2 - 1].x;
        ofisMaxX = krastovishta[broiKrastovishta/2].x;
    }

    sort(krastovishta, krastovishta + broiKrastovishta, poMalkoPoY);

    if(broiKrastovishta % 2 == 1){
        ofisMinY = krastovishta[broiKrastovishta/2].y;
        ofisMaxY = ofisMinY;
    }else{
        ofisMinY = krastovishta[broiKrastovishta/2 - 1].y;
        ofisMaxY = krastovishta[broiKrastovishta/2].y;
    }

    long long sumarnoRazstoqnie = 0;

    for(long long i = 0; i < broiKrastovishta; i++){
        sumarnoRazstoqnie += 2*razstoqnie(krastovishta[i], {ofisMinY, ofisMinX});
    }

    //cout<<"max x "<<ofisMaxX<<" max y "<<ofisMaxY<<endl;
    //cout<<"min x "<<ofisMinX<<" min y "<<ofisMinY<<endl;

    long long naiGolqmotoNaiMalkoRazst = 0;

    for(long long i = 0; i < broiKrastovishta; i++){
        long long parvoRazst = razstoqnie(krastovishta[i], {ofisMaxY, ofisMaxX});
        long long vtoroRazst = razstoqnie(krastovishta[i], {ofisMaxY, ofisMinX});
        long long tretoRazst = razstoqnie(krastovishta[i], {ofisMinY, ofisMaxX});
        long long chetvRazst = razstoqnie(krastovishta[i], {ofisMinY, ofisMinX});

        long long tekushto = max(max(parvoRazst, vtoroRazst), max(tretoRazst, chetvRazst));

        naiGolqmotoNaiMalkoRazst = max(naiGolqmotoNaiMalkoRazst, tekushto);
    }

    long long otgovor = sumarnoRazstoqnie - naiGolqmotoNaiMalkoRazst;

    cout<<otgovor<<endl;

    return 0;
}
