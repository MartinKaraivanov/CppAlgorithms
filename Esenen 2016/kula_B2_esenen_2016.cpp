#include<iostream>
#include<stack>
using namespace std;

int broiDrugiKuli;

int visochinaNaNashata;

int visochini[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiDrugiKuli>>visochinaNaNashata;

    for(int i = 0; i < broiDrugiKuli; i++){
        cin>>visochini[i];
    }

    stack<int> s;

    int broiPoVisokiOtNashta = 0;

    int maximalenBroiPokritiKuli = 0;

    for(int i = 0; i < broiDrugiKuli; i++){
        while(s.empty() == false){
            int naiOtgore = s.top();
            s.pop();

            if(naiOtgore > visochini[i]){
                s.push(naiOtgore);
                break;
            }

            if(naiOtgore > visochinaNaNashata){
                broiPoVisokiOtNashta--;
            }
        }

        if(visochini[i] > visochinaNaNashata){
            broiPoVisokiOtNashta++;
        }
        s.push(visochini[i]);

        if(s.size() - broiPoVisokiOtNashta > maximalenBroiPokritiKuli){
            maximalenBroiPokritiKuli = s.size() - broiPoVisokiOtNashta;
        }
    }

    cout<<maximalenBroiPokritiKuli<<endl;

    return 0;
}
