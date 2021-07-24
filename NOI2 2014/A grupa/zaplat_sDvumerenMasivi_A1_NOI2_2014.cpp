#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int broiSLujiteli;

////// todo: dvete dvoiki da sa dvumerni masivis po 2 elementa i d ane se kopirvat a da se prevkluchva indeksa 0,1,0,1...

/*int predishniZaplati[100010];
vector<int> vidovePredishniZaplati[100010];

int segashniZaplati[100010];
vector<int> vidoveSegashniZalati[100010];*/

int zaplati[2][100010];
vector<int> vidoveZaplati[2][100010];

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

        if(vidoveZaplati[0][predishnoIndex].size() > 0 && vidoveZaplati[1][segashnoIndex].size() > 0){
            if(vidoveZaplati[0][predishnoIndex].size() == vidoveZaplati[1][segashnoIndex].size()){
                //cout<<"pri staro "<<predishnoIndex<<" i novo "<<segashnoIndex<<" namerih s ravna duljina "<<endl;

                for(unsigned int i = 0; i < vidoveZaplati[0][predishnoIndex].size(); i++){
                    if(vidoveZaplati[0][predishnoIndex][i] != vidoveZaplati[1][segashnoIndex][i]){
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
            if(vidoveZaplati[0][predishnoIndex].size() == 0){
                predishnoIndex++;
            }
            if(vidoveZaplati[1][segashnoIndex].size() == 0){
                segashnoIndex++;
            }
        }
    }

    return stavaLi;
}

/*void slaganeNaNoviteStoinostiDaSaStari(){
    for(int i = 0; i < broiSLujiteli; i++){
        predishniZaplati[i] = segashniZaplati[i];
        segashniZaplati[i] = 0;
    }

    for(int i = 0; i <= naiGolqmataZaplata; i++){
        vidovePredishniZaplati[i] = vidoveSegashniZalati[i];
        vidoveSegashniZalati[i].clear();
    }
}*/

void nulirvaneNaKoiIndex(int index){
    for(int i = 0; i < broiSLujiteli; i++){
        zaplati[index][i] = 0;
    }

    for(int i = 0; i <= naiGolqmataZaplata; i++){
        vidoveZaplati[index][i].clear();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiSLujiteli;

    for(int i = 0; i < broiSLujiteli; i++){
        cin>>zaplati[0][i];
        vidoveZaplati[0][zaplati[0][i]].push_back(i);
        naiGolqmataZaplata = max(naiGolqmataZaplata, zaplati[0][i]);
    }

    int koeEPoslednotoPovishenie = 0;

    for(int t = 1; t <= 12; t++){
        int segashenIndex = t%2;
        int drugiqIndex = (t + 1)%2;

        stack<int> s;

        bool promeniliLiSmeNeshto = false;

        for(int i = broiSLujiteli - 1; i >= 0; i--){
            int tuka = zaplati[drugiqIndex][i];

            /*cout<<"pri index "<<i<<" v steka ima "<<s.size()<<endl;

            if(s.empty() == false){
                cout<<"i nai gornoto e "<<predishniZaplati[s.top()]<<" a nashto e "<<predishniZaplati[i]<<endl;
            }*/

            int segashnoGledane = i;

            while(s.empty() == false){
                if(zaplati[drugiqIndex][s.top()] <= tuka){
                    s.pop();
                }else{
                    segashnoGledane = s.top();
                    promeniliLiSmeNeshto = true;
                    break;
                }
            }

            zaplati[segashenIndex][i] = (zaplati[drugiqIndex][i] + zaplati[drugiqIndex][segashnoGledane])/2;
            s.push(i);
        }

        /*cout<<"sled "<<t<<endl;

        for(int i = 0; i < broiSLujiteli; i++){
            cout<<segashniZaplati[i]<<endl;
        }
        cout<<endl;*/

        for(int i = 0; i < broiSLujiteli; i++){
            vidoveZaplati[segashenIndex][zaplati[segashenIndex][i]].push_back(i);
        }

        if(promeniliLiSmeNeshto == true && okLiE() == true){
            nulirvaneNaKoiIndex(drugiqIndex);
            koeEPoslednotoPovishenie = t;
        }else{
            break;
        }
    }

    int j = koeEPoslednotoPovishenie%2;

    for(int i = 0; i < broiSLujiteli; i++){
        cout<<zaplati[j][i]<<endl;
    }

    return 0;
}
