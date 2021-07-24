#include<iostream>
#include<queue>
#include<vector>
//#include<algorithm>
using namespace std;

struct Danni{
    int vrah;
    int razstoqnie;
};

int broiVarhove;
int broiRebra;

int koiVrah;
int pgOtkolkoDaERazst;

vector<int> sasedstvo[100010];


bool visited[100010];

int varhoveOtPeriferiqta[100010];
int broiVarhoveOtPeriferiqta;

bool vatreLiE[100010];
int broiVatre;

int main(){
    cin>>broiVarhove>>broiRebra>>koiVrah>>pgOtkolkoDaERazst;

    for(int i = 0; i < broiRebra; i++){
        int otVrah;
        int doVrah;
        cin>>otVrah>>doVrah;
        sasedstvo[otVrah].push_back(doVrah);
        sasedstvo[doVrah].push_back(otVrah);
    }

    /*for(int i = 1; i <= broiVarhove; i++){
            cout<<i<<" : ";
        for(int sased : sasedstvo[i]){
            cout<<sased<<" ";
        }
        cout<<endl;
    }*/

    queue<Danni> q;

    Danni nachalno = {koiVrah, 0};

    q.push(nachalno);

    while(q.empty() == false){
        Danni naiOtgore = q.front();
        q.pop();

        if(naiOtgore.razstoqnie <= pgOtkolkoDaERazst && visited[naiOtgore.vrah] == false){
            vatreLiE[naiOtgore.vrah] = true;
            broiVatre ++;
        }

        if(naiOtgore.razstoqnie > pgOtkolkoDaERazst){
            break;
        }

        /*if(naiOtgore.razstoqnie > pgOtkolkoDaERazst && visited[naiOtgore.vrah] == false){
            varhoveOtPeriferiqta[broiVarhoveOtPeriferiqta] = naiOtgore.vrah;
            broiVarhoveOtPeriferiqta++;
            //cout<<"Namerih novo periferno, do vrah "<<naiOtgore.vrah<<" i razst e "<<naiOtgore.razstoqnie<<endl;
        }*/

        visited[naiOtgore.vrah] = true;
        //cout<<endl<<"Tuko shto "<<naiOtgore.vrah<<" stana poseten "<<endl;



        for(int k = 0; k < sasedstvo[naiOtgore.vrah].size(); k++){
            int sased = sasedstvo[naiOtgore.vrah][k];
            Danni zaDob = {sased, naiOtgore.razstoqnie + 1};

            if(visited[sased] == false){
                q.push(zaDob);
                //cout<<"Tuko shto dobavih v opashkata sased "<<zaDob.vrah<<" i razstoqnie "<<zaDob.razstoqnie<<endl;
            }
        }

    }

    /*sort(varhoveOtPeriferiqta, varhoveOtPeriferiqta + broiVarhoveOtPeriferiqta);

    cout<<broiVarhoveOtPeriferiqta<<endl;

    for(int i = 0; i < broiVarhoveOtPeriferiqta; i++){
        cout<<varhoveOtPeriferiqta[i]<<endl;
    }*/

    cout<<broiVarhove - broiVatre<<endl;

    for(int i = 1; i <= broiVarhove; i++){
        if(vatreLiE[i] == false){
            cout<<i<<endl;
        }
    }

    return 0;
}
