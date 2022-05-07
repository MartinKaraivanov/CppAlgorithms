#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int mnogo = 1000000007;

int broiChisla;
int originalniChisla[1000010];
vector<int> chisla;

int main(){

    cin>>broiChisla;

    for(int i = 0; i < broiChisla; i++){
        cin>>originalniChisla[i];
        originalniChisla[i]--;
        chisla.push_back(originalniChisla[i]);
    }

    /*cout<<"originalnata redica: "<<endl;
    for(int i = 0; i < broiChisla; i++){
        cout<<originalniChisla[i]<<" ";
    }
    cout<<endl;*/

    sort(chisla.begin(), chisla.end());

    int broiPermutacii = 0;

    //cout<<"permutacii:"<<endl;

    do{
        /*for(int i = 0; i < broiChisla; i++){
            cout<<chisla[i]<<" ";
        }
        cout<<endl;*/

        bool okLiE = true;

        for(int i = 0; i < broiChisla; i++){
            if(originalniChisla[chisla[i]] != chisla[originalniChisla[i]]){
                okLiE = false;
            }
        }

        if(okLiE == true){
            broiPermutacii = (broiPermutacii + 1)%mnogo;
            //cout<<"tazi stava!!!!!!!"<<endl;
            for(int i = 0; i < broiChisla; i++){
                cout<<chisla[i]<<" ";
            }
            cout<<endl;
        }
    }while(next_permutation(chisla.begin(), chisla.end()));

    cout<<broiPermutacii<<endl;

    return 0;
}
