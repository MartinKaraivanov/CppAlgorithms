#include<iostream>
using namespace std;

long long broiChisla;
long long kolkoPoneNOD;

long long chisla[100010];

long long broiZaqvki;

long long zaqvkaOt[1000010];
long long zaqvkaDo[1000010];

long long otgovori[1000010];

long long nod(long long a, long long b){
    while(b > 0){
        long long p = b;
        b = a%b;
        a = p;
    }

    return a;
}

long long nodOtDo[2010][2010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiChisla>>kolkoPoneNOD;

    for(long long i = 1; i <= broiChisla; i++){
        cin>>chisla[i];
    }

    cin>>broiZaqvki;

    for(long long i = 0; i < broiZaqvki; i++){
        cin>>zaqvkaOt[i]>>zaqvkaDo[i];
    }

    for(long long i = 1; i <= broiChisla; i++){
        long long nodTuka = chisla[i];
        nodOtDo[i][i] = nodTuka;
        for(long long j = i + 1; j <= broiChisla; j++){
            nodTuka = nod(nodTuka, chisla[j]);
            nodOtDo[i][j] = nodTuka;
        }
    }

    for(long long i = 0; i < broiZaqvki; i++){
        long long naiGolqmataPodredica = 0;

        //cout<<"sega sam na zaqvka ot "<<zaqvkaOt[i]<<" do "<<zaqvkaDo[i]<<endl;

        for(long long j = zaqvkaOt[i]; j <= zaqvkaDo[i]; j++){
            //cout<<"sega gledam ako pochnem ot index "<<j<<" kadeto ima chislo "<<chisla[j]<<endl;
            long long tekushtaDaljina = 0;

            for(long long m = j; m <= zaqvkaDo[i]; m++){
                //cout<<"v momenta sum na index "<<m<<" chislo "<<chisla[m]<<endl;
                if(nodOtDo[j][m] >= kolkoPoneNOD){
                    tekushtaDaljina++;
                    //cout<<"produljavame napred"<<endl;
                }else{
                    //cout<<"spirame"<<endl;
                    break;
                }
            }

            naiGolqmataPodredica = max(naiGolqmataPodredica, tekushtaDaljina);
        }

        otgovori[i] = naiGolqmataPodredica;
    }

    for(long long i = 0; i < broiZaqvki; i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
