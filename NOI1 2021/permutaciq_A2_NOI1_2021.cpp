#include<iostream>
using namespace std;

int daljinaNaRedicata;
int broiPrilaganiq;

int prilaganiq[30010];

void privediVDrugoto(){

    int novataRedichka[30010];

    for(int i = 0; i < daljinaNaRedicata; i++){
        novataRedichka[prilaganiq[i]] = i + 1;
    }

    for(int i = 0; i < daljinaNaRedicata; i++){
        prilaganiq[i] = novataRedichka[i] - 1;
    }

}

void umnoji(int (&redica)[30010], int sKoq[30010]){

    int novaRedica[30010];

    for(int i = 0; i < daljinaNaRedicata; i++){
        novaRedica[i] = redica[sKoq[i]];
    }

    for(int i = 0; i < daljinaNaRedicata; i++){
        redica[i] = novaRedica[i];
    }

}

void vdiganeNaStepen(int (&koe)[30010], int naKoqStepen){
    int zaVrashtane[30010];
    int smetnato[30010];

    for(int i = 0; i < daljinaNaRedicata; i++){
        zaVrashtane[i] = koe[i];
        smetnato[i] = koe[i];
    }

    int kopieStepen = naKoqStepen;

    while(kopieStepen > 0){
        if((kopieStepen & 1) == 1){
            umnoji(zaVrashtane, smetnato);
        }

        umnoji(smetnato, smetnato);

        cout<<"sega vrashtaneto e "<<endl;

        for(int i = 0; i < daljinaNaRedicata; i++){
            cout<<zaVrashtane[i]<<" ";
        }
        cout<<endl;

        kopieStepen >>= 1;
    }

    for(int i = 0; i < daljinaNaRedicata; i++){
        koe[i] = zaVrashtane[i];
    }

}


int main(){

    cin>>daljinaNaRedicata>>broiPrilaganiq;

    for(int i = 0; i < daljinaNaRedicata; i++){
        cin>>prilaganiq[i];
        prilaganiq[i]--;
    }

    privediVDrugoto();

    cout<<"sega nachalnoto e "<<endl;
    for(int i = 0; i < daljinaNaRedicata; i++){
        cout<<prilaganiq[i]<<" ";
    }
    cout<<endl;

    vdiganeNaStepen(prilaganiq, broiPrilaganiq);

    for(int i = 0; i < daljinaNaRedicata; i++){
        cout<<prilaganiq[i] + 1<<" ";
    }
    cout<<endl;

    return 0;
}
