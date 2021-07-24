#include<iostream>
#include<cmath>
using namespace std;

bool composite[100000000];
bool prosti[100000000];
long long n=100000000;

void eratosten(){
    int sqrt_n=sqrt(n);
    for(int i=2; i < sqrt_n ; i++){
        if(!composite[i]){
            for(int x=i*i;x<n;x+=i){
                composite[x]=true;
            }
        }
    }

    for(int i=2;i<n;i++){
        if(composite[i]==false){
            prosti[i]=true;
        }
    }
}

int kolkoNuliImaVNachaloto(string cifriNaChislo){
    int kolkoN=0;
    for(int j=cifriNaChislo.size()-2;j>=0;j--){
        if(cifriNaChislo[j]=='0'){
            kolkoN++;
        }else{
            break;
        }
    }

    return kolkoN;
}

string sabiraneNaDvaStringa(string str1, string str2){
    return str1+str2;
}

string otChisloKamString(long long chislo){
    string novoChislo;

    while(chislo>0){
        novoChislo+=chislo%10+'0';
        chislo/=10;
    }

    return novoChislo;
}

string otChisloKamNormalenStringNeNaobratno(long long chislo){
    string novoChislo;

    while(chislo>0){
        char novaCifrichka='0'+chislo%10;
        novoChislo= novaCifrichka + novoChislo;
        chislo/=10;
    }

    return novoChislo;
}

int otStringKamChislo(string cifriNaChislo, int bezKoiElement){
    long long chislo=0;

    int start;

    if((bezKoiElement==0) && (kolkoNuliImaVNachaloto(cifriNaChislo)>0)){
        int kolkoN=kolkoNuliImaVNachaloto(cifriNaChislo);
        start=cifriNaChislo.size()-1-kolkoN;
    }else{
        start=cifriNaChislo.size()-1;
    }

    for(int i=start;i>=0;i--){
        if(i!=cifriNaChislo.size()-bezKoiElement-1){
            chislo=chislo*10+(cifriNaChislo[i]-'0');
        }
    }

    return chislo;
}

void vsichkiVazmozhniChislaZaPoluchavane(long long chis){
    string chi=otChisloKamString(chis);

    for(int c=0;c<chi.size();c++){
        long long chislo=otStringKamChislo(chi, c);

        if(chislo>0){

            cout<<chislo;

            cout<<endl;
        }

        vsichkiVazmozhniChislaZaPoluchavane(chislo);
    }

}

int brVazmProsti(long long chis){
    string chi=otChisloKamString(chis);

    int broiVazmozhniProsti=0;

    for(int c=0;c<chi.size();c++){
        long long chislo=otStringKamChislo(chi, c);

        cout<<chislo;

        if(prosti[chislo]==true){
            broiVazmozhniProsti++;
            cout<<" prosto";
        }

        cout<<endl;
    }

    cout<<broiVazmozhniProsti<<endl;
}

int kolkoNaiMnogoProsti(long long chis){
    string chi=otChisloKamString(chis);

    if(chi.size()==0){
        return 0;
    }

    int prostiPoluch[chi.size()];

    for(int k=0;k<chi.size();k++){
        prostiPoluch[k]=0;
    }

    for(int c=0;c<chi.size();c++){
        long long chislo=otStringKamChislo(chi, c);
        bool prostoLiE=false;

        if(prosti[chislo]==true){
            prostoLiE=true;
        }

        if(prostoLiE==true){
            prostiPoluch[c]=1+kolkoNaiMnogoProsti(chislo);
        }else{
            prostiPoluch[c]=kolkoNaiMnogoProsti(chislo);
        }
    }

    int naiMnogoProstiPolucheni=0;

    for(int i=0;i<chi.size();i++){
        if(prostiPoluch[i]>naiMnogoProstiPolucheni){
            naiMnogoProstiPolucheni=prostiPoluch[i];
        }
    }

    return naiMnogoProstiPolucheni;
}

int main(){
    eratosten();

    int broiChisla;

    cin>>broiChisla;

    long long naChislo[broiChisla];

    for(int i=0;i<broiChisla;i++){
        cin>>naChislo[i];
    }

    int otgovori[broiChisla];

    for(int i=0;i<broiChisla;i++){
        int naiMnogoProsti=kolkoNaiMnogoProsti(naChislo[i]);

        if(prosti[naChislo[i]]==true){
            naiMnogoProsti+=1;
        }

        otgovori[i]=naiMnogoProsti;
    }

    for(int i=0;i<broiChisla;i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
