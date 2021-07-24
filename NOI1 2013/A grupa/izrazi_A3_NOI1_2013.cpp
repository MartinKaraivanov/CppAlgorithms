#include<iostream>
#include<stack>
using namespace std;

string izrazi[4];

int main(){

    for(int t = 0; t < 4; t++){
        cin>>izrazi[t];

        stack<int> zaNormalniSkobi;
        stack<int> zaKvadratniSkobi;

        bool tovaOkLiE = true;

        for(unsigned int i = 0; i < izrazi[t].size(); i++){
            char segashenElement = izrazi[t][i];

            //cout<<i<<" "<<zaNormalniSkobi.size()<<" "<<zaKvadratniSkobi.size()<<endl;

            if((segashenElement == ')' && zaNormalniSkobi.size() == 0) ||
                (segashenElement == ']' && zaKvadratniSkobi.size() == 0) ||
                (segashenElement == '(' && zaNormalniSkobi.size() >= 1) ||
                (segashenElement == '[' && (zaNormalniSkobi.size() >= 1 || zaKvadratniSkobi.size() >= 1)) ||
                (segashenElement == ')' && izrazi[t][i - 1] != '(') ||
                (segashenElement == ']' && izrazi[t][i - 1] != ')') ||
                (segashenElement == ']' && zaNormalniSkobi.size() >= 1))
            {
                //cout<<"skoba na index "<<i<<" ne e ok"<<endl;
                tovaOkLiE = false;
                break;
            }

            if(segashenElement == '('){
                zaNormalniSkobi.push(1);
            }else{
                if(segashenElement == ')'){
                    zaNormalniSkobi.pop();
                }else{
                    if(segashenElement == '['){
                        zaKvadratniSkobi.push(1);
                    }else{
                        zaKvadratniSkobi.pop();
                    }
                }
            }
        }

        if(zaKvadratniSkobi.size() >= 1 || zaNormalniSkobi.size() >= 1){
            tovaOkLiE = false;
        }

        if(tovaOkLiE == true){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }

    }

    return 0;
}
