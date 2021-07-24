#include<iostream>
using namespace std;
int main(){
    int n;
    int m;
    cin>>n>>m;

    char red[n][m];

    for(int i=0;i<n;i++){
        cin>>red[i];
    }

    int broiTochki=0;
    int broiPoredniRedove=0;

    bool samoZvezdichkiLiIma=true;

    for(int i=0;i<n;i++){

        bool toziRedHubavLiE=true;

        for(int j=0;j<m;j++){
            if(red[i][j]=='.'){
                toziRedHubavLiE=false;
                samoZvezdichkiLiIma=false;
            }
        }

        if(toziRedHubavLiE==true){
            broiPoredniRedove++;
        }else{
            broiTochki+=(broiPoredniRedove*(broiPoredniRedove+1))/2;
            broiPoredniRedove=0;
        }

        if(i==n-1){
            broiTochki+=(broiPoredniRedove*(broiPoredniRedove+1))/2;
        }

    }

    if(samoZvezdichkiLiIma==true){
        cout<<(n*(n+1))/2<<endl;
    }else{
        cout<<broiTochki<<endl;
    }


    return 0;
}
