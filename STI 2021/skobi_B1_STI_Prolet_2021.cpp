#include<iostream>
using namespace std;

const int mnogo = 1000000007;

string vhod;

int priTolkova[2][5010];

/*int broiNachini(int index, int broiZatvarqshti){
    if(index == 0 && broiZatvarqshti == 0){
        return 1;
    }

    if(broiZatvarqshti > index + 1 || broiZatvarqshti < 0){
        return 0;
    }

    if(priTolkova[index][broiZatvarqshti] > -1){
        return priTolkova[index][broiZatvarqshti];
    }

    int zaTuka = 0;

    if(vhod[index] == '('){
        zaTuka = broiNachini(index - 1, broiZatvarqshti - 1)%mnogo;
    }else{
        if(vhod[index] == ')'){
            zaTuka = broiNachini(index - 1, broiZatvarqshti + 1)%mnogo;
       }else{
            zaTuka = (broiNachini(index - 1, broiZatvarqshti - 1) + broiNachini(index - 1, broiZatvarqshti + 1))%mnogo;
       }
    }

    priTolkova[index][broiZatvarqshti] = zaTuka;
    return zaTuka;
}*/

int sCycli(int zaIndex, int zaBroiZatvarqshti){
    priTolkova[0][0] = 1;

    for(int index = 1; index <= zaIndex; index++){
        for(int broiZatvarqshti = 0; broiZatvarqshti <= zaIndex; broiZatvarqshti++){
            int zaTuka = 0;

            if(vhod[index] == '('){
                if(broiZatvarqshti - 1 >= 0){
                    zaTuka = priTolkova[(index - 1)%2][broiZatvarqshti - 1]%mnogo;
                }
            }else{
                if(vhod[index] == ')'){
                    zaTuka = priTolkova[(index - 1)%2][broiZatvarqshti + 1]%mnogo;
               }else{
                    if(broiZatvarqshti - 1 >= 0){
                        zaTuka = priTolkova[(index - 1)%2][broiZatvarqshti - 1]%mnogo;
                    }

                    zaTuka = (zaTuka + priTolkova[(index - 1)%2][broiZatvarqshti + 1])%mnogo;
               }
            }

            priTolkova[index%2][broiZatvarqshti] = zaTuka;
        }
    }

    return priTolkova[zaIndex%2][zaBroiZatvarqshti];
}

int main(){
    cin>>vhod;

    vhod = '0' + vhod;

    /*for(unsigned int i = 0; i <= vhod.size(); i++){
        for(unsigned int j = 0; j <= vhod.size()/2; j++){
            priTolkova[i][j] = -1;
        }
    }*/

    if(vhod.size()%2 == 0){
        cout<<0<<endl;
    }else{
        int otgovor = sCycli(vhod.size() - 1, 0);

        cout<<otgovor<<endl;
    }

    return 0;
}
