#include<iostream>
#include<vector>
using namespace std;

const long long mnogo = 1000000000000000000;

string izraz;

vector<string> chasti;

bool znakLiE(char simvol){
    if(simvol == '+' || simvol == '-' || simvol == '*'){
        return true;
    }

    return false;
}

long long otStringVChislo(string zaPrevrashtane){
    long long chislo = 0;

    for(long long i = 0; i < (long long)zaPrevrashtane.size(); i++){
        chislo = 10*chislo + (zaPrevrashtane[i] - '0');
    }

    return chislo;
}

struct DanniZaVrashtane{
    long long naiMalak;
    long long naiGolqm;
    bool imaLiGo;
};

long long izvarshiDeistvieto(long long parvoChislo, long long vtoroChislo, char znak){
    if(znak == '+'){
        return parvoChislo + vtoroChislo;
    }
    if(znak == '-'){
        return parvoChislo - vtoroChislo;
    }
    return parvoChislo*vtoroChislo;
}

DanniZaVrashtane priTolkova[45][45];

DanniZaVrashtane otgovorZa(long long otIndex, long long daljina){
    long long doIndex = otIndex + daljina - 1;

    if(otIndex == doIndex){
        long long chislotoTuk = otStringVChislo(chasti[otIndex]);
        return {chislotoTuk, chislotoTuk, true};
    }

    if(priTolkova[otIndex][daljina].imaLiGo == true){
        return priTolkova[otIndex][daljina];
    }

    long long naiMalkoTuka = mnogo;
    long long naiGolqmoTuka = -mnogo;

    for(long long i = otIndex + 1; i <= doIndex - 1; i += 2){
        char znakTuka = chasti[i][0];
        DanniZaVrashtane parvoto = otgovorZa(otIndex, i - otIndex);
        DanniZaVrashtane vtoroto = otgovorZa(i + 1, doIndex - i);

        long long tukaNaiMalko = 0;
        long long tukaNaiGolqmo = 0;
        if(znakTuka == '-'){
            tukaNaiMalko = izvarshiDeistvieto(parvoto.naiMalak, vtoroto.naiGolqm, znakTuka);
            tukaNaiGolqmo = izvarshiDeistvieto(parvoto.naiGolqm, vtoroto.naiMalak, znakTuka);
        }else{
            tukaNaiMalko = izvarshiDeistvieto(parvoto.naiMalak, vtoroto.naiMalak, znakTuka);
            tukaNaiGolqmo = izvarshiDeistvieto(parvoto.naiGolqm, vtoroto.naiGolqm, znakTuka);
        }

        naiMalkoTuka = min(naiMalkoTuka, tukaNaiMalko);
        naiGolqmoTuka = max(naiGolqmoTuka, tukaNaiGolqmo);
    }

    priTolkova[otIndex][daljina].imaLiGo = true;
    priTolkova[otIndex][daljina].naiMalak = naiMalkoTuka;
    priTolkova[otIndex][daljina].naiGolqm = naiGolqmoTuka;
    return {naiMalkoTuka, naiGolqmoTuka, true};
}

DanniZaVrashtane sCycli(long long zaOtIndex, long long zaDaljina){
    //cout<<"paranetrite sa "<<zaOtIndex<<" "<<zaDaljina<<endl;

    for(long long i = zaOtIndex; i <= zaOtIndex + zaDaljina; i+=2){
        long long chislotoTuk = otStringVChislo(chasti[i]);
        //cout<<i<<" "<<chislotoTuk<<endl;
        priTolkova[i][1] = {chislotoTuk, chislotoTuk, false};
    }

    //cout<<"izlqzah"<<endl;

    for(long long daljina = 3; daljina <= zaDaljina; daljina+=2){
        for(long long otIndex = zaOtIndex; otIndex <= zaOtIndex + zaDaljina - daljina + 1; otIndex += 2){

            long long doIndex = otIndex + daljina - 1;

            long long naiMalkoTuka = mnogo;
            long long naiGolqmoTuka = -mnogo;

            //cout<<"sega she tursime za ot "<<otIndex<<" do "<<doIndex<<endl;

            for(long long i = otIndex + 1; i <= doIndex - 1; i += 2){
                //cout<<"tuka ito e "<<i<<" "<<endl;
                char znakTuka = chasti[i][0];
                //cout<<"znaka tuka e "<<znakTuka<<endl;
                DanniZaVrashtane parvoto = priTolkova[otIndex][i - otIndex];
                DanniZaVrashtane vtoroto = priTolkova[i + 1][doIndex - i];

                long long tukaNaiMalko = 0;
                long long tukaNaiGolqmo = 0;
                if(znakTuka == '-'){
                    tukaNaiMalko = izvarshiDeistvieto(parvoto.naiMalak, vtoroto.naiGolqm, znakTuka);
                    tukaNaiGolqmo = izvarshiDeistvieto(parvoto.naiGolqm, vtoroto.naiMalak, znakTuka);
                }else{
                    tukaNaiMalko = izvarshiDeistvieto(parvoto.naiMalak, vtoroto.naiMalak, znakTuka);
                    tukaNaiGolqmo = izvarshiDeistvieto(parvoto.naiGolqm, vtoroto.naiGolqm, znakTuka);
                }

                naiMalkoTuka = min(naiMalkoTuka, tukaNaiMalko);
                naiGolqmoTuka = max(naiGolqmoTuka, tukaNaiGolqmo);
            }

            priTolkova[otIndex][daljina].imaLiGo = true;
            priTolkova[otIndex][daljina].naiMalak = naiMalkoTuka;
            priTolkova[otIndex][daljina].naiGolqm = naiGolqmoTuka;

            //cout<<otIndex<<" "<<daljina<<" "<<doIndex<<" "<<naiMalkoTuka<<" "<<naiGolqmoTuka<<endl;
        }
    }

    //cout<<"i ot tuka izlqzah"<<endl;

    return priTolkova[zaOtIndex][zaDaljina];
}

int main(){
    cin>>izraz;

    for(long long i = 0; i < (long long)izraz.size(); i++){

        if(znakLiE(izraz[i]) == true){
            string tuka = "";
            tuka += izraz[i];

            chasti.push_back(tuka);
        }else{
            string tuka = "";

            while(znakLiE(izraz[i]) == false && i < (long long)izraz.size()){
                tuka.push_back(izraz[i]);
                i++;
            }

            i--;

            chasti.push_back(tuka);
        }
    }

    //DanniZaVrashtane otgovor = otgovorZa(0, (long long)chasti.size());
    DanniZaVrashtane otgovor = sCycli(0, (long long)chasti.size());

    cout<<otgovor.naiMalak<<endl;

    return 0;
}
