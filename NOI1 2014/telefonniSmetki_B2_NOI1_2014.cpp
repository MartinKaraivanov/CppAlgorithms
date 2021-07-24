#include<iostream>
#include<map>
#include<algorithm>
#include<iomanip>
using namespace std;

int broiSmetki;
int broiPlateni;

double unplateni[2000000];
int broiche;

map<double, int> nePlateni;

bool poMalkoLiE(double a, double b){
    return a > b;
}

int main(){
    cin>>broiSmetki>>broiPlateni;

    for(int i = 0; i < broiSmetki; i++){
        double cenichka;
        cin>>cenichka;
        nePlateni[cenichka]++;
    }

    for(int i = 0; i < broiPlateni; i++){
        double platena;
        cin>>platena;

        nePlateni[platena]--;
    }

    for(map<double, int>::iterator sm = nePlateni.begin(); sm != nePlateni.end(); sm++){
        for(int i = 0; i < sm->second; i++){
            unplateni[broiche] = sm->first;
            broiche++;
        }
    }

    sort(unplateni, unplateni+broiche, poMalkoLiE);

    for(int i = 0; i < broiche; i++){
        cout<<fixed<<setprecision(2)<<unplateni[i]<<" ";
    }

    cout<<endl;

    return 0;
}
