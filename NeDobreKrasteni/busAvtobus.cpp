#include<iostream>
#include<algorithm>
using namespace std;

struct danniZaMarshruta{
    int nachalnaSpirka;
    int krainaSpirka;
    int cenaNaKartata;
};

int main(){
    int broiMarshruti;
    int nachalnaSpirka;
    int finalnaSpirka;

    cin>>broiMarshruti>>nachalnaSpirka>>finalnaSpirka;

    danniZaMarshruta spirki[broiMarshruti];

    for(int i=0;i<broiMarshruti;i++){
        cin>>spirki[i].nachalnaSpirka>>spirki[i].krainaSpirka>>spirki[i].cenaNaKartata;
    }

    int obshtaCenaZaPatuvaneto=0;

    for(int i=0;i<broiMarshruti;i++){
        int nachaloNaChast = max(nachalnaSpirka,spirki[i].nachalnaSpirka);
        int kraiNaChast = min(finalnaSpirka,spirki[i].krainaSpirka);

        if (kraiNaChast > nachaloNaChast){
            if(kraiNaChast-nachaloNaChast>spirki[i].cenaNaKartata){
                obshtaCenaZaPatuvaneto+=spirki[i].cenaNaKartata;
            }else{
                obshtaCenaZaPatuvaneto+=kraiNaChast-nachaloNaChast;
            }
        }
    }

    cout<<obshtaCenaZaPatuvaneto<<endl;

    return 0;
}
