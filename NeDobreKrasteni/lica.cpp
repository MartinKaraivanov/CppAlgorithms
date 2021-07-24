#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdio.h>
using namespace std;

bool poMalkoLiE(double a, double b){
    return a<b;
}

int main(){
    double ax;
    double ay;
    double bx;
    double by;
    double cx;
    double cy;

    cin>>ax>>ay>>bx>>by>>cx>>cy;

    double liceNaTriagalnik;
    double liceParviDop;
    double liceVtoriDop;
    double liceTretiDop;
    double licePravoagalnik;
    double broiNuzhniTriagalnici;

    liceParviDop=(abs(ax-bx)*abs(ay-by))/2;
    liceVtoriDop=(abs(ax-cx)*abs(ay-cy))/2;
    liceTretiDop=(abs(bx-cx)*abs(by-cy))/2;
    licePravoagalnik=abs(max(max(ax,bx),cx)-min(min(ax,bx),cx))*abs(max(max(ay,by),cy)-min(min(ay,by),cy));
    liceNaTriagalnik=licePravoagalnik-(liceParviDop+liceVtoriDop+liceTretiDop);

    double lica[3];
    lica[0]=liceParviDop;
    lica[1]=liceVtoriDop;
    lica[2]=liceTretiDop;

    sort(lica,lica+3,poMalkoLiE);

    for(int i=0;i<3;i++){
        if(lica[i]==0.0){
            broiNuzhniTriagalnici=0;
            break;
        }else{
            broiNuzhniTriagalnici=3;
        }
    }

    printf("%.1f",liceNaTriagalnik);
    cout<<endl<<broiNuzhniTriagalnici<<endl;

    if(broiNuzhniTriagalnici==3){
        for(int i=0;i<3;i++){
            printf("%.1f",lica[i]);
            cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}
