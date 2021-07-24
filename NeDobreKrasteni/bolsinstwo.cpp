#include<iostream>
#include<algorithm>

bool poMalkoLiE(int a, int b){
    return a<b;
}

using namespace std;
int main(){
    long long n;
    cin>>n;
    long long chisla[n];
    for(int i=0;i<n;i++){
        cin>>chisla[i];
    }

    sort(chisla,chisla+n,poMalkoLiE);
    cout<<chisla[n/2];

    return 0;
}
