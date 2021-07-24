#include<iostream>
#include<cmath>
using namespace std;

double koeChislo;

int naiBlizkoPoGolqmONaDesetDelqshtoSe(int chislo){
    if(chislo % 10 == 0){
        return chislo;
    }

    return (chislo/10)*10 + 10;
}

int main(){
    cin>>koeChislo;

    for(int strana = 10; strana >= 1; strana--){
        double srednoAritmetichno = koeChislo / (strana * strana);

        double x = (srednoAritmetichno*2 - (strana - 1)*11)/2;

        //cout<<strana<<" "<<srednoAritmetichno<<" "<<x<<endl<<endl;

        //int xche = x;
        if(x - floor(x) < 0.00001 && x > 0){
            int xche = x;
            if(xche + strana - 1 <= naiBlizkoPoGolqmONaDesetDelqshtoSe(xche)){
                cout<<x<<endl;
                break;
            }
        }

    }


    return 0;
}
