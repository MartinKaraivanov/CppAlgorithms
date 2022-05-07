#include<iostream>
using namespace std;

const long long mnogo = 1000000007;

long long kraenX;
long long kraenY;

long long skokPoX;
long long skokPoY;

long long zaKolkoSekundi;

long long priTolkovaX[10024][2];

long long brVazmojnostiZaX(long long otX, long long zaSekundi){
    if(zaSekundi == 0){
        if(otX == 0){
            return 1;
        }else{
            return 0;
        }
    }

    if(priTolkovaX[otX][zaSekundi] > -1){
        return priTolkovaX[otX][zaSekundi];
    }

    long long zaTuka = 0;

    for(long long promqnaPoX = 0; promqnaPoX <= min(skokPoX, otX); promqnaPoX++){
        zaTuka = (zaTuka + brVazmojnostiZaX(otX - promqnaPoX, zaSekundi - 1))%mnogo;
    }

    priTolkovaX[otX][zaSekundi] = zaTuka;
    return zaTuka;
}

long long priTolkovaY[10024][2];

long long brVazmojnostiZaY(long long otY, long long zaSekundi){
    if(zaSekundi == 0){
        if(otY == 0){
            return 1;
        }else{
            return 0;
        }
    }

    if(priTolkovaY[otY][zaSekundi] > -1){
        return priTolkovaY[otY][zaSekundi];
    }

    long long zaTuka = 0;

    for(long long promqnaPoY = 0; promqnaPoY <= min(skokPoY, otY); promqnaPoY++){
        zaTuka = (zaTuka + brVazmojnostiZaY(otY - promqnaPoY, zaSekundi - 1))%mnogo;
    }

    priTolkovaY[otY][zaSekundi] = zaTuka;
    return zaTuka;
}

long long sCycliX(long long zaOtX, long long zaZaSekundi){
    priTolkovaX[0][0] = 1;

    for(long long zaSekundi = 1; zaSekundi <= zaZaSekundi; zaSekundi++){

        long long doKadePreizchislqvame = min(skokPoX, zaOtX);

        priTolkovaX[0][zaSekundi%2] = priTolkovaX[0][(zaSekundi-1)%2]%mnogo;

        for(long long x = 1; x <= doKadePreizchislqvame; x++){
            priTolkovaX[x][zaSekundi%2] = (priTolkovaX[x - 1][zaSekundi%2] + priTolkovaX[x][(zaSekundi-1)%2])%mnogo;
        }

        long long sboraNPosledniteNqkolko = priTolkovaX[doKadePreizchislqvame][zaSekundi%2];

        for(long long otX = doKadePreizchislqvame + 1; otX <= zaOtX; otX++){

            sboraNPosledniteNqkolko = (sboraNPosledniteNqkolko + priTolkovaX[otX][(zaSekundi - 1)%2])%mnogo;
            sboraNPosledniteNqkolko = (sboraNPosledniteNqkolko - priTolkovaX[otX - doKadePreizchislqvame - 1][(zaSekundi - 1)%2] + mnogo)%mnogo;

            priTolkovaX[otX][zaSekundi%2] = sboraNPosledniteNqkolko;
        }
    }

    return priTolkovaX[zaOtX][zaZaSekundi%2];
}

long long sCycliY(long long zaOtY, long long zaZaSekundi){
    priTolkovaY[0][0] = 1;

    for(long long zaSekundi = 1; zaSekundi <= zaZaSekundi; zaSekundi++){

        long long doKadePreizchislqvame = min(skokPoY, zaOtY);

        priTolkovaY[0][zaSekundi%2] = priTolkovaY[0][(zaSekundi-1)%2]%mnogo;

        for(long long y = 1; y <= doKadePreizchislqvame; y++){
            priTolkovaY[y][zaSekundi%2] = (priTolkovaY[y - 1][zaSekundi%2] + priTolkovaY[y][(zaSekundi-1)%2])%mnogo;
        }

        long long sboraNPosledniteNqkolko = priTolkovaY[doKadePreizchislqvame][zaSekundi%2];

        for(long long otY = doKadePreizchislqvame + 1; otY <= zaOtY; otY++){

            sboraNPosledniteNqkolko = (sboraNPosledniteNqkolko + priTolkovaY[otY][(zaSekundi - 1)%2])%mnogo;
            sboraNPosledniteNqkolko = (sboraNPosledniteNqkolko - priTolkovaY[otY - doKadePreizchislqvame - 1][(zaSekundi - 1)%2] + mnogo)%mnogo;

            priTolkovaY[otY][zaSekundi%2] = sboraNPosledniteNqkolko;
        }
    }

    return priTolkovaY[zaOtY][zaZaSekundi%2];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>kraenX>>kraenY>>skokPoX>>skokPoY>>zaKolkoSekundi;

    /*for(long long x = 0; x <= kraenX; x++){
        for(long long i = 0; i <= zaKolkoSekundi; i++){
            priTolkovaX[x][i] = -1;
        }
    }

    for(long long y = 0; y <= kraenY; y++){
        for(long long i = 0; i <= zaKolkoSekundi; i++){
            priTolkovaY[y][i] = -1;
        }
    }*/

    //long long broiNachiniZaX = brVazmojnostiZaX(kraenX, zaKolkoSekundi);
    //long long broiNachiniZaY = brVazmojnostiZaY(kraenY, zaKolkoSekundi);

    long long broiNachiniZaX = sCycliX(kraenX, zaKolkoSekundi);
    long long broiNachiniZaY = sCycliY(kraenY, zaKolkoSekundi);

    long long otgovor = (broiNachiniZaX*broiNachiniZaY)%mnogo;

    cout<<otgovor<<endl;

    return 0;
}
