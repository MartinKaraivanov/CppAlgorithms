#include<iostream>
#include<queue>
using namespace std;

struct Mostcheta{
    int otMostche;
    int doMostche;
};

int broiOstrovcheta;
int broiMostove;

int broiMostchetaSVrazkaSNego[1000000];

int main(){
    cin>>broiOstrovcheta>>broiMostove;

    for(int i = 0; i < broiMostove; i++){
        int otMostche;
        int doMostche;
        cin>>otMostche>>doMostche;

        broiMostchetaSVrazkaSNego[otMostche]++;
        broiMostchetaSVrazkaSNego[doMostche]++;

    }

    queue<Mostcheta> q;

    bool daVartimLi = true;

    int broiNamereni = 0;
    int parvo = 0;
    int vtoro = 0;

    while(daVartimLi == true){
        daVartimLi = false;

        for(int i = 1; i <= broiOstrovcheta; i++){
            if(broiNamereni == 2){
                ///cout<<broiNamereni<<" "<<parvo<<" "<<vtoro;

                Mostcheta zaDobavqne = {parvo, vtoro};
                q.push(zaDobavqne);
                broiNamereni = 0;
                parvo = 0;
                vtoro = 0;
            }

            if(broiMostchetaSVrazkaSNego[i] % 2 == 1 || broiMostchetaSVrazkaSNego[i] == 0){
                if(parvo == 0){
                    parvo = i;
                    broiMostchetaSVrazkaSNego[parvo]++;
                }else{
                    if(i != parvo){
                        vtoro = i;
                    }else{
                        if(i != 1){
                            vtoro = 1;
                        }else{
                            vtoro = 2;
                        }
                    }
                    broiMostchetaSVrazkaSNego[vtoro]++;
                }
                broiNamereni++;
            }
        }

        if(broiNamereni == 2){
            ///cout<<broiNamereni<<" "<<parvo<<" "<<vtoro;

            Mostcheta zaDobavqne = {parvo, vtoro};
            q.push(zaDobavqne);
            broiNamereni = 0;
            parvo = 0;
            vtoro = 0;
        }

        for(int i = 1; i <= broiOstrovcheta; i++){
            if(broiMostchetaSVrazkaSNego[i] == 0 || broiMostchetaSVrazkaSNego[i] % 2 == 1){
                daVartimLi = true;
                break;
            }
        }

    }

    int broiNuzhniMostcheta = q.size();

    cout<<broiNuzhniMostcheta<<endl;

    while(q.empty() == false){
        Mostcheta m = q.front();
        q.pop();
        cout<<m.otMostche<<" "<<m.doMostche<<endl;
    }

    return 0;
}
