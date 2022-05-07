#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int koqStepenNa2;
int broiVarhove = 1;

int kadeSeHrani[600000];

int desnite[600000];

int naiLeviqVPoddarvotoNa[1200000];
int naiDesniqVPOddarvotoNa[1200000];

void nameriNaiNiskite(int segashenVrah){
    if(segashenVrah >= broiVarhove){
        naiLeviqVPoddarvotoNa[segashenVrah] = segashenVrah;
        naiDesniqVPOddarvotoNa[segashenVrah] = segashenVrah;
        return ;
    }

    nameriNaiNiskite(segashenVrah*2);
    nameriNaiNiskite(segashenVrah*2 + 1);

    naiLeviqVPoddarvotoNa[segashenVrah] = naiLeviqVPoddarvotoNa[segashenVrah*2];
    naiDesniqVPOddarvotoNa[segashenVrah] = naiDesniqVPOddarvotoNa[segashenVrah*2 + 1];
}

int broiPresichaniq(int lqvoPoddarvo, int dqsnoPoddarvo){

    int lqvotoOtKade = naiLeviqVPoddarvotoNa[lqvoPoddarvo];
    int lqvotoDoKade = naiDesniqVPOddarvotoNa[lqvoPoddarvo];
    int dqsnotoOtKade = naiLeviqVPoddarvotoNa[dqsnoPoddarvo];
    int dqsnotoDoKade = naiDesniqVPOddarvotoNa[dqsnoPoddarvo];

    lqvotoOtKade -= broiVarhove - 1;
    lqvotoDoKade -= broiVarhove - 1;
    dqsnotoOtKade -= broiVarhove - 1;
    dqsnotoDoKade -= broiVarhove - 1;

    //cout<<"proverqvame ot "<<lqvotoOtKade<<" do "<<lqvotoDoKade<<" s "<<dqsnotoOtKade<<" "<<dqsnotoDoKade<<endl;

    int broiVDqsnoto = dqsnotoDoKade - dqsnotoOtKade + 1;

    memcpy(desnite, kadeSeHrani + dqsnotoOtKade, 4*broiVDqsnoto);

    sort(desnite, desnite + broiVDqsnoto);

    /*cout<<"sortiranoto e ";

    for(int i = 0; i < broiVDqsnoto; i++){
        cout<<desnite[i]<<" ";
    }
    cout<<endl;*/

    int broi = 0;

    for(int i = lqvotoOtKade; i <= lqvotoDoKade; i++){
        /*for(int j = dqsnotoOtKade; j <= dqsnotoDoKade; j++){
            if(kadeSeHrani[i] > kadeSeHrani[j]){
                broi++;
            }
        }*/

        int lqvKrai = 0;
        int desenKrai = broiVDqsnoto - 1;

        while(lqvKrai + 1 < desenKrai){
            int sredata = (lqvKrai + desenKrai)/2;

            if(desnite[sredata] > kadeSeHrani[i]){
                desenKrai = sredata;
            }else{
                lqvKrai = sredata + 1;
            }
        }

        //cout<<"sled cikala leviq krai e "<<lqvKrai<<endl;
        if(desnite[lqvKrai] > kadeSeHrani[i] && lqvKrai > 0){
            lqvKrai--;
        }else{
            if(lqvKrai < broiVDqsnoto - 1){
                lqvKrai++;
            }
            if(desnite[lqvKrai] > kadeSeHrani[i] && lqvKrai > 0){
                lqvKrai--;
            }
        }

        //cout<<"pri index "<<i<<" leviq krai e "<<lqvKrai<<endl;

        if(desnite[lqvKrai] < kadeSeHrani[i]){
            broi += lqvKrai + 1;
        }
    }

    //cout<<"kazvame "<<broi<<endl;

    //cout<<"pitat ni za ot "<<lqvotoOtKade<<" do "<<lqvotoDoKade<<" i "<<dqsnotoOtKade<<" "<<dqsnotoDoKade<<" i kazvame "<<broi<<endl;

    return broi;
}

int naiMalakBroiPresich(int vrahNomer){
    if(vrahNomer >= broiVarhove){
        return 0;
    }

    int otNadolu = naiMalakBroiPresich(vrahNomer*2) + naiMalakBroiPresich(vrahNomer*2 + 1);

    int ednataOpciq = broiPresichaniq(vrahNomer*2, vrahNomer*2 + 1);
    int drugataOpciq = broiPresichaniq(vrahNomer*2 + 1, vrahNomer*2);

    int zaTuka = otNadolu + min(ednataOpciq, drugataOpciq);

    return zaTuka;
}

int main(){

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    //cin>>koqStepenNa2;

    scanf("%i", &koqStepenNa2);

    for(int i = 0; i < koqStepenNa2; i++){
        broiVarhove *= 2;
    }

    for(int i = 1; i <= broiVarhove; i++){
        //cin>>kadeSeHrani[i];
        scanf("%i", &kadeSeHrani[i]);
    }

    nameriNaiNiskite(1);

    int otgovor = naiMalakBroiPresich(1);

    //cout<<otgovor<<endl;

    printf("%i \n", otgovor);

    return 0;
}
