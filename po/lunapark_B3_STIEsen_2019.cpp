#include<iostream>
using namespace std;

int broiVarhove;
int broiZaqvki;

int sasedstvo[1000][1000];

int naiDalgaOtsechka[1000][1000];
int naiKasaOtsechka[1000][1000];

unsigned long long Mnogo = 10000000;

void golqmFloyd(){
    for(int i = 1; i <= broiVarhove; i++){
        for(int j = 1; j <= broiVarhove; j++){
            naiDalgaOtsechka[i][j] = sasedstvo[i][j];
        }
    }

    for(int m = 1; m <= broiVarhove; m++){
        for(int i = 1; i <= broiVarhove; i++){
            for(int j = 1; j <= broiVarhove; j++){
                if(i != j && i!=m && j!=m){
                    if((naiDalgaOtsechka[m][j] > naiDalgaOtsechka[i][j])){
                        naiDalgaOtsechka[i][j] = naiDalgaOtsechka[m][j];
                    }
                }
            }
        }
    }
}

int main(){
    cin>>broiVarhove;

    for(int i = 0; i < broiVarhove; i++){
        int otKoi;
        int doKoi;
        int razstoqnie;

        cin>>otKoi>>doKoi>>razstoqnie;
        sasedstvo[otKoi][doKoi] = razstoqnie;
        sasedstvo[doKoi][otKoi] = razstoqnie;
    }

    cin>>broiZaqvki;

    for(int i = 0; i < broiZaqvki; i++){
        int tip;
        int otKoi;
        int doKoi;

        cin>>tip>>otKoi>>doKoi;
    }

    golqmFloyd();

    cout<<"------------------------------------"<<endl;

    for(int i = 1; i <= broiVarhove; i++){
        for(int j = 1; j <= broiVarhove; j++){
            cout<<i<<" "<<j<<" "<<naiDalgaOtsechka[i][j]<<endl;
        }
    }

    return 0;
}
