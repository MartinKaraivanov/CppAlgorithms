#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int broiSLujiteli;

////// todo: dvete dvoiki da sa dvumerni masivis po 2 elementa i d ane se kopirvat a da se prevkluchva indeksa 0,1,0,1...

int predishniZaplati[100010];
vector<int> vidovePredishniZaplati[100010];

int segashniZaplati[100010];
vector<int> vidoveSegashniZalati[100010];

int naiGolqmataZaplata;

////////bool toziChovekImameLiGo[100010];

bool okLiE(){
    bool stavaLi = true;

    int predishnoIndex = 0;
    int segashnoIndex = 0;

    while(predishnoIndex <= naiGolqmataZaplata && segashnoIndex <= naiGolqmataZaplata){
        if(stavaLi == false){
            break;
        }

        //cout<<predishnoIndex<<" "<<segashnoIndex<<endl;

        if(vidovePredishniZaplati[predishnoIndex].size() > 0 && vidoveSegashniZalati[segashnoIndex].size() > 0){
            if(vidovePredishniZaplati[predishnoIndex].size() == vidoveSegashniZalati[segashnoIndex].size()){
                //cout<<"pri staro "<<predishnoIndex<<" i novo "<<segashnoIndex<<" namerih s ravna duljina "<<endl;

                for(unsigned int i = 0; i < vidovePredishniZaplati[predishnoIndex].size(); i++){
                    if(vidovePredishniZaplati[predishnoIndex][i] != vidoveSegashniZalati[segashnoIndex][i]){
                        stavaLi = false;
                        break;
                    }
                }

                predishnoIndex++;
                segashnoIndex++;
            }else{
                stavaLi = false;
                break;
            }
        }else{
            if(vidovePredishniZaplati[predishnoIndex].size() == 0){
                predishnoIndex++;
            }
            if(vidoveSegashniZalati[segashnoIndex].size() == 0){
                segashnoIndex++;
            }
        }
    }

    return stavaLi;
}

void slaganeNaNoviteStoinostiDaSaStari(){
    for(int i = 0; i < broiSLujiteli; i++){
        predishniZaplati[i] = segashniZaplati[i];
        segashniZaplati[i] = 0;
    }

    for(int i = 0; i <= naiGolqmataZaplata; i++){
        vidovePredishniZaplati[i] = vidoveSegashniZalati[i];
        vidoveSegashniZalati[i].clear();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiSLujiteli;

    for(int i = 0; i < broiSLujiteli; i++){
        cin>>predishniZaplati[i];
        vidovePredishniZaplati[predishniZaplati[i]].push_back(i);
        naiGolqmataZaplata = max(naiGolqmataZaplata, predishniZaplati[i]);
    }

    for(int t = 1; t <= 12; t++){
        stack<int> s;

        bool promeniliLiSmeNeshto = false;

        for(int i = broiSLujiteli - 1; i >= 0; i--){
            int tuka = predishniZaplati[i];

            /*cout<<"pri index "<<i<<" v steka ima "<<s.size()<<endl;

            if(s.empty() == false){
                cout<<"i nai gornoto e "<<predishniZaplati[s.top()]<<" a nashto e "<<predishniZaplati[i]<<endl;
            }*/

            int segashnoGledane = i;

            while(s.empty() == false){
                if(predishniZaplati[s.top()] <= tuka){
                    s.pop();
                }else{
                    segashnoGledane = s.top();
                    promeniliLiSmeNeshto = true;
                    break;
                }
            }

            segashniZaplati[i] = (predishniZaplati[i] + predishniZaplati[segashnoGledane])/2;
            s.push(i);
        }

        /*cout<<"sled "<<t<<endl;

        for(int i = 0; i < broiSLujiteli; i++){
            cout<<segashniZaplati[i]<<endl;
        }
        cout<<endl;*/

        for(int i = 0; i < broiSLujiteli; i++){
            vidoveSegashniZalati[segashniZaplati[i]].push_back(i);
        }

        if(promeniliLiSmeNeshto == true && okLiE() == true){
            slaganeNaNoviteStoinostiDaSaStari();
        }else{
            break;
        }
    }

    for(int i = 0; i < broiSLujiteli; i++){
        cout<<predishniZaplati[i]<<endl;
    }

    return 0;
}
