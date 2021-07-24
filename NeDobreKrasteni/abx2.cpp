#include <iostream>
using namespace std;
int main (){
    char a,b;
    int c,normalnoA,normalnoB;
    cin>>a;
    cin>>b;
    cin>>c;
    if(a=='x'){
        normalnoA=c-(b-'0');
        cout<<normalnoA;
    }
    if(b=='x'){
        normalnoB=c-(a-'0');
        cout<<normalnoB;
    }


return 0;
}
