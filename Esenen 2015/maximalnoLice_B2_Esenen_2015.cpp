#include<iostream>
#include<stack>
using namespace std;

int broiKoloni;
int visochini[1000010];

int broiOtlqvoDolepeniPoVisoki[1000010];
int broiOtdqsnoDolepeniPoVisoki[1000010];

int main(){
    cin>>broiKoloni;

    for(int i = 0; i < broiKoloni; i++){
        cin>>visochini[i];
    }

    stack<int> s;

    for(int i = 0; i < broiKoloni; i++){
        if(s.empty() == true || visochini[s.top()] < visochini[i]){
            broiOtlqvoDolepeniPoVisoki[i] = 0;
        }else{
            int indexNaPosledenPoVisok = -1;
            while(s.empty() == false && visochini[s.top()] >= visochini[i]){
                indexNaPosledenPoVisok = s.top();
                s.pop();
            }
            broiOtlqvoDolepeniPoVisoki[i] = broiOtlqvoDolepeniPoVisoki[indexNaPosledenPoVisok] + (i - indexNaPosledenPoVisok);
        }
        s.push(i);
    }

    while(s.empty() == false){
        s.pop();
    }

    for(int i = broiKoloni - 1; i >= 0; i--){
        if(s.empty() == true || visochini[s.top()] < visochini[i]){
            broiOtdqsnoDolepeniPoVisoki[i] = 0;
        }else{
            int indexNaPosledenPoVisok = -1;
            while(s.empty() == false && visochini[s.top()] >= visochini[i]){
                indexNaPosledenPoVisok = s.top();
                s.pop();
            }
            broiOtdqsnoDolepeniPoVisoki[i] = broiOtdqsnoDolepeniPoVisoki[indexNaPosledenPoVisok] + (indexNaPosledenPoVisok - i);
        }
        s.push(i);
    }

    int maximalnoLice = 0;

    for(int i = 0; i < broiKoloni; i++){
        int tekushto = (broiOtlqvoDolepeniPoVisoki[i] + broiOtdqsnoDolepeniPoVisoki[i] + 1)*visochini[i];
        //cout<<i<<" "<<broiOtlqvoDolepeniPoVisoki[i]<<" "<<broiOtdqsnoDolepeniPoVisoki[i]<<endl;
        maximalnoLice = max(maximalnoLice, tekushto);
    }

    cout<<maximalnoLice<<endl;

    return 0;
}
