#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

int broiTochki;

DanniZaTochka tochki[200005];

int tipNaTochkata[200005];

int broiOtVsekiVid[6];

int broiZaqvki;

map<int, map<int, int>> zaXY;
map<int, map<int, int>> zaYX;

int naiLqvaZaY(int y){
    if(zaYX[y].begin() == zaYX[y].end()){
        return -1;
    }
    return zaYX[y].begin()->second;
}

int naiDqsnaZaY(int y){
    if(zaYX[y].begin() == zaYX[y].end()){
        return -1;
    }
    return zaYX[y].rbegin()->second;
}

int naiDolnaZaX(int x){
    if(zaXY[x].begin() == zaXY[x].end()){
        return -1;
    }
    return zaXY[x].begin()->second;
}
int naiGornaZaX(int x){
    if(zaXY[x].begin() == zaXY[x].end()){
        return -1;
    }
    return zaXY[x].rbegin()->second;
}

int kakuvVidETochkata(int koqTochka){
    /// 1 - vatreshna, 2- nkakva, 3 - extremna

    bool krainaLiEPoX = (naiLqvaZaY(tochki[koqTochka].y) == koqTochka) || (naiDqsnaZaY(tochki[koqTochka].y) == koqTochka);
    bool krainaLiEPoY = (naiGornaZaX(tochki[koqTochka].x) == koqTochka) || (naiDolnaZaX(tochki[koqTochka].x) == koqTochka);

    if(krainaLiEPoX && krainaLiEPoY){
        return 3;
    }else{
        if(!krainaLiEPoX && !krainaLiEPoY){
            return 1;
        }else{
            return 2;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiTochki;

    for(int i = 1; i <= broiTochki; i++){
        cin>>tochki[i].x>>tochki[i].y;
    }

    for(int i = 1; i <= broiTochki; i++){
        zaXY[tochki[i].x][tochki[i].y] = i;
        zaYX[tochki[i].y][tochki[i].x] = i;
    }

    for(int i = 1; i <= broiTochki; i++){
        int tipNaTazi = kakuvVidETochkata(i);

        tipNaTochkata[i] = tipNaTazi;
        broiOtVsekiVid[tipNaTazi]++;
    }

    cout<<broiOtVsekiVid[3]<<" "<<broiOtVsekiVid[1]<<endl;

    cin>>broiZaqvki;

    for(int i = 0; i < broiZaqvki; i++){
        int vid;
        int x;
        int y;

        cin>>vid>>x>>y;

        vector<int> vazmozhniPromeneni;

        if(vid == 1){
            int naiNadolu = naiDolnaZaX(x);
            int naiNagore = naiGornaZaX(x);
            int naiNalqvo = naiLqvaZaY(y);
            int naiNadqsno = naiDqsnaZaY(y);

            if(naiNadolu != -1){
                vazmozhniPromeneni.push_back(naiNadolu);
            }
            if(naiNagore != -1 && naiNagore != naiNadolu){
                vazmozhniPromeneni.push_back(naiNagore);
            }

            if(naiNadqsno != -1){
                vazmozhniPromeneni.push_back(naiNadqsno);
            }
            if(naiNalqvo != -1 && naiNalqvo != naiNadqsno){
                vazmozhniPromeneni.push_back(naiNalqvo);
            }

            broiTochki++;
            tochki[broiTochki] = {x, y};

            vazmozhniPromeneni.push_back(broiTochki);

            zaXY[x][y] = broiTochki;
            zaYX[y][x] = broiTochki;

            for(int j = 0; j < vazmozhniPromeneni.size(); j++){
                int starTip = tipNaTochkata[vazmozhniPromeneni[j]];
                broiOtVsekiVid[starTip]--;

                int novTip = kakuvVidETochkata(vazmozhniPromeneni[j]);
                tipNaTochkata[vazmozhniPromeneni[j]] = novTip;
                broiOtVsekiVid[novTip]++;
            }

        }else{
            int koqTochkaE = zaXY[x][y];

            vazmozhniPromeneni.push_back(koqTochkaE);

            zaXY[x].erase(y);
            zaYX[y].erase(x);

            int naiNadolu = naiDolnaZaX(x);
            int naiNagore = naiGornaZaX(x);
            int naiNalqvo = naiLqvaZaY(y);
            int naiNadqsno = naiDqsnaZaY(y);

            if(naiNadolu != -1){
                vazmozhniPromeneni.push_back(naiNadolu);
            }
            if(naiNagore != -1 && naiNagore != naiNadolu){
                vazmozhniPromeneni.push_back(naiNagore);
            }

            if(naiNadqsno != -1){
                vazmozhniPromeneni.push_back(naiNadqsno);
            }
            if(naiNalqvo != -1 && naiNalqvo != naiNadqsno){
                vazmozhniPromeneni.push_back(naiNalqvo);
            }

            for(int j = 0; j < vazmozhniPromeneni.size(); j++){
                int starTip = tipNaTochkata[vazmozhniPromeneni[j]];
                broiOtVsekiVid[starTip]--;

                if(vazmozhniPromeneni[j] != koqTochkaE){
                    int novTip = kakuvVidETochkata(vazmozhniPromeneni[j]);
                    tipNaTochkata[vazmozhniPromeneni[j]] = novTip;
                    broiOtVsekiVid[novTip]++;
                }
            }

            tipNaTochkata[koqTochkaE] = 5;
        }

        cout<<broiOtVsekiVid[3]<<" "<<broiOtVsekiVid[1]<<endl;
    }


    return 0;
}
