#include<iostream>
#include<vector>
using namespace std;

int broiLinii;

vector<int> sasedstvo[20010];

vector<int> vsekiParvi;

bool visited[20010];

bool istinskoVisited[20010];

bool imaLiCikul(int segashen){
    //cout<<segashen<<" "<<otKoiTragnahme<<" "<<parviqLiE<<endl;
    if(visited[segashen] == true){
        return true;
    }

    if(istinskoVisited[segashen] == true){
        return false;
    }

    istinskoVisited[segashen] = true;

    visited[segashen] = true;

    bool zaVrasht = false;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        bool tekushto = imaLiCikul(sasedstvo[segashen][i]);
        if(tekushto == true){
            zaVrasht = tekushto;
            break;
        }
    }

    visited[segashen] = false;
    return zaVrasht;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiLinii;

    for(int i = 0; i < broiLinii; i++){
        int broiTuka;
        cin>>broiTuka;

        int predishen;
        cin>>predishen;

        sasedstvo[0].push_back(predishen);

        for(int j = 1; j < broiTuka; j++){
            int segashen;
            cin>>segashen;

            sasedstvo[predishen].push_back(segashen);
            predishen = segashen;
        }
    }

    bool mojemLi = !imaLiCikul(0);

    if(mojemLi == true){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }

    return 0;
}
