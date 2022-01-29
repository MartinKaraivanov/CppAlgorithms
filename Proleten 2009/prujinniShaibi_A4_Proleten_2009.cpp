#include<iostream>
#include<vector>
#include<set>
using namespace std;

int kolkoShaibi;

int nod(int a, int b){

    if(a > b){
        swap(a, b);
    }

    while(b > 0){
        int p = b;
        b = a%b;
        a = p;
    }

    return a;
}

set<pair<int, int>> priTolkova[111];

set<pair<int, int>> kolkoVazmojnosti(int zaKolkoShaibi){
    if(zaKolkoShaibi == 0){
        set<pair<int, int>> zaVrasht;
        pair<int, int> nula = {0, 1};
        zaVrasht.insert(nula);
        return zaVrasht;
    }
    if(priTolkova[zaKolkoShaibi].size() > 0){
        return priTolkova[zaKolkoShaibi];
    }

    set<pair<int, int>> zaVrasht;

    for(int i = 1; i <= zaKolkoShaibi; i++){
        set<pair<int, int>> tuka = kolkoVazmojnosti(zaKolkoShaibi - i);
        for(set<pair<int, int>>::iterator j = tuka.begin(); j != tuka.end(); j++){
            int novChislitel = (j->first)*i + j->second;
            int novZnamenatel = (j->second)*i;
            int nodatIm = nod(novChislitel, novZnamenatel);
            novChislitel /= nodatIm;
            novZnamenatel /= nodatIm;
            pair<int, int> novoChislo = {novChislitel, novZnamenatel};
            zaVrasht.insert(novoChislo);
        }
    }

    priTolkova[zaKolkoShaibi] = zaVrasht;
    return zaVrasht;
}








/*
otgovori[1] = 1;
otgovori[2] = 2;
otgovori[3] = 3;
otgovori[4] = 5;
otgovori[5] = 7;
otgovori[6] = 11;
otgovori[7] = 15;
otgovori[8] = 22;
otgovori[9] = 30;
otgovori[10] = 41;
otgovori[11] = 55;
otgovori[12] = 75;
otgovori[13] = 97;
otgovori[14] = 129;
otgovori[15] = 166;
otgovori[16] = 213;
otgovori[17] = 272;
otgovori[18] = 343;
otgovori[19] = 430;
otgovori[20] = 536;
otgovori[21] = 664;
otgovori[22] = 822;
otgovori[23] = 1008;
otgovori[24] = 1230;
otgovori[25] = 1495;
otgovori[26] = 1808;
otgovori[27] = 2178;
otgovori[28] = 2616;
otgovori[29] = 3122;
otgovori[30] = 3720;
otgovori[31] = 4416;
otgovori[32] = 5221;
otgovori[33] = 6164;
otgovori[34] = 7249;
otgovori[35] = 8497;
otgovori[36] = 9941;
otgovori[37] = 11593;
otgovori[38] = 13481;
otgovori[39] = 15665;
otgovori[40] = 18150;
otgovori[41] = 20971;
otgovori[42] = 24184;
otgovori[43] = 27827;
otgovori[44] = 31974;
otgovori[45] = 36650;
otgovori[46] = 41944;
otgovori[47] = 47930;
otgovori[48] = 54670;
otgovori[49] = 62256;
otgovori[50] = 70786;
otgovori[51] = 80369;
otgovori[52] = 91112;
otgovori[53] = 103154;
otgovori[54] = 116602;
otgovori[55] = 131678;
otgovori[56] = 148498;
otgovori[57] = 167233;
otgovori[58] = 188134;
otgovori[59] = 211415;
otgovori[60] = 237274;
otgovori[61] = 266013;
otgovori[62] = 297967;
otgovori[63] = 333355;
otgovori[64] = 372567;
otgovori[65] = 416029;
otgovori[66] = 464134;
otgovori[67] = 517244;
otgovori[68] = 575923;
otgovori[69] = 640708;
otgovori[70] = 712174;
otgovori[71] = 790933;
otgovori[72] = 877625;
otgovori[73] = 973112;
otgovori[74] = 1078082;
otgovori[75] = 1193425;
otgovori[76] = 1320094;
otgovori[77] = 1459178;
otgovori[78] = 1611738;
otgovori[79] = 1778922;
otgovori[80] = 1962030;
*/







int sCycli(int zaZaKolkoShaibi){
    priTolkova[0].insert({0, 1});

    for(int zaKolkoShaibi = 1; zaKolkoShaibi <= zaZaKolkoShaibi; zaKolkoShaibi++){

        for(int i = 1; i <= zaKolkoShaibi; i++){
            for(set<pair<int, int>>::iterator j = priTolkova[zaKolkoShaibi - i].begin(); j != priTolkova[zaKolkoShaibi - i].end(); j++){
                int novChislitel = (j->first)*i + j->second;
                int novZnamenatel = (j->second)*i;
                int nodatIm = nod(novChislitel, novZnamenatel);
                novChislitel /= nodatIm;
                novZnamenatel /= nodatIm;
                pair<int, int> novoChislo = {novChislitel, novZnamenatel};
                priTolkova[zaKolkoShaibi].insert(novoChislo);
            }
        }
        cout<<"otgovori["<<zaKolkoShaibi<<"] = "<<priTolkova[zaKolkoShaibi].size()<< ";"<<endl;
    }

    return priTolkova[zaZaKolkoShaibi].size();
}

int main(){

    cin>>kolkoShaibi;

    //int otgovor = kolkoVazmojnosti(kolkoShaibi).size();
    int otgovor = sCycli(kolkoShaibi);

    cout<<otgovor<<endl;

    return 0;
}
