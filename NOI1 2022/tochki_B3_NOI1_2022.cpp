#include<iostream>
using namespace std;

struct Koordinati{
    long long x;
    long long y;
};

long long broiTochki;

Koordinati tochki[100010];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiTochki;

    for(long long i = 0; i < broiTochki; i++){
        cin>>tochki[i].x>>tochki[i].y;
    }

    long long totalnoX = 0;
    long long totalnoY = 0;
    long long sborXDoTuk = 0;
    long long sborYDoTuk = 0;

    for(long long i = 0; i < broiTochki; i++){
        totalnoX += (broiTochki-1)*tochki[i].x*tochki[i].x;
        totalnoY += (broiTochki-1)*tochki[i].y*tochki[i].y;

        totalnoX -= 2*tochki[i].x*sborXDoTuk;
        totalnoY -= 2*tochki[i].y*sborYDoTuk;

        sborXDoTuk += tochki[i].x;
        sborYDoTuk += tochki[i].y;
    }

    long long totalno = totalnoX + totalnoY;

    cout<<totalno<<endl;

    return 0;
}
