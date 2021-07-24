#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

string vhod;

string cifrataVDvoichna(int cifra){
    if(cifra == 0){
        return "11";
    }

    int chisloto = cifra + 3;

    stack<int> cifriteMuNaobratno;

    while(chisloto > 0){
        cifriteMuNaobratno.push(chisloto%2);
        chisloto /= 2;
    }

    string zaVrashtane;

    while(cifriteMuNaobratno.empty() == false){
        zaVrashtane += cifriteMuNaobratno.top() + '0';
        cifriteMuNaobratno.pop();
    }

    return zaVrashtane;
}

string sglobqvane(queue<string> otdelniChasti){
    string zaVrasht;

    while(otdelniChasti.empty() == false){
        zaVrasht += otdelniChasti.front();
        otdelniChasti.pop();
    }

    return zaVrasht;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>vhod;

    vector<int> otgovori;

    for(int chislo = 0; chislo <= 90000; chislo++){
        int copieNaChislo = chislo;
        stack<int> cifriteNahisloto;

        if(chislo == 0){
            cifriteNahisloto.push(0);
        }

        while(copieNaChislo > 0){
            cifriteNahisloto.push(copieNaChislo%10);
            copieNaChislo /= 10;
        }

        queue<string> kodiranotoChislo;

        while(cifriteNahisloto.empty() == false){
            kodiranotoChislo.push(cifrataVDvoichna(cifriteNahisloto.top()));
            cifriteNahisloto.pop();
        }

        string segashnotoChislo = sglobqvane(kodiranotoChislo);

        //cout<<chislo<<" "<<segashnotoChislo<<endl;

        if(segashnotoChislo == vhod){
            otgovori.push_back(chislo);
        }
    }

    if(otgovori.size() == 0){
        cout<<-1<<endl;
    }

    for(unsigned int i = 0; i < otgovori.size(); i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
