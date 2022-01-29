#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<set>
using namespace std;

long long nachalnaParva;
long long nachalnaVtora;
long long nachalnaTreta;

long long kolkoHoda;

struct DanniZaSastoqnie{
    long long broiVParvata;
    long long broiVavVtorata;
    long long broiVTretata;
    long long nomerNaHoda;
};

struct DanniZaHoda{
    long long predenHodNomer;
    long long tipNaHoda; /// 1 - 2v1; 2 - 1v2; 3 - 3v1; 4 - 1v3; 5 - 3v2; 6 - 2v3
};

vector<DanniZaHoda> hodove;

set<pair<long long, long long>> visited;

long long bfs(){

    DanniZaSastoqnie startovo = {nachalnaParva, nachalnaVtora, nachalnaTreta, -1};

    queue<DanniZaSastoqnie> q;

    q.push(startovo);

    long long nomerNaPoslednoto = -1;

    while(q.empty() == false){
        DanniZaSastoqnie naiOtpred = q.front();
        q.pop();

        //cout<<"segashno sastoqnie "<<naiOtpred.broiVParvata<<" "<<naiOtpred.broiVavVtorata<<" "<<naiOtpred.broiVTretata<<endl;

        if(naiOtpred.broiVParvata == 0 || naiOtpred.broiVavVtorata == 0 || naiOtpred.broiVTretata == 0){
            nomerNaPoslednoto = naiOtpred.nomerNaHoda;
            break;
        }

        /// mejdu 1 i 2
        if(naiOtpred.broiVParvata < naiOtpred.broiVavVtorata){
            //cout<<"tuka parvata e po malka ot vtorata"<<endl;
            DanniZaSastoqnie novo = {naiOtpred.broiVParvata*2, naiOtpred.broiVavVtorata-naiOtpred.broiVParvata, naiOtpred.broiVTretata, (long long)hodove.size()};
            if(visited.find({novo.broiVParvata, novo.broiVavVtorata}) == visited.end()){
                //cout<<"i pravim kombinaciq "<<novo.broiVParvata<<" "<<novo.broiVavVtorata<<" "<<novo.broiVTretata<<endl;
                visited.insert({novo.broiVParvata, novo.broiVavVtorata});
                q.push(novo);
                hodove.push_back({naiOtpred.nomerNaHoda, 1});
            }
        }else{
            //cout<<"tuka vtorata e po malka ot parvata"<<endl;
            DanniZaSastoqnie novo = {naiOtpred.broiVParvata-naiOtpred.broiVavVtorata, naiOtpred.broiVavVtorata*2, naiOtpred.broiVTretata, (long long)hodove.size()};
            if(visited.find({novo.broiVParvata, novo.broiVavVtorata}) == visited.end()){
                //cout<<"i pravim kombinaciq "<<novo.broiVParvata<<" "<<novo.broiVavVtorata<<" "<<novo.broiVTretata<<endl;
                visited.insert({novo.broiVParvata, novo.broiVavVtorata});
                q.push(novo);
                hodove.push_back({naiOtpred.nomerNaHoda, 2});
            }
        }

        /// mejdu 1 i 3
        if(naiOtpred.broiVParvata < naiOtpred.broiVTretata){
            //cout<<"tuka parvata e po malka ot tretata"<<endl;
            DanniZaSastoqnie novo = {naiOtpred.broiVParvata*2, naiOtpred.broiVavVtorata, naiOtpred.broiVTretata-naiOtpred.broiVParvata, (long long)hodove.size()};
            if(visited.find({novo.broiVParvata, novo.broiVavVtorata}) == visited.end()){
                //cout<<"i pravim kombinaciq "<<novo.broiVParvata<<" "<<novo.broiVavVtorata<<" "<<novo.broiVTretata<<endl;
                visited.insert({novo.broiVParvata, novo.broiVavVtorata});
                q.push(novo);
                hodove.push_back({naiOtpred.nomerNaHoda, 3});
            }
        }else{
            //cout<<"tuka tretata e po malka ot parvata"<<endl;
            DanniZaSastoqnie novo = {naiOtpred.broiVParvata-naiOtpred.broiVTretata, naiOtpred.broiVavVtorata, naiOtpred.broiVTretata*2, (long long)hodove.size()};
            if(visited.find({novo.broiVParvata, novo.broiVavVtorata}) == visited.end()){
                //cout<<"i pravim kombinaciq "<<novo.broiVParvata<<" "<<novo.broiVavVtorata<<" "<<novo.broiVTretata<<endl;
                visited.insert({novo.broiVParvata, novo.broiVavVtorata});
                q.push(novo);
                hodove.push_back({naiOtpred.nomerNaHoda, 4});
            }
        }

        /// mejdu 2 i 3
        if(naiOtpred.broiVavVtorata < naiOtpred.broiVTretata){
            //cout<<"tuka vtorata e po malka ot tretata"<<endl;
            DanniZaSastoqnie novo = {naiOtpred.broiVParvata, naiOtpred.broiVavVtorata*2, naiOtpred.broiVTretata-naiOtpred.broiVavVtorata, (long long)hodove.size()};
            if(visited.find({novo.broiVParvata, novo.broiVavVtorata}) == visited.end()){
                //cout<<"i pravim kombinaciq "<<novo.broiVParvata<<" "<<novo.broiVavVtorata<<" "<<novo.broiVTretata<<endl;
                visited.insert({novo.broiVParvata, novo.broiVavVtorata});
                q.push(novo);
                hodove.push_back({naiOtpred.nomerNaHoda, 5});
            }
        }else{
            //cout<<"tuka tretata e po malka ot vtorata"<<endl;
            DanniZaSastoqnie novo = {naiOtpred.broiVParvata, naiOtpred.broiVavVtorata-naiOtpred.broiVTretata, naiOtpred.broiVTretata*2, (long long)hodove.size()};
            if(visited.find({novo.broiVParvata, novo.broiVavVtorata}) == visited.end()){
                //cout<<"i pravim kombinaciq "<<novo.broiVParvata<<" "<<novo.broiVavVtorata<<" "<<novo.broiVTretata<<endl;
                visited.insert({novo.broiVParvata, novo.broiVavVtorata});
                q.push(novo);
                hodove.push_back({naiOtpred.nomerNaHoda, 6});
            }
        }

        //cout<<endl;

    }

    return nomerNaPoslednoto;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>nachalnaParva>>nachalnaVtora>>nachalnaTreta;

    cin>>kolkoHoda;

    long long posleden = bfs();

    stack<long long> obratenRed;

    long long segashen = posleden;

    while(segashen != -1){
        obratenRed.push(hodove[segashen].tipNaHoda);
        segashen = hodove[segashen].predenHodNomer;
    }

    cout<<obratenRed.size()<<endl;

    while(obratenRed.empty() == false){
        long long naiOtgore = obratenRed.top();
        obratenRed.pop();

        if(naiOtgore == 1){
            cout<<2<<" "<<1<<endl;
        }else{
            if(naiOtgore == 2){
                cout<<1<<" "<<2<<endl;
            }else{
                if(naiOtgore == 3){
                    cout<<3<<" "<<1<<endl;
                }else{
                    if(naiOtgore == 4){
                        cout<<1<<" "<<3<<endl;
                    }else{
                        if(naiOtgore == 5){
                            cout<<3<<" "<<2<<endl;
                        }else{
                            cout<<2<<" "<<3<<endl;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
