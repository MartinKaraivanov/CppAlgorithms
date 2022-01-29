#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

const int mnogo = 30010;

int broiRobotcheta;
int maxY;
int maxX;

struct Koordinati{
    int x;
    int y;
};

struct DanniZaRobotche{
    Koordinati tochka;
    char posoka;
};

DanniZaRobotche robotcheta[15010];

int naiDqsnotoNalqvo[30010];
int naiLqvotoNadqsno[30010];
int naiGornotoNadolu[30010];
int naiDolnotoNagore[30010];

void nameriKrainite(){
    for(int i = 0; i <= maxX; i++){
        naiGornotoNadolu[i] = mnogo;
    }
    for(int i = 0; i <= maxY; i++){
        naiLqvotoNadqsno[i] = mnogo;
    }

    for(int i = 0; i < broiRobotcheta; i++){
        if(robotcheta[i].posoka == 'r'){
            naiLqvotoNadqsno[robotcheta[i].tochka.y] = min(robotcheta[i].tochka.x, naiLqvotoNadqsno[robotcheta[i].tochka.y]);
        }else{
            if(robotcheta[i].posoka == 'l'){
                naiDqsnotoNalqvo[robotcheta[i].tochka.y] = max(robotcheta[i].tochka.x, naiDqsnotoNalqvo[robotcheta[i].tochka.y]);
            }else{
                if(robotcheta[i].posoka == 'u'){
                    naiDolnotoNagore[robotcheta[i].tochka.x] = max(robotcheta[i].tochka.y, naiDolnotoNagore[robotcheta[i].tochka.x]);
                }else{
                    naiGornotoNadolu[robotcheta[i].tochka.x] = min(robotcheta[i].tochka.y, naiGornotoNadolu[robotcheta[i].tochka.x]);
                }
            }
        }
    }
}

struct DanniZaOtsechka{
    Koordinati edinKrai;
    Koordinati drugKrai;
};

struct DanniZaVertTochka{
    Koordinati tochka;
    int tip; /// 1 - nachalna, 2 - kraina
};

vector<DanniZaVertTochka> vertikalni;
vector<DanniZaOtsechka> horizontalni;

void nameriOtsechkite(){

    for(int x = 1; x <= maxX; x++){
        if(naiGornotoNadolu[x] == mnogo && naiDolnotoNagore[x] == 0){
            /// nqma otsechka tuka
        }else{
            if(naiGornotoNadolu[x] == mnogo && naiDolnotoNagore[x] > 0){
                DanniZaOtsechka tukaOtsechka = {{x, 1}, {x, naiDolnotoNagore[x]}};
                vertikalni.push_back({tukaOtsechka.edinKrai, 1});
                vertikalni.push_back({tukaOtsechka.drugKrai, 2});
            }else{
                if(naiGornotoNadolu[x] < mnogo && naiDolnotoNagore[x] == 0){
                    DanniZaOtsechka tukaOtsechka = {{x, naiGornotoNadolu[x]}, {x, maxY}};
                    vertikalni.push_back({tukaOtsechka.edinKrai, 1});
                    vertikalni.push_back({tukaOtsechka.drugKrai, 2});
                }else{
                    if(naiGornotoNadolu[x] <= naiDolnotoNagore[x]){
                        DanniZaOtsechka tukaOtsechka = {{x, 1}, {x, maxY}};
                        vertikalni.push_back({tukaOtsechka.edinKrai, 1});
                        vertikalni.push_back({tukaOtsechka.drugKrai, 2});
                    }else{
                        DanniZaOtsechka tukaOtsechka1 = {{x, 1}, {x, naiDolnotoNagore[x]}};
                        vertikalni.push_back({tukaOtsechka1.edinKrai, 1});
                        vertikalni.push_back({tukaOtsechka1.drugKrai, 2});

                        DanniZaOtsechka tukaOtsechka2 = {{x, naiGornotoNadolu[x]}, {x, maxY}};
                        vertikalni.push_back({tukaOtsechka2.edinKrai, 1});
                        vertikalni.push_back({tukaOtsechka2.drugKrai, 2});
                    }
                }
            }
        }
    }

    for(int y = 1; y <= maxY; y++){
        if(naiLqvotoNadqsno[y] == mnogo && naiDqsnotoNalqvo[y] == 0){
            /// nqma otsechka tuka
        }else{
            if(naiLqvotoNadqsno[y] == mnogo && naiDqsnotoNalqvo[y] > 0){
                DanniZaOtsechka tukaOtsechka = {{1, y}, {naiDqsnotoNalqvo[y], y}};
                horizontalni.push_back(tukaOtsechka);
            }else{
                if(naiLqvotoNadqsno[y] < mnogo && naiDqsnotoNalqvo[y] == 0){
                    DanniZaOtsechka tukaOtsechka = {{naiLqvotoNadqsno[y], y}, {maxX, y}};
                    horizontalni.push_back(tukaOtsechka);
                }else{
                    if(naiLqvotoNadqsno[y] <= naiDqsnotoNalqvo[y]){
                        DanniZaOtsechka tukaOtsechka = {{1, y}, {maxX, y}};
                        horizontalni.push_back(tukaOtsechka);
                    }else{
                        DanniZaOtsechka tukaOtsechka1 = {{1, y}, {naiDqsnotoNalqvo[y], y}};
                        horizontalni.push_back(tukaOtsechka1);

                        DanniZaOtsechka tukaOtsechka2 = {{naiLqvotoNadqsno[y], y}, {maxX, y}};
                        horizontalni.push_back(tukaOtsechka2);
                    }
                }
            }
        }
    }
}

bool koqEPoNapredSpecTochka(DanniZaVertTochka a, DanniZaVertTochka b){
    if(a.tochka.y < b.tochka.y){
        return true;
    }
    if(a.tochka.y > b.tochka.y){
        return false;
    }
    if(a.tip < b.tip){
        return true;
    }
    if(a.tip > b.tip){
        return false;
    }
    return a.tochka.x < b.tochka.x;
}

bool koqEPONapredOtsechka(DanniZaOtsechka a, DanniZaOtsechka b){
    if(a.edinKrai.y < b.edinKrai.y){
        return true;
    }
    if(a.edinKrai.y > b.edinKrai.y){
        return false;
    }
    return a.edinKrai.x < b.edinKrai.x;
}

int darvo[100010];

int broiNujniVarhove;

void nameriBroiNujniVarhove(){
    for(int i = 1; true; i *= 2){
        if(i >= maxX){
            broiNujniVarhove = 2*i;
            return ;
        }
    }
}

int daiListo(int index){
    return index + broiNujniVarhove/2;
}

void update(int index, int delta){
    int segIndex = daiListo(index);

    while(segIndex > 0){
        darvo[segIndex] += delta;
        segIndex /= 2;
    }
}

int query(int otKade, int doKade){
    int broi = 0;

    int lqvIndex = daiListo(otKade);
    int desenIndex = daiListo(doKade);

    if(lqvIndex == desenIndex){
        return darvo[lqvIndex];
    }

    broi += darvo[lqvIndex];
    broi += darvo[desenIndex];

    while(lqvIndex + 1< desenIndex){
        if(lqvIndex % 2 == 0){
            broi += darvo[lqvIndex + 1];
        }
        if(desenIndex % 2 == 1){
            broi += darvo[desenIndex - 1];
        }

        lqvIndex /= 2;
        desenIndex /= 2;
    }

    return broi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiRobotcheta>>maxY>>maxX;

    for(int i = 0; i < broiRobotcheta; i++){
        cin>>robotcheta[i].tochka.y>>robotcheta[i].tochka.x>>robotcheta[i].posoka;
    }

    nameriKrainite();
    nameriOtsechkite();
    nameriBroiNujniVarhove();

    int obshtBroiPokriti = 0;

    for(int i = 0; i < (int)vertikalni.size() - 1; i+=2){
        obshtBroiPokriti += abs(vertikalni[i+1].tochka.x - vertikalni[i].tochka.x) + abs(vertikalni[i+1].tochka.y - vertikalni[i].tochka.y) + 1;
    }
    for(int i = 0; i < (int)horizontalni.size(); i++){
        obshtBroiPokriti += abs(horizontalni[i].edinKrai.x - horizontalni[i].drugKrai.x) + abs(horizontalni[i].edinKrai.y - horizontalni[i].drugKrai.y) + 1;
    }

    sort(vertikalni.begin(), vertikalni.end(), koqEPoNapredSpecTochka);
    sort(horizontalni.begin(), horizontalni.end(), koqEPONapredOtsechka);

    int broiPresichaniq = 0;

    int indexHorizont = 0;
    int indexVertikalni = 0;

    while(indexHorizont < horizontalni.size() && indexVertikalni < vertikalni.size()){
        //cout<<"sega sme na horizontalna "<<horizontalni[indexHorizont].edinKrai.x<<" "<<horizontalni[indexHorizont].edinKrai.y<<" ";
        //cout<<horizontalni[indexHorizont].drugKrai.x<<" "<<horizontalni[indexHorizont].drugKrai.y<<" i vertikalna ";
        //cout<<vertikalni[indexVertikalni].tochka.x<<" "<<vertikalni[indexVertikalni].tochka.y<<" i tip "<<vertikalni[indexVertikalni].tip<<endl;
        if((horizontalni[indexHorizont].edinKrai.y < vertikalni[indexVertikalni].tochka.y) ||
            (horizontalni[indexHorizont].edinKrai.y == vertikalni[indexVertikalni].tochka.y && vertikalni[indexVertikalni].tip == 2))
        {
            int sega = query(horizontalni[indexHorizont].edinKrai.x, horizontalni[indexHorizont].drugKrai.x);
            //cout<<"sega queryto e "<<sega<<endl;
            broiPresichaniq += sega;
            indexHorizont++;
        }else{
            if(vertikalni[indexVertikalni].tip == 1){
                update(vertikalni[indexVertikalni].tochka.x, 1);
            }else{
                update(vertikalni[indexVertikalni].tochka.x, -1);
            }
            //cout<<"updatenahme "<<vertikalni[indexVertikalni].tochka.x<<" i sega tam pishe ";
            //cout<<query(vertikalni[indexVertikalni].tochka.x, vertikalni[indexVertikalni].tochka.x)<<endl;
            indexVertikalni++;
        }
    }

    int broiZamarseni = obshtBroiPokriti - broiPresichaniq;

    cout<<broiZamarseni<<endl;

    return 0;
}
