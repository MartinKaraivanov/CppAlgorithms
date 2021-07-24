#include<iostream>
using namespace std;
int main(){
    int a;
    int b;
    int c;
    cin>>a>>b>>c;

    if(0-a+b+c==13){
        cout<<"Yes"<<endl;
    }else{
        if(0-a+0-b+c==13){
            cout<<"Yes"<<endl;
        }else{
            if(0-a+0-b+0-c==13){
                cout<<"Yes"<<endl;
            }else{
                if(a+0-b+0-c==13){
                    cout<<"Yes"<<endl;
                }else{
                    if(a+b+0-c==13){
                        cout<<"Yes"<<endl;
                    }else{
                        if(a+0-b+c==13){
                            cout<<"Yes"<<endl;
                        }else{
                            cout<<"No"<<endl;
                        }
                    }
                }
            }
        }
    }


    return 0;
}
