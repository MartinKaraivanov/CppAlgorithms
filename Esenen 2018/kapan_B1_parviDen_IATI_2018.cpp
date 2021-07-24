#include<iostream>
using namespace std;

int broiOtsechki;

bool imameLiVertikalnaOtsechka;

bool izpolzvanaLiE[80][80];

int daiKoordinat(int a){
    return a + broiOtsechki;
}

bool mozheLiDaMrudnem(int x, int y){
    if(izpolzvanaLiE[daiKoordinat(x - 1)][daiKoordinat(y)] == false ||
       izpolzvanaLiE[daiKoordinat(x + 1)][daiKoordinat(y)] == false ||
       izpolzvanaLiE[daiKoordinat(x)][daiKoordinat(y - 1)] == false ||
       izpolzvanaLiE[daiKoordinat(x)][daiKoordinat(y + 1)] == false)
    {
        return true;
    }

    return false;
}

long long broiVazmozhniKombinaiiZaTrap(int broiOstavashtiOtsechki, int x, int y, bool hodiliLiSmeNagore){
    if(izpolzvanaLiE[daiKoordinat(x)][daiKoordinat(y)] == true){
        return 0;
    }

    izpolzvanaLiE[daiKoordinat(x)][daiKoordinat(y)] = true;

    if(broiOstavashtiOtsechki == 0){
        if(mozheLiDaMrudnem(x, y) == false){
            return 1;
        }

        return 0;
    }

    long long zaTuk = 0;

    zaTuk += broiVazmozhniKombinaiiZaTrap(broiOstavashtiOtsechki - 1, x - 1, y, hodiliLiSmeNagore);

    zaTuk += broiVazmozhniKombinaiiZaTrap(broiOstavashtiOtsechki - 1, x + 1, y, hodiliLiSmeNagore);

    zaTuk += broiVazmozhniKombinaiiZaTrap(broiOstavashtiOtsechki - 1, x, y + 1, true);

    if(hodiliLiSmeNagore == true){
        zaTuk += broiVazmozhniKombinaiiZaTrap(broiOstavashtiOtsechki - 1, x, y - 1, hodiliLiSmeNagore);
    }

    return zaTuk;
}

int main(){
    cin>>broiOtsechki;

    izpolzvanaLiE[daiKoordinat(0)][daiKoordinat(0)] = true;

    long long broiKapani = broiVazmozhniKombinaiiZaTrap(broiOtsechki - 1, 1, 0, false);

    cout<<broiKapani<<endl;

    return 0;
}
