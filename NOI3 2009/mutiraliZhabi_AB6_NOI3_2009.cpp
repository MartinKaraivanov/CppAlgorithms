#include<iostream>
#include<vector>
using namespace std;

int broiZhabi;

int visochini[1000010];
int silaSkokove[1000010];

int doKakvaVisochinaMozheDaStigne[1000010];

vector<int> v;

int posledenElement(){
    return v[v.size() - 1];
}

int razmer(){
    return v.size();
}

void slozhi(int kakvo){
    v.push_back(kakvo);
}

void mahni(){
    v.pop_back();
}

int kakvoImaNaEdiKoqSiPoziciq(int poziciq){
    return v[razmer() - 1 - poziciq];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiZhabi;

    for(int i = 0; i < broiZhabi; i++){
        cin>>visochini[i];
    }

    for(int i = 0; i < broiZhabi; i++){
        cin>>silaSkokove[i];
    }

    for(int i = broiZhabi - 1; i >= 0; i--){
        while(razmer() > 0 && visochini[posledenElement()] <= visochini[i]){
            mahni();
        }
        if(razmer() == 0 || razmer() < silaSkokove[i]){
            doKakvaVisochinaMozheDaStigne[i] = -1;
        }else{
            doKakvaVisochinaMozheDaStigne[i] = visochini[kakvoImaNaEdiKoqSiPoziciq(silaSkokove[i] - 1)];
        }
        slozhi(i);
    }

    for(int i = 0; i < broiZhabi; i++){
        cout<<doKakvaVisochinaMozheDaStigne[i]<<" ";
    }

    cout<<endl;

    return 0;
}
