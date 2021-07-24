#include<iostream>
using namespace std;

char redica[1050];
int broi=0;

int main(){
    char bukva;

    while(cin>>bukva){
        redica[broi]=bukva;
        broi++;
    }

    bool pravimLiPromqna=true;

    while((pravimLiPromqna==true) && (broi>=3) ){
        char kopirasht[1050];
        int novBroi=0;

        char predhodenSimvol = 0;
        int broiPosledovatelniEdnakvi=1;

        for(int i=0;i<broi;i++){
            if(predhodenSimvol==redica[i]){
                broiPosledovatelniEdnakvi++;

                if(broiPosledovatelniEdnakvi==3){
                    novBroi=novBroi-2;
                }
            }else{
                broiPosledovatelniEdnakvi=1;
                predhodenSimvol=redica[i];
            }

            if(broiPosledovatelniEdnakvi<=2){
                kopirasht[novBroi]=redica[i];
                novBroi++;
            }
        }

        if(novBroi==broi){
            pravimLiPromqna=false;
        }

        for(int i=0;i<novBroi;i++){
            redica[i]=kopirasht[i];
        }

        broi=novBroi;
    }

    if(broi>0){
        for(int i=0;i<broi;i++){
            cout<<redica[i];
        }
    }else{
        cout<<"EMPTY";
    }

    cout<<endl;

    return 0;
}
