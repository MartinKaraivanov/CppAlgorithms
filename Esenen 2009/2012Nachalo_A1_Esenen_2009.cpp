#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;

const double pi = 3.14159265358979323846264;

struct Koordinati{
    double x;
    double y;
    double z;
};

int broiLetishta;
int broiVrazki;

double skorost;

int rezervoarCapacitet;

struct DanniZaLetishte{
    Koordinati kadeE;
    int prezarejdaLiSe;
};

DanniZaLetishte letishta[1010];

struct DanniZaPolet{
    int doKade;
    int neobhodimoGorivo;
    double razst;
};

vector<DanniZaPolet> poletiOt[1010];

int start;
int finaal;

struct DanniZaStiganeto{
    double naiMalkoRazst;
    int sKolkoGorivoOst;
};

DanniZaStiganeto naiKasotoDo[1010];

struct DanniZaOpashkata{
    int doKoi;
    int ostavshtoGorivo;
    double razstDoNego;
    double bonusRazstoqnie;

    DanniZaOpashkata(int doKoi, int ostavshtoGorivo, double razstDoNego, double bonusRazstoqnie)
        : doKoi(doKoi), ostavshtoGorivo(ostavshtoGorivo), razstDoNego(razstDoNego), bonusRazstoqnie(bonusRazstoqnie)
    {

    }
};

struct KoiEPoNapred{
    bool operator()(DanniZaOpashkata const& a, DanniZaOpashkata const& b)
    {
        return a.bonusRazstoqnie > b.bonusRazstoqnie;
    }
};

double radiusa;

double razstoqnietoMejduTochki(Koordinati parva, Koordinati vtora){
    Koordinati treta = {vtora.x, vtora.y, parva.z};

    double a = sqrt((parva.x - treta.x)*(parva.x - treta.x) + (parva.y - treta.y)*(parva.y - treta.y));

    double b = abs(vtora.z - treta.z);

    return sqrt(a*a + b*b);
}

double duljinaNaDagataMejdu(Koordinati parva, Koordinati vtora){
    double hordata = razstoqnietoMejduTochki(parva, vtora);

    double sinusa = hordata/(2*radiusa);

    double ygyla = asin(sinusa) * 180.0 / pi;

    double kakvaChastSme = (2*ygyla)/360;

    double obikolkaPlaneta = 2*radiusa*pi;

    return kakvaChastSme*obikolkaPlaneta;
}

double mnogo;

double razstDoKraq[1010];

double nameriOtgovora(){

    for(int i = 1; i <= broiLetishta; i++){
        naiKasotoDo[i] = {mnogo, 0};
    }

    priority_queue<DanniZaOpashkata, vector<DanniZaOpashkata>, KoiEPoNapred> q;

    q.push({start, rezervoarCapacitet, 0, razstDoKraq[start]});

    double otgovora = 0;

    while(q.empty() == false){
        DanniZaOpashkata naiOtpred = q.top();
        q.pop();

        //cout<<naiOtpred.doKoi<<" "<<naiOtpred.ostavshtoGorivo<<" "<<naiOtpred.razstDoNego<<endl;

        if(naiOtpred.ostavshtoGorivo < 0){
            continue;
        }

        if(naiOtpred.razstDoNego > naiKasotoDo[naiOtpred.doKoi].naiMalkoRazst && naiOtpred.ostavshtoGorivo < naiKasotoDo[naiOtpred.doKoi].sKolkoGorivoOst){
            continue;
        }

        if(naiOtpred.bonusRazstoqnie > naiKasotoDo[finaal].naiMalkoRazst){
            //cout<<naiOtpred.doKoi<<" e ravno na "<<finaal;
            otgovora = naiKasotoDo[finaal].naiMalkoRazst/skorost;
            break;
        }

        if(naiOtpred.razstDoNego < naiKasotoDo[naiOtpred.doKoi].naiMalkoRazst){
            naiKasotoDo[naiOtpred.doKoi].naiMalkoRazst = naiOtpred.razstDoNego;
            naiKasotoDo[naiOtpred.doKoi].sKolkoGorivoOst = naiOtpred.ostavshtoGorivo;
        }else{
            if(naiOtpred.razstDoNego > naiKasotoDo[naiOtpred.doKoi].naiMalkoRazst){

            }else{
                naiKasotoDo[naiOtpred.doKoi].sKolkoGorivoOst = max(naiKasotoDo[naiOtpred.doKoi].sKolkoGorivoOst, naiOtpred.ostavshtoGorivo);
            }
        }


        int segaGorivo = naiOtpred.ostavshtoGorivo;

        if(letishta[naiOtpred.doKoi].prezarejdaLiSe == 1){
            segaGorivo = rezervoarCapacitet;
        }

        for(int i = 0; i < (int)poletiOt[naiOtpred.doKoi].size(); i++){
            DanniZaPolet sledvashtoto = poletiOt[naiOtpred.doKoi][i];
            if(sledvashtoto.neobhodimoGorivo <= segaGorivo &&
                (naiOtpred.razstDoNego + sledvashtoto.razst < naiKasotoDo[sledvashtoto.doKade].naiMalkoRazst ||
                    segaGorivo - sledvashtoto.neobhodimoGorivo > naiKasotoDo[sledvashtoto.doKade].sKolkoGorivoOst) &&
                naiOtpred.razstDoNego + sledvashtoto.razst + razstDoKraq[sledvashtoto.doKade] <= naiKasotoDo[finaal].naiMalkoRazst)
            {
                //cout<<"ot "<<naiOtpred.doKoi<<" otivame v "<<sledvashtoto.doKade<<" za pat "<<naiOtpred.razstDoNego + sledvashtoto.razst<<" i shte budem s gorivo ";
                //cout<<segaGorivo - sledvashtoto.neobhodimoGorivo<<endl;
                q.push({sledvashtoto.doKade,
                        segaGorivo - sledvashtoto.neobhodimoGorivo,
                        naiOtpred.razstDoNego + sledvashtoto.razst,
                        naiOtpred.razstDoNego + sledvashtoto.razst + razstDoKraq[sledvashtoto.doKade]});
            }
        }

    }

    return otgovora;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiLetishta>>broiVrazki>>skorost>>rezervoarCapacitet;

    for(int i = 1; i <= broiLetishta; i++){
        cin>>letishta[i].kadeE.x>>letishta[i].kadeE.y>>letishta[i].kadeE.z>>letishta[i].prezarejdaLiSe;
    }

    radiusa = razstoqnietoMejduTochki({0, 0, 0}, letishta[1].kadeE);

    mnogo = 1000000007*pi*radiusa;

    for(int i = 0; i < broiVrazki; i++){
        int otKade;
        int doKade;
        int gorivo;

        cin>>otKade>>doKade>>gorivo;

        double tukaRazst = duljinaNaDagataMejdu(letishta[otKade].kadeE, letishta[doKade].kadeE);

        poletiOt[otKade].push_back({doKade, gorivo, tukaRazst});
        poletiOt[doKade].push_back({otKade, gorivo, tukaRazst});
    }

    cin>>start>>finaal;

    for(int i = 1; i <= broiLetishta; i++){
        razstDoKraq[i] = duljinaNaDagataMejdu(letishta[i].kadeE, letishta[finaal].kadeE);
    }

    double otg = nameriOtgovora();

    cout<<fixed<<setprecision(10)<<otg<<endl;

    return 0;
}
