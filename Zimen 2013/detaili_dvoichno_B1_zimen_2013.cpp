#include<iostream>
using namespace std;

struct DanniZaZavod{
    int nachalnoZabavqne;
    int vremeZaObrabotkaNaEdinDetail;
};

int broiFabriki;
int broiElementi;

DanniZaZavod zavodi[100010];

bool stavaLiSTovaVreme(long long sVreme){
    long long broiOstavashti = broiElementi;
    //int naKoqFabrikaSme = 0;

    //cout<<"za vreme "<<sVreme<<endl;

    for(int naKoqFabrikaSme = 0; naKoqFabrikaSme < broiFabriki; naKoqFabrikaSme++){
        //cout<<naKoqFabrikaSme<<" "<<zavodi[naKoqFabrikaSme].nachalnoZabavqne<<" "<<zavodi[naKoqFabrikaSme].vremeZaObrabotkaNaEdinDetail<<endl;
        long long tukMozhemDaVzemem =
            max((sVreme - zavodi[naKoqFabrikaSme].nachalnoZabavqne), (long long)0)/zavodi[naKoqFabrikaSme].vremeZaObrabotkaNaEdinDetail;
        broiOstavashti -= tukMozhemDaVzemem;

        if(broiOstavashti <= 0){
            break;
        }
    }

    return broiOstavashti <= 0;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiFabriki>>broiElementi;

    for(int i = 0; i < broiFabriki; i++){
        cin>>zavodi[i].vremeZaObrabotkaNaEdinDetail>>zavodi[i].nachalnoZabavqne;
    }

    long long minimalnoVremeZaObrabotka = -1;

    /*for(long long i = 1; true; i++){
        if(stavaLiSTovaVreme(i) == true){
            minimalnoVremeZaObrabotka = i;
            break;
        }
    }*/

    long long lqvKrai = 0;
    long long desenKrai = 100000000000;

    while(true){
        //long long poSredata = (lqvKrai + desenKrai)/2;
        if(lqvKrai + 1 >= desenKrai){
            minimalnoVremeZaObrabotka = desenKrai;
            break;
        }

        long long poSredata = (lqvKrai + desenKrai)/2;

        //cout<<lqvKrai<<" "<<desenKrai<<" "<<poSredata<<" ";

        bool okLiE = stavaLiSTovaVreme(poSredata);

        //cout<<okLiE<<endl;

        if(okLiE == true){
            desenKrai = poSredata;
        }else{
            lqvKrai = poSredata;
        }
    }

    cout<<minimalnoVremeZaObrabotka<<endl;

    return 0;
}
