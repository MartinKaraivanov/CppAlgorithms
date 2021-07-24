#include<iostream>
using namespace std;

int main(){
    int koiChlen;
    int naKolkoOstatyk;
    cin>>koiChlen>>naKolkoOstatyk;

    int predposledenChlen=1;
    int posledenChlen=1;

    int razmerNaCikyl=0;

    if(koiChlen<=2){
        cout<<1;
        return 0;
    }

    for(int i=3;i<=koiChlen;i++){
        int novChlen=(posledenChlen+predposledenChlen)%naKolkoOstatyk;
        predposledenChlen=posledenChlen;
        posledenChlen=novChlen;
        razmerNaCikyl++;
        if((predposledenChlen==1) && (posledenChlen==1) ){
            break;
        }
    }


    if((predposledenChlen==1) && (posledenChlen==1) ){
        predposledenChlen=1;
        posledenChlen=1;
        for(int i=3;i<=(koiChlen%razmerNaCikyl);i++){
            int novChlen=(posledenChlen+predposledenChlen)%naKolkoOstatyk;
            predposledenChlen=posledenChlen;
            posledenChlen=novChlen;
        }
        cout<<posledenChlen;
    }else{
        cout<<posledenChlen;
    }

    return 0;
}
