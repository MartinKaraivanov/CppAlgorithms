#include<iostream>
#include<queue>
using namespace std;

const long long mnogo = 100000000007;

long long broiDni;
long long cenaPrestoi;

long long ceniPetrol[1000010];

priority_queue<int> q;

/*
long long priTolkova[2][10010];

long long pechalbaPri(long long doKade, long long sKolkoPetrol){
    if(doKade == 0){
        if(sKolkoPetrol == 0){
            return 0;
        }else{
            return -mnogo;
        }
    }
    if(sKolkoPetrol < 0){
        return -mnogo;
    }
    if(priTolkova[doKade][sKolkoPetrol] > -mnogo){
        return priTolkova[doKade][sKolkoPetrol];
    }

    long long akoNePravimNishto = pechalbaPri(doKade - 1, sKolkoPetrol);
    long long akoKupim = pechalbaPri(doKade - 1, sKolkoPetrol - 1) - ceniPetrol[doKade];
    long long akoProdadem = pechalbaPri(doKade - 1, sKolkoPetrol + 1) + ceniPetrol[doKade];

    long long tuka = max(akoNePravimNishto, max(akoKupim, akoProdadem)) - sKolkoPetrol*cenaPrestoi;

    priTolkova[doKade][sKolkoPetrol] = tuka;
    return tuka;
}

long long sCycli(long long zaDoKade, long long zaSKolkoPetrol){
    for(long long i = 1; i <= zaDoKade; i++){
        priTolkova[0][i] = -mnogo;
    }

    for(long long doKade = 1; doKade <= zaDoKade; doKade++){
        for(long long sKolkoPetrol = 0; sKolkoPetrol <= zaDoKade; sKolkoPetrol++){

            long long akoNePravimNishto = priTolkova[(doKade - 1)%2][sKolkoPetrol];
            long long akoKupim = 0;
            if(sKolkoPetrol > 0){
                akoKupim = priTolkova[(doKade - 1)%2][sKolkoPetrol - 1] - ceniPetrol[doKade];
            }
            long long akoProdadem = priTolkova[(doKade - 1)%2][sKolkoPetrol + 1] + ceniPetrol[doKade];

            long long tuka = max(akoNePravimNishto, max(akoKupim, akoProdadem)) - sKolkoPetrol*cenaPrestoi;

            priTolkova[doKade%2][sKolkoPetrol] = tuka;
        }
    }

    return priTolkova[zaDoKade%2][zaSKolkoPetrol];
}
*/

int main(){

    cin>>broiDni>>cenaPrestoi;

    for(long long i = 1; i <= broiDni; i++){
        cin>>ceniPetrol[i];
    }

    for(int i = broiDni; i >= 1; i--){
        ceniPetrol[i] += (broiDni - i)*cenaPrestoi;
    }

    int otgovor = 0;

    for(int i = broiDni; i >= 1; i--){
        if(q.empty() == false && q.top() > ceniPetrol[i]){
            otgovor += (q.top() - ceniPetrol[i]);
            q.pop();
            q.push(ceniPetrol[i]);
            q.push(ceniPetrol[i]);
        }else{
            q.push(ceniPetrol[i]);
        }
    }

    cout<<otgovor<<endl;

    return 0;
}
