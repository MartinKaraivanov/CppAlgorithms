#include<iostream>
#include<cmath>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

DanniZaTochka tochki[4];

bool nqkoeOtLicataSborLiImE(int parvo, int vtoro, int treto, int chetvarto){
    if((parvo + vtoro + treto == chetvarto) ||
        (vtoro + treto + chetvarto == parvo) ||
        (parvo + vtoro + chetvarto == treto) ||
        (parvo + treto + chetvarto == vtoro))
    {
        return true;
    }

    return false;
}

int main(){
    for(int i = 0; i < 4; i++){
        cin>>tochki[i].x>>tochki[i].y;
    }

    /// 2s = ax*(by - cy) + bx*(cy - ay) + cx*(ay - by)

    int liceParvo =
        abs(tochki[0].x*(tochki[1].y - tochki[2].y) +
            tochki[1].x*(tochki[2].y - tochki[0].y) +
            tochki[2].x*(tochki[0].y - tochki[1].y));

    int liceVtoro =
        abs(tochki[1].x*(tochki[2].y - tochki[3].y) +
            tochki[2].x*(tochki[3].y - tochki[1].y) +
            tochki[3].x*(tochki[1].y - tochki[2].y));

    int liceTreto =
        abs(tochki[0].x*(tochki[1].y - tochki[3].y) +
            tochki[1].x*(tochki[3].y - tochki[0].y) +
            tochki[3].x*(tochki[0].y - tochki[1].y));

    int liceChetvarto =
        abs(tochki[0].x*(tochki[3].y - tochki[2].y) +
            tochki[3].x*(tochki[2].y - tochki[0].y) +
            tochki[2].x*(tochki[0].y - tochki[3].y));

    int broiNeNuleviLica = (liceParvo > 0) + (liceVtoro > 0) + (liceTreto > 0) + (liceChetvarto > 0);

    if(broiNeNuleviLica == 0){
        cout<<0<<endl;
        return 0;
    }

    if(broiNeNuleviLica == 2){
        cout<<1<<endl;
        return 0;
    }

    if(broiNeNuleviLica == 3){
        cout<<2<<endl;
        return 0;
    }

    if(broiNeNuleviLica == 4){
        if(nqkoeOtLicataSborLiImE(liceParvo, liceVtoro, liceTreto, liceChetvarto) == true){
            cout<<3<<endl;
        }else{
            cout<<4<<endl;
        }
    }

    return 0;
}
