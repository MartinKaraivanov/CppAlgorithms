#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int broiTochki;

struct DanniZaTochka{
    int x;
    int y;
    int tip;
    int origNomer;
};

DanniZaTochka tochki[300010];

DanniZaTochka startova;
DanniZaTochka drugVidStart;

double izchisliAgal(DanniZaTochka a, DanniZaTochka b){
    return atan2((double)b.y-a.y, (double)b.x-a.x);
}


bool koqEPoNapred(DanniZaTochka a, DanniZaTochka b){

    double parviAgal = izchisliAgal(startova, drugVidStart);
    double vtoriAgal = izchisliAgal(startova, a);
    double tretiAgal = izchisliAgal(startova, b);

    return abs(vtoriAgal - parviAgal) > abs(tretiAgal - parviAgal);
}

int main(){

    cin>>broiTochki;

    for(int i = 0; i < broiTochki; i++){
        cin>>tochki[i].x>>tochki[i].y;
        tochki[i].tip = 1;
        tochki[i].origNomer = i + 1;
    }

    for(int i = broiTochki; i < 2*broiTochki; i++){
        cin>>tochki[i].x>>tochki[i].y;
        tochki[i].tip = 2;
        tochki[i].origNomer = i + 1;
    }

    startova = tochki[0];
    drugVidStart = tochki[broiTochki + 1];
    swap(tochki[broiTochki + 1], tochki[1]);

    sort(tochki + 2, tochki + 2*broiTochki, koqEPoNapred);

    /*
    cout<<endl;
    cout<<tochki[0].x<<" "<<tochki[0].y<<endl;
    cout<<tochki[1].x<<" "<<tochki[1].y<<endl<<endl;

    for(int i = 2; i < 2*broiTochki; i++){
        cout<<tochki[i].x<<" "<<tochki[i].y<<"  "<<tochki[i].tip<<" "<<tochki[i].origNomer<<endl;
    }
    */

    vector<pair<int, int>> vrazki;
    int segashnaCherv = -1;

    for(int i = 1; i < 2*broiTochki; i++){
        if(tochki[i].tip == 2){
            vrazki.push_back({startova.origNomer, tochki[i].origNomer});
            segashnaCherv = tochki[i].origNomer;
        }else{
            vrazki.push_back({segashnaCherv, tochki[i].origNomer});
        }
    }

    cout<<vrazki.size()<<endl;

    for(int i = 0; i < (int)vrazki.size(); i++){
        cout<<vrazki[i].first<<" "<<vrazki[i].second<<endl;
    }

    return 0;
}
