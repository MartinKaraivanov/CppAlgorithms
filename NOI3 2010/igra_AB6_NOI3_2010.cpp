#include<iostream>
#include<algorithm>
using namespace std;

int broiKupchinki;

int vavdedeniKamani[25];

int broiKamaniVKupchinka[25];

int broiTakuvBroi[25];

int brRazlichniKupchinki;

bool pechelivshaPoziciqLiE(int broiRazlichniKupchinki){
    if(broiRazlichniKupchinki == 1){
        return true;
    }

    bool imameLiPechelivshaPoziciqZaTozi = false;

    for(int i = 0; i < broiKupchinki; i++){
        if(broiTakuvBroi[broiKamaniVKupchinka[i]] > 0){
            for(int j = 0; j < broiKupchinki; j++){
                if(broiKamaniVKupchinka[i] > broiKamaniVKupchinka[j]){
                    if(broiTakuvBroi[broiKamaniVKupchinka[j]] > 0){
                        broiTakuvBroi[broiKamaniVKupchinka[j]]++;
                        broiTakuvBroi[broiKamaniVKupchinka[i]]--;
                        bool imaLiPechelivsho = false;
                        if(broiTakuvBroi[broiKamaniVKupchinka[i]] == 0){
                            imaLiPechelivsho = pechelivshaPoziciqLiE(broiRazlichniKupchinki - 1);
                        }else{
                            imaLiPechelivsho = pechelivshaPoziciqLiE(broiRazlichniKupchinki);
                        }
                        broiTakuvBroi[broiKamaniVKupchinka[j]]--;
                        broiTakuvBroi[broiKamaniVKupchinka[i]]++;
                        if(imaLiPechelivsho == true){
                            imameLiPechelivshaPoziciqZaTozi = true;
                            break;
                        }
                    }
                }
            }
        }
        if(imameLiPechelivshaPoziciqZaTozi == true){
            break;
        }
    }

    return !imameLiPechelivshaPoziciqZaTozi;
}

int main(){
    cin>>broiKupchinki;

    for(int i = 0; i < broiKupchinki; i++){
        int broiTuka;
        cin>>broiTuka;
        vavdedeniKamani[i] = broiTuka;
    }

    sort(vavdedeniKamani, vavdedeniKamani + broiKupchinki);

    int nomercheZaKamache = 1;

    for(int i = 0; i < broiKupchinki; i++){
        int segashno = vavdedeniKamani[i];
        int j = i;
        while(vavdedeniKamani[j] == segashno){
            broiKamaniVKupchinka[j] = nomercheZaKamache;
            broiTakuvBroi[nomercheZaKamache]++;
            j++;
        }
        nomercheZaKamache++;
        i = j - 1;
    }

    bool mozhemLiDaSpechelim = pechelivshaPoziciqLiE(brRazlichniKupchinki);

    cout<<!mozhemLiDaSpechelim<<endl;

    return 0;
}
