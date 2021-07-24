#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int broiMikrofoni;
int broiHoraProiznasqshtiRechi;

struct MomentNaPristiganeIVremeZaGovorene{
    int momentNaPristigane;
    int vremeZaGovorene;
};

struct NomerNaMikrofonaIKogaShteSeOsvobodi{
    int nomer;
    int kogaShteSeOsvobodi;
    bool operator <(const NomerNaMikrofonaIKogaShteSeOsvobodi& b) const {
        if(kogaShteSeOsvobodi > b.kogaShteSeOsvobodi){
            return true;
        }else{
            if(kogaShteSeOsvobodi < b.kogaShteSeOsvobodi){
                return false;
            }else{
                return nomer > b.nomer;
            }
        }
    }
};

bool poMalkOLiE(MomentNaPristiganeIVremeZaGovorene a, MomentNaPristiganeIVremeZaGovorene b){
    if(a.momentNaPristigane<b.momentNaPristigane){
        return true;
    }else{
        if(a.momentNaPristigane>b.momentNaPristigane){
            return false;
        }else{
            // ==
            return a.vremeZaGovorene>b.vremeZaGovorene;
        }
    }
}

int main(){
    cin>>broiMikrofoni>>broiHoraProiznasqshtiRechi;

    MomentNaPristiganeIVremeZaGovorene hora[broiHoraProiznasqshtiRechi];

    for(int i=0;i<broiHoraProiznasqshtiRechi;i++){
        cin>>hora[i].momentNaPristigane>>hora[i].vremeZaGovorene;
    }

    sort(hora, hora+broiHoraProiznasqshtiRechi, poMalkOLiE);

    priority_queue<NomerNaMikrofonaIKogaShteSeOsvobodi> mikrofoniVremeOstavashto;

    for(int i=0;i<broiMikrofoni;i++){
        NomerNaMikrofonaIKogaShteSeOsvobodi n={i+1, 0};
        mikrofoniVremeOstavashto.push(n);
    }


    for(int i=0;i<broiHoraProiznasqshtiRechi;i++){
        NomerNaMikrofonaIKogaShteSeOsvobodi x=mikrofoniVremeOstavashto.top();
        mikrofoniVremeOstavashto.pop();
        x.kogaShteSeOsvobodi=max(hora[i].momentNaPristigane, x.kogaShteSeOsvobodi)+hora[i].vremeZaGovorene;
        mikrofoniVremeOstavashto.push(x);
    }

    NomerNaMikrofonaIKogaShteSeOsvobodi x;

    while(mikrofoniVremeOstavashto.empty()==false){
        x=mikrofoniVremeOstavashto.top();
        mikrofoniVremeOstavashto.pop();
    }

    cout<<x.kogaShteSeOsvobodi<<" "<<x.nomer<<endl;

    return 0;
}
