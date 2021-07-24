#include<iostream>
using namespace std;

int broiMazheEdno;
int broiZheniEdno;

int broiMazheDve;
int broiZheniDve;

int main(){
    cin>>broiMazheEdno>>broiZheniEdno;

    cin>>broiMazheDve>>broiZheniDve;

    if(broiMazheEdno < broiZheniEdno || (broiZheniEdno == broiMazheEdno && broiZheniEdno % 2 == 1)){
        cout<<"NO";
    }else{
        int prednoOtp = -1;
        while(broiZheniEdno > 0 || broiMazheEdno > 0){
            if(prednoOtp == -1){
                if(broiZheniEdno >= 2){
                    cout<<"00";
                    prednoOtp = 0;
                    broiZheniEdno -= 2;
                    continue;
                }
                if(broiZheniEdno == 1){
                    cout<<0;
                    prednoOtp = 0;
                    broiZheniEdno -= 1;
                    continue;
                }
                if(broiZheniEdno == 0){
                    while(broiMazheEdno > 0){
                        cout<<1;
                        broiMazheEdno--;
                    }
                }
            }
            if(prednoOtp == 0){
                if(broiMazheEdno == 1){
                    cout<<1;
                    broiMazheEdno--;
                    prednoOtp = 1;
                    continue;
                }
                if(broiMazheEdno >= 2){
                    cout<<11;
                    broiMazheEdno -= 2;
                    prednoOtp = 1;
                }
            }
            if(prednoOtp == 1){
                if(broiZheniEdno >= 2){
                    cout<<"00";
                    broiZheniEdno -= 2;
                    prednoOtp = 0;
                    continue;
                }
                if(broiZheniEdno == 1){
                    cout<<0;
                    broiZheniEdno--;
                    prednoOtp = 0;
                    continue;
                }
                if(broiZheniEdno == 0){
                    while(broiMazheEdno > 0){
                        cout<<1;
                        broiMazheEdno--;
                    }
                }
            }
        }
    }

    cout<<endl;


    if(broiMazheDve < broiZheniDve || (broiZheniDve == broiMazheDve && broiZheniDve % 2 == 1)){
        cout<<"NO"<<endl;
    }else{
        int prednoOtp = -1;
        while(broiZheniDve > 0 || broiMazheDve > 0){
            if(prednoOtp == -1){
                if(broiZheniDve >= 2){
                    cout<<"00";
                    prednoOtp = 0;
                    broiZheniDve -= 2;
                    continue;
                }
                if(broiZheniDve == 1){
                    cout<<0;
                    prednoOtp = 0;
                    broiZheniDve -= 1;
                    continue;
                }
                if(broiZheniDve == 0){
                    while(broiMazheDve > 0){
                        cout<<1;
                        broiMazheDve--;
                    }
                }
            }
            if(prednoOtp == 0){
                if(broiMazheDve == 1){
                    cout<<1;
                    broiMazheDve--;
                    prednoOtp = 1;
                    continue;
                }
                if(broiMazheDve >= 2){
                    cout<<11;
                    broiMazheDve -= 2;
                    prednoOtp = 1;
                }
            }
            if(prednoOtp == 1){
                if(broiZheniDve >= 2){
                    cout<<"00";
                    broiZheniDve -= 2;
                    prednoOtp = 0;
                    continue;
                }
                if(broiZheniDve == 1){
                    cout<<0;
                    broiZheniDve--;
                    prednoOtp = 0;
                    continue;
                }
                if(broiZheniDve == 0){
                    while(broiMazheDve > 0){
                        cout<<1;
                        broiMazheDve--;
                    }
                }
            }
        }

    }


    return 0;
}
