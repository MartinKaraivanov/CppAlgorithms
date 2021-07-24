#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int broiDvoiki = 0;

    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            broiDvoiki++;
        }
    }

    cout<<broiDvoiki<<endl;

    return 0;
}
