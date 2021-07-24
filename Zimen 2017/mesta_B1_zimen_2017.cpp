#include<iostream>
#include<vector>
using namespace std;

struct DanniZaDupkata{
    int dalzhina;
    int nachalo;
    int krai;
};

int broiA;
int broiB;
int broiC;

char podredba[10000000];

DanniZaDupkata dupki[15000];
int broiDupki;

vector<DanniZaDupkata> ostavashtiDupki;

int main(){
    cin>>broiA>>broiB>>broiC;

    int prednaPoziciq = 0;

    for(int i = 0; i < broiA; i++){
        int poziciq;
        cin>>poziciq;

        podredba[poziciq - 1] = 'A';

        //cout<<poziciq - prednaPoziciq - 1<<" ";

        if(poziciq - prednaPoziciq - 1 > 0){
            dupki[broiDupki] = {poziciq - prednaPoziciq - 1, prednaPoziciq, poziciq - 2};
            //cout<<broiDupki<<endl;
            broiDupki++;
        }
        prednaPoziciq = poziciq;
    }

    int obshtBroiMesta = broiA+broiB+broiC;



    int poziciq = obshtBroiMesta + 1;

    if(poziciq - prednaPoziciq - 1 > 0){
        dupki[broiDupki] = {poziciq - prednaPoziciq - 1, prednaPoziciq, poziciq - 2};
        broiDupki++;
    }




    /*for(int i = 0; i < broiDupki; i++){
        cout<<dupki[i].dalzhina<<" "<<dupki[i].nachalo<<" "<<dupki[i].krai<<endl;
    }*/

    for(int i = 0; i < broiDupki; i++){
        if(dupki[i].dalzhina == 0){
            cout<<"ne kakto trqbva";
            return 0;
        }
        broiB -= dupki[i].dalzhina/2;
        broiC -= dupki[i].dalzhina/2;
        ostavashtiDupki.push_back(dupki[i]);
    }

    if(broiB < 0 || broiC < 0){
        cout<<-1<<endl;
        return 0;
    }

    for(unsigned int i = 0; i < ostavashtiDupki.size(); i++){
        //cout<<ostavashtiDupki[i].dalzhina<<" "<<ostavashtiDupki[i].nachalo<<" "<<ostavashtiDupki[i].krai<<endl;
        if(ostavashtiDupki[i].dalzhina % 2 == 0){
            int a = 0;
            for(int j = ostavashtiDupki[i].nachalo; j <= ostavashtiDupki[i].krai; j++){
                if(a % 2 == 0){
                    podredba[j] = 'B';
                }else{
                    podredba[j] = 'C';
                }
                a++;
           }
        }else{
            if(broiB > 0){
                int a = 0;
                for(int j = ostavashtiDupki[i].nachalo; j <= ostavashtiDupki[i].krai; j++){
                    if(a % 2 == 0){
                        podredba[j] = 'B';
                    }else{
                        podredba[j] = 'C';
                    }
                    a++;
                }
                broiB--;
            }else{
                int a = 0;
                for(int j = ostavashtiDupki[i].nachalo; j <= ostavashtiDupki[i].krai; j++){
                    if(a % 2 == 0){
                        podredba[j] = 'C';
                    }else{
                        podredba[j] = 'B';
                    }
                    a++;
                }
                broiC--;
            }
        }
    }

    if(broiB < 0 || broiC < 0){
        cout<<-1<<endl;
        return 0;
    }

    for(int i = 0; i < obshtBroiMesta; i++){
        cout<<podredba[i];
    }

    cout<<endl;

    return 0;
}
