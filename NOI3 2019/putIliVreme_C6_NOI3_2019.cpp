#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct Danni{
    int toziVrah;
    int toziSkorost;
    double vremeDoNego;
    int otKadeIdvame;
    int otKadeSkorost;
    bool operator<(const Danni& a) const {
        return vremeDoNego > a.vremeDoNego;
    }
};

int broiVarhove;
int broiPatishta;
int doKade;

int ogranichenie[200][200];
int dalzhina[200][200];
bool sasedstvo[200][200];

bool namerenLiE[200][550];
Danni patche[200][550];

int main(){
    cin>>broiVarhove>>broiPatishta>>doKade;

    for(int i = 0; i < broiPatishta; i++){
        int otKoi;
        int doKoi;
        int ogrSkorost;
        int dalg;

        cin>>otKoi>>doKoi>>ogrSkorost>>dalg;

        sasedstvo[otKoi][doKoi] = true;

        ogranichenie[otKoi][doKoi] = ogrSkorost;
        dalzhina[otKoi][doKoi] = dalg;
    }

//    for(int i = 0; i < 200; i++){
//        patche[i] = -1;
//    }

    Danni posleden = {-1, -2, -3, -4, -5};

    priority_queue<Danni> q;
    Danni nachalno = {0, 70, 0, -1, 0};
    q.push(nachalno);
    while(q.empty() == false){
        Danni segashen = q.top();
        q.pop();

        if(namerenLiE[segashen.toziVrah][segashen.toziSkorost]){
            continue;
        }

        namerenLiE[segashen.toziVrah][segashen.toziSkorost] = true;
        patche[segashen.toziVrah][segashen.toziSkorost] = segashen;

        if(segashen.toziVrah == doKade){
            posleden = segashen;
            break;
        }

        for(int doVrah = 0; doVrah < broiVarhove; doVrah++){
            if(sasedstvo[segashen.toziVrah][doVrah] == true){
                int skorost;
                if(ogranichenie[segashen.toziVrah][doVrah] != 0){
                    skorost = ogranichenie[segashen.toziVrah][doVrah];
                }else{
                    skorost = segashen.toziSkorost;
                }

                if(namerenLiE[doVrah][skorost] == true){
                    continue;
                }

                double dSkorost = skorost;
                double d = dalzhina[segashen.toziVrah][doVrah];
                double oshteVreme = d/dSkorost;
                double novoVreme = segashen.vremeDoNego + oshteVreme;

                Danni zaDob = {doVrah, skorost, novoVreme, segashen.toziVrah, segashen.toziSkorost};
                q.push(zaDob);
            }
        }
    }

    stack<int> s;
    Danni vrah = posleden;
    while(true){
        //cout<<vrah.toziVrah<<" "<<vrah.toziSkorost
          //  <<" "<<vrah.vremeDoNego<<" "<<" "<<vrah.otKadeIdvame<<" "<<vrah.otKadeSkorost<<endl;

        s.push(vrah.toziVrah);

        if(vrah.otKadeIdvame == -1){
            break;
        }

        vrah = patche[vrah.otKadeIdvame][vrah.otKadeSkorost];

    }

    //cout<<"oshte edno stigame"<<endl;

    while(s.empty() == false){
        int naiOtgore = s.top();
        s.pop();
        cout<<naiOtgore<<" ";
    }

    return 0;
}
