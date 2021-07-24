#include<iostream>
using namespace std;

int broiRaioni;
int posledniqRaion;

int main(){
    cin>>broiRaioni>>posledniqRaion;

    int naiKasnoZaSega = 0;
    int mPriNaiKasnoto = 0;

    for(int m = 1; m < broiRaioni; m++){
        int broiche = 0;
        for(int g = 1; g != posledniqRaion; g = (g + m) % broiRaioni){
            broiche++;
            if(broiche > broiRaioni){
                break;
            }
            //cout<<g<<" ";
        }
        //cout<<endl;
        if(broiche > broiRaioni){
            continue;
        }
        if(broiche > naiKasnoZaSega){
            naiKasnoZaSega = broiche;
            mPriNaiKasnoto = m;
        }
    }

    cout<<mPriNaiKasnoto<<endl;

    return 0;
}
