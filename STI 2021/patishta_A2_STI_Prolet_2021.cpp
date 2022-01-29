#include<iostream>
#include<climits>
using namespace std;

const long long mnogo = 1000000007;

long long broiGradove;
long long broiPatishta;
long long koiNaiKasPat;

long long sasedstvo[111][111];

long long startova[111][111];

void copiraiMatricata(long long vKoq[111][111], long long otKoq[111][111]){
    for(long long i = 0; i <= broiGradove; i++){
        for(long long j = 0; j <= broiGradove; j++){
            vKoq[i][j] = otKoq[i][j];
        }
    }
}

long long saberi(long long parvo, long long vtoro){
    if(parvo >= mnogo || vtoro >= mnogo){
        return mnogo;
    }

    long long tuka = parvo + vtoro;

    if(tuka >= mnogo){
        return mnogo;
    }

    return tuka;
}

long long umnoji(long long parvo, long long vtoro){
    if(parvo >= mnogo || vtoro >= mnogo){
        return mnogo;
    }

    long long tuka = parvo*vtoro;

    if(tuka >= mnogo){
        return mnogo;
    }

    return tuka;
}

void umnojiMatrici(long long parva[111][111], long long vtora[111][111]){
    long long rezultatna[111][111];

    for(long long i = 0; i <= broiGradove; i++){
        for(long long j = 0; j <= broiGradove; j++){

            rezultatna[i][j] = 0;

            for(long long k = 0; k <= broiGradove; k++){
                //rezultatna[i][j] += parva[i][k]*vtora[k][j];
                rezultatna[i][j] = saberi(rezultatna[i][j], umnoji(parva[i][k], vtora[k][j]));
            }

        }
    }

    copiraiMatricata(parva, rezultatna);
}

void bavnoStepenuvane(long long matricata[111][111], long long stepen){
    long long zaVdigane[111][111];

    copiraiMatricata(zaVdigane, matricata);

    /*for(int i = 0; i <= broiGradove; i++){
        for(int j = 0; j <= broiGradove; j++){
            matricata[i][j] = 0;

            if(i == j){
                matricata[i][j] = 1;
            }
        }
    }*/

    for(int i = 1; i < stepen; i++){
        umnojiMatrici(matricata, zaVdigane);
    }
}

void burzoStepenuvane(long long matricata[111][111], long long stepen){
    long long zaVdigane[111][111];

    copiraiMatricata(zaVdigane, matricata);

    for(int i = 0; i <= broiGradove; i++){
        for(int j = 0; j <= broiGradove; j++){
            matricata[i][j] = 0;

            if(i == j){
                matricata[i][j] = 1;
            }
        }
    }

    long long copieStepen = stepen;

    while(copieStepen > 0){
        if(copieStepen & 1 == 1){
            umnojiMatrici(matricata, zaVdigane);
        }

        umnojiMatrici(zaVdigane, zaVdigane);

        copieStepen >>= 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiGradove>>broiPatishta>>koiNaiKasPat;

    for(long long i = 0; i < broiPatishta; i++){
        long long otKade;
        long long doKade;

        cin>>otKade>>doKade;

        sasedstvo[otKade][doKade]++;
        startova[otKade][doKade]++;
    }

    sasedstvo[0][1] = 1;
    startova[0][1] = 1;

    sasedstvo[0][0] = 1;
    startova[0][0] = 1;

    int otgovor = 0;

    for(int i = 1; true; i++){
        copiraiMatricata(sasedstvo, startova);

        burzoStepenuvane(sasedstvo, i);
        //bavnoStepenuvane(sasedstvo, i);

        if(sasedstvo[0][broiGradove] >= koiNaiKasPat){
            otgovor = i;
            break;
        }

        //copiraiMatricata(sasedstvo, startova);
    }

    cout<<otgovor - 1<<endl;

    /*long long lqvKrai = 1;
    long long desenKrai = (long long)1<<30;

    while(lqvKrai < desenKrai){
        long long sredata = (lqvKrai + desenKrai)/2;

        burzoStepenuvane(sasedstvo, sredata);

        //cout<<lqvKrai<<" "<<desenKrai<<" "<<sredata<<" "<<sasedstvo[0][broiGradove]<<endl;

        /*for(int i = 0; i <= broiGradove; i++){
            for(int j = 0; j <= broiGradove; j++){
                cout<<sasedstvo[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;*/

        /*if(sasedstvo[0][broiGradove] == koiNaiKasPat){
            cout<<sredata - 1<<endl;
            return 0;
        }

        if(sasedstvo[0][broiGradove] > koiNaiKasPat){
            //cout<<"poveche ot nujnoto e "<<endl;
            desenKrai = sredata;
        }else{
            //cout<<"po malko e "<<endl;
            lqvKrai = sredata + 1;
        }

        copiraiMatricata(sasedstvo, startova);
    }

    long long otgovor = lqvKrai - 1;

    cout<<otgovor<<endl;*/

    return 0;
}
