#include<iostream>
#include<string>
#include<stack>
using namespace std;

string dvoichenZapis;

int tovaChisloVDvoichenZapis[] = {11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100 };

bool ednakviLiSaVectorite(string edno, string dve){
    bool stavaLi = true;
    for(int j = 0; j < edno.size(); j++){
        if(edno[j] - '0' != dve[j] - '0'){
            stavaLi = false;
            break;
        }
    }
    return stavaLi;
}

int main(){
    cin>>dvoichenZapis;

    if(dvoichenZapis.size() == 2 && dvoichenZapis[0] == '1' && dvoichenZapis[1] == '1'){
        cout<<0<<endl;
        return 0;
    }

    for(int s : dvoichenZapis){
        cout<<s - '0';
    }

    int broiche = -1;

    for(int i = 0; i < 100000; i++){
        int coppie = i;
        string novoChislo;
        stack<int> s;
        while(coppie > 0){
            int cifra = coppie % 10;
            s.push(tovaChisloVDvoichenZapis[cifra]);
            //cout<<cifra<<" "<<tovaChisloVDvoichenZapis[cifra]<<endl;
            coppie/=10;
        }
        while(s.empty() == false){
            novoChislo.push_back(s.top());
            s.pop();
        }

        //cout<<endl;
        cout<<i<<endl;

        for(int c : dvoichenZapis){
            cout<<c - '0'<<" ";
        }
        cout<<" ";
        for(int c : novoChislo){
            cout<<c<<" ";
        }
        cout<<endl;

        if(ednakviLiSaVectorite(novoChislo, dvoichenZapis)){
            cout<<i<<endl;
            broiche++;
        }

        /*if(novoChislo == dvoichenZapis){
            cout<<i<<endl;
            broiche++;
        }*/
    }

    if(broiche == -1){
        cout<<-1;
    }

    return 0;
}
