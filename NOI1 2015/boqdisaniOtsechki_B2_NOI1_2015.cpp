#include<iostream>
using namespace std;

int broiOtsechki;

bool imameLiOtsechkaTuk[10100];

int main(){
    cin>>broiOtsechki;

    int naiOtdalechenaTochka = 0;

    for(int i = 0; i < broiOtsechki; i++){
        int nachalo;
        int krai;
        cin>>nachalo>>krai;

        naiOtdalechenaTochka = max(naiOtdalechenaTochka, krai);

        for(int j = nachalo; j < krai; j++){
            imameLiOtsechkaTuk[j] = true;
        }

    }

    int broiPostroeniOtsechki = 0;
    int naiDalga = 0;

    int segashnaDalzhina = 0;
    bool dosegaVotseckaLiSmeBili = false;

    for(int i = 1; i <= naiOtdalechenaTochka; i++){
        if(imameLiOtsechkaTuk[i]){
            segashnaDalzhina++;
            dosegaVotseckaLiSmeBili = true;
        }else{
            if(dosegaVotseckaLiSmeBili == true){
                naiDalga = max(naiDalga, segashnaDalzhina);
                broiPostroeniOtsechki++;
                segashnaDalzhina = 0;
                dosegaVotseckaLiSmeBili = false;
            }
        }
    }

    /*for(int nachalo = 1; nachalo <= naiOtdalechenaTochka; nachalo++){
        if(imameLiOtsechkaTuk[nachalo - 1]){
            continue;
        }
        for(int krai = nachalo + 1; krai <= naiOtdalechenaTochka; krai++){
            if(imameLiOtsechkaTuk[krai]){
                continue;
            }
            bool dobraLiE = true;
            for(int i = nachalo; i < krai; i++){
                if(imameLiOtsechkaTuk[i] == false){
                    dobraLiE = false;
                    break;
                }
            }
            if(dobraLiE){
                //cout<<nachalo<<" "<<krai<<endl;
                broiPostroeniOtsechki++;
                //cout<<nachalo<<" "<<krai<<endl;
                naiDalga = max(naiDalga, krai - nachalo);
            }
        }
    }*/

    cout<<broiPostroeniOtsechki<<" "<<naiDalga<<endl;

    return 0;
}
