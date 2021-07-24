#include<iostream>
#include<stack>
using namespace std;
int main(){
    float cenaNaBnzina;

    stack<float> ceni;

    while(cin>>cenaNaBnzina){
        ceni.push(cenaNaBnzina);
    }

    long long naiDlgaRedica=0;
    long long segashnaDalzhina=1;
    float predishnaCena=0;

    while(ceni.empty()==false){
        float naiGornaCena=ceni.top();
        ceni.pop();

        if(naiGornaCena<=predishnaCena){
            segashnaDalzhina++;
        }else{
            segashnaDalzhina=1;
        }

        if(segashnaDalzhina>naiDlgaRedica){
            naiDlgaRedica=segashnaDalzhina;
        }

        predishnaCena=naiGornaCena;
    }

    cout<<naiDlgaRedica<<endl;

    return 0;
}
