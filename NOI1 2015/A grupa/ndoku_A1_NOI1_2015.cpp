#include<iostream>
#include<map>
using namespace std;

int n;

char otgovarqshtiSimvoli[40];

int main(){
    cin>>n;

    for(int i = 0; i < n; i++){
        char naToziRed[10];
        cin>>naToziRed;
        for(int j = 0; j < n; j++){
            otgovarqshtiSimvoli[i*n + j] = naToziRed[j];
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n*n; i++){
            if(i % n == k){
                for(int j = 0; j < n*n; j++){
                    cout<<otgovarqshtiSimvoli[(j + i)%(n*n)];
                }
                cout<<endl;
            }
        }
    }

    return 0;
}
