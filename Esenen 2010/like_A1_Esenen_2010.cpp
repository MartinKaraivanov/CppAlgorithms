#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
using namespace std;

int broiVarhove;
int broiRebra;

vector<int> sasedstvo[1010];

void dopalni(){
    for(int i = 1; i <= broiVarhove; i++){
        if(sasedstvo[i].size() % 2 == 1){
            sasedstvo[i].push_back(0);
            sasedstvo[0].push_back(i);
        }
    }
}

void mahniRebro(int otKade, int doKade){

    for(int i = 0; i < (int)sasedstvo[otKade].size(); i++){
        if(sasedstvo[otKade][i] == doKade){
            sasedstvo[otKade][i] = -1;
            break;
        }
    }

    for(int i = 0; i < (int)sasedstvo[doKade].size(); i++){
        if(sasedstvo[doKade][i] == otKade){
            sasedstvo[doKade][i] = -1;
            break;
        }
    }
}

void eulerovCikal(int start){

    stack<int> s;
    s.push(start);

    vector<int> resultat;

    while(s.empty() == false){
        int naiOtgore = s.top();

        //resultat.push_back(naiOtgore);

        int sledvashtiq = -1;

        for(int i = 0; i < (int)sasedstvo[naiOtgore].size(); i++){
            if(sasedstvo[naiOtgore][i] != -1){
                sledvashtiq = sasedstvo[naiOtgore][i];
                break;
            }
        }

        if(sledvashtiq == -1){
            s.pop();
            resultat.push_back(naiOtgore);
        }else{
            mahniRebro(naiOtgore, sledvashtiq);
            s.push(sledvashtiq);
        }
    }

    for(int i = 2; i < (int)resultat.size() - 1; i++){
        cout<<resultat[i - 1]<<" "<<resultat[i]<<endl;
    }

}

int main(){
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiVarhove>>broiRebra;*/

    scanf("%d %d", &broiVarhove, &broiRebra);

    for(int i = 0; i < broiRebra; i++){
        int otKade;
        int doKade;

        //cin>>otKade>>doKade;

        scanf("%d %d", &otKade, &doKade);

        sasedstvo[otKade].push_back(doKade);
        sasedstvo[doKade].push_back(otKade);
    }

    dopalni();

    //cout<<"Yes"<<endl;

    printf("Yes \n");

    eulerovCikal(0);

    return 0;
}
