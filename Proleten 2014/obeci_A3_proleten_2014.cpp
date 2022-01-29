#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<stack>
using namespace std;

struct Coordinati{
    double x;
    double y;
};

int broiTochki;

Coordinati tochki[2010];

double razstMejdu(Coordinati parva, Coordinati vtora){
    return sqrt((parva.x - vtora.x)*(parva.x - vtora.x) + (parva.y - vtora.y)*(parva.y - vtora.y));
}

vector<int> sasedstvo[4020];

bool visited[4020];
bool reverseVisited[4020];

stack<int> s;

int whichSCC[4020];

int counterSCC;

void dfs(int segashenVrah){
    if(visited[segashenVrah] == true){
        return ;
    }

    visited[segashenVrah] = true;

    for(int i = 0; i < (int)sasedstvo[segashenVrah].size(); i++){
         if(visited[sasedstvo[segashenVrah][i]] == false){
            dfs(sasedstvo[segashenVrah][i]);
         }
    }

    s.push(segashenVrah);
}

void reverseDFS(int segashenVrah){
    if(reverseVisited[segashenVrah] == true){
        return ;
    }

    reverseVisited[segashenVrah] = true;

    for(int i = 0; i < (int)sasedstvo[segashenVrah].size(); i++){
        if(reverseVisited[sasedstvo[segashenVrah][i]] == false){
            reverseDFS(sasedstvo[segashenVrah][i]);
        }
    }

    whichSCC[segashenVrah] = counterSCC;
}

bool stavaLiSTolkova(double naiGolqmoRazst){

    for(int i = 0; i <= broiTochki*2; i++){
        sasedstvo[i].clear();
        whichSCC[i] = 0;
        visited[i] = false;
        reverseVisited[i] = false;
    }
    counterSCC = 0;

    for(int i = 0; i < broiTochki; i++){
        for(int j = i + 1; j < broiTochki; j++){
            double razstTuka = razstMejdu(tochki[i], tochki[j]);

            if(razstTuka > naiGolqmoRazst){
                sasedstvo[i + broiTochki].push_back(j);
                sasedstvo[j + broiTochki].push_back(i);
                sasedstvo[i].push_back(j + broiTochki);
                sasedstvo[j].push_back(i + broiTochki);
            }else{
                /*sasedstvo[i].push_back(j);
                sasedstvo[j].push_back(i);
                sasedstvo[i + broiTochki].push_back(j + broiTochki);
                sasedstvo[j + broiTochki].push_back(i + broiTochki);*/
            }
        }
    }

    for(int i = 0; i < 2*broiTochki; i++){
        if(visited[i] == false){
            dfs(i);
        }
    }

    while(s.empty() == false){
        int naiOtgore = s.top();
        s.pop();

        if(reverseVisited[naiOtgore] == false){
            counterSCC++;
            reverseDFS(naiOtgore);
        }
    }

    bool mojeLi = true;

    for(int i = 0; i < broiTochki; i++){
        if(whichSCC[i] == whichSCC[i + broiTochki]){
            mojeLi = false;
            break;
        }
    }

    return mojeLi;
}

int main(){
    cin>>broiTochki;

    for(int i = 0; i < broiTochki; i++){
        cin>>tochki[i].x>>tochki[i].y;
    }

    double naiGolqmotoRazstoqnie = 0;

    for(int i = 0; i < broiTochki; i++){
        for(int j = i + 1; j < broiTochki; j++){
            double tuka = razstMejdu(tochki[i], tochki[j]);
            naiGolqmotoRazstoqnie = max(naiGolqmotoRazstoqnie, tuka);
        }
    }

    /*for(int i = 0; i < broiTochki; i++){
        for(int j = i + 1; j < broiTochki; j++){
            cout<<i<<" "<<j<<" "<<razstMejdu(tochki[i], tochki[j])<<endl;
        }
    }*/

    //cout<<"v nachaloto nai golqmoto e "<<naiGolqmotoRazstoqnie<<endl;

    double lqvKrai = 0;
    double desenKrai = naiGolqmotoRazstoqnie;
    double stapka = 0.0000001;

    while(lqvKrai + stapka < desenKrai){
        double sredata = (lqvKrai + desenKrai)/2;

        //cout<<"tuka proverqvame za "<<sredata<<endl;

        if(stavaLiSTolkova(sredata) == true){
            desenKrai = sredata;
            //cout<<"stava"<<endl;
        }else{
            lqvKrai = sredata + stapka;
            //cout<<"ne stava"<<endl;
        }
    }

    cout<<fixed<<setprecision(6)<<lqvKrai<<endl;

    return 0;
}
