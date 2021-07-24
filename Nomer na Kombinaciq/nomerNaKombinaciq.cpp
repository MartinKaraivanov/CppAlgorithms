#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long long kolkoChislaIzbor;

long long kolkoCifrena;

vector<int> chisla;

long long koiNomer;

long long chisloNaStepen(long long koeChislo, long long naKoqStepen){
    long long rezultat = 1;

    long long hubavaStepen = koeChislo;
    long long copieNaKoqStepen = naKoqStepen;
    while(copieNaKoqStepen > 0){
        int ostatukPriDelenieNa2 = copieNaKoqStepen%2;
        rezultat *= max((long long)1, ostatukPriDelenieNa2*hubavaStepen);
        hubavaStepen *= hubavaStepen;
        copieNaKoqStepen /= 2;
    }

    return rezultat;
}

long long koiNomerEKombinaciqta(vector<int> chislanaKombinaciqta){
    long long nomer = 1;

    for(int i = 0; i < kolkoCifrena; i++){
        int zaTuk = (chislanaKombinaciqta[i] - 1)*(chisloNaStepen(kolkoChislaIzbor, kolkoChislaIzbor - (i + 1)));
        nomer += zaTuk;
    }

    return nomer;
}

vector<int> otNomerKamKomb(long long nomer){
    nomer--;

    vector<int> kombinaciqta;

    for(int i = 0; i < kolkoCifrena; i++){
        long long naKolkoDelime = chisloNaStepen(kolkoChislaIzbor, kolkoChislaIzbor - (i + 1));
        int zaTuk = nomer/naKolkoDelime + 1;
        kombinaciqta.push_back(zaTuk);
        nomer -= (nomer/naKolkoDelime)*naKolkoDelime;
    }

    return kombinaciqta;
}

int main(){
    cin>>kolkoChislaIzbor>>kolkoCifrena;

    /*for(unsigned int i = 0; i < kolkoCifrena; i++){
        long long tuka;
        cin>>tuka;
        chisla.push_back(tuka);
    }

    cin>>koiNomer;

    long long nomerNaKombinaciqta = koiNomerEKombinaciqta(chisla);

    cout<<nomerNaKombinaciqta<<endl;

    vector<int> kombinaciqtaNaNomera = otNomerKamKomb(koiNomer);

    for(int i = 0; i < kolkoCifrena; i++){
        cout<<kombinaciqtaNaNomera[i]<<" ";
    }

    cout<<endl;*/

    cout<<chisloNaStepen(kolkoChislaIzbor, kolkoCifrena);

    return 0;
}
