#include<iostream>
using namespace std;

struct DanniZaDostroqvaneto{
    int koqPregrada;
    int sKolko;
};

int broiPregradi;

int visochini[1000005];

int broiDostroqvaniq;

DanniZaDostroqvaneto dostroqvaniq[1000005];

int naiVisokataPrediNeq[1000005];
int naiVisokataSledNeq[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiPregradi;

    for(int i = 0; i < broiPregradi; i++){
        cin>>visochini[i];
    }

    cin>>broiDostroqvaniq;

    for(int i = 0; i < broiDostroqvaniq; i++){
        int koqPreg;
        int sKolko;
        cin>>koqPreg>>sKolko;

        visochini[koqPreg] += sKolko;
        dostroqvaniq[i] = {koqPreg, sKolko};
    }

    naiVisokataPrediNeq[1] = 0;
    for(int i = 2; i < broiPregradi; i++){
        //naiVisokataPrediNeq[i] = max(naiVisokataPrediNeq[i - 1], visochini[i - 1]);
        if(visochini[naiVisokataPrediNeq[i - 1]] > visochini[i - 1]){
            naiVisokataPrediNeq[i] = naiVisokataPrediNeq[i - 1];
        }else{
            naiVisokataPrediNeq[i] = i - 1;
        }
    }

    naiVisokataSledNeq[broiPregradi - 2] = broiPregradi - 1;
    for(int i = broiPregradi - 3; i >= 0; i--){
        //naiVisokataSledNeq[i] = max(naiVisokataSledNeq[i + 1], visochini[i + 1]);
        if(visochini[naiVisokataSledNeq[i + 1]] > visochini[i + 1]){
            naiVisokataSledNeq[i] = naiVisokataSledNeq[i + 1];
        }else{
            naiVisokataSledNeq[i] = i + 1;
        }
    }
    naiVisokataSledNeq[broiPregradi - 1] = broiPregradi;

    /*for(int i = 0; i < broiPregradi; i++){
        cout<<i<<" "<<naiVisokataPrediNeq[i]<<" "<<naiVisokataSledNeq[i]<<endl;
    }*/

    int broiMahame = 0;

    for(int i = 0; i < broiDostroqvaniq; i++){
        if(dostroqvaniq[i].koqPregrada == 0 || dostroqvaniq[i].koqPregrada == broiPregradi - 1){
            continue;
        }

        int segPregrada = dostroqvaniq[i].koqPregrada;
        int originalnaVisochina = visochini[segPregrada] - dostroqvaniq[i].sKolko;

        if(visochini[naiVisokataPrediNeq[segPregrada]] == visochini[naiVisokataSledNeq[segPregrada]] ||
           (visochini[naiVisokataPrediNeq[segPregrada]] >= visochini[segPregrada] &&
                visochini[naiVisokataSledNeq[segPregrada]] >= visochini[segPregrada]) ||
            (originalnaVisochina >= visochini[naiVisokataPrediNeq[segPregrada]] &&
                originalnaVisochina >= visochini[naiVisokataSledNeq[segPregrada]])
           )
        {
            broiMahame++;
        }

    }

    long long obemDazhd = 0;

    for(int i = 0; i < broiPregradi - 1; i++){
        long long poGolqmotoOtLqvite = max(visochini[i], visochini[naiVisokataPrediNeq[i]]);
        long long poGolqmotoOtDesnite = max(visochini[i + 1], visochini[naiVisokataSledNeq[i + 1]]);
        //cout<<i<<" "<<poGolqmotoOtLqvite<<" "<<poGolqmotoOtDesnite<<endl;

        obemDazhd += min(poGolqmotoOtLqvite, poGolqmotoOtDesnite);
    }

    cout<<broiDostroqvaniq - broiMahame<<" "<<obemDazhd<<endl;

    return 0;
}
