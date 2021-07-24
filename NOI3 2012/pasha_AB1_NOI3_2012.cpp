#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<iomanip>
#include<algorithm>
#include<map>
using namespace std;

const long long mnogo = 100000000;

int broiOvce;
int broiKoshari;
int broiVEdnaKoshara;

long long razstoqnieOtOvcaDoKoshara[505][505];

struct Koordinati{
    double x;
    double y;
};

Koordinati ovce[505];
Koordinati koshari[505];

int broiVarhove;

struct DanniZaSaseda{
    int doKoi;
    int capacitet;
    int potok;
    int indexObratno;
};

long long razstoqnieMejdu(Koordinati a, Koordinati b){
    /*double poX = abs(a.x - b.x);
    poX *= poX;

    double poY = abs(a.y - b.y);
    poY *= poY;

    double pravoRazstoqnie = sqrt(poX + poY);

    double zaVrasht = pravoRazstoqnie * mnogo;*/

    a.x *= mnogo;
    a.y *= mnogo;
    b.x *= mnogo;
    b.y *= mnogo;

    long long zaVrasht = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));

    return (long long)zaVrasht;
}

vector<DanniZaSaseda> sasedstvo[10010];

int nivo[10010];

void nuliraneNaNivoto(){
    for(int i = 0; i <= broiVarhove + 1; i++){
        nivo[i] = -1;
    }
}

bool bfs(int start, int krai){
    nuliraneNaNivoto();

    queue<int> q;
    q.push(start);

    nivo[start] = 0;

    while(q.empty() == false){
        int naiOtpred = q.front();
        q.pop();

        for(int i = 0; i < (int)sasedstvo[naiOtpred].size(); i++){
            DanniZaSaseda sledvasht = sasedstvo[naiOtpred][i];

            if(nivo[sledvasht.doKoi] < 0 && sledvasht.potok < sledvasht.capacitet){
                q.push(sledvasht.doKoi);
                nivo[sledvasht.doKoi] = nivo[naiOtpred] + 1;
            }
        }

    }

    if(nivo[krai] > -1){
        return true;
    }
    return false;
}

int startNaTozi[10010];

int pratiPotok(int segashen, int potok, int kraen){
    if(segashen == kraen){
        return potok;
    }

    for( ; startNaTozi[segashen] < (int)sasedstvo[segashen].size(); startNaTozi[segashen]++){

        DanniZaSaseda &sledvasht = sasedstvo[segashen][startNaTozi[segashen]];

        if(nivo[sledvasht.doKoi] == nivo[segashen] + 1 && sledvasht.potok < sledvasht.capacitet){
            int segashenPotok = min(potok, sledvasht.capacitet - sledvasht.potok);

            int tekushtPotok = pratiPotok(sledvasht.doKoi, segashenPotok, kraen);

            if(tekushtPotok > 0){
                sledvasht.potok += tekushtPotok;

                //cout<<"dobavih ot "<<segashen<<" kum "<<sledvasht.doKoi<<" "<<tekushtPotok<<" i stana ";
                //cout<<sledvasht.potok<<endl;

                sasedstvo[sledvasht.doKoi][sledvasht.indexObratno].potok -= tekushtPotok;
                //cout<<"namalih ot "<<sledvasht.doKoi<<" do "<<sasedstvo[sledvasht.doKoi][sledvasht.indexObratno].doKoi;
                //cout<<" s "<<tekushtPotok;
                //cout<<" i stana na "<<sasedstvo[sledvasht.doKoi][sledvasht.indexObratno].potok<<endl;
                return tekushtPotok;
            }
        }

    }

    return 0;
}

int dinicFlow(int start, int krai){
    int maximalenPotok = 0;

    while(true){
        bool stigameLi = bfs(start, krai);

        if(stigameLi == false){
            break;
        }

        //cout<<"stigameee"<<endl;

        for(int i = 0; i <= broiVarhove + 1; i++){
            startNaTozi[i] = 0;
        }

        //cout<<"nulirahme gi"<<endl;

        int tekushtPotok = pratiPotok(start, 1000000, krai);

        while(tekushtPotok > 0){
            maximalenPotok += tekushtPotok;

            //cout<<"tekushtiq potok e "<<tekushtPotok<<endl;
            tekushtPotok = pratiPotok(start, 1000000, krai);
        }
    }

    return maximalenPotok;
}

int daiNomerche(int nomerNaNeshtoto, bool ovcaLiE){
    if(ovcaLiE == false){
        return nomerNaNeshtoto + broiOvce;
    }

    return nomerNaNeshtoto;
}

void postroiSasedstvo(long long doVreme){
    int startovNomer = broiVarhove;
    int finalenNomer = broiVarhove + 1;

    for(int i = 0; i <= broiVarhove; i++){
        sasedstvo[i].clear();
    }

    for(int i = 0; i < broiOvce; i++){
        int ovcaNomerch = daiNomerche(i, true);

        DanniZaSaseda zaPushvane = {ovcaNomerch, 1, 0, (int)sasedstvo[ovcaNomerch].size()};
        DanniZaSaseda zaPushvane2 = {startovNomer, 0, 0, (int)sasedstvo[startovNomer].size()};
        sasedstvo[startovNomer].push_back(zaPushvane);
        sasedstvo[ovcaNomerch].push_back(zaPushvane2);
    }

    for(int i = 0; i < broiOvce; i++){
        for(int j = 0; j < broiKoshari; j++){
            if(razstoqnieOtOvcaDoKoshara[i][j] <= doVreme){
                int ovcaNomerche = daiNomerche(i, true);
                int kosharkaNomerche = daiNomerche(j, false);

                DanniZaSaseda zaPushvane = {kosharkaNomerche, 1, 0, (int)sasedstvo[kosharkaNomerche].size()};
                DanniZaSaseda zaPushvane2 = {ovcaNomerche, 0, 0, (int)sasedstvo[ovcaNomerche].size()};
                sasedstvo[ovcaNomerche].push_back(zaPushvane);
                sasedstvo[kosharkaNomerche].push_back(zaPushvane2);
            }
        }
    }

    for(int i = 0; i < broiKoshari; i++){
        int kosharkaNomerche = daiNomerche(i, false);

        DanniZaSaseda zaPushvane = {finalenNomer, broiVEdnaKoshara, 0, (int)sasedstvo[finalenNomer].size()};
        DanniZaSaseda zaPushvane2 = {kosharkaNomerche, 0, 0, (int)sasedstvo[kosharkaNomerche].size()};
        sasedstvo[kosharkaNomerche].push_back(zaPushvane);
        sasedstvo[finalenNomer].push_back(zaPushvane2);
    }
}

map<long long, bool> toziImameLiGo;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiOvce>>broiKoshari>>broiVEdnaKoshara;

    for(int i = 0; i < broiOvce; i++){
        cin>>ovce[i].x>>ovce[i].y;
    }

    for(int i = 0; i < broiKoshari; i++){
        cin>>koshari[i].x>>koshari[i].y;
    }

    broiVarhove = broiOvce + broiKoshari;

    vector<long long> vremenata;

    long long naiGolqmoVreme = 0;

    for(int i = 0; i < broiOvce; i++){
        for(int j = 0; j < broiKoshari; j++){
            long long dotazi = razstoqnieMejdu(ovce[i], koshari[j]);

            if(toziImameLiGo[dotazi] == false){
                vremenata.push_back(dotazi);
                toziImameLiGo[dotazi] = true;
            }

            razstoqnieOtOvcaDoKoshara[i][j] = dotazi;
        }
    }

    sort(vremenata.begin(), vremenata.end());

    /*for(long long vreme = mnogo; vreme <= naiGolqmoVreme; vreme++){
        postroiSasedstvo(vreme);

        int potok = fordFulkerson(broiVarhove, broiVarhove + 1);

        cout<<vreme<<" "<<potok<<endl;

        if(potok == broiOvce){
            otgovor = vreme;
            break;
        }
    }*/

    long long lqvKrai = 0;
    long long desenkrai = vremenata.size() - 1;

    while(lqvKrai < desenkrai){
        long long poSredata = (lqvKrai + desenkrai)/2;

        postroiSasedstvo(vremenata[poSredata]);

        /*cout<<"probvame za "<<vremenata[poSredata]<<endl;

        for(int i = 0; i <= broiVarhove + 1; i++){
            cout<<"sasedstvo na "<<i<<": "<<endl;
            for(DanniZaSaseda j : sasedstvo[i]){
                cout<<j.doKoi<<" "<<j.capacitet<<" "<<j.potok<<" "<<j.indexObratno<<endl;
            }
        }*/

        int potok = dinicFlow(broiVarhove, broiVarhove + 1);

        //cout<<"potoka e "<<potok<<endl;


        if(potok == broiOvce){
            desenkrai = poSredata;
        }else{
            lqvKrai = poSredata + 1;
        }
    }

    double otgovor = vremenata[lqvKrai];

    otgovor /= mnogo;

    cout<<fixed<<setprecision(6)<<otgovor<<endl;

    return 0;
}
