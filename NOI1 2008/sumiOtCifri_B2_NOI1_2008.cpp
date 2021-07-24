#include<iostream>
using namespace std;

int chislo;

int sborNaCifriteVDvoichenZapis(int chi){

    int sborche = 1;

    while(chi > 1){
        int ost = chi%2;
        sborche+=ost;
        chi/=2;
    }

    return sborche;
}

int main(){
    cin>>chislo;

    int sumaOtVsichki = 0;

    for(int i = 1; i <= chislo; i++){
        sumaOtVsichki+=sborNaCifriteVDvoichenZapis(i);
    }

    cout<<sumaOtVsichki<<endl;

    return 0;
}
