#include<iostream>
#include<vector>
#include<set>
using namespace std;

int broiSpecialisti;
int broiVrazki;

struct DanniZaNujdaene{
    int otKoi;
    int priPoneKolko;
};

vector<DanniZaNujdaene> toziOtKoiSeNujdae[1010];

vector<int> sasedstvo[1010];

bool segashnoVisited[1010];

bool visited[1010];

bool imaLiCikul(int segashen){
    //cout<<"tuko shto me pusnaha v "<<segashen<<" koito v seg visited e "<<segashnoVisited[segashen]<<endl;
    if(segashnoVisited[segashen] == true){
        //cout<<"sreshtnahme "<<segashen<<endl;
        return true;
    }

    if(visited[segashen] == true){
        return false;
    }

    segashnoVisited[segashen] = true;
    visited[segashen] = true;

    bool zaVrasht = false;

    for(int i = 0; i < (int)sasedstvo[segashen].size(); i++){
        //cout<<"sega sme na "<<segashen<<" i puskame na "<<sasedstvo[segashen][i]<<endl;
        bool tekushto = imaLiCikul(sasedstvo[segashen][i]);
        if(tekushto == true){
            zaVrasht = true;
            break;
        }
    }

    segashnoVisited[segashen] = false;

    return zaVrasht;
}

void praveneNaSasedstvoto(int zaRadiaciq){
    for(int i = 1; i <= broiSpecialisti; i++){
        sasedstvo[i].clear();
        visited[i] = false;
    }

    for(int i = 1; i <= broiSpecialisti; i++){
        for(int j = 0; j < (int)toziOtKoiSeNujdae[i].size(); j++){
            if(toziOtKoiSeNujdae[i][j].priPoneKolko <= zaRadiaciq){
                sasedstvo[toziOtKoiSeNujdae[i][j].otKoi].push_back(i);
                //sasedstvo[i].push_back(toziOtKoiSeNujdae[i][j].otKoi);
            }
        }
    }
}

bool mojeLiSTolkova(int radiaciq){

    praveneNaSasedstvoto(radiaciq);

    /*cout<<"radiaciq "<<radiaciq<<endl;
    for(int i = 1; i <= broiSpecialisti; i++){
        cout<<i<<": "<<sasedstvo[i].size()<<endl;
        for(int j = 0; j < sasedstvo[i].size(); j++){
            cout<<sasedstvo[i][j]<<" ";
        }
        cout<<endl;
    }*/

    bool imaLi = false;

    for(int i = 1; i <= broiSpecialisti; i++){
        if(visited[i] == false){
            //cout<<"puskame ot "<<i<<endl;
            bool tekushto = imaLiCikul(i);

            if(tekushto == true){
                imaLi = true;
                break;
            }
        }
    }

    return !imaLi;
}

vector<int> redNaVlizane;

int broiVlizashtiV[1010];

void praveneNaReda(int finalnaRadiaciq){
    praveneNaSasedstvoto(finalnaRadiaciq);

    /*cout<<finalnaRadiaciq<<endl;

    for(int i = 1; i <= broiSpecialisti; i++){
        cout<<i<<": "<<endl;
        for(int j = 0; j < sasedstvo[i].size(); j++){
            cout<<sasedstvo[i][j]<<" ";
        }
        cout<<endl;
    }*/

    for(int i = 1; i <= broiSpecialisti; i++){
        for(int j = 0; j < (int)sasedstvo[i].size(); j++){
            broiVlizashtiV[sasedstvo[i][j]]++;
        }
    }

    multiset<int> s;

    for(int i = 1; i <= broiSpecialisti; i++){
        if(broiVlizashtiV[i] == 0){
            s.insert(i);
        }
    }

    while(s.empty() == false){
        int segashen = *s.begin();
        s.erase(s.begin());
        redNaVlizane.push_back(segashen);

        for(int i = 0; i < (int)sasedstvo[segashen].size(); i++){
            broiVlizashtiV[sasedstvo[segashen][i]]--;

            if(broiVlizashtiV[sasedstvo[segashen][i]] == 0){
                s.insert(sasedstvo[segashen][i]);
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiSpecialisti>>broiVrazki;

    int maxRadioact = 0;

    for(int i = 0; i < broiVrazki; i++){
        int koi;
        int otKoi;
        int poneK;

        cin>>koi>>otKoi>>poneK;

        toziOtKoiSeNujdae[koi].push_back({otKoi, poneK});

        maxRadioact = max(maxRadioact, poneK);
    }

    int lqvKrai = 0;
    int desenKrai = maxRadioact;

    while(lqvKrai < desenKrai){
        int sredata = (lqvKrai + desenKrai)/2;

        if(mojeLiSTolkova(sredata) == true){
            lqvKrai = sredata + 1;
        }else{
            desenKrai = sredata;
        }
    }

    if(mojeLiSTolkova(lqvKrai) == false){
        lqvKrai--;
    }

    praveneNaReda(lqvKrai);

    if(lqvKrai >= maxRadioact){
        lqvKrai = -1;
    }

    cout<<lqvKrai<<endl;

    for(int i = 0; i < (int)redNaVlizane.size(); i++){
        cout<<redNaVlizane[i]<<" ";
    }

    cout<<endl;

    return 0;
}
