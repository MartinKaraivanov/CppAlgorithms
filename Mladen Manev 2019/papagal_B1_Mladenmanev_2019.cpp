#include<iostream>
using namespace std;

string duma;

int broiPalindromiOtToziIndex(int index){
    int brPalin = 0;

    int segIndex = index;
    int saotvetenIndex = index;

    while(segIndex >= 0 && saotvetenIndex < duma.size() && duma[segIndex] == duma[saotvetenIndex]){
        brPalin++;
        segIndex--;
        saotvetenIndex++;
    }

    segIndex = index;
    saotvetenIndex = index + 1;

    while(segIndex >= 0 && saotvetenIndex < duma.size() && duma[segIndex] == duma[saotvetenIndex]){
        brPalin++;
        segIndex--;
        saotvetenIndex++;
    }

    return brPalin;
}

int main(){
    cin>>duma;

    int broiPalindromi = 0;

    for(unsigned int i = 0; i < duma.size(); i++){
        int segashno = broiPalindromiOtToziIndex(i);
        broiPalindromi += segashno;
    }

    cout<<broiPalindromi<<endl;

    return 0;
}
