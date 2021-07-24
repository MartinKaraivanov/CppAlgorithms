#include<iostream>
using namespace std;

int normalni[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
string simvol[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

string prevarni(int arabsko){
    int i = 12;

    int copieArabsko = arabsko;

    string rimsko = "";

    while(copieArabsko > 0){
        int kolkoPati = copieArabsko/normalni[i];
        copieArabsko = copieArabsko%normalni[i];

        for(int j = 0; j < kolkoPati; j++){
            rimsko = rimsko + simvol[i];
        }

        i--;
    }

    return rimsko;
}

int main(){
    int arabskoCHislo;
    cin>>arabskoCHislo;

    string rimskoChislo = prevarni(arabskoCHislo);

    cout<<rimskoChislo<<endl;

    return 0;
}
