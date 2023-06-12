
#include<iostream>
using namespace std;

int broiVarhove;
int broiRebra;
long long koiNaiKratakPat;

long long sasedstvo[128][128];

long long nuleva[128][128];

void kopiraiMatricata(long long (&koq)[128][128], long long (&vKoq)[128][128]){

    for(int i = 0; i <= broiVarhove; i++){
        for(int j = 0; j <= broiVarhove; j++){
            vKoq[i][j] = koq[i][j];
        }
    }

}

void umnoji(long long (&parva)[128][128], long long (&vtora)[128][128]){

    long long rezultatna[128][128];

    for(int i = 0; i <= broiVarhove; i++){
        for(int j = 0; j <= broiVarhove; j++){

            rezultatna[i][j] = 0;

            for(int k = 0; k <= broiVarhove; k++){
                rezultatna[i][j] += parva[i][k]*vtora[k][j];
            }

        }
    }

    kopiraiMatricata(rezultatna, vtora);
}

void vdigniSaedstvoNaStepen(long long (&vTazi)[128][128], long long stepen){

    long long kopie[128][128];

    kopiraiMatricata(sasedstvo, kopie);

    kopiraiMatricata(nuleva, vTazi);

    while(stepen > 0){
        if((stepen & 1) == 1){
            umnoji(kopie, vTazi);
        }
        umnoji(kopie, kopie);

        stepen >>= 1;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiVarhove>>broiRebra>>koiNaiKratakPat;

    for(int i = 0; i < broiRebra; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;

        sasedstvo[otKade][doKade]++;
    }

    sasedstvo[broiVarhove][0]++;
    sasedstvo[0][0]++;

    for(int i = 0; i <= broiVarhove; i++){
        nuleva[i][i] = 1;
    }

    long long rez[128][128];
    kopiraiMatricata(sasedstvo, rez);

    long long maxDqsno = 1;

    while(true){

        umnoji(rez, rez);

        //cout<<maxDqsno + 1<<" "<<rez[1][0]<<endl;

        if(rez[1][0] >= koiNaiKratakPat){
            break;
        }
        maxDqsno++;
    }



    long long lqvKrai = 0;
    long long desenKrai = (long long)1<<maxDqsno;

    while(lqvKrai + 1 < desenKrai){
        long long sredata = (lqvKrai + desenKrai)/2;

        vdigniSaedstvoNaStepen(rez, sredata + 1);

        //cout<<"na stepen "<<sredata + 1<<" kazvame che do kraq ima "<<rez[1][0]<<" patq"<<endl;

        if(rez[1][0] < koiNaiKratakPat){
            lqvKrai = sredata;
        }else{
            desenKrai = sredata;
        }
    }

    cout<<lqvKrai + 1<<endl;


    return 0;
}
