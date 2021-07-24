#include<iostream>
#include<vector>
#include<stack>
#include<iomanip>
#include<cmath>
using namespace std;

vector<int> otKade;
vector<int> doKade;

vector<int> sabirane(vector<int> ednoChislo, vector<int> drugoChislo){
    int edinIndex = ednoChislo.size() - 1;
    int drugIndex = drugoChislo.size() - 1;

    stack<int> cifri;

    int ostatak = 0;

    while(edinIndex >= 0 || drugIndex >= 0){
        int ednataCifra;
        int drugataCifra;

        if(edinIndex >= 0){
            ednataCifra = ednoChislo[edinIndex];
        }else{
            ednataCifra = 0;
        }

        if(drugIndex >= 0){
            drugataCifra = drugoChislo[drugIndex];
        }else{
            drugataCifra = 0;
        }

        int tukaCifra = (ednataCifra + drugataCifra + ostatak)%10;

        ostatak = (ednataCifra + drugataCifra + ostatak)/10;

        //cout<<edinIndex<<" "<<drugIndex<<" "<<ednataCifra<<" "<<drugataCifra<<" "<<tukaCifra<<" "<<ostatak<<endl;

        cifri.push(tukaCifra);

        edinIndex--;
        drugIndex--;
    }

    if(ostatak > 0){
        cifri.push(ostatak);
    }

    vector<int> rezultat;

    while(cifri.empty() == false){
        rezultat.push_back(cifri.top());
        cifri.pop();
    }

    return rezultat;
}

vector<int> izvajdane(vector<int> umalqemo, vector<int> umalitel){
    int edinIndex = umalqemo.size() - 1;
    int drugIndex = umalitel.size() - 1;

    stack<int> cifri;

    int ostatak = 0;

    while(edinIndex >= 0){
        int ednaCifra = umalqemo[edinIndex];
        int drugaCifra;

        if(drugIndex >= 0){
            drugaCifra = umalitel[drugIndex];
        }else{
            drugaCifra = 0;
        }

        int tukaCifra = ednaCifra - drugaCifra - ostatak;

        if(tukaCifra < 0){
            tukaCifra += 10;
            ostatak = 1;
        }else{
            ostatak = 0;
        }

        cifri.push(tukaCifra);

        edinIndex--;
        drugIndex--;
    }

    vector<int> rezultat;

    bool slojiliLiSmeVeche = false;

    while(cifri.empty() == false){
        if(slojiliLiSmeVeche == false && cifri.top() == 0){
            cifri.pop();
        }else{

            slojiliLiSmeVeche = true;

            rezultat.push_back(cifri.top());
            cifri.pop();
        }
    }

    if(rezultat.size() == 0){
        rezultat.push_back(0);
    }

    return rezultat;
}

vector<int> delenieNaDve(vector<int> chislo){
    vector<int> rezultat;

    bool napraviliLiSmeDelenieVeche = false;

    int ostatak = 0;

    for(unsigned int i = 0; i < chislo.size(); i++){
        int tukaCifra = (chislo[i] + 10*ostatak)/2;

        //cout<<i<<" "<<tukaCifra<<" "<<ostatak<<endl;

        if(tukaCifra == 0 && napraviliLiSmeDelenieVeche == false){

        }else{
            rezultat.push_back(tukaCifra);
        }

        napraviliLiSmeDelenieVeche = true;

        ostatak = (10*ostatak + chislo[i])%2;
    }

    return rezultat;
}

bool tovaPoMalkoLiEOtDrugoto(vector<int> parvoto, vector<int> vtoroto){
    //cout<<parvoto.size()<<" "<<vtoroto.size()<<endl;
    if(parvoto.size() < vtoroto.size()){
        return true;
    }

    if(parvoto.size() > vtoroto.size()){
        return false;
    }

    bool poMalkoLiE = true;

    bool vichkiLiSaImEdnkavi = true;

    for(unsigned int i = 0; i < parvoto.size(); i++){
        if(parvoto[i] > vtoroto[i]){
            poMalkoLiE = false;
            vichkiLiSaImEdnkavi = false;
            break;
        }else{
            if(vtoroto[i] > parvoto[i]){
                vichkiLiSaImEdnkavi = false;
                break;
            }
        }
    }

    if(vichkiLiSaImEdnkavi == true){
        poMalkoLiE = false;
    }

    return poMalkoLiE;
}

bool poMalkoRavno(vector<int> parvoto, vector<int> vtoroto){
    if(parvoto.size() < vtoroto.size()){
        return true;
    }

    if(parvoto.size() > vtoroto.size()){
        return false;
    }

    bool poMalkoLiE = true;

    for(unsigned int i = 0; i < parvoto.size(); i++){
        if(parvoto[i] > vtoroto[i]){
            poMalkoLiE = false;
            break;
        }else{
            if(vtoroto[i] > parvoto[i]){
                break;
            }
        }
    }

    return poMalkoLiE;
}

vector<int> umnojenie(vector<int> parvo, vector<int> vtoro){
    int daljinaParvo = parvo.size();
    int daljinaVtoro = vtoro.size();

    if(daljinaParvo == daljinaVtoro && daljinaParvo == 0){
        return {0};
    }

    vector<int> obratenRezultat(daljinaParvo + daljinaVtoro, 0);

    int indexParvo = 0;
    int indexVtoro = 0;

    for(int i = daljinaParvo - 1; i >= 0; i--){
        int ostatak = 0;

        int cifraParvo = parvo[i];

        indexVtoro = 0;

        for(int j = daljinaVtoro - 1; j >= 0; j--){
            int cifraVtoro = vtoro[j];

            int sbor = cifraParvo*cifraVtoro + obratenRezultat[indexParvo + indexVtoro] + ostatak;

            ostatak = sbor/10;

            obratenRezultat[indexParvo + indexVtoro] = sbor%10;

            indexVtoro++;
        }

        if(ostatak > 0){
            obratenRezultat[indexParvo + indexVtoro] += ostatak;
        }

        indexParvo++;
    }

    for(int i = obratenRezultat.size() - 1; i >= 0; i--){
        if(obratenRezultat[i] == 0){
            obratenRezultat.pop_back();
        }else{
            break;
        }
    }

    if(obratenRezultat.size() == 0){
        return {0};
    }

    vector<int> istinskiRezultat;

    for(int i = obratenRezultat.size() - 1; i >= 0; i--){
        istinskiRezultat.push_back(obratenRezultat[i]);
    }

    return istinskiRezultat;
}

vector<int> otgovorZaDo(vector<int> doKoeChislo){
    vector<int> lqvKrai = {1};
    vector<int> desenKrai;

    desenKrai.push_back(1);

    for(unsigned int i = 0; i < doKoeChislo.size()/2 + 1; i++){
        desenKrai.push_back(0);
    }

    while(tovaPoMalkoLiEOtDrugoto(lqvKrai, desenKrai) == true){
        vector<int> poSredata = delenieNaDve(sabirane(lqvKrai, desenKrai));

        /*cout<<"lqv krai ";

        for(auto i : lqvKrai){
            cout<<i;
        }

        cout<<" desen krai ";

        for(auto i : desenKrai){
            cout<<i;
        }

        cout<<" sredata ";

        for(auto i : poSredata){
            cout<<i;
        }

        cout<<" ";*/

        if(poMalkoRavno(sabirane(umnojenie(poSredata, poSredata), poSredata), doKoeChislo) == true){
            lqvKrai = sabirane(poSredata, {1});
            //cout<<"tuka stava "<<endl;
        }else{
            desenKrai = poSredata;
            //cout<<"tuka ne stava "<<endl;
        }
    }

    /*cout<<"tuka vrashtame ";

    for(auto i : lqvKrai){
        cout<<i;
    }

    cout<<endl;*/

    return lqvKrai;
}

/*long double naiGolqmotoDo(long double krai){
    long double lqvKrai = 1;
    long double desenKrai = sqrt(krai) + 1;

    //cout<<fixed<<setprecision(0)<<lqvKrai<<" "<<desenKrai<<endl<<endl;

    while(lqvKrai < desenKrai){
        long double poSredata = floor((lqvKrai + desenKrai)/2);

        //cout<<fixed<<setprecision(0)<<lqvKrai<<" "<<desenKrai<<endl;

        //cout<<fixed<<setprecision(0)<<krai<<" "<<poSredata<<" ";

        if(krai - (poSredata*poSredata + poSredata) > -0.000000001){
            lqvKrai = poSredata + 1;
            //cout<<"tuova stava"<<endl;
        }else{
            desenKrai = poSredata;
            //cout<<"tova ne stava "<<endl;
        }
    }

    //cout<<"tuka vrashtame "<<fixed<<setprecision(0)<<lqvKrai<<endl;
    return lqvKrai;
}

long double otKade;
long double doKade;*/

int main(){
    string parvoChislo;
    string vtoroChislo;

    cin>>parvoChislo>>vtoroChislo;

    for(unsigned int i = 0; i < parvoChislo.size(); i++){
        otKade.push_back(parvoChislo[i] - '0');
    }

    for(unsigned int i = 0; i < vtoroChislo.size(); i++){
        doKade.push_back(vtoroChislo[i] - '0');
    }

    /*vector<int> res = sabirane(umnojenie({2,5,0,0,0,0,0}, {2,5,0,0,0,0,0}), {2,5,0,0,0,0,0});

    for(auto i : res){
        cout<<i;
    }

    cout<<endl<<endl;*/

    vector<int> otgovorZaN = otgovorZaDo(doKade);
    vector<int> otgovorZaM = otgovorZaDo(izvajdane(otKade, {1}));

    vector<int> otg = izvajdane(otgovorZaN, otgovorZaM);

    for(unsigned int i = 0; i < otg.size(); i++){
        cout<<otg[i];
    }

    cout<<endl;


    /*cin>>otKade>>doKade;

    cout<<fixed<<setprecision(0)<<naiGolqmotoDo(doKade) - naiGolqmotoDo(otKade - 1)<<endl;*/

    return 0;
}
