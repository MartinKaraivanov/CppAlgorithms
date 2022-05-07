#include<iostream>
using namespace std;
int main(){

    int predenElement = 2;
    int segashenElement = 8;

    for(int i = 2; i < 10; i++){
        int sledvashtElement = 4*segashenElement - 3*predenElement;
        predenElement = segashenElement;
        segashenElement = sledvashtElement;
    }

    cout<<segashenElement<<endl;

    return 0;
}
