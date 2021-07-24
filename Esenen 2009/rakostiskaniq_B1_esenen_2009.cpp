#include<iostream>
using namespace std;

string polozhenie;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>polozhenie;

    long long broiRakost = 0;
    long long vreme = 0;

    long long broiEdnoDoDrugoL = 0;
    long long broiRta = 0;
    bool imaliLiSmeR = false;

    for(unsigned int i = 0; i < polozhenie.size(); i++){
        if(polozhenie[i] == 'R'){
            imaliLiSmeR = true;
            broiRta++;
            if(broiEdnoDoDrugoL > 0){
                broiEdnoDoDrugoL--;
            }
        }else{
            if(imaliLiSmeR == true){
                broiRakost += broiRta;

                vreme = broiRta + broiEdnoDoDrugoL;

                broiEdnoDoDrugoL++;
            }
        }
    }

    cout<<vreme<<" "<<broiRakost<<endl;

    //cout<<"NEVEREND"<<endl;

    return 0;
}
