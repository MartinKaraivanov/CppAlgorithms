#include<iostream>
using namespace std;

int start[6];
int krai[6];

int main(){
    cin>>start[0]>>start[1]>>start[2]>>start[3]>>start[4]>>start[5];
    cin>>krai[0]>>krai[1]>>krai[2]>>krai[3]>>krai[4]>>krai[5];

    int broiche = 0;

    while(start[0] != krai[0] && start[1] != krai[1] && start[2] != krai[2] &&
            start[3] != krai[3] && start[4] != krai[4] && start[5] != krai[5])
    {
        broiche++;
        int indexhe = 5;
        while(start[indexhe] == 2){

        }
    }

    cout<<broiche<<endl;

    return 0;
}
