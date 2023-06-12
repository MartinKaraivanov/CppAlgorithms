#include<iostream>
#include<map>
#include<set>
using namespace std;

long long broiChisla;
long long k;
long long broiZaqvki;

long long chisla[100010];

long long xorDo[100010];
map<long long, long long> broiMestaSXor;
set<long long> xorove;

long long izchisliTretataZaqvka(long long otKade, long long doKade){

    broiMestaSXor[0]++;
    xorove.insert(0);
    for(long long i = otKade; i <= doKade; i++){
        xorDo[i] = xorDo[i - 1]^(chisla[i]%(k+1));
        //cout<<"xor do index "<<i<<" e "<<xorDo[i]<<endl;
        broiMestaSXor[xorDo[i]]+=1;
        //cout<<"tozi xor go vijdame za "<<broiMestaSXor[xorDo[i]]<<" pat"<<endl;
        xorove.insert(xorDo[i]);
    }

    long long broiNestavashtiInte = 0;

    for(set<long long>::iterator i = xorove.begin(); i != xorove.end(); i++){
        long long tuka = broiMestaSXor[*i];

        broiNestavashtiInte += tuka*(tuka-1)/2;
    }

    long long obshtBroi = (doKade-otKade+2)*(doKade-otKade+1)/2;

    return obshtBroi - broiNestavashtiInte;
}

int main(){

    cin>>broiChisla>>k>>broiZaqvki;

    for(long long i = 1; i <= broiChisla; i++){
        cin>>chisla[i];
    }

    for(long long q = 0; q < broiZaqvki; q++){
        string tip;
        long long otKade;
        long long doKade;

        cin>>tip>>otKade>>doKade;

        if(tip == "U"){
            long long sKolko;

            cin>>sKolko;

        }else{
            if(tip == "Q1"){

                //cout<<"1"<<endl;
            }else{
                if(tip == "Q2"){

                    //cout<<"W"<<endl;
                }else{
                    long long otgovor = izchisliTretataZaqvka(otKade, doKade);

                    cout<<otgovor<<endl;
                }
            }
        }
    }

    return 0;
}
