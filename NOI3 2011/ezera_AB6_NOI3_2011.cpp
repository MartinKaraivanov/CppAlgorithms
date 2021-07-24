#include<iostream>
#include<stack>
using namespace std;

struct DanniZaEzeroto{
    int nachalo;
    int krai;
};

int main(){
    stack<int> s;

    int x = 0;

    char naklonTuk;

    int obshtSbor = 0;

    stack<DanniZaEzeroto> ezera;

    while(cin>>naklonTuk){
        if(naklonTuk == '_'){

        }else{
            if(naklonTuk == '/'){
                if(s.empty() == false){
                    int naiOtgore = s.top();
                    s.pop();
                    int tuka = 2*(x - naiOtgore);
                    obshtSbor += tuka;

                    while(ezera.empty() == false){
                        DanniZaEzeroto segashnoEzero = ezera.top();
                        if(naiOtgore < segashnoEzero.nachalo && x > segashnoEzero.krai){
                            ezera.pop();
                        }else{
                            break;
                        }
                    }

                    ezera.push({naiOtgore, x});
                }
            }else{
                s.push(x);
            }
        }
        x++;
    }

    cout<<ezera.size()<<" "<<obshtSbor/2<<endl;

    return 0;
}
