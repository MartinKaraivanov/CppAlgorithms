#include<iostream>
using namespace std;

int broiVarhove;

bool sasedstvo[1010][1010];
int pat[1010];

bool mozheLiTuka(int segashenVrah, int poziciq){
    if(sasedstvo[pat[poziciq - 1]][segashenVrah] == false){
        return false;
    }

    for(int i = 1; i <= poziciq; i++){
        if(pat[i] == segashenVrah){
            return false;
        }
    }

    return true;
}

bool LewisHamilton(int poziciq){
    if(poziciq == broiVarhove){
        return true;
    }

    for(int vrah = 1; vrah <= broiVarhove; vrah++){
        if(mozheLiTuka(vrah, poziciq) == true){
            pat[poziciq] = vrah;

            if(LewisHamilton(poziciq + 1))
                return true;

            pat[poziciq] = -1;
        }
    }

    return false;
}

int main(){
    cin>>broiVarhove;

    for(int i = 1; i <= broiVarhove; i++){
        int broiPobediNaTozi;
        cin>>broiPobediNaTozi;

        for(int j = 0; j < broiPobediNaTozi; j++){
            int koiEPobedil;
            cin>>koiEPobedil;

            sasedstvo[i][koiEPobedil] = true;
        }
    }

    for(int i = 0; i <= broiVarhove; i++){
        pat[i] = -1;
    }

    for(int i = 1; i <= broiVarhove; i++){
        for(int j = 1; j <= broiVarhove; j++){
            pat[j] = -1;
        }

        pat[0] = i;
        if(LewisHamilton(1) == true){
            for(int k = 0; k < broiVarhove; k++){
                cout<<pat[k]<<" ";
            }
            return 0;
        }
    }

    cout<<"No solution"<<endl;

    return 0;
}
