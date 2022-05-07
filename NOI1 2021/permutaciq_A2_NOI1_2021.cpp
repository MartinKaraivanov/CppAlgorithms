#include<iostream>
using namespace std;

long long daljinaNaRedicata;
long long broiPrilaganiq;

long long prilaganiq[30010];

void privediVDrugoto(){

    long long novataRedichka[30010];

    for(long long i = 0; i < daljinaNaRedicata; i++){
        novataRedichka[prilaganiq[i]] = i + 1;
    }

    for(long long i = 0; i < daljinaNaRedicata; i++){
        prilaganiq[i] = novataRedichka[i] - 1;
    }

}

void umnoji(long long (&redica)[30010], long long sKoq[30010]){

    long long novaRedica[30010];

    for(long long i = 0; i < daljinaNaRedicata; i++){
        novaRedica[i] = redica[sKoq[i]];
    }

    for(long long i = 0; i < daljinaNaRedicata; i++){
        redica[i] = novaRedica[i];
    }

}

void vdiganeNaStepen(long long (&koe)[30010], long long naKoqStepen){
    long long zaVrashtane[30010];
    long long smetnato[30010];

    for(long long i = 0; i < daljinaNaRedicata; i++){
        zaVrashtane[i] = koe[i];
        smetnato[i] = koe[i];
    }

    long long kopieStepen = naKoqStepen;

    //cout<<"she digame na "<<kopieStepen<<" stepen"<<endl;

    while(kopieStepen > 0){
        //cout<<"kopiestepen e "<<kopieStepen<<endl;
        if((kopieStepen & 1) == 1){
            //cout<<"sega sme na cifra koqto e 1 i umnojavame zavrahstane"<<endl;
            umnoji(zaVrashtane, smetnato);

            /*cout<<"sega vrashtaneto e "<<endl;

            for(long long i = 0; i < daljinaNaRedicata; i++){
                cout<<zaVrashtane[i]<<" ";
            }
            cout<<endl;*/
        }

        umnoji(smetnato, smetnato);

        kopieStepen >>= 1;
    }

    for(long long i = 0; i < daljinaNaRedicata; i++){
        koe[i] = zaVrashtane[i];
    }

}

int main(){

    cin>>daljinaNaRedicata>>broiPrilaganiq;

    for(long long i = 0; i < daljinaNaRedicata; i++){
        cin>>prilaganiq[i];
        prilaganiq[i]--;
    }

    privediVDrugoto();

    /*cout<<"sega nachalnoto e "<<endl;
    for(long long i = 0; i < daljinaNaRedicata; i++){
        cout<<prilaganiq[i]<<" ";
    }
    cout<<endl;*/

    vdiganeNaStepen(prilaganiq, broiPrilaganiq-1);

    for(long long i = 0; i < daljinaNaRedicata; i++){
        cout<<prilaganiq[i] + 1<<" ";
    }
    cout<<endl;

    return 0;
}
