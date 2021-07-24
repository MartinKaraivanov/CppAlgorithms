#include<iostream>
#include<algorithm>
using namespace std;

int karti[5];

int main(){
    for(int i = 0; i < 5; i++){
        cin>>karti[i];
    }

    sort(karti, karti + 5);

    if(karti[0] == karti[4]){
        cout<<"Impossible"<<endl;
        return 0;
    }

    if(karti[0] == karti[3] || karti[1] == karti[4]){
        cout<<"Four of a Kind"<<endl;
        return 0;
    }

    if((karti[0] == karti[1] && karti[2] == karti[4]) || (karti[0] == karti[2] && karti[3] == karti[4]))
    {
        cout<<"Full House"<<endl;
        return 0;
    }

    if(karti[0] + 1 == karti[1] && karti[1] + 1 == karti[2] && karti[2] + 1 == karti[3] && karti[3] + 1 == karti[4]){
        cout<<"Straight"<<endl;
        return 0;
    }

    if(karti[0] == karti[2] || karti[1] == karti[3] || karti[2] == karti[4]){
        cout<<"Three of a Kind"<<endl;
        return 0;
    }

    if((karti[0] == karti[1] && karti[2] == karti[3]) ||
        (karti[0] == karti[1] && karti[3] == karti[4]) ||
        (karti[1] == karti[2] && karti[3] == karti[4]))
    {
        cout<<"Two Pairs"<<endl;
        return 0;
    }

    if((karti[0] == karti[1]) ||
       (karti[1] == karti[2]) ||
       (karti[2] == karti[3]) ||
       (karti[3] == karti[4]))
    {
        cout<<"One Pair"<<endl;
        return 0;
    }

    cout<<"Nothing"<<endl;

    return 0;
}
