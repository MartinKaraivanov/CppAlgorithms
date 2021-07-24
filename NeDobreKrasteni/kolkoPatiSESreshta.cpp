#include <iostream>
using namespace std;
int main(){
    int daljina,naKoeERavno,broene=0;
    cin>>daljina>>naKoeERavno;
    int masiv[daljina];
    for(int i=0;i<daljina;i++){
        cin>>masiv[i];
    }
    for(int i=0;i<daljina;i++){
        if(masiv[i]==naKoeERavno){
            broene++;
        }
    }
    cout<<broene;

    return 0;
}
