#include<iostream>
#include<cmath>
using namespace std;

struct Koordinati{
    int x;
    int y;
};

Koordinati kashta;
Koordinati koordinatiNaKoli[100];
int broiKoli;

bool izpolzvaliLiSmeKola[100];
int posledovatelnostOtNomeraNaKoli[100];

int daljinaNaNaiKratakPat=1000000;


int raztoqnieMezhdu2tochki(Koordinati a, Koordinati b){
    int raz=0;
    raz=abs(a.x-b.x)+abs(a.y-b.y);
    return raz;
}

int obshtoRazstVPosledovatelnost(){
    int obshtoR=0;
    obshtoR+=raztoqnieMezhdu2tochki(kashta,koordinatiNaKoli[posledovatelnostOtNomeraNaKoli[0]]);
    for(int i=1;i<broiKoli;i++){
        obshtoR+=raztoqnieMezhdu2tochki(koordinatiNaKoli[posledovatelnostOtNomeraNaKoli[i-1]],koordinatiNaKoli[posledovatelnostOtNomeraNaKoli[i]]);
    }
    obshtoR+=raztoqnieMezhdu2tochki(koordinatiNaKoli[posledovatelnostOtNomeraNaKoli[broiKoli-1]],kashta);
    return obshtoR;
}

void otpechatva(){
    for(int i=0;i<broiKoli;i++){
        cout<<posledovatelnostOtNomeraNaKoli[i]<<" ";
    }
    cout<<"    "<<obshtoRazstVPosledovatelnost()<<endl;
}

void naiMalakPat(){
    if(obshtoRazstVPosledovatelnost()<daljinaNaNaiKratakPat){
        daljinaNaNaiKratakPat=obshtoRazstVPosledovatelnost();
    }
}

void generirneNaPatishta(int poziciq){
    if(poziciq==broiKoli){
        //otpechatva();
        naiMalakPat();
    }else{
        for(int nomerNaKola=0;nomerNaKola<broiKoli;nomerNaKola++){
            if(izpolzvaliLiSmeKola[nomerNaKola]==false){
                posledovatelnostOtNomeraNaKoli[poziciq]=nomerNaKola;
                izpolzvaliLiSmeKola[nomerNaKola]=true;
                generirneNaPatishta(poziciq+1);
                izpolzvaliLiSmeKola[nomerNaKola]=false;
            }
        }
    }
}

int main(){
    int a;
    int b;

    cin>>a>>b;

    cin>>kashta.x>>kashta.y;

    cin>>broiKoli;

    for(int i=0;i<broiKoli;i++){
        cin>>koordinatiNaKoli[i].x>>koordinatiNaKoli[i].y;
    }

    generirneNaPatishta(0);

    cout<<daljinaNaNaiKratakPat;

    return 0;
}
