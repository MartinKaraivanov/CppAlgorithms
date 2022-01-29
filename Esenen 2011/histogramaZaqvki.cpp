#include<iostream>
#include<stack>
using namespace std;

int maxX;

int visochini[1010];

int naiGolqmotoLiceSVisochina[1010];

void preizchisliLicata(){

    stack<int> s;

    for(int i = 0; i < maxX; i++){

        while(s.empty() == false){
            if(visochini[s.top()] <= visochini[i]){
                break;
            }else{

                int naiOtgreVis = visochini[s.top()];
                s.pop();

                int tukaLice = 0;

                if(s.empty() == true){
                    tukaLice = i*naiOtgreVis;
                }else{
                    tukaLice = (i - s.top() - 1)*naiOtgreVis;
                }

                naiGolqmotoLiceSVisochina[naiOtgreVis] = max(naiGolqmotoLiceSVisochina[naiOtgreVis], tukaLice);
            }
        }

        s.push(i);
    }

    while(s.empty() == false){
        int naiOtgreVis = visochini[s.top()];
        s.pop();

        int tukaLice = 0;

        if(s.empty() == true){
            tukaLice = maxX*naiOtgreVis;
        }else{
            tukaLice = (maxX - s.top() - 1)*naiOtgreVis;
        }

        naiGolqmotoLiceSVisochina[naiOtgreVis] = max(naiGolqmotoLiceSVisochina[naiOtgreVis], tukaLice);
    }


}

int liceSVisochinaNaiMnogo[1010];

void izchisliSMaxVisochina(int naiGolqmataVisochina){
    int maxLice = 0;

    for(int i = 0; i <= naiGolqmataVisochina; i++){
        maxLice = max(maxLice, naiGolqmotoLiceSVisochina[i]);

        liceSVisochinaNaiMnogo[i] = maxLice;
    }
}

int broiZaqvki;

int main(){

    cin>>maxX;

    int maxVis = 0;

    for(int i = 0; i < maxX; i++){
        cin>>visochini[i];
        maxVis = max(maxVis, visochini[i]);
    }

    preizchisliLicata();
    izchisliSMaxVisochina(maxVis);

    cin>>broiZaqvki;

    for(int i = 0; i < broiZaqvki; i++){
        int kakvaVisochina;
        cin>>kakvaVisochina;

        cout<<"nai golqmoto lice s nai mnogo visochina e "<<liceSVisochinaNaiMnogo[kakvaVisochina]<<endl;
    }

    return 0;
}
