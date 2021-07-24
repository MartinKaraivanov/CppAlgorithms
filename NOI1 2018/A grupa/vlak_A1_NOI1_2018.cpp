#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main(){
    int doKolkoPermutaciq;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>doKolkoPermutaciq;

    for(int t = 0; t < 5; t++){
        queue<int> a;

        for(int i = 1; i <= doKolkoPermutaciq; i++){
            a.push(i);
        }

        bool mozheLi = true;

        stack<int> c;

        for(int i = 0; i < doKolkoPermutaciq; i++){
            int zaTuk;
            cin>>zaTuk;

            while(a.empty() == false && a.front() <= zaTuk){
                //cout<<"sega v a nai malkoto e "<<a.front()<<endl;
                c.push(a.front());
                a.pop();
            }

            //cout<<"nai otgore na c e "<<c.top()<<endl;
            if(c.top() != zaTuk){
                mozheLi = false;
            }else{
                c.pop();
            }
        }

        if(mozheLi == true){
            cout<<1;
        }else{
            cout<<0;
        }
        //cout<<endl<<endl;
    }

    return 0;
}
