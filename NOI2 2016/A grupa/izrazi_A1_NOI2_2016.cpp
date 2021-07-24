#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct DanniZaVrashtaneto{
    int stoinost;
    int kadeEZatvarqshtataSkoba;
};

string vhod;

int stoinostNaTaziBukva[250];

//vector<int> otgovori;

int funkciqta(int a, int b){
    if(a == 1 && b == 1){
        return 0;
    }

    return 1;
}

DanniZaVrashtaneto stoinostVTeziSkobi(int poziciqNaOtvarqshta){
    int stoinst = 0;
    bool imaliLiSmePrediTova = false;

    int index = poziciqNaOtvarqshta + 1;

    while(vhod[index] != ')'){
        if(index == vhod.size()){
            break;
        }

        if(vhod[index] == ' '){
            index++;
        }

        //cout<<"sega sum na "<<index<<" tuka ima "<<vhod[index]<<endl;
        if(vhod[index] == '('){
            //cout<<"sq she pusna navutre "<<endl;
            DanniZaVrashtaneto rezultatOtPuskaneto = stoinostVTeziSkobi(index);
            //cout<<"sled vrushtaneto imame "<<stoinst<<" i "<<rezultatOtPuskaneto.stoinost;
            if(imaliLiSmePrediTova == true){
                stoinst = funkciqta(stoinst, rezultatOtPuskaneto.stoinost);
            }else{
                stoinst = rezultatOtPuskaneto.stoinost;
                imaliLiSmePrediTova = true;
            }
            //cout<<" i se poluchava "<<stoinst<<endl;
            index = rezultatOtPuskaneto.kadeEZatvarqshtataSkoba;
            imaliLiSmePrediTova = true;
        }else{
            //cout<<"sq imame "<<stoinst<<" i "<<stoinostNaTaziBukva[vhod[index] - '0'];
            if(imaliLiSmePrediTova == true){
                stoinst = funkciqta(stoinst, stoinostNaTaziBukva[vhod[index]]);
            }else{
                stoinst = stoinostNaTaziBukva[vhod[index]];
                imaliLiSmePrediTova = true;
            }
            //cout<<" i se poluchava "<<stoinst<<endl;
        }

        index++;
    }

    //cout<<"vrushtami "<<stoinst<<endl;
    return {stoinst, index};
}

int sasStack(){
    //int stoinst = 0;
    bool imaliLiSmePrediTova = false;

    stack<int> stoinosti;

    stoinosti.push(-1);

    for(int index = 0; index < vhod.size(); index++){
        //cout<<index<<" "<<vhod[index]<<" "<<stoinosti.top()<<endl;
        if(vhod[index] == '('){
            stoinosti.push(-1);
            continue;
        }

        if(vhod[index] == ')'){
            int naiOtgore = stoinosti.top();
            stoinosti.pop();

            if(stoinosti.empty() == false){
                if(stoinosti.top() == -1){
                    stoinosti.pop();
                    stoinosti.push(naiOtgore);
                }else{
                    int vtorot = stoinosti.top();
                    stoinosti.pop();

                    int novaStoinost = funkciqta(naiOtgore, vtorot);

                    stoinosti.push(novaStoinost);
                }
            }else{
                stoinosti.push(naiOtgore);
            }

            continue;
        }

        if(vhod[index] == ' '){
            continue;
        }

        int naiOtgore = stoinosti.top();

        stoinosti.pop();

        int novaStoinost = -1;

        if(naiOtgore == -1){
            novaStoinost = stoinostNaTaziBukva[vhod[index]];
        }else{
            novaStoinost = funkciqta(naiOtgore, stoinostNaTaziBukva[vhod[index]]);
        }

        stoinosti.push(novaStoinost);
    }

    //cout<<endl;
    return stoinosti.top();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>vhod;

    string stoinosti;

    for(int t = 0; true; t++){
        cin>>stoinosti;
        if(stoinosti[0] == '0' || stoinosti[0] == '1'){
            char segashna = 'a';

            for(unsigned int i = 0; i < stoinosti.size(); i++){
                stoinostNaTaziBukva[segashna] = stoinosti[i] - '0';
                segashna++;
            }

            /*DanniZaVrashtaneto rezultatTuka = stoinostVTeziSkobi(-1);

            cout<<rezultatTuka.stoinost;*/

            int rezultat = sasStack();

            cout<<rezultat;
        }else{
            break;
        }
    }

    /*for(unsigned int i = 0; i < otgovori.size(); i++){
        cout<<otgovori[i];
    }*/

    cout<<endl;

    return 0;
}
