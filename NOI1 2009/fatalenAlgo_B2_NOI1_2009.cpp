#include<iostream>
#include<cmath>
using namespace std;

int broiVaprosi;

string otgovori;

bool sastavnoLiE[1050];

void eratosten(){
    sastavnoLiE[1] = true;

    int korenKvadraten = sqrt(1001);

    for(int i = 2; i <= korenKvadraten + 1; i++){
        if(sastavnoLiE[i] == false){
            for(int j = i*i; j < 1001; j += i){
                sastavnoLiE[j] = true;
            }
        }
    }
}

int naiMalkotoProstoPoneNashto(int otKoe){
    int koeE = -1;

    for(int i = otKoe; true; i++){
        if(sastavnoLiE[i] == false){
            koeE = i;
            break;
        }
    }

    return koeE;
}

char koqBukvaETaqCifra(int cifra){
    if(cifra == 1){
        return 'a';
    }

    if(cifra == 2){
        return 'b';
    }

    if(cifra == 3){
        return 'c';
    }

    return 'd';
}

int main(){
    cin>>broiVaprosi;

    cin>>otgovori;

    eratosten();

    int naiMnogotoSavpadashti = 0;
    int priKoi = -1;

    for(int m = 1; m <= 1000; m++){
        int broiSavpadashtiTuk  = 0;
        int segChislo = m;

        cout<<m<<endl;

        for(int i = 0; i < broiVaprosi; i++){
            cout<<segChislo - min(i, 1)<<" ";
            segChislo = naiMalkotoProstoPoneNashto(segChislo);
            cout<<segChislo<<endl;

            int bukva = 0;

            while(segChislo%13 != 0){
                segChislo++;
                bukva++;
                bukva %= 4;
            }

            char tuka = koqBukvaETaqCifra((bukva + 2)%4);
            segChislo++;

            if(tuka == otgovori[i]){
                broiSavpadashtiTuk++;
            }

            cout<<i<<" "<<tuka<<endl;
        }
        cout<<broiSavpadashtiTuk<<endl;
        cout<<endl;

        if(broiSavpadashtiTuk > naiMnogotoSavpadashti){
            naiMnogotoSavpadashti = broiSavpadashtiTuk;
            priKoi = m;
        }

        if(naiMnogotoSavpadashti == broiVaprosi){
            break;
        }
    }

    cout<<priKoi<<endl;

    return 0;
}
