#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct DanniZaUchastnika{
    string ime;
    double bal;
    int redNaPristigane;

    DanniZaUchastnika(string ime, double bal, int redNaPristigane)
        : ime(ime), bal(bal), redNaPristigane(redNaPristigane)
    {

    }
};

struct koiSheGoIzslushatParvo{
    bool operator()(DanniZaUchastnika const& a, DanniZaUchastnika const& b)
    {
        if(a.bal < b.bal){
            return true;
        }else{
            if(a.bal > b.bal){
                return false;
            }else{
                return a.redNaPristigane > b.redNaPristigane;
            }
        }
    }
};

priority_queue<DanniZaUchastnika, vector<DanniZaUchastnika>, koiSheGoIzslushatParvo> q;

int main(){
    int broiDni;

    cin>>broiDni;

    int uchastnikNomer = 1;

    for(int d = 0; d < broiDni; d++){
        int broiZaToziDen;
        cin>>broiZaToziDen;

        for(int i = 0; i < broiZaToziDen; i++){
            string kakSeKazva;
            double kolkoMuEBala;
            cin>>kakSeKazva>>kolkoMuEBala;

            q.push({kakSeKazva, kolkoMuEBala, uchastnikNomer});
            uchastnikNomer++;
        }

        int broiPreslushani;

        cin>>broiPreslushani;

        for(int i = 0; i < broiPreslushani; i++){
            q.pop();
        }

    }

    cout<<q.top().ime<<endl;

    return 0;
}
