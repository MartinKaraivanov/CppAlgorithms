#include<iostream>
#include<queue>
using namespace std;

int tegla[1500];
int n;

struct NachloIKrai{
    int nachalo;
    int krai;
};

int koiIndeksDaEPosledniq(NachloIKrai b){
    int i=b.nachalo;
    int j=b.krai;
    int lqvoTeglo=tegla[i];
    int dqsnoTeglo=tegla[j];

    while(i+1<j){
        if(lqvoTeglo==dqsnoTeglo){
            if (i-b.nachalo > b.krai-j){
                j--;
            }else{
                i++;
            }
        }else{
            if(lqvoTeglo>dqsnoTeglo){
                j--;
                dqsnoTeglo+=tegla[j];
            }else{
                i++;
                lqvoTeglo+=tegla[i];
            }
        }
    }

    return i;
}

int kolkoTezhiTaziChasta(NachloIKrai b){
    int masa=0;
    for(int i=b.nachalo;i<=b.krai;i++){
        masa+=tegla[i];
    }
    return masa;
}

int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>tegla[i];
    }

    queue<NachloIKrai> q;

    NachloIKrai start = {0,n-1};
    q.push(start);

    int povdignataMasa=0;

    while(q.empty()==false){
        NachloIKrai parche = q.front();
        q.pop();

        if(parche.nachalo < parche.krai){
            povdignataMasa+=kolkoTezhiTaziChasta(parche);

            int posledno = koiIndeksDaEPosledniq(parche);

            NachloIKrai p = {parche.nachalo, posledno};
            q.push(p);

            NachloIKrai v = {posledno+1 , parche.krai};
            q.push(v);
        }
    }

    cout<<povdignataMasa<<endl;

    return 0;
}
