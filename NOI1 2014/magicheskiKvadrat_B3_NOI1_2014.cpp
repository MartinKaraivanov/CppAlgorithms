#include<iostream>
#include<algorithm>
using namespace std;

int istinskiChisla[9];

int broiDobriPodredbi;

void pribavqne(){
    int sumichka = istinskiChisla[0] + istinskiChisla[1] + istinskiChisla[2];
    if(istinskiChisla[3] + istinskiChisla[4] + istinskiChisla[5] == sumichka &&
       istinskiChisla[6] + istinskiChisla[7] + istinskiChisla[8] == sumichka &&
       istinskiChisla[0] + istinskiChisla[3] + istinskiChisla[6] == sumichka &&
       istinskiChisla[1] + istinskiChisla[4] + istinskiChisla[7] == sumichka &&
       istinskiChisla[2] + istinskiChisla[5] + istinskiChisla[8] == sumichka &&
       istinskiChisla[0] + istinskiChisla[4] + istinskiChisla[8] == sumichka &&
       istinskiChisla[2] + istinskiChisla[4] + istinskiChisla[6] == sumichka)
    {
        broiDobriPodredbi++;
    }
}

int main(){
    for(int i = 0; i < 9; i++){
        cin>>istinskiChisla[i];
    }

    sort(istinskiChisla, istinskiChisla + 9);

    do{
        pribavqne();
    }
    while(next_permutation(istinskiChisla, istinskiChisla + 9));

    cout<<broiDobriPodredbi<<endl;

    return 0;
}
