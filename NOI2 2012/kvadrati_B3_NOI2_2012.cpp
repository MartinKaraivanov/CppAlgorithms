#include<iostream>
using namespace std;

long long sumishka;

long long kvadrati[5050];
bool imameLiGo[20000000];
long long broiKvadrati;

int main(){
    cin>>sumishka;

    for(int i = 0; i <= 5000; i++){
        long long kvadrat = i * i;
        if(kvadrat > sumishka){
            break;
        }
        kvadrati[broiKvadrati] = kvadrat;
        broiKvadrati++;
    }

    long long broiVazmozhniXove = 0;

    for(int i = 0; i < broiKvadrati; i++){
        for(int j = i; j < broiKvadrati; j++){
            if(kvadrati[i] + kvadrati[j] <= sumishka && imameLiGo[kvadrati[i] + kvadrati[j]] == false){
                broiVazmozhniXove++;
                //cout<<kvadrati[i] + kvadrati[j]<<" "<<i<<" "<<j<<endl;
                imameLiGo[kvadrati[i] + kvadrati[j]] = true;
            }
        }
    }

    cout<<broiVazmozhniXove - 1<<endl;

    return 0;
}
