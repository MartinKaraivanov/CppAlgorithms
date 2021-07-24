#include<iostream>
using namespace std;

int broiPravoag;
int broiTochki;

int visochinaNaToziX[1000010];

int main(){
    cin>>broiPravoag>>broiTochki;

    int predishenKraiPoX = 0;

    for(int i = 0; i < broiPravoag; i++){
        int dalzhinaPoX;
        int visochinaPoY;
        cin>>dalzhinaPoX>>visochinaPoY;
        for(int j = predishenKraiPoX; j <= predishenKraiPoX + dalzhinaPoX; j++){
            visochinaNaToziX[j] = max(visochinaPoY, visochinaNaToziX[j]);
        }
        predishenKraiPoX += dalzhinaPoX;
    }

    //cout<<endl;

    /*for(int i = 0; i <predishenKraiPoX; i++){
        cout<<visochinaNaToziX[i]<<" ";
    }*/

    int broiTochkiVPravoagalnicite = 0;

    for(int i = 0; i < broiTochki; i++){
        int xTochka;
        int yTochka;
        cin>>xTochka>>yTochka;

        if(yTochka <= visochinaNaToziX[xTochka]){
            broiTochkiVPravoagalnicite++;
        }
    }

    cout<<broiTochkiVPravoagalnicite<<endl;

    return 0;
}
