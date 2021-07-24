#include<iostream>
#include<cmath>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

struct DanniZaOtsechka{
    DanniZaTochka lqvaTochka;
    DanniZaTochka dqsnaTochka;
};

int broiOtsechki;
DanniZaOtsechka otsechki[110];

bool imameLiTova[210][210];

int daiKoordinat(int a){
    return a + 100;
}

int naiGolqmObshtDelitel(int a, int b){
    while(b != 0){
        int p = b;
        b = a%b;
        a = p;
    }
    return a;
}

int main(){
    cin>>broiOtsechki;

    for(int i = 0; i < broiOtsechki; i++){
        DanniZaTochka uzhLqvKrai;
        DanniZaTochka uzhDesenKrai;

        //cout<<i<<"   ";

        cin>>uzhLqvKrai.x>>uzhLqvKrai.y>>uzhDesenKrai.x>>uzhDesenKrai.y;

        if(uzhDesenKrai.x < uzhLqvKrai.x || (uzhDesenKrai.x == uzhLqvKrai.x && uzhDesenKrai.y < uzhLqvKrai.y)){
            swap(uzhLqvKrai, uzhDesenKrai);
        }

        otsechki[i].lqvaTochka = uzhLqvKrai;
        otsechki[i].dqsnaTochka = uzhDesenKrai;
    }

    /*for(int i = 0; i < broiOtsechki; i++){
        cout<<i<<"  "<<otsechki[i].lqvaTochka.x<<" "<<otsechki[i].lqvaTochka.y<<" ";
        cout<<otsechki[i].dqsnaTochka.x<<" "<<otsechki[i].dqsnaTochka.y<<endl;
    }*/

    int broiRazlichni = 0;

    bool imaLiHorizontalna = false;
    bool imaLiVertikalna = false;

    for(int i = 0; i < broiOtsechki; i++){
        int razlikaVXovete = otsechki[i].dqsnaTochka.x - otsechki[i].lqvaTochka.x;
        int razlikaVYcite = otsechki[i].dqsnaTochka.y - otsechki[i].lqvaTochka.y;

        if(razlikaVXovete == 0){
            if(imaLiVertikalna == false){
                imaLiVertikalna = true;
                //cout<<i<<" tuka ima nova vertikalna"<<endl;
                broiRazlichni++;
            }
        }else{
            if(razlikaVYcite == 0){
                if(imaLiHorizontalna == false){
                    imaLiHorizontalna = true;
                    broiRazlichni++;
                    //cout<<i<<" tuka ima nova horizontalna"<<endl;
                }
            }else{
                /*double otnoshenie = (double)razlikaVXovete/(double)razlikaVYcite;
                if(imaLiTakovaOtnoshenie[otnoshenie] == false){
                    imaLiTakovaOtnoshenie[otnoshenie] = true;
                    broiRazlichni++;
                }*/
                int nod = naiGolqmObshtDelitel(abs(razlikaVXovete), abs(razlikaVYcite));
                razlikaVXovete /= nod;
                razlikaVYcite /= nod;
                if(imameLiTova[daiKoordinat(razlikaVXovete)][daiKoordinat(razlikaVYcite)] == false){
                    imameLiTova[daiKoordinat(razlikaVXovete)][daiKoordinat(razlikaVYcite)] = true;
                    broiRazlichni++;
                }
            }
        }

    }

    cout<<broiRazlichni<<endl;

    return 0;
}
