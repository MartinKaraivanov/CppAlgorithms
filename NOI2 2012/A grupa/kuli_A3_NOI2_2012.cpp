#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct DanniZaKula{
    int x;
    int visochina;
};

struct DanniZaPoluchavaneto{
    int koi;
    int dalbochina;
};

int broiKuli;
int naiGolqmaVazmozhnaRazlika;

DanniZaKula kuli[15050];

vector<int> sasedstvo[15050];

bool visited[15050];

bool dveteKuliVizhdatLiSe(DanniZaKula lqva, DanniZaKula dqsna, DanniZaKula sredna){
    double koeficientNaPodobie = ((double)sredna.x-(double)lqva.x)/((double)dqsna.x-(double)lqva.x);

    double h2Prim = lqva.visochina + koeficientNaPodobie*(dqsna.visochina - lqva.visochina);

    if(sredna.visochina - h2Prim > -0.000001){
        return false;
    }

    return true;
}

int bfs(){
    queue<DanniZaPoluchavaneto> q;

    q.push({0, 1});

    int broiOtsvashti = 0;

    while(q.empty() == false){
        DanniZaPoluchavaneto naiOtgore = q.front();
        q.pop();

        if(naiOtgore.koi == broiKuli - 1){
            broiOtsvashti = naiOtgore.dalbochina;
            break;
        }

        if(visited[naiOtgore.koi] == true){
            continue;
        }

        visited[naiOtgore.koi] = true;

        for(unsigned int i = 0; i < sasedstvo[naiOtgore.koi].size(); i++){
            if(visited[sasedstvo[naiOtgore.koi][i]] == false){
                q.push({sasedstvo[naiOtgore.koi][i], naiOtgore.dalbochina + 1});
            }
        }
    }

    return broiOtsvashti;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiKuli>>naiGolqmaVazmozhnaRazlika;

    for(int i = 0; i < broiKuli; i++){
        cin>>kuli[i].x>>kuli[i].visochina;
    }

    for(int i = 0; i < broiKuli - 1; i++){
        int doKade = min(i + naiGolqmaVazmozhnaRazlika, broiKuli - 1);

        sasedstvo[i].push_back(i + 1);

        int koqtoHvarlqNaiGolqmaSqnka = i + 1;
        double tangensaI = (double)(kuli[i + 1].visochina - kuli[i].visochina)/(double)(kuli[i + 1].x - kuli[i].x);

        for(int j = i + 2; j <= doKade; j++){
            if(kuli[j].x - kuli[i].x > naiGolqmaVazmozhnaRazlika){
                break;
            }

            if(dveteKuliVizhdatLiSe(kuli[i], kuli[j], kuli[koqtoHvarlqNaiGolqmaSqnka]) == true){
                sasedstvo[i].push_back(j);
            }

            double tangensaNaSegashnata = (double)(kuli[j].visochina - kuli[i].visochina)/(double)(kuli[j].x - kuli[i].x);
            if(tangensaNaSegashnata > tangensaI){
                tangensaI = tangensaNaSegashnata;
                koqtoHvarlqNaiGolqmaSqnka = j;
            }

        }
    }

    /*for(int i = 0; i < broiKuli; i++){
        cout<<i<<": ";
        for(auto j : sasedstvo[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }*/

    int broiOstavshtiKuli = bfs();

    cout<<broiOstavshtiKuli<<endl;

    return 0;
}
