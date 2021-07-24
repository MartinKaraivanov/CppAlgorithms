#include<iostream>
#include<queue>
#include<map>
using namespace std;

long long broiGradove;
long long broiPatishta;
long long naiMalkoKolkoK;

map<long long, long long> vrazkiIzlizashtiOtNego;

int main(){
    cin>>broiGradove>>broiPatishta;

    for(long long i = 1; i <= broiPatishta; i++){
        long long otGrad;
        long long doGrad;
        cin>>otGrad>>doGrad;
        vrazkiIzlizashtiOtNego[otGrad]++;
        vrazkiIzlizashtiOtNego[doGrad]++;
    }

    cin>>naiMalkoKolkoK;

    /*for(auto element : vrazkiIzlizashtiOtNego){
        cout<<element.first<<" "<<element.second<<endl;
    }*/

    long long broiche = 0;

    queue<long long> q;

    for(map<long long, long long>::iterator el = vrazkiIzlizashtiOtNego.begin(); el != vrazkiIzlizashtiOtNego.end(); el++){
        if(el->second >= naiMalkoKolkoK){
            broiche++;
            q.push(el->first);
        }
    }

    cout<<broiche<<endl;

    if(broiche == 0){
        return 0;
    }

    while(q.empty() == false){
        cout<<q.front()<<" ";
        q.pop();
    }

    cout<<endl;

    return 0;
}
