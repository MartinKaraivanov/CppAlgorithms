#include<iostream>
#include<cmath>
using namespace std;

int broiChisla;
long long chisla[20000];
bool imameLiPolozhitelniSumi[1000000];
bool imameLiOtricatelniSumi[1000000];

bool imaLiGo(int chislo){
    if(chislo<0){
        int absolutno=abs(chislo);
        return imameLiOtricatelniSumi[absolutno];
    }else{
        return imameLiPolozhitelniSumi[chislo];
    }
}

void popalni(int chislo){
    if(chislo<0){
        int absolutno=abs(chislo);
        imameLiOtricatelniSumi[absolutno]=true;
    }else{
        imameLiPolozhitelniSumi[chislo]=true;
    }
}

int main(){
    cin>>broiChisla;

    for(int i=0;i<broiChisla;i++){
        cin>>chisla[i];
    }

    for(int j=0;j<broiChisla;j++){
        if(chisla[j]<0){
            for(int staraSuma=-1000000;staraSuma<=1000000;staraSuma++){
                if(imaLiGo(staraSuma)==true){
                    if(imaLiGo(staraSuma+chisla[j])==false){
                        popalni(staraSuma+chisla[j]);
                        //cout<<staraSuma+chisla[j]<<endl;
                    }
                }
            }
            if(imaLiGo(chisla[j])==false){
                popalni(chisla[j]);
            }
        }else{
            for(int staraSuma=1000000;staraSuma>=-1000000;staraSuma--){
                if(imaLiGo(staraSuma)==true){
                    if(imaLiGo(staraSuma+chisla[j])==false){
                        popalni(staraSuma+chisla[j]);
                        //cout<<staraSuma+chisla[j]<<endl;
                    }
                }
            }
            if(imaLiGo(chisla[j])==false){
                popalni(chisla[j]);
            }
        }
    }

    int broiRazlichniSumi = 0;
    for(int i=-1000000;i<=1000000;i++){
        if(imaLiGo(i)==true){
            broiRazlichniSumi++;
            //cout<<i<<endl;
        }
    }

    cout<<broiRazlichniSumi<<endl;

    return 0;
}
