#include<iostream>
using namespace std;

int broiVarhove;
int start;
int finish;
int broiRebra;
double patishtaINadezhnost[55][55];
bool biliLiSmeTuk[55];
bool imameLiNaiNadezhdenPat[55][55];

int main(){
    cin>>broiVarhove>>start>>finish>>broiRebra;

    for(int i=0;i<broiRebra;i++){
        int a;
        int b;
        int r;

        cin>>a>>b>>r;

        patishtaINadezhnost[a][b]=r;
        patishtaINadezhnost[b][a]=r;
    }

    patishtaINadezhnost[start][start]=100;
    imameLiNaiNadezhdenPat[start][start]=true;

    bool nameriliLiSmeNeshto=true;
    while(nameriliLiSmeNeshto==true){
        nameriliLiSmeNeshto=false;

        double naiNadezhdno=0;
        int doKoiVrahENaiNadezhdno;

        for(int mezhdinenVrah=0;mezhdinenVrah<broiVarhove;mezhdinenVrah++){
            if((patishtaINadezhnost[start][mezhdinenVrah]>naiNadezhdno) &&
            (imameLiNaiNadezhdenPat[start][mezhdinenVrah]==false))
            {
                naiNadezhdno=patishtaINadezhnost[start][mezhdinenVrah];
                doKoiVrahENaiNadezhdno=mezhdinenVrah;
                nameriliLiSmeNeshto=true;
            }
        }

        if(nameriliLiSmeNeshto==true){
            imameLiNaiNadezhdenPat[start][doKoiVrahENaiNadezhdno]=true;

            for(int doVrah=0 ; doVrah<broiVarhove ; doVrah++){
                if( (imameLiNaiNadezhdenPat[start][doVrah]==false) &&
                    (patishtaINadezhnost[doKoiVrahENaiNadezhdno][doVrah]>0) &&
                    (patishtaINadezhnost[start][doVrah] <
                        patishtaINadezhnost[start][doKoiVrahENaiNadezhdno]+patishtaINadezhnost[doKoiVrahENaiNadezhdno][doVrah]))
                {
                    patishtaINadezhnost[start][doVrah] =
                        (patishtaINadezhnost[start][doKoiVrahENaiNadezhdno]*
                         patishtaINadezhnost[doKoiVrahENaiNadezhdno][doVrah])/100;
                }
            }
        }

    }

    double nadezhdnost=patishtaINadezhnost[start][finish];

    cout<<nadezhdnost;

    return 0;
}
