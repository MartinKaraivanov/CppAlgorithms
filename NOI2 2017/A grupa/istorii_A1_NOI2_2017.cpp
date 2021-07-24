#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct DanniZaIstoriqta{
    long long zabavnost;
    long long kogaIzticha;
};

long long broiDni;
long long broiDniAktualnost;

long long nachalnaZabavnost;
long long poKakvo;
long long plusKakvo;
long long modulKakvo;

long long novaZabavnost(long long predishnaZabavnost){
    return (predishnaZabavnost*poKakvo + plusKakvo)%modulKakvo;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiDni>>broiDniAktualnost;

    cin>>nachalnaZabavnost>>poKakvo>>plusKakvo>>modulKakvo;

    long long poslednaZabavnost = nachalnaZabavnost;

    long long sbor = nachalnaZabavnost;

    deque<DanniZaIstoriqta> q;

    q.push_front({nachalnaZabavnost, broiDniAktualnost - 1});

    for(long long i = 1; i < broiDni; i++){
        poslednaZabavnost = novaZabavnost(poslednaZabavnost);

        while(q.empty() == false){
            DanniZaIstoriqta naiOtpred = q.front();

            if(poslednaZabavnost > naiOtpred.zabavnost){
                q.pop_front();
            }else{
                break;
            }
        }

        while(q.empty() == false){
            if(q.back().kogaIzticha < i){
                q.pop_back();
            }else{
                break;
            }
        }

        q.push_front({poslednaZabavnost, i + broiDniAktualnost - 1});

        sbor += q.back().zabavnost;
    }

    cout<<sbor<<endl;

    return 0;
}
