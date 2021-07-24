#include<iostream>
#include<stack>
using namespace std;

struct DannZaSkobite{
    int kadeEOtvarqshta;
    int kadeEZatvarqshta;
    char kakvoEPrediTqh;
    char kakvoESledTqh;
    bool imaLiPlusMinus;
    bool imaLiPoDeleno;
    bool ostavatLi;
};

string vhod;

DannZaSkobite skobi[100010];
int broiDvoikiSkobi;

int koqSkobaZapochvaTuk[200010];
int koqSkobaSvarshvaTuk[200010];

int ostavatLiTeziSkobi(int koi){
    /// 0 - specialen slichai, 1 - mahat, 2 - ostavat

    if(skobi[koi].imaLiPoDeleno == false && skobi[koi].imaLiPlusMinus == false)
    {
        return 0;
    }

    if((skobi[koi].kakvoEPrediTqh == '+' && skobi[koi].kakvoESledTqh == ')') ||
        (skobi[koi].kakvoEPrediTqh == '(' && skobi[koi].kakvoESledTqh == '+') ||
        (skobi[koi].kakvoEPrediTqh == '(' && skobi[koi].kakvoESledTqh == '-') ||
        (skobi[koi].kakvoEPrediTqh == '+' && skobi[koi].kakvoESledTqh == '+') ||
        (skobi[koi].kakvoEPrediTqh == '+' && skobi[koi].kakvoESledTqh == '-'))
    {
        return 1;
    }

    if(skobi[koi].imaLiPlusMinus == true || skobi[koi].kakvoEPrediTqh == '/'){
        return 2;
    }

    return 1;
}

void otpechatvane(string zaOtpechatvane, int otKade, int doKade){
    for(int i = otKade; i <= doKade; i++){
        cout<<zaOtpechatvane[i];
    }
    cout<<endl;
}

int main(){
    cin>>vhod;

    stack<int> s;

    for(unsigned int i = 0; i < vhod.size(); i++){
        int vKoqSme = 0;

        if(s.empty() == false){
            vKoqSme = s.top();
        }

        if(vhod[i] == '('){
            broiDvoikiSkobi++;
            vKoqSme = broiDvoikiSkobi;
            skobi[vKoqSme].kadeEOtvarqshta = i;
            if(i == 0){
                skobi[vKoqSme].kakvoEPrediTqh = '(';
            }else{
                skobi[vKoqSme].kakvoEPrediTqh = vhod[i - 1];
            }
            skobi[vKoqSme].ostavatLi = true;
            s.push(vKoqSme);
            koqSkobaZapochvaTuk[i] = vKoqSme;
        }else{
            if(vhod[i] == ')'){
                skobi[vKoqSme].kadeEZatvarqshta = i;
                if(i == vhod.size() - 1){
                    skobi[vKoqSme].kakvoESledTqh = ')';
                }else{
                    skobi[vKoqSme].kakvoESledTqh = vhod[i + 1];
                }
                s.pop();
                koqSkobaSvarshvaTuk[i] = vKoqSme;
            }else{
                if(vhod[i] == '+' || vhod[i] == '-'){
                    skobi[vKoqSme].imaLiPlusMinus = true;
                }else{
                    if(vhod[i] == '*' || vhod[i] == '/'){
                        skobi[vKoqSme].imaLiPoDeleno = true;
                    }
                }
            }
        }
    }

    /*for(int i = 0; i <= broiDvoikiSkobi; i++){
        cout<<i<<" "<<skobi[i].kadeEOtvarqshta<<" "<<skobi[i].kadeEZatvarqshta<<" "<<skobi[i].kakvoEPrediTqh<<" ";
        cout<<skobi[i].kakvoESledTqh<<" "<<skobi[i].imaLiPlusMinus<<" "<<skobi[i].imaLiPoDeleno<<" "<<skobi[i].ostavatLi<<endl;
    }*/

    for(int i = 1; i <= broiDvoikiSkobi; i++){
        int tukaKakvoPravim = ostavatLiTeziSkobi(i);

        //cout<<i<<" "<<tukaKakvoPravim<<endl;

        if(tukaKakvoPravim == 0){
            skobi[i + 1].kakvoEPrediTqh = skobi[i].kakvoEPrediTqh;
            skobi[i + 1].kakvoESledTqh = skobi[i].kakvoESledTqh;
            skobi[i].ostavatLi = false;
        }else{
            if(tukaKakvoPravim == 1){
                skobi[i].ostavatLi = false;
            }else{
                skobi[i].ostavatLi = true;
            }
        }
    }

    string izhod;

    for(unsigned int i = 0; i < vhod.size(); i++){
        if((vhod[i] == '(' && skobi[koqSkobaZapochvaTuk[i]].ostavatLi == false) ||
            (vhod[i] == ')' && skobi[koqSkobaSvarshvaTuk[i]].ostavatLi == false))
        {

        }else{
            izhod.push_back(vhod[i]);
        }
    }

    if(izhod[0] == '(' && izhod[izhod.size() - 1] == ')'){
        int broiOtvarqshti = 0;
        int broiZatvarqshti = 0;

        bool mozhemLiDGiMahnem = true;
        for(unsigned int i = 1; i < izhod.size() - 1; i++){
            if(izhod[i] == '('){
                broiOtvarqshti++;
            }else{
                if(izhod[i] == ')'){
                    broiZatvarqshti++;
                }
            }

            if(broiZatvarqshti > broiOtvarqshti){
                mozhemLiDGiMahnem = false;
                break;
            }
        }

        if(mozhemLiDGiMahnem == true){
            otpechatvane(izhod, 1, izhod.size() - 2);
            return 0;
        }
    }

    otpechatvane(izhod, 0, izhod.size() - 1);

    return 0;
}
