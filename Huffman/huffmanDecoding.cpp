#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;


string dekodiraiBytove(string vhodenString){
    char tekushtByte = 0;
    int broqch = 0;

    vector<char> izrechenie;

    string zaVrasht;

    for(int i = 0; i < (int)vhodenString.size(); i++){
        tekushtByte <<= 1;
        tekushtByte += vhodenString[i] - '0';
        broqch++;

        if(broqch == 8){
            zaVrasht += tekushtByte;
            tekushtByte = 0;
            broqch = 0;
        }
    }

    return zaVrasht;
}

map<char, string> kodove;

struct DanniZaVarha{
    int vrahNomer;
    int lqvoDete;
    int dqsnoDete;
    char stoinost;
};

vector<DanniZaVarha> varhove;
int korenNomer;

void slojiTovaTam(char stoinost, string pat){
    int segashenVrah = korenNomer;

    for(int i = 0; i < (int)pat.size(); i++){
        if(pat[i] == '0'){
            if(varhove[segashenVrah].lqvoDete == -1){
                varhove[segashenVrah].lqvoDete = (int)varhove.size();
                varhove.push_back({(int)varhove.size(), -1, -1, -1});
            }

            segashenVrah = varhove[segashenVrah].lqvoDete;
        }else{
            if(varhove[segashenVrah].dqsnoDete == -1){
                varhove[segashenVrah].dqsnoDete = (int)varhove.size();
                varhove.push_back({(int)varhove.size(), -1, -1, -1});
            }

            segashenVrah = varhove[segashenVrah].dqsnoDete;
        }
    }

    varhove[segashenVrah].stoinost = stoinost;
}

string vhodenString;

int main(){

    int broiKodove;

    cin>>broiKodove;

    for(int i = 0; i < broiKodove; i++){
        char simvol;
        string kodaMu;

        cin>>simvol>>kodaMu;

        kodove[simvol] = kodaMu;
    }

    cin>>vhodenString;

    varhove.push_back({0, -1, -1, -1});
    korenNomer = 0;

    for(map<char, string>::iterator i = kodove.begin(); i != kodove.end(); i++){
        slojiTovaTam(i->first, i->second);
    }

    int segashenVrah = korenNomer;

    string rezultat;

    for(int i = 0; i < (int)vhodenString.size(); i++){
        if(vhodenString[i] == '0'){
            segashenVrah = varhove[segashenVrah].lqvoDete;
        }else{
            segashenVrah = varhove[segashenVrah].dqsnoDete;
        }

        if(varhove[segashenVrah].lqvoDete == -1 && varhove[segashenVrah].dqsnoDete == -1){
            rezultat += varhove[segashenVrah].stoinost;
            segashenVrah = korenNomer;
        }
    }


    //string rezultat = dekodiraiBytove(vhodenString);

    cout<<endl<<rezultat<<endl;

    return 0;
}
