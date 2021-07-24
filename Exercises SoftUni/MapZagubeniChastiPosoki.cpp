#include<iostream>
#include<cmath>
using namespace std;

char karta[20];
int broiSimvoli;
int broiPropuski;
char propuski[20];

char bukvichki[]={'L' , 'R' , 'S'};

void pechatane(){
    int broqch=0;
    for(int i=0;i<broiSimvoli;i++){
        if(karta[i]!='*'){
            cout<<karta[i];
        }else{
            cout<<propuski[broqch];
            broqch++;
        }
    }
    cout<<endl;
}

void vazstanovqvane(int broiOstavashtiMesta, int broqchche){
    if(broiOstavashtiMesta==0){
        pechatane();
    }else{
        for(int i=0;i<3;i++){
            propuski[broqchche]=bukvichki[i];
            vazstanovqvane(broiOstavashtiMesta-1, broqchche+1);
        }
    }
}

int main(){
    char posoka;

    while(cin>>posoka){
        if(posoka=='*'){
            broiPropuski++;
        }
        karta[broiSimvoli]=posoka;
        broiSimvoli++;
    }

    int broiVazmozhniNachiniZaVazstanovqvane=pow(3, broiPropuski);

    cout<<broiVazmozhniNachiniZaVazstanovqvane<<endl;

    vazstanovqvane(broiPropuski, 0);

    return 0;
}
