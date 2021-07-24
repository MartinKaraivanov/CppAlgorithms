#include<iostream>
#include<queue>
using namespace std;

struct DanniZaIzgnilata{
    int y;
    int x;
    int naKoiDenEIzgnila;
};

int maxY;
int maxX;

int sledKolkoDni;

bool izgniliLiSa[1010][1010];

int main(){
    cin>>maxY>>maxX>>sledKolkoDni;

    int izgnilaY;
    int izgnilaX;

    queue<DanniZaIzgnilata> q;

    while(cin>>izgnilaY){
        cin>>izgnilaX;

        q.push({izgnilaY, izgnilaX, 0});
    }

    int oceleliQbalki = maxY * maxX;

    while(true){
        DanniZaIzgnilata naiNapred = q.front();
        q.pop();

        if(naiNapred.naKoiDenEIzgnila > sledKolkoDni){
            q.push(naiNapred);
            break;
        }

        if(izgniliLiSa[naiNapred.x][naiNapred.y] == true){
            continue;
        }

        izgniliLiSa[naiNapred.x][naiNapred.y] = true;
        oceleliQbalki--;

        if(naiNapred.x - 1 > 0){
            q.push({naiNapred.y, naiNapred.x - 1, naiNapred.naKoiDenEIzgnila + 1});
        }
        if(naiNapred.x + 1 <= maxX){
            q.push({naiNapred.y, naiNapred.x + 1, naiNapred.naKoiDenEIzgnila + 1});
        }
        if(naiNapred.y - 1 > 0){
            q.push({naiNapred.y - 1, naiNapred.x, naiNapred.naKoiDenEIzgnila + 1});
        }
        if(naiNapred.y + 1 <= maxY){
            q.push({naiNapred.y + 1, naiNapred.x, naiNapred.naKoiDenEIzgnila + 1});
        }
    }


    cout<<oceleliQbalki<<endl;

    return 0;
}
