#include<iostream>
using namespace std;

string vhod;

int main(){
    cin>>vhod;

    int broiEdinici = 0;
    int broiNuli = 0;

    for(unsigned int i = 0; i < vhod.size(); i++){
        if(vhod[i] == '1'){
            broiEdinici++;
        }else{
            broiNuli++;
        }
    }

    if(broiNuli < broiEdinici - 1 || broiEdinici == 1 || (broiEdinici - 1 == broiNuli && broiEdinici%3 != 0)){
        cout<<"NO"<<endl;
        return 0;
    }

    if(broiEdinici == 0){
        cout<<vhod<<endl;
        return 0;
    }

    if(broiEdinici - 1 == broiNuli){
        cout<<1;
        for(int i = broiNuli; i > 0; i--){
            cout<<"01";
        }
        cout<<endl;
        return 0;
    }

    cout<<1;
    broiEdinici--;

    if(broiEdinici % 3 == 2){
        for(int i = broiEdinici; i > 0; i--){
            cout<<"01";
            broiNuli--;
        }
        for(int i = broiNuli; i > 0; i--){
            cout<<0;
        }
        cout<<endl;
    }else{
        if(broiEdinici % 3 == 1){
            for(int i = broiEdinici; i > 1; i--){
                cout<<"01";
                broiNuli--;
            }
            cout<<"001";
            broiNuli -= 2;
            for(int i = broiNuli; i > 0; i--){
                cout<<0;
            }
            cout<<endl;
        }else{
            for(int i = broiEdinici; i > 2; i--){
                cout<<"01";
                broiNuli--;
            }
            cout<<"00101";
            broiNuli -= 3;
            for(int i = broiNuli; i > 0; i--){
                cout<<0;
            }
            cout<<endl;
        }
    }

    return 0;
}
