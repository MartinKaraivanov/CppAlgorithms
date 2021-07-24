#include<iostream>
#include<queue>
using namespace std;

bool poznavatLiSe[5000][5000];
int otborNaChovek[5000];
int kolkoChovekaImaVToziOtbor[5000];

int main(){
    int broiUChastnici;
    int broiDvoiki;
    cin>>broiUChastnici>>broiDvoiki;

    for(int i=0;i<broiDvoiki;i++){
        int parviChovek;
        int vtoriChovek;
        cin>>parviChovek>>vtoriChovek;
        poznavatLiSe[parviChovek][vtoriChovek]=true;
        poznavatLiSe[vtoriChovek][parviChovek]=true;
    }

    queue<int> hora;

    otborNaChovek[1]=1;
    hora.push(1);

    while(hora.empty()==false){
        int predenChovek=hora.front();
        hora.pop();

        for(int novChovek=1;novChovek<=broiUChastnici;novChovek++){
            if(otborNaChovek[novChovek]==0){
                if(poznavatLiSe[predenChovek][novChovek]==true){
                    otborNaChovek[novChovek]=otborNaChovek[predenChovek]+1;
                    hora.push(novChovek);
                }
            }
        }
    }

    for(int i=1;i<=broiUChastnici;i++){
        kolkoChovekaImaVToziOtbor[otborNaChovek[i]]++;
    }

    int naiMnogoHoraVOtbor=0;

    for(int i=1;i<=broiUChastnici;i++){
        if(kolkoChovekaImaVToziOtbor[i]>naiMnogoHoraVOtbor){
            naiMnogoHoraVOtbor=kolkoChovekaImaVToziOtbor[i];
        }
    }


    cout<<naiMnogoHoraVOtbor<<endl;

    return 0;
}
