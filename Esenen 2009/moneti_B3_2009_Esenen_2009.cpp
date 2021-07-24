#include<iostream>
#include<map>
#include<vector>
using namespace std;

vector<int> leviMoneti[3];
char znaci[3];
vector<int> desniMoneti[3];

int otKoqStranaE(int koqMoneta, int koeMerene){
    bool imaLiQOtlqvo = false;
    for(int i = 0; i < 4; i++){
        if(leviMoneti[koeMerene][i] == abs(koqMoneta)){
            imaLiQOtlqvo = true;
            break;
        }
    }
    if(imaLiQOtlqvo == true){
        return 1;
    }

    bool imaLiQOtDqsno = false;
    for(int i = 0; i < 4; i++){
        if(desniMoneti[koeMerene][i] == abs(koqMoneta)){
            imaLiQOtDqsno = true;
            break;
        }
    }
    if(imaLiQOtDqsno == true){
        return 2;
    }

    return 0;
}

int main(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            int tuk;
            cin>>tuk;
            leviMoneti[i].push_back(tuk);
        }
        cin>>znaci[i];
        for(int j = 0; j < 4; j++){
            int tuk;
            cin>>tuk;
            desniMoneti[i].push_back(tuk);
        }
    }

    vector<int> vazmozhni;

    for(int i = -12; i <= 12; i++){
        if(i == 0){
            continue;
        }

        bool stavaLi = true;

        if(i < 0){
            for(int j = 0; j < 3; j++){
                int otKadeE = otKoqStranaE(i, j);
                if((otKadeE == 0 && znaci[j] != '=') ||
                   (otKadeE == 1 && znaci[j] != '<') ||
                   (otKadeE == 2 && znaci[j] != '>'))
                {
                    stavaLi = false;
                    break;
                }
            }
        }else{
            for(int j = 0; j < 3; j++){
                int otKadeE = otKoqStranaE(i, j);
                if((otKadeE == 0 && znaci[j] != '=') ||
                   (otKadeE == 1 && znaci[j] != '>') ||
                   (otKadeE == 2 && znaci[j] != '<'))
                {
                    stavaLi = false;
                    break;
                }
            }
        }

        if(stavaLi == true){
            vazmozhni.push_back(i);
        }
    }

    if(vazmozhni.size() == 0){
        cout<<"impossible"<<endl;
    }else{
        if(vazmozhni.size() >= 2){
            cout<<"indefinite"<<endl;
        }else{
            int chisloto = vazmozhni[0];
            if(chisloto < 0){
                cout<<abs(chisloto)<<"-"<<endl;
            }else{
                cout<<chisloto<<"+"<<endl;
            }
        }
    }

    return 0;
}
