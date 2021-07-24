#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct DanniZaParvaStepenKoreni{
    double koren;
    bool nalqvoOtNegoLiEPolozhitelno;
};

struct DanniZaVtoraStepenKoreni{
    double parviKoren;
    double vtoriKoren;
    bool mezhduTqhliEPolozhitelno;
};

int broiMillioneri;
int broiPitaniq;

vector<double> uravneniqParvaStepen[100010];
int broiOtParvaStepen;
vector<DanniZaParvaStepenKoreni> koreniNaParvataStepen;

vector<double> uravneniqVtoraStepen[100010];
int broiOtVtoraStepen;
vector<DanniZaVtoraStepenKoreni> koreniNaVtorataStepen;

vector<double> uravneniqTretaStepen[100010];
int broiOtTretaStepen;

double pitaniq[100010];

int broiPechelivshiPriTakavaCena[100010];

void praveneNaKoreniteNaParviteStepeni(){
    for(int i = 0; i < broiOtParvaStepen; i++){
        double koren;
        double a = uravneniqParvaStepen[i][0];
        double b = uravneniqParvaStepen[i][1];
        koren = (0 - b)/a;

        bool prediKorenaLiEPolozhitelno;
        if(a > 0){
            prediKorenaLiEPolozhitelno = false;
        }else{
            prediKorenaLiEPolozhitelno = true;
        }

        DanniZaParvaStepenKoreni novKoren = {koren, prediKorenaLiEPolozhitelno};
        koreniNaParvataStepen.push_back(novKoren);
    }
}

void praveneNaKoreniteNaVtoriteStepeni(){
    for(int i = 0; i < broiOtVtoraStepen; i++){
        double a = uravneniqVtoraStepen[i][0];
        double b = uravneniqVtoraStepen[i][1];
        double c = uravneniqVtoraStepen[i][2];

        double discriminanta = b*b - 4*a*c;

        if(discriminanta <= 0){

        }else{
            double parviKoren = (-b + sqrt(discriminanta))/(2*a);
            double vtoriKoren = (-b - sqrt(discriminanta))/(2*a);
        }

        bool mezhduTqhLiEPolozhitelno;

        if(a > 0){
            mezhduTqhLiEPolozhitelno = false;
        }else{
            mezhduTqhLiEPolozhitelno = true;
        }

        DanniZaVtoraStepenKoreni zaDob = {parviKoren, vtoriKoren, mezhduTqhLiEPolozhitelno};

        koreniNaVtorataStepen.push_back(zaDob);
    }
}

bool polozhitelnaLiEPechalbataNaToziChovekPriTaziCena(int koiMillioner, int koqCena){
    double pechalbaZaSega = 0;

    for(unsigned int i = 0; i < uravneniqTretaStepen[koiMillioner].size(); i++){
        double zaTuka = uravneniqTretaStepen[koiMillioner][i]*pow(pitaniq[koqCena], uravneniqTretaStepen[koiMillioner].size() - i - 1);
        pechalbaZaSega += zaTuka;
    }

    if(pechalbaZaSega > 0){
        return true;
    }

    return false;
}

int main(){
    cin>>broiMillioneri>>broiPitaniq;

    for(int i = 0; i < broiMillioneri; i++){
        int broiKoeficienti;
        cin>>broiKoeficienti;
        for(int j = 0; j < broiKoeficienti; j++){
            double saotvetenKoeficient;
            cin>>saotvetenKoeficient;
            if(broiKoeficienti == 4){
                uravneniqTretaStepen[broiOtTretaStepen].push_back(saotvetenKoeficient);
            }else{
                if(broiKoeficienti == 3){
                    uravneniqVtoraStepen[broiOtVtoraStepen].push_back(saotvetenKoeficient);
                }else{
                    uravneniqParvaStepen[broiOtParvaStepen].push_back(saotvetenKoeficient);
                }
            }
        }
        if(broiKoeficienti == 4){
            broiOtTretaStepen++;
        }else{
            if(broiKoeficienti == 3){
                broiOtVtoraStepen++;
            }else{
                broiOtParvaStepen++;
            }
        }
    }

    for(int i = 0; i < broiPitaniq; i++){
        cin>>pitaniq[i];
    }

    praveneNaKoreniteNaParviteStepeni();
    praveneNaKoreniteNaVtoriteStepeni();

    cout<<endl;

    for(int i = 0; i < broiOtParvaStepen; i++){
        DanniZaParvaStepenKoreni segashno = koreniNaParvataStepen[i];
        cout<<segashno.koren<<" "<<segashno.nalqvoOtNegoLiEPolozhitelno<<endl;
    }

    cout<<endl;

    for(int i = 0; i < broiOtVtoraStepen; i++){
        DanniZaVtoraStepenKoreni segashno = koreniNaVtorataStepen[i];
        cout<<segashno.parviKoren<<" "<<segashno.vtoriKoren<<" "<<segashno.mezhduTqhliEPolozhitelno<<endl;
    }

    for(int i = 0; i < broiPitaniq; i++){
        for(int j = 0; j < broiOtTretaStepen; j++){
            bool polozhitelnaLiENaTozi = polozhitelnaLiEPechalbataNaToziChovekPriTaziCena(j, i);
            if(polozhitelnaLiENaTozi){
                broiPechelivshiPriTakavaCena[i]++;
            }
        }
    }

    for(int i = 0; i < broiPitaniq; i++){
        cout<<broiPechelivshiPriTakavaCena[i]<<endl;
    }

    return 0;
}
