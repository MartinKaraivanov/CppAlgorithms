#include<iostream>
#include<queue>
using namespace std;

struct DanniZaParcheto{
    int x;
    int y;
    int naKoqStapkaSheSeRaztopi;
};

int razmer;

bool more[5050][5050];

int broiNuliokoloTozi(int x, int y){
    int brNuliOkoloTozi = 4 - (more[x - 1][y] + more[x + 1][y] + more[x][y - 1] + more[x][y + 1]);

    return brNuliOkoloTozi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>razmer;

    for(int y = 1; y <= razmer; y++){
        string red;
        cin>>red;
        for(int x = 1; x <= razmer; x++){
            more[x][y] = red[x - 1] - '0';
        }
    }

    queue<DanniZaParcheto> q;

    for(int y = 1; y <= razmer; y++){
        for(int x = 1; x <= razmer; x++){
            if(broiNuliokoloTozi(x, y) >= 2){
                q.push({x, y, 1});
            }
        }
    }

    int nuzhniChasove = 0;

    while(q.empty() == false){
        DanniZaParcheto naiNapred = q.front();
        q.pop();

        if(more[naiNapred.x][naiNapred.y] == 0)
        {
            continue;
        }

        nuzhniChasove = max(nuzhniChasove, naiNapred.naKoqStapkaSheSeRaztopi);

        more[naiNapred.x][naiNapred.y] = 0;

        if(more[naiNapred.x + 1][naiNapred.y] == 1 && broiNuliokoloTozi(naiNapred.x + 1, naiNapred.y) == 2){
            q.push({naiNapred.x + 1, naiNapred.y, naiNapred.naKoqStapkaSheSeRaztopi + 1});
        }
        if(more[naiNapred.x - 1][naiNapred.y] == 1 && broiNuliokoloTozi(naiNapred.x - 1, naiNapred.y) == 2){
            q.push({naiNapred.x - 1, naiNapred.y, naiNapred.naKoqStapkaSheSeRaztopi + 1});
        }
        if(more[naiNapred.x][naiNapred.y + 1] == 1 && broiNuliokoloTozi(naiNapred.x, naiNapred.y + 1) == 2){
            q.push({naiNapred.x, naiNapred.y + 1, naiNapred.naKoqStapkaSheSeRaztopi + 1});
        }
        if(more[naiNapred.x][naiNapred.y - 1] == 1 && broiNuliokoloTozi(naiNapred.x, naiNapred.y - 1) == 2){
            q.push({naiNapred.x, naiNapred.y - 1, naiNapred.naKoqStapkaSheSeRaztopi + 1});
        }

    }

    cout<<nuzhniChasove<<endl;

    return 0;
}
