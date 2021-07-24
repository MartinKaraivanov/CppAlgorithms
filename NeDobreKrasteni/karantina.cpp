#include<iostream>
#include<queue>
using namespace std;

string hora[12000];
int broiHora;

bool kontakt[12000][12000];
bool podKarantinaLiE[12000];

int nomerche(string ime){
    for(int i=0;i<broiHora;i++){
        if(ime==hora[i]){
            return i;
        }
    }
    return -1;
}

int dobavqne(string ime){
    hora[broiHora]=ime;
    broiHora++;
    return broiHora-1;
}

int daiNomerche(string ime){
    int nom=nomerche(ime);
    if(nom==-1){
        return dobavqne(ime);
    }else{
        return nom;
    }
}

int main(){
    string desenChovek;
    string lqvChovek;
    int nomerNaPacient;

    while(cin>>lqvChovek){
        if (cin>>desenChovek){
            int nomNaLqv=daiNomerche(lqvChovek);
            int nomNaDesen=daiNomerche(desenChovek);
            kontakt[nomNaLqv][nomNaDesen]=true;
            kontakt[nomNaDesen][nomNaLqv]=true;
        }else{
            nomerNaPacient=daiNomerche(lqvChovek);
        }
    }

    queue<int> karantina;

    karantina.push(nomerNaPacient);

    while(karantina.empty()==false){
        int segNomerche=karantina.front();
        karantina.pop();

        if(podKarantinaLiE[segNomerche]==false){
            podKarantinaLiE[segNomerche]=true;

            for(int drugChovek=0;drugChovek<broiHora;drugChovek++){
                if(kontakt[segNomerche][drugChovek]==true){
                    karantina.push(drugChovek);
                }
            }
        }
    }

    int broiZaKarantina=0;

    for(int i=0;i<broiHora;i++){
        if(podKarantinaLiE[i]==true){
            broiZaKarantina++;
        }
    }

    cout<<broiZaKarantina-1<<endl;

    return 0;
}
