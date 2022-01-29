#include<string>
using namespace std;

string find_reverse(int N, int M, int connections[][2]){

    string otgovor;

    for(int i = 0; i < M; i++){
        if(connections[i][0] > connections[i][1]){
            otgovor.push_back('1');
        }else{
            otgovor.push_back('0');
        }
    }

    return otgovor;
}
