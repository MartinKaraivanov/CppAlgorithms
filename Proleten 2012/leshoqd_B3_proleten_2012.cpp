#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

struct DanniZaPolenceto{
    int x;
    int y;
    int kolkoNadPovarhnosttaE;
};

int maxY;
int maxX;

int gubeneNaVisochina;
int maxVisochina;

int visochini[260][260];
int skorosti[260][260];

int yGnezdo;
int xGnezdo;

int yPlyachka;
int xPlyachka;

int nomercheNaStarta;
int nomercheNaFinala;

vector<int> sasedstvo[3000000];

int nomercheNaTozi[300][300][35];

DanniZaPolenceto koiESTovaNomerche[3000000];

int broiObhodeniPoleta;

int daiNomercheZaTozi(DanniZaPolenceto a){
    if(nomercheNaTozi[a.x][a.y][a.kolkoNadPovarhnosttaE] > 0){
        return nomercheNaTozi[a.x][a.y][a.kolkoNadPovarhnosttaE];
    }

    broiObhodeniPoleta++;
    nomercheNaTozi[a.x][a.y][a.kolkoNadPovarhnosttaE] = broiObhodeniPoleta;
    koiESTovaNomerche[broiObhodeniPoleta] = a;

    return broiObhodeniPoleta;
}

bool visited[3000000];

void praveneNaSasedstvoto(){

    queue<DanniZaPolenceto> q;

    q.push({xGnezdo, yGnezdo, 0});

    while(q.empty() == false){
        DanniZaPolenceto naiOtgore = q.front();
        q.pop();

        int nasheNomerche = daiNomercheZaTozi(naiOtgore);

        if(visited[nasheNomerche] == true){
            continue;
        }else{
            visited[nasheNomerche] = true;
        }

        if(naiOtgore.x > 1){
            int novoKolkoOtgoreSme = naiOtgore.kolkoNadPovarhnosttaE - gubeneNaVisochina +
                skorosti[naiOtgore.x][naiOtgore.y] + visochini[naiOtgore.x][naiOtgore.y] -
                visochini[naiOtgore.x - 1][naiOtgore.y];

            int nomercheNaNoviq = daiNomercheZaTozi({naiOtgore.x - 1, naiOtgore.y, novoKolkoOtgoreSme});

            if((novoKolkoOtgoreSme > 0 && novoKolkoOtgoreSme <= maxVisochina) || nomercheNaNoviq == nomercheNaFinala){
                sasedstvo[nasheNomerche].push_back(nomercheNaNoviq);
                q.push({naiOtgore.x - 1, naiOtgore.y, novoKolkoOtgoreSme});
            }
        }
        if(naiOtgore.x < maxX){
            int novoKolkoOtgoreSme = naiOtgore.kolkoNadPovarhnosttaE - gubeneNaVisochina +
                skorosti[naiOtgore.x][naiOtgore.y] + visochini[naiOtgore.x][naiOtgore.y] -
                visochini[naiOtgore.x + 1][naiOtgore.y];

            int nomercheNaNoviq = daiNomercheZaTozi({naiOtgore.x + 1, naiOtgore.y, novoKolkoOtgoreSme});

            if((novoKolkoOtgoreSme > 0 && novoKolkoOtgoreSme <= maxVisochina) || nomercheNaNoviq == nomercheNaFinala){
                sasedstvo[nasheNomerche].push_back(nomercheNaNoviq);
                q.push({naiOtgore.x + 1, naiOtgore.y, novoKolkoOtgoreSme});
            }
        }
        if(naiOtgore.y > 1){
            int novoKolkoOtgoreSme = naiOtgore.kolkoNadPovarhnosttaE - gubeneNaVisochina +
                skorosti[naiOtgore.x][naiOtgore.y] + visochini[naiOtgore.x][naiOtgore.y] -
                visochini[naiOtgore.x][naiOtgore.y - 1];

            int nomercheNaNoviq = daiNomercheZaTozi({naiOtgore.x, naiOtgore.y - 1, novoKolkoOtgoreSme});

            if((novoKolkoOtgoreSme > 0 && novoKolkoOtgoreSme <= maxVisochina) || nomercheNaNoviq == nomercheNaFinala){
                sasedstvo[nasheNomerche].push_back(nomercheNaNoviq);
                q.push({naiOtgore.x, naiOtgore.y - 1, novoKolkoOtgoreSme});
            }
        }
        if(naiOtgore.y < maxY){
            int novoKolkoOtgoreSme = naiOtgore.kolkoNadPovarhnosttaE - gubeneNaVisochina +
                skorosti[naiOtgore.x][naiOtgore.y] + visochini[naiOtgore.x][naiOtgore.y] -
                visochini[naiOtgore.x][naiOtgore.y + 1];

            int nomercheNaNoviq = daiNomercheZaTozi({naiOtgore.x, naiOtgore.y + 1, novoKolkoOtgoreSme});

            if((novoKolkoOtgoreSme > 0 && novoKolkoOtgoreSme <= maxVisochina) || nomercheNaNoviq == nomercheNaFinala ){
                sasedstvo[nasheNomerche].push_back(nomercheNaNoviq);
                q.push({naiOtgore.x, naiOtgore.y + 1, novoKolkoOtgoreSme});
            }
        }

    }
}

void umnoPraveneNaSasedstvoto(){
    for(int z = 0; z <= maxVisochina; z++){
        for(int y = 1; y <= maxY; y++){
            for(int x = 1; x <= maxX; x++){
                int nasheNomerche = daiNomercheZaTozi({x, y, z});

                if(x > 1){
                    int novoKolkoOtgoreSme = z - gubeneNaVisochina +
                        skorosti[x][y] + visochini[x][y] -
                        visochini[x - 1][y];

                    int nomercheNaNoviq = daiNomercheZaTozi({x - 1, y, novoKolkoOtgoreSme});

                    if((novoKolkoOtgoreSme > 0 && novoKolkoOtgoreSme <= maxVisochina) || nomercheNaNoviq == nomercheNaFinala)
                    {
                        sasedstvo[nasheNomerche].push_back(nomercheNaNoviq);
                    }
                }
                if(x < maxX){
                    int novoKolkoOtgoreSme = z - gubeneNaVisochina +
                        skorosti[x][y] + visochini[x][y] -
                        visochini[x + 1][y];

                    int nomercheNaNoviq = daiNomercheZaTozi({x + 1, y, novoKolkoOtgoreSme});

                    if((novoKolkoOtgoreSme > 0 && novoKolkoOtgoreSme <= maxVisochina) || nomercheNaNoviq == nomercheNaFinala)
                    {
                        sasedstvo[nasheNomerche].push_back(nomercheNaNoviq);
                    }
                }
                if(y > 1){
                    int novoKolkoOtgoreSme = z - gubeneNaVisochina +
                        skorosti[x][y] + visochini[x][y] -
                        visochini[x][y - 1];

                    int nomercheNaNoviq = daiNomercheZaTozi({x, y - 1, novoKolkoOtgoreSme});

                    if((novoKolkoOtgoreSme > 0 && novoKolkoOtgoreSme <= maxVisochina) || nomercheNaNoviq == nomercheNaFinala)
                    {
                        sasedstvo[nasheNomerche].push_back(nomercheNaNoviq);
                    }
                }
                if(y < maxY){
                    int novoKolkoOtgoreSme = z - gubeneNaVisochina +
                        skorosti[x][y] + visochini[x][y] -
                        visochini[x][y + 1];

                    int nomercheNaNoviq = daiNomercheZaTozi({x, y + 1, novoKolkoOtgoreSme});

                    if((novoKolkoOtgoreSme > 0 && novoKolkoOtgoreSme <= maxVisochina) || nomercheNaNoviq == nomercheNaFinala)
                    {
                        sasedstvo[nasheNomerche].push_back(nomercheNaNoviq);
                    }
                }
            }
        }
    }
}

int dalbochina[3000000];

int bfs(){

    queue<int> q;
    q.push(nomercheNaStarta);

    while(q.empty() == false){
        int nasheNomerche = q.front();
        q.pop();

        if(nasheNomerche == nomercheNaFinala){
            break;
        }

        for(unsigned int i = 0; i < sasedstvo[nasheNomerche].size(); i++){
            int sledvahstoNomerche = sasedstvo[nasheNomerche][i];

            if(dalbochina[sledvahstoNomerche] == 0){
                dalbochina[sledvahstoNomerche] = dalbochina[nasheNomerche] + 1;
                q.push(sledvahstoNomerche);
            }
        }
    }

    if(dalbochina[nomercheNaFinala] == 0){
        return -1;
    }

    return dalbochina[nomercheNaFinala];
}

int main(){
    cin>>maxY>>maxX>>gubeneNaVisochina>>maxVisochina;

    for(int y = 1; y <= maxY; y++){
        for(int x = 1; x <= maxX; x++){
            cin>>visochini[x][y]>>skorosti[x][y];
        }
    }

    cin>>xGnezdo>>yGnezdo>>xPlyachka>>yPlyachka;

    nomercheNaStarta = daiNomercheZaTozi({xGnezdo, yGnezdo, 0});
    nomercheNaFinala = daiNomercheZaTozi({xPlyachka, yPlyachka, 0});

    umnoPraveneNaSasedstvoto();

    int prelitaniqDoTam = bfs();

    /*for(int i = 1; i <= broiObhodeniPoleta; i++){
        DanniZaPolenceto a = koiESTovaNomerche[i];
        cout<<a.x<<" "<<a.y<<" "<<a.kolkoNadPovarhnosttaE<<":"<<endl;
        for(int j : sasedstvo[i]){
            DanniZaPolenceto b = koiESTovaNomerche[j];
            cout<<b.x<<" "<<b.y<<" "<<b.kolkoNadPovarhnosttaE<<endl;
        }
        cout<<endl<<endl;;
    }*/

    if(prelitaniqDoTam == -1){
        cout<<"crash"<<endl;
    }else{
        cout<<prelitaniqDoTam<<endl;
    }

    return 0;
}
