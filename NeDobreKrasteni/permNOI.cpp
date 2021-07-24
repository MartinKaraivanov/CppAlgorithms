#include<iostream>
using namespace std;

long long chislaIKolkoPatiSeSreshtaCifrataVtqh[1000000][10];

int main(){
    long long broiChisla;
    cin>>broiChisla;

    unsigned long long chisla[broiChisla];

    for(int i=0;i<broiChisla;i++){
        cin>>chisla[i];
    }

    for(int i=0;i<broiChisla;i++){
			unsigned long long kopieNaChisloto=chisla[i];
			while(kopieNaChisloto>0){
				chislaIKolkoPatiSeSreshtaCifrataVtqh[i][kopieNaChisloto%10]++;
				kopieNaChisloto/=10;
			}
    }

    long long broiRazmestvaniq=0;

    for(int i=0;i<broiChisla;i++){
		bool imaLiPoluchavashtoSe=false;

		for(int d=0;d<broiChisla;d++){

			bool mozheLiDaSePoluchi=true;

			for(int j=0;j<10;j++){
				if((chislaIKolkoPatiSeSreshtaCifrataVtqh[i][j]==chislaIKolkoPatiSeSreshtaCifrataVtqh[d][j]) && (d!=i)){
					mozheLiDaSePoluchi=true;
				}else{
					mozheLiDaSePoluchi=false;
					break;
				}
			}

			if(mozheLiDaSePoluchi==true){
				imaLiPoluchavashtoSe=true;
			}

		}

		if(imaLiPoluchavashtoSe==true){
			broiRazmestvaniq++;
		}

    }

    cout<<broiRazmestvaniq<<endl;

    return 0;
}
