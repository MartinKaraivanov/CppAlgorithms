#include<iostream>
#include<algorithm>
using namespace std;

int kolkoTochki;
int dx;
int dy;

struct coordinatiNaTochkite{
    int y;
    int x;
};

bool tochkataVPravoagalnikaLiE(int yNaTochkata, int xNaTochkata, int yNaPravoagalnika, int xNaPravoagalnika, int dy, int dx){
    if((xNaTochkata<=xNaPravoagalnika+dx) &&
       (xNaTochkata>=xNaPravoagalnika) &&
       (yNaTochkata>=yNaPravoagalnika-dy) &&
       (yNaTochkata<=yNaPravoagalnika)){
        return true;
    }else{
        return false;
    }
}

bool poMalkoLiE(coordinatiNaTochkite c, coordinatiNaTochkite d){
    if(c.x==d.x){
        return c.y>d.y;
    }else{
        return c.x<d.x;
    }
}

coordinatiNaTochkite tochki[120000];

int main(){
    cin>>kolkoTochki>>dx>>dy;


    for(int i=0;i<kolkoTochki;i++){
        cin>>tochki[i].x>>tochki[i].y;
    }

    sort(tochki, tochki+kolkoTochki, poMalkoLiE);

    int maximalenBroiPrepokritiTochki=0;

    for(int i=0;i<kolkoTochki;i++){
        int broiTochkiVPravoagalnika=0;
        for(int j=i;j<kolkoTochki;j++){
            bool vPravoagLiE=tochkataVPravoagalnikaLiE(tochki[j].y, tochki[j].x, tochki[i].y, tochki[i].x, dy, dx);

            if(vPravoagLiE==true){
                broiTochkiVPravoagalnika++;
            }

            if(tochki[j].x>tochki[i].x+dx){
                break;
            }
        }
        if(broiTochkiVPravoagalnika>maximalenBroiPrepokritiTochki){
            maximalenBroiPrepokritiTochki=broiTochkiVPravoagalnika;
        }
    }

    cout<<maximalenBroiPrepokritiTochki<<endl;

    return 0;
}
