#include<iostream>
#include<vector>
using namespace std;

const long long Mnogo = 1000000001;

long long broiExtremumi;
long long extremumi[300010];

long long broiKoitoZnaem;
long long koqZnaem[300010];
long long visochinataI[300010];

struct DanniZaTochka{
    long long x;
    long long tip; /// 1 - vrah/dol, 2 - sredna
    bool imaLiVisochina;
    long long visochina;
    long long idxVOrgMasiv;
};

vector<DanniZaTochka> vsichkiteNiTochki;

struct DanniZaVisochinata{
    long long minimalna;
    bool slojiliLiSmeMin;
    long long maximalna;
    bool slojiliLiSmeMax;
};

DanniZaVisochinata visochini[300010];

void slaganeNaVsichki(){
    long long indexExtr = 0;
    long long indexZnae = 0;

    while(indexExtr < broiExtremumi || indexZnae < broiKoitoZnaem){
        if(indexExtr < broiExtremumi && indexZnae < broiKoitoZnaem){
            if(extremumi[indexExtr] < koqZnaem[indexZnae]){
                vsichkiteNiTochki.push_back({extremumi[indexExtr], 1, false, 0, indexExtr});
                indexExtr++;
            }else{
                if(extremumi[indexExtr] > koqZnaem[indexZnae]){
                    vsichkiteNiTochki.push_back({koqZnaem[indexZnae], 2, true, visochinataI[indexZnae], -1});
                    indexZnae++;
                }else{
                    vsichkiteNiTochki.push_back({extremumi[indexExtr], 1, true, visochinataI[indexZnae], indexExtr});
                    indexExtr++;
                    indexZnae++;
                }
            }
        }else{
            if(indexExtr < broiExtremumi){
                vsichkiteNiTochki.push_back({extremumi[indexExtr], 1, false, 0, indexExtr});
                indexExtr++;
            }
            if(indexZnae < broiKoitoZnaem){
                vsichkiteNiTochki.push_back({koqZnaem[indexZnae], 2, true, visochinataI[indexZnae], -1});
                indexZnae++;
            }
        }
    }
}

long long maxRazlikaMejduSasedni(){
    long long maxR = 0;

    for(long long i = 1; i < broiExtremumi; i++){
        maxR = max(maxR, extremumi[i] - extremumi[i - 1]);
    }

    return maxR;
}

void otLqvoNadqsno(){
    long long predenExtr = -1;
    long long predenZnaem = -1;

    for(unsigned long long i = 0; i < vsichkiteNiTochki.size(); i++){
        if(vsichkiteNiTochki[i].tip == 1){
            long long poKakvo = 1;
            if(vsichkiteNiTochki[i].idxVOrgMasiv % 2 == 0){
                poKakvo = -1;
            }

            if(vsichkiteNiTochki[i].imaLiVisochina == true){
                visochini[vsichkiteNiTochki[i].x].minimalna = vsichkiteNiTochki[i].visochina;
                visochini[vsichkiteNiTochki[i].x].maximalna = vsichkiteNiTochki[i].visochina;
                visochini[vsichkiteNiTochki[i].x].slojiliLiSmeMax = true;
                visochini[vsichkiteNiTochki[i].x].slojiliLiSmeMin = true;
                predenZnaem = i;
            }else{
                if(predenZnaem >= predenExtr && predenZnaem > -1){
                    long long vazmojna =
                        vsichkiteNiTochki[predenZnaem].visochina +
                        (vsichkiteNiTochki[i].x - vsichkiteNiTochki[predenZnaem].x)*poKakvo;

                    if(poKakvo == 1){
                        if(visochini[vsichkiteNiTochki[i].x].slojiliLiSmeMin == false){
                            visochini[vsichkiteNiTochki[i].x].minimalna = vazmojna;
                            visochini[vsichkiteNiTochki[i].x].slojiliLiSmeMin = true;
                        }else{
                            visochini[vsichkiteNiTochki[i].x].minimalna =
                                max(visochini[vsichkiteNiTochki[i].x].minimalna, vazmojna);
                        }
                    }else{
                        if(visochini[vsichkiteNiTochki[i].x].slojiliLiSmeMax == false){
                            visochini[vsichkiteNiTochki[i].x].maximalna = vazmojna;
                            visochini[vsichkiteNiTochki[i].x].slojiliLiSmeMax = true;
                        }else{
                            visochini[vsichkiteNiTochki[i].x].maximalna =
                                min(visochini[vsichkiteNiTochki[i].x].maximalna, vazmojna);
                        }
                    }

                }
            }

            predenExtr = i;
        }else{
            visochini[vsichkiteNiTochki[i].x].minimalna = vsichkiteNiTochki[i].visochina;
            visochini[vsichkiteNiTochki[i].x].maximalna = vsichkiteNiTochki[i].visochina;
            visochini[vsichkiteNiTochki[i].x].slojiliLiSmeMin = true;
            visochini[vsichkiteNiTochki[i].x].slojiliLiSmeMax = true;
            predenZnaem = i;
        }
    }
}

void otDqsnoNalqvo(){
    long long predenExtr = vsichkiteNiTochki.size();
    long long predenZnaem = vsichkiteNiTochki.size();

    for(long long i = vsichkiteNiTochki.size() - 1; i >= 0; i--){
        if(vsichkiteNiTochki[i].tip == 1){
            long long poKakvo = 1;
            if(vsichkiteNiTochki[i].idxVOrgMasiv % 2 == 1){
                poKakvo = -1;
            }

            if(vsichkiteNiTochki[i].imaLiVisochina == true){
                visochini[vsichkiteNiTochki[i].x].minimalna = vsichkiteNiTochki[i].visochina;
                visochini[vsichkiteNiTochki[i].x].maximalna = vsichkiteNiTochki[i].visochina;
                visochini[vsichkiteNiTochki[i].x].slojiliLiSmeMax = true;
                visochini[vsichkiteNiTochki[i].x].slojiliLiSmeMin = true;
                predenZnaem = i;
            }else{
                if(predenZnaem <= predenExtr && (unsigned)predenZnaem < vsichkiteNiTochki.size()){
                    long long vazmojna =
                        vsichkiteNiTochki[predenZnaem].visochina +
                        (vsichkiteNiTochki[i].x - vsichkiteNiTochki[predenZnaem].x)*poKakvo;

                    if(poKakvo == -1){
                        if(visochini[vsichkiteNiTochki[i].x].slojiliLiSmeMin == false){
                            visochini[vsichkiteNiTochki[i].x].minimalna = vazmojna;
                            visochini[vsichkiteNiTochki[i].x].slojiliLiSmeMin = true;
                        }else{
                            visochini[vsichkiteNiTochki[i].x].minimalna =
                                max(visochini[vsichkiteNiTochki[i].x].minimalna, vazmojna);
                        }
                    }else{
                        if(visochini[vsichkiteNiTochki[i].x].slojiliLiSmeMax == false){
                            visochini[vsichkiteNiTochki[i].x].maximalna = vazmojna;
                            visochini[vsichkiteNiTochki[i].x].slojiliLiSmeMax = true;
                        }else{
                            visochini[vsichkiteNiTochki[i].x].maximalna =
                                min(visochini[vsichkiteNiTochki[i].x].maximalna, vazmojna);
                        }
                    }

                }
            }

            predenExtr = i;
        }else{
            visochini[vsichkiteNiTochki[i].x].minimalna = vsichkiteNiTochki[i].visochina;
            visochini[vsichkiteNiTochki[i].x].maximalna = vsichkiteNiTochki[i].visochina;
            visochini[vsichkiteNiTochki[i].x].slojiliLiSmeMin = true;
            visochini[vsichkiteNiTochki[i].x].slojiliLiSmeMax = true;
            predenZnaem = i;
        }
    }
}

long long minimalniVazmojniVisochiniNaExtr[300010];

bool toziVNachalotoImaLi[300010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiExtremumi;

    for(long long i = 0; i < broiExtremumi; i++){
        cin>>extremumi[i];
    }

    cin>>broiKoitoZnaem;

    for(long long i = 0; i < broiKoitoZnaem; i++){
        cin>>koqZnaem[i]>>visochinataI[i];
        toziVNachalotoImaLi[koqZnaem[i]] = true;
    }

    slaganeNaVsichki();

    otLqvoNadqsno();

    /*for(long long i = 1; i <= extremumi[broiExtremumi - 1]; i++){
        cout<<i<<" "<<visochini[i].minimalna<<" "<<visochini[i].maximalna<<endl;
    }*/

    otDqsnoNalqvo();

    /*for(long long i = 1; i <= extremumi[broiExtremumi - 1]; i++){
        cout<<i<<" "<<visochini[i].minimalna<<" "<<visochini[i].maximalna<<endl;
    }*/

    long long naiMalkoto = Mnogo;
    long long naiGolqmoto = -Mnogo;

    for(long long i = 0; i < broiExtremumi; i++){
        long long x = extremumi[i];

        if(visochini[x].slojiliLiSmeMin == true){
            naiGolqmoto = max(naiGolqmoto, visochini[x].minimalna);
        }
        if(visochini[x].slojiliLiSmeMax == true){
            naiMalkoto = min(naiMalkoto, visochini[x].maximalna);
        }
    }

    long long akoVzimameStoinostite = naiGolqmoto - naiMalkoto;

    long long naiGolqmataRazlikaMuSasedni = maxRazlikaMejduSasedni();

    long long otg = max(akoVzimameStoinostite, naiGolqmataRazlikaMuSasedni);

    long long minimalnaVazmojna = naiGolqmoto - otg;

    for(long long i = 0; i < broiExtremumi; i += 2){
        if(toziVNachalotoImaLi[extremumi[i]] == false){
            minimalniVazmojniVisochiniNaExtr[i] = minimalnaVazmojna;
            visochini[extremumi[i]].maximalna = minimalnaVazmojna;
            visochini[extremumi[i]].slojiliLiSmeMax = true;
        }else{
            minimalniVazmojniVisochiniNaExtr[i] = visochini[extremumi[i]].maximalna;
        }
    }

    /*for(long long i = 0; i < broiExtremumi; i ++){
        cout<<extremumi[i]<<" "<<minimalniVazmojniVisochiniNaExtr[i]<<endl;
    }*/

    for(long long i = 1; i < broiExtremumi; i += 2){
        if(toziVNachalotoImaLi[extremumi[i]] == true){
            minimalniVazmojniVisochiniNaExtr[i] = visochini[extremumi[i]].minimalna;
        }else{
            long long naLqvo = -Mnogo;

            for(long long x = extremumi[i]; x > 0; x--){
                if(visochini[x].slojiliLiSmeMax == true){
                    naLqvo = visochini[x].maximalna + (extremumi[i] - x);
                    //cout<<"namerihme che na x "<<x<<" ima neshto s visochina "<<visochini[x].maximalna<<endl;
                    break;
                }
            }

            long long naDqsno = -Mnogo;

            for(long long x = extremumi[i]; x <= extremumi[broiExtremumi - 1]; x++){
                if(visochini[x].slojiliLiSmeMax == true){
                    naDqsno = visochini[x].maximalna + (x - extremumi[i]);
                    break;
                }
            }

            //cout<<i<<" "<<naLqvo<<" "<<naDqsno<<endl;
            minimalniVazmojniVisochiniNaExtr[i] = max(naLqvo, naDqsno);
        }
    }

    /*for(long long i = 0; i < broiExtremumi; i ++){
        cout<<extremumi[i]<<" "<<minimalniVazmojniVisochiniNaExtr[i]<<endl;
    }*/

    long long sbor = 0;

    for(long long i = 0; i < broiExtremumi; i++){
        sbor += minimalniVazmojniVisochiniNaExtr[i];
    }

    cout<<otg<<" "<<sbor<<endl;

    return 0;
}
