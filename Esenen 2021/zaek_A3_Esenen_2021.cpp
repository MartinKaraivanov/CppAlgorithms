#include<iostream>
using namespace std;

int broiKletki;
int vremeUplashen;
int vremeLubopiten;

int main(){

    cin>>broiKletki>>vremeUplashen>>vremeLubopiten;

    if(vremeUplashen == 0 && vremeLubopiten == 1){
        int broiProverki = broiKletki/2 + 2;

        cout<<broiProverki<<" ";

        for(int i = 0; i < broiProverki; i++){
            cout<<broiKletki/2 + 1<<" ";
        }

        cout<<endl;
    }else{
        if(vremeUplashen == 1 && vremeLubopiten == 0){
            int broiProverki = broiKletki/2 + 1;

            cout<<broiProverki<<" ";

            for(int i = 0; i < broiProverki - 2; i++){
                cout<<broiKletki/2 + 1<<" ";
            }
            cout<<1<<" "<<broiKletki<<endl;
        }else{
            if(vremeUplashen == 1 && vremeLubopiten == 1){
                int broiProverki = broiKletki;

                cout<<broiProverki<<" ";

                int doKoiIndexSme = 1;

                for(int i = 1; i <= broiProverki; i++){
                    if(i % 2 == 1){
                        cout<<doKoiIndexSme<<" ";
                    }else{
                        cout<<broiKletki<<" ";
                    }
                    doKoiIndexSme++;
                }
            }
        }
    }

    return 0;
}
