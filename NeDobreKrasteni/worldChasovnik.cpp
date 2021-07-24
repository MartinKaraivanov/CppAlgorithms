#include<iostream>
#include<stack>
#include<queue>
using namespace std;

bool podredeniLiSaChislata(queue<int> topchenca, int broiTopki){
    if(topchenca.size()==broiTopki){
        bool pravilnaLiERedicata = true;
        int predishnaTopka=0;
        for(int i=1;i<=broiTopki;i++){
            int novaTopka=topchenca.front();
            topchenca.pop();
            topchenca.push(novaTopka);

            if(novaTopka<=predishnaTopka){
                pravilnaLiERedicata=false;
            }

            predishnaTopka=novaTopka;
        }
        return pravilnaLiERedicata;
    }else{
        return false;
    }
}

int main(){
    int s;
    int m;
    int h;
    int nachalenBroiTopki;

    cin>>s>>m>>h>>nachalenBroiTopki;

    stack <int> kupaSekundi;
    stack <int> kupaMinuti;
    stack <int> kupaChasove;

    queue <int> topki;

    for(int i=1;i<=nachalenBroiTopki;i++){
        topki.push(i);
    }

    int denonoshtiq=0;

    int sek=0;
    int minu=0;
    int hou=0;

    while((podredeniLiSaChislata(topki,nachalenBroiTopki)==false) || (denonoshtiq==0) ){
        while(hou<h){
            while(minu<m){
                while(sek<s){
                    kupaSekundi.push(topki.front());
                    topki.pop();
                    sek++;
                }

                kupaMinuti.push(kupaSekundi.top());
                kupaSekundi.pop();

                while(kupaSekundi.empty()==false){
                    topki.push(kupaSekundi.top());
                    kupaSekundi.pop();
                }
                sek=0;
                minu++;
            }

            kupaChasove.push(kupaMinuti.top());
            kupaMinuti.pop();

            while(kupaMinuti.empty()==false){
                topki.push(kupaMinuti.top());
                kupaMinuti.pop();
            }
            minu=0;
            hou++;
        }

        while(kupaChasove.empty()==false){
            topki.push(kupaChasove.top());
            kupaChasove.pop();
        }

        hou=0;
        denonoshtiq++;
    }

    cout<<denonoshtiq;

    return 0;
}
