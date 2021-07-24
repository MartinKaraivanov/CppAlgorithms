#include<iostream>
using namespace std;

string parvo;
string vtoro;

int ndp[1000][1000];

int main(){
    cin>>parvo>>vtoro;

    for(int v = 1; v <= vtoro.size(); v++){
        for(int p = 1; p <= parvo.size(); p++){
            if(ndp[p-1][v] > ndp[p][v-1]){
                ndp[p][v] = ndp[p-1][v];
                //cout<<p<<" "<<v<<" "<<ndp[p][v]<<endl;
            }else{
                if(ndp[p-1][v] < ndp[p][v-1]){
                    ndp[p][v] = ndp[p][v-1];
                    //cout<<p<<" "<<v<<" "<<ndp[p][v]<<endl;
                }else{
                    if(parvo[p] == vtoro[v]){
                        ndp[p][v] = 1 + ndp[p-1][v-1];
                    }else{
                        ndp[p][v] = max(ndp[p-1][v], ndp[p][v-1]);
                    }
                    //cout<<p<<" "<<v<<" "<<ndp[p][v]<<endl;
                }
            }
        }
    }

    int broiche = ndp[parvo.size()][vtoro.size()];

    cout<<broiche<<endl;

    return 0;
}
