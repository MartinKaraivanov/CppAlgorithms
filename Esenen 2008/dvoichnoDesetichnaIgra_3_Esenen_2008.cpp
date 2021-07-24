#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> cifri;

map<vector<int>, int> priTolkova;

vector<int> priDelenieNa2(vector<int> prediTova){
    vector<int> nov;

    int sega = 0;
    int ostatuk = 0;

    bool imameLiNeNula = false;

    unsigned int index = 0;

    while(index < prediTova.size()){
        sega = 10*sega + prediTova[index];
        if(sega > 1 || imameLiNeNula){
            ostatuk = sega % 2;
            nov.push_back(sega/2);
            sega = ostatuk;
            imameLiNeNula = true;
        }
        index++;
    }

    return nov;
}

vector<int> priDelenieNa10(vector<int> prediTova){
    prediTova.pop_back();
    return prediTova;
}

bool imaLiPechelivshHod(vector<int> segashno){
    /*for(unsigned int i = 0; i < segashno.size(); i++){
        cout<<segashno[i];
    }
    cout<<endl;*/

    if(segashno.size() == 0){
        return true;
    }

    if(priTolkova[segashno] == 1){
        return false;
    }
    if(priTolkova[segashno] == 2){
        return true;
    }

    //cout<<"Sega she delime na 10"<<endl;
    bool sHod1PechelimLi = imaLiPechelivshHod(priDelenieNa10(segashno));

    //cout<<"Sega she delime na 2"<<endl;
    bool sHod2PechelimLi = imaLiPechelivshHod(priDelenieNa2(segashno));

    if(!sHod1PechelimLi && !sHod2PechelimLi){
        priTolkova[segashno] = 2;
        return true;
    }

    priTolkova[segashno] = 1;
    return false;
}

void nulirane(){
    cifri.clear();
    priTolkova.clear();
}

int main(){
    string vhod;

    for(int i = 0; i < 4; i++){
        cin>>vhod;
        for(unsigned int j = 0; j < vhod.size(); j++){
            cifri.push_back(vhod[j] - '0');
        }

        bool akoSeDeliNa10ToestKomanda2 = imaLiPechelivshHod(priDelenieNa10(cifri));
        bool akoSeDeliNa2ToestKomanda1 = imaLiPechelivshHod(priDelenieNa2(cifri));

        if(!akoSeDeliNa2ToestKomanda1 && !akoSeDeliNa10ToestKomanda2){
            cout<<0;
        }else{
            if(akoSeDeliNa2ToestKomanda1){
                cout<<1;
            }else{
                cout<<2;
            }
        }
        nulirane();
    }

    cout<<endl;

    return 0;
}
