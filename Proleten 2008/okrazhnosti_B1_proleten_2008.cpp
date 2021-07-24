#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;

struct DanniZaOkrazhnost{
    double xCentar;
    double yCentar;
    double radius;
};

int broiOkrazhnosti;

DanniZaOkrazhnost okrazhnosti[1010];

vector<int> sasedniNaTozi[1010];

int bfs(){
    int dalbochina[1010];

    for(int i = 0; i <= broiOkrazhnosti; i++){
        dalbochina[i] = -1;
    }

    queue<int> q;

    q.push(1);
    dalbochina[1] = 0;

    while(q.empty() == false){
        int vrah = q.front();
        q.pop();

        if(vrah == broiOkrazhnosti){
            break;
        }

        for(unsigned int i = 0; i < sasedniNaTozi[vrah].size(); i++){
            if(dalbochina[sasedniNaTozi[vrah][i]] == -1){
               dalbochina[sasedniNaTozi[vrah][i]] = dalbochina[vrah] + 1;
               q.push(sasedniNaTozi[vrah][i]);
            }
        }
    }

    return dalbochina[broiOkrazhnosti];
}

bool dveteOkrazhnostiPresichatLiSeTochnoVDveTochki(int parva, int vtora){
    double razstMuXce = okrazhnosti[parva].xCentar - okrazhnosti[vtora].xCentar;
    double razstMuYce = okrazhnosti[parva].yCentar - okrazhnosti[vtora].yCentar;

    double razstoqqnieMezzhduDvataCentura = sqrt(razstMuXce * razstMuXce + razstMuYce * razstMuYce);

    double razlikaNaRadiusite = abs(okrazhnosti[parva].radius - okrazhnosti[vtora].radius);
    double sborNaRadiusite = okrazhnosti[parva].radius + okrazhnosti[vtora].radius;

    if(razstoqqnieMezzhduDvataCentura - razlikaNaRadiusite > 0.000001 &&
        sborNaRadiusite - razstoqqnieMezzhduDvataCentura > 0.000001)
    {
        return true;
    }else{
        return false;
    }
}

int main(){
    cin>>broiOkrazhnosti;

    for(int i = 1; i <= broiOkrazhnosti; i++){
        double x;
        double y;
        double radius;

        cin>>x>>y>>radius;

        okrazhnosti[i] = {x, y, radius};

        for(int j = 1; j < i; j++){
            if(dveteOkrazhnostiPresichatLiSeTochnoVDveTochki(i, j) == true){
                sasedniNaTozi[i].push_back(j);
                sasedniNaTozi[j].push_back(i);
            }
        }
    }

    int razstoqnie = bfs();

    cout<<razstoqnie<<endl;

    return 0;
}
