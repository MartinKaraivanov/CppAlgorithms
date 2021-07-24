#include<iostream>
#include<queue>
using namespace std;

bool sasedstvo[1500][1500];
int ocvetqvane[1500];

int main(){
    int broiNaseleniMesta;
    int prohodimiPatishta;

    cin>>broiNaseleniMesta>>prohodimiPatishta;

    int nachalnoMqsto[prohodimiPatishta];
    int krainoMqsto[prohodimiPatishta];

    for(int i=0;i<prohodimiPatishta;i++){
        cin>>nachalnoMqsto[i]>>krainoMqsto[i];
    }

    int broiVaprosi;
    cin>>broiVaprosi;

    int pitashtoNachalo[broiVaprosi];
    int pitashtKrai[broiVaprosi];

    for(int i=0;i<broiVaprosi;i++){
        cin>>pitashtoNachalo[i]>>pitashtKrai[i];
    }


    for(int i=0;i<prohodimiPatishta;i++){
        sasedstvo[nachalnoMqsto[i]][krainoMqsto[i]]=true;
        sasedstvo[krainoMqsto[i]][nachalnoMqsto[i]]=true;
    }


    int cvqt=1;

    queue<int> patishta;

    for(int i=1;i<=broiNaseleniMesta;i++){
        if(ocvetqvane[i]==0){
            patishta.push(i);

            while(patishta.empty()==false){
                int selo=patishta.front();
                patishta.pop();

                if(ocvetqvane[selo]==0){
                    ocvetqvane[selo]=cvqt;

                    for(int drugoSelo=1;drugoSelo<=broiNaseleniMesta;drugoSelo++){
                        if(sasedstvo[selo][drugoSelo]==true){
                            patishta.push(drugoSelo);
                        }
                    }

                }
            }
            cvqt++;
        }
    }


    char otgovor[broiVaprosi];

    for(int i=0;i<broiVaprosi;i++){
        if(ocvetqvane[pitashtoNachalo[i]]==ocvetqvane[pitashtKrai[i]]){
            otgovor[i]='1';
        }else{
            otgovor[i]='0';
        }
    }

    for(int i=0;i<broiVaprosi;i++){
        cout<<otgovor[i];
    }

    cout<<endl;

    return 0;
}
