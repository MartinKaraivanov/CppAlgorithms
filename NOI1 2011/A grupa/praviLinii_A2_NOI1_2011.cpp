#include<iostream>
using namespace std;

struct DanniZaPrava{
    int a;
    int b;
    int c;
};

int broiPravi;

DanniZaPrava pravi[1010];

DanniZaPrava klasove[1010];
int broiKlasove;

int main(){
    cin>>broiPravi;

    for(int i = 0; i < broiPravi; i++){
        cin>>pravi[i].a>>pravi[i].b>>pravi[i].c;
    }

    int broiRazlichniPravi = 0;

    for(int i = 0; i < broiPravi; i++){
        bool taziPrinadlezhiLiNaKlas = false;
        bool taziSavpadaLiSDruga = false;

        for(int k = 0; k < broiKlasove; k++){
            if(klasove[k].a*pravi[i].b == klasove[k].b*pravi[i].a){
                taziPrinadlezhiLiNaKlas = true;
            }
        }

        for(int j = 0; j < i; j++){
            if(pravi[j].a*pravi[i].b == pravi[j].b*pravi[i].a &&
               pravi[j].a*pravi[i].c == pravi[j].c*pravi[i].a &&
               pravi[j].b*pravi[i].c == pravi[j].c*pravi[i].b)
            {
                taziSavpadaLiSDruga = true;
            }
        }

        if(taziPrinadlezhiLiNaKlas == false){
            klasove[broiKlasove] = pravi[i];
            broiKlasove++;
        }

        if(taziSavpadaLiSDruga == false){
            broiRazlichniPravi++;
        }

    }

    cout<<broiRazlichniPravi<<endl;
    cout<<broiKlasove<<endl;

    return 0;
}
