#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int broiZaqvki;

struct Koordinati{
    long long x;
    long long y;
};

Koordinati tochki[1000010];

Koordinati transformiraiTochkata(Koordinati tochka){
    return {-(tochka.y + tochka.x), tochka.y - tochka.x};
}

bool koqEPoNapred(Koordinati a, Koordinati b){
    if(a.y < b.y){
        return true;
    }
    if(a.y > b.y){
        return false;
    }
    return a.x > b.x;
}

set<int> kadeIma;

int main(){

    cin>>broiZaqvki;

    for(int i = 0; i < broiZaqvki; i++){
        cin>>tochki[i].y>>tochki[i].x;
    }

    for(int i = 0; i < broiZaqvki; i++){
        tochki[i] = transformiraiTochkata(tochki[i]);
    }

    sort(tochki, tochki + broiZaqvki, koqEPoNapred);


    for(int i = 0; i < broiZaqvki; i++){

        set<int>::iterator a = kadeIma.lower_bound(tochki[i].x);

        //cout<<"za tochka "<<tochki[i].x<<" "<<tochki[i].y<<" namirame "<<*a<<endl;

        if(a == kadeIma.end()){
            //cout<<"NQMAA"<<endl;
            kadeIma.insert(tochki[i].x);
        }else{
            kadeIma.erase(a);
            kadeIma.insert(tochki[i].x);

            /*cout<<"sled kato iztrivame segashnoto i dobavqme seta e ";
            for(int j : kadeIma){
                cout<<j<<" ";
            }
            cout<<endl;*/
        }
    }

    cout<<kadeIma.size()<<endl;

    return 0;
}
