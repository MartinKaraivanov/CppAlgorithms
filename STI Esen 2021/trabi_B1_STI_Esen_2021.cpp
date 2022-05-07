#include<iostream>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;

int broiVarhove;

struct DanniZaTrabata{
    int doKoi;
    double kolkoProcenta;
    int modernaLiE;
};

vector<DanniZaTrabata> sasedstvo[1024];

double kolkoVodaTrqbvaV[1024];

struct DanniZaVarha{
    int koiVrah;
    double kolkoVodaStiga;
};

bool mojeLiSTolkova(double kolichestvoVoda){

    queue<DanniZaVarha> q;
    q.push({1, kolichestvoVoda});

    bool stavaLi = true;

    while(q.empty() == false){
        DanniZaVarha naiOtpred = q.front();
        q.pop();

        if(kolkoVodaTrqbvaV[naiOtpred.koiVrah] > -1 && kolkoVodaTrqbvaV[naiOtpred.koiVrah] - naiOtpred.kolkoVodaStiga > 0.0000000000001){
            stavaLi = false;
            break;
        }

        for(int i = 0; i < (int)sasedstvo[naiOtpred.koiVrah].size(); i++){
            double novaVoda = sasedstvo[naiOtpred.koiVrah][i].kolkoProcenta*naiOtpred.kolkoVodaStiga;
            if(sasedstvo[naiOtpred.koiVrah][i].modernaLiE == 1){
                novaVoda = novaVoda*novaVoda;
            }

            q.push({sasedstvo[naiOtpred.koiVrah][i].doKoi, novaVoda});
        }
    }

    return stavaLi;
}

int main(){

    cin>>broiVarhove;

    for(int i = 0; i < broiVarhove - 1; i++){
        int otKade;
        int doKade;
        double procent;
        int moderna;

        cin>>otKade>>doKade>>procent>>moderna;

        sasedstvo[otKade].push_back({doKade, procent/100, moderna});
    }

    for(int i = 1; i <= broiVarhove; i++){
        cin>>kolkoVodaTrqbvaV[i];
    }

    /*double nujnaVoda = -1;

    for(double i = 0; true; i += 0.001){
        if(mojeLiSTolkova(i)){
            nujnaVoda = i;
            break;
        }
    }

    cout<<fixed<<setprecision(3)<<nujnaVoda<<endl;*/

    double lqvKrai = 0;
    double desenKrai = 3000000000;

    while(lqvKrai + 0.00001 < desenKrai){
        double sredata = (lqvKrai + desenKrai)/2;

        bool tukaMojeLi = mojeLiSTolkova(sredata);

        //cout<<"pri lqv krai "<<lqvKrai<<" desen krai "<<desenKrai<<" i sreda "<<sredata<<" kazvame che "<<tukaMojeLi<<endl;

        if(tukaMojeLi == true){
            desenKrai = sredata;
        }else{
            lqvKrai = sredata + 0.00001;
        }
    }

    cout<<fixed<<setprecision(4)<<lqvKrai<<endl;

    return 0;
}
