#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int broiSmetki;
int broiPlateni;

double smetki[1000100];
double plateni[1000010];


bool poMalkoLiE(double a, double b){
    return a > b;
}

int main(){
    cin>>broiSmetki>>broiPlateni;

    for(int i = 0; i < broiSmetki; i++){
        double cenichka;
        cin>>cenichka;

        smetki[i] = cenichka;
    }

    for(int i = 0; i < broiPlateni; i++){
        double platena;
        cin>>platena;

        plateni[i] = platena;
    }

    sort(smetki, smetki + broiSmetki, poMalkoLiE);
    sort(plateni, plateni + broiPlateni, poMalkoLiE);

    int poNeplatenite = 0;
    int poPlatenite = 0;

    while(poNeplatenite != broiSmetki && poPlatenite != broiPlateni){
        if(smetki[poNeplatenite] == plateni[poPlatenite]){
            poNeplatenite++;
            poPlatenite++;
            continue;
        }
        cout<<fixed<<setprecision(2)<<smetki[poNeplatenite]<<" ";
        poNeplatenite++;
    }

    cout<<endl;

    return 0;
}
