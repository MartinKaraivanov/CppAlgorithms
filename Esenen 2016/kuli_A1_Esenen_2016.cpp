#include<iostream>
#include<stack>
using namespace std;

int broiSgradi;
int visochini[1000010];

int broiKuli;
int visochiniKuli[100010];

int otgovori[100010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiSgradi>>broiKuli;

    for(int i = 0; i < broiSgradi; i++){
        cin>>visochini[i];
    }

    for(int i = 0; i < broiKuli; i++){
        cin>>visochiniKuli[i];
    }

    for(int i = 0; i < broiKuli; i++){
        stack<int> s;

        int naiMnogoto = 0;

        int broiPokrivanivMomenta = 0;

        //cout<<"za kulata s visochina "<<visochiniKuli[i]<<endl;

        for(int j = 0; j < broiSgradi; j++){
            while(s.empty() == false){
                if(s.top() < visochini[j]){

                    if(visochiniKuli[i] > s.top()){
                        broiPokrivanivMomenta--;
                    }

                    s.pop();
                }else{
                    break;
                }
            }

            s.push(visochini[j]);

            if(visochini[j] < visochiniKuli[i]){
                broiPokrivanivMomenta++;
            }

            //cout<<"sgrada "<<j<<" s visochina "<<visochini[j]<<" i moje da pokriva "<<broiPokrivanivMomenta<<endl;

            naiMnogoto = max(naiMnogoto, broiPokrivanivMomenta);
        }

        //cout<<"otgovora e "<<naiMnogoto<<endl;

        otgovori[i] = naiMnogoto;
    }

    for(int i = 0; i < broiKuli; i++){
        cout<<otgovori[i]<<" ";
    }

    cout<<endl;

    return 0;
}
