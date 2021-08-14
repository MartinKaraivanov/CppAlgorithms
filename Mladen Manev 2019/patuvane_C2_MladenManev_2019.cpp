#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int broiVarhove;
int broiPitaniq;

vector<int> sasedstvo[100010];

int vreme;

int momentNaVlizane[100010];
int momentNaIzlizane[100010];

int bashta[100010];

void prenastrovashtoDfs(int segashen, int otKadeIdvame){

    for(int i = 0; i < (int)sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeIdvame){
            prenastrovashtoDfs(sasedstvo[segashen][i], segashen);
        }else{
            swap(sasedstvo[segashen][i], sasedstvo[segashen][0]);
        }
    }

}

void dfs(int segashen, int otKadIdvame){
    bashta[segashen] = otKadIdvame;

    momentNaVlizane[segashen] = vreme;

    for(int i = 0; i < (int)sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadIdvame){
            vreme++;
            dfs(sasedstvo[segashen][i], segashen);
        }
    }

    vreme++;
    momentNaIzlizane[segashen] = vreme;
}

int otgovori[100010];

int main(){
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/

    //cin>>broiVarhove>>broiPitaniq;

    scanf("%i %i", &broiVarhove, &broiPitaniq);

    for(int i = 0; i < broiVarhove - 1; i++){
        int otKade;
        int doKade;

        //cin>>otKade>>doKade;

        scanf("%i %i", &otKade, &doKade);

        sasedstvo[otKade].push_back(doKade);
        sasedstvo[doKade].push_back(otKade);
    }

    prenastrovashtoDfs(1, -1);
    dfs(1, -1);

    for(int i = 0; i < broiPitaniq; i++){
        int otKade;
        int doKade;

        //cin>>otKade>>doKade;

        scanf("%i %i", &otKade, &doKade);

        if(momentNaIzlizane[otKade] < momentNaVlizane[doKade] || momentNaIzlizane[doKade] < momentNaVlizane[otKade]){
            otgovori[i] = bashta[otKade];
            //cout<<"ne sa ot edno poddarvo"<<endl;
        }else{
            if(momentNaVlizane[otKade] < momentNaVlizane[doKade]){
                int lqvKrai = 0;

                if(bashta[otKade] != -1){
                    lqvKrai = 1;
                }

                int desenKrai = sasedstvo[otKade].size() - 1;

                while(lqvKrai < desenKrai){
                    int sredata = (lqvKrai + desenKrai)/2;

                    if(momentNaIzlizane[sasedstvo[otKade][sredata]] <= momentNaVlizane[doKade]){
                        lqvKrai = sredata + 1;
                    }else{
                        desenKrai = sredata;
                    }

                }

                otgovori[i] = sasedstvo[otKade][lqvKrai];

                /*for(int j = 0; j < (int)sasedstvo[otKade].size(); j++){
                    int tekusht = sasedstvo[otKade][j];
                    if(momentNaVlizane[tekusht] < momentNaVlizane[doKade] &&
                        momentNaIzlizane[tekusht] > momentNaIzlizane[doKade] &&
                        momentNaVlizane[otKade] < momentNaVlizane[tekusht] &&
                        momentNaIzlizane[otKade] > momentNaIzlizane[tekusht])
                    {
                        otgovori[i] = tekusht;
                        break;
                    }
                }*/

                if(otgovori[i] == 0){
                    otgovori[i] = doKade;
                }

                //cout<<"ot e nad do"<<endl;
            }else{
                otgovori[i] = bashta[otKade];
                //cout<<"do e nad ot"<<endl;
            }
        }
    }

    for(int i = 0; i < broiPitaniq; i++){
        //cout<<otgovori[i]<<endl;
        printf("%i \n", otgovori[i]);
    }

    return 0;
}
