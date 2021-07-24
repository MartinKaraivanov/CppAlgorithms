#include<iostream>
#include<vector>
using namespace std;

long long kolkoCifrena;

vector<int> chisla;

long long koiNomer;

long long factoriel[20];

void praveneNaFactoriel(){
    factoriel[0] = 1;

    for(int i = 1; i <= kolkoCifrena; i++){
        factoriel[i] = factoriel[i - 1]*i;
    }
}

long long koiNomerEPermutaciqta(vector<int> chislaNaPermutaciqta){
    long long nomer = 1;

    bool izpolzvanoLiE[20];

    for(int i = 0; i < 20; i++){
        izpolzvanoLiE[i] = false;
    }

    for(int i = 0; i < chislaNaPermutaciqta.size(); i++){
        izpolzvanoLiE[chislaNaPermutaciqta[i]] = true;
        int broi = 0;

        for(int j = 1; j < chislaNaPermutaciqta[i]; j++){
            if(izpolzvanoLiE[j] == false){
                broi++;
            }
        }

        long long zaTuk = factoriel[kolkoCifrena - i - 1]*broi;
        //cout<<i<<" "<<zaTuk<<endl;
        nomer += zaTuk;
    }

    return nomer;
}

vector<int> otNomerKamPermtaciq(long long nomer){
    nomer--;

    vector<int> permutaciq;

    bool izpolzvanoLiE[20];

    for(int i = 0; i < 20; i++){
        izpolzvanoLiE[i] = false;
    }

    for(int i = 0; i < kolkoCifrena; i++){
        int koeNeizplozvanoChislo = nomer/factoriel[kolkoCifrena - i - 1] + 1;

        int tuka = -1;
        int brNeIzpolvaniDoTuk = 0;

        for(int j = 1; j <= kolkoCifrena; j++){
            if(izpolzvanoLiE[j] == false){
                tuka = j;
                brNeIzpolvaniDoTuk++;
            }
            if(brNeIzpolvaniDoTuk == koeNeizplozvanoChislo){
                break;
            }
        }

        permutaciq.push_back(tuka);
        nomer -= (nomer/factoriel[kolkoCifrena - i - 1])*factoriel[kolkoCifrena - i - 1];
        izpolzvanoLiE[tuka] = true;
    }

    return permutaciq;
}

int main(){
    cin>>kolkoCifrena;

    for(unsigned int i = 0; i < kolkoCifrena; i++){
        long long tuka;
        cin>>tuka;
        chisla.push_back(tuka);
    }

    cin>>koiNomer;

    praveneNaFactoriel();

    long long nomerNaPermutaciqta = koiNomerEPermutaciqta(chisla);

    cout<<nomerNaPermutaciqta<<endl;

    vector<int> permutaciqtaNaNomera = otNomerKamPermtaciq(koiNomer);

    for(int i = 0; i < kolkoCifrena; i++){
        cout<<permutaciqtaNaNomera[i]<<" ";
    }

    cout<<endl;

    return 0;
}
