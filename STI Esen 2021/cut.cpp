#include<vector>
#include<iostream>
#include<stack>
using namespace std;

long long init(vector<int> h, int K){

    long long answer = 0;

    stack<int> s;

    for(int i = 0; i < (int)h.size(); i++){
        int broiMahnati = 0;

        while(s.empty() == false){
            if(h[i] >= s.top()){
                broiMahnati++;
                s.pop();
            }else{
                break;
            }
        }

        s.push(h[i]);
        answer += broiMahnati + min(K, (int)s.size());
    }

    return answer;
}
