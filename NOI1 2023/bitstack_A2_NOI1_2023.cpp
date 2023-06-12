#include<iostream>
#include<vector>
using namespace std;

int broiTestove;

int broiChisla;

unsigned long long kolkoDaSePoluchi;

unsigned long long chisla[100010];

vector<char> otgovor;

bool mojeLi(int doIndex, unsigned long long chislo, unsigned long long maska){
    if(doIndex == 1){
        if((maska & chislo) == (maska & chisla[doIndex])){
            return true;
        }else{
            return false;
        }
    }

    bool stavaLiSOr = false;

    if(((maska & chisla[doIndex]) & chislo) == (maska & chisla[doIndex])){
        stavaLiSOr = mojeLi(doIndex - 1, (chislo & maska) & (~chisla[doIndex]), maska & (~chisla[doIndex]));
    }
    if(stavaLiSOr == true){
        otgovor.push_back('|');
        return true;
    }

    bool stavaLiSAnd = false;

    if(((maska & chislo) & chisla[doIndex]) == (maska & chislo)){
        stavaLiSAnd = mojeLi(doIndex - 1, (chislo & maska) & chisla[doIndex], maska & chisla[doIndex]);
    }

    if(stavaLiSAnd == true){
        otgovor.push_back('&');
        return true;
    }

    return false;
}

int main(){

    cin>>broiTestove;

    for(int t = 0; t < broiTestove; t++){
        cin>>broiChisla>>kolkoDaSePoluchi;

        for(int i = 1; i <= broiChisla; i++){
            cin>>chisla[i];
        }

        bool stavaLi = mojeLi(broiChisla, kolkoDaSePoluchi, ~0);

        if(stavaLi == true){
            cout<<"YES"<<endl;
            for(int i = 0; i < (int)otgovor.size(); i++){
                cout<<otgovor[i];
            }
            cout<<endl;
            otgovor.clear();
        }else{
            cout<<"NO"<<endl;
        }
    }


    return 0;
}
