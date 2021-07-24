#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int broiComputri;
int broiVrazki;

vector<int> normalnoSasedstvo[1630];

vector<int> obratnoSasedstvo[1630];

int tipove[1630]; /// 0 - neizpolzvano, 1 - izpolzvano, 2 - nachalno

void bfs(int start, vector<int> sasedstvo[1630]){
    bool visited[1630];

    for(int i = 0; i < broiComputri; i++){
        visited[i] = false;
    }

    queue<int> q;

    q.push(start);
    tipove[start] = 2;
    visited[start] = true;

    while(q.empty() == false){
        int naiOtpred = q.front();
        q.pop();

        if(visited[naiOtpred] == true && naiOtpred != start){
            continue;
        }
        visited[naiOtpred] = true;

        if(tipove[naiOtpred] == 2 && naiOtpred == start){

        }else{
            tipove[naiOtpred] = 1;
        }

        for(unsigned int i = 0; i < sasedstvo[naiOtpred].size(); i++){
            if(visited[sasedstvo[naiOtpred][i]] == false){
                q.push(sasedstvo[naiOtpred][i]);
            }
        }

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiComputri>>broiVrazki;

    for(int i = 0; i < broiVrazki; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;

        normalnoSasedstvo[otKade].push_back(doKade);
        obratnoSasedstvo[doKade].push_back(otKade);
    }

    for(int i = 0; i < broiComputri; i++){
        if(tipove[i] == 0){
            bfs(i, normalnoSasedstvo);
        }
    }

    int broiStartirashti = 0;

    for(int i = 0; i < broiComputri; i++){
        if(tipove[i] == 2){
            broiStartirashti++;
        }
    }

    for(int i = 0; i < broiComputri; i++){
        tipove[i] = 0;
    }

    for(int i = 0; i < broiComputri; i++){
        if(tipove[i] == 0){
            bfs(i, obratnoSasedstvo);
        }
    }

    int broiObratniStartirashti = 0;

    for(int i = 0; i < broiComputri; i++){
        if(tipove[i] == 2){
            broiObratniStartirashti++;
        }
    }

    cout<<broiStartirashti<<" ";

    if(broiObratniStartirashti == 1 && broiStartirashti == 1){
        cout<<0<<endl;
    }else{
        cout<<max(broiObratniStartirashti, broiStartirashti)<<endl;
    }

    return 0;
}
