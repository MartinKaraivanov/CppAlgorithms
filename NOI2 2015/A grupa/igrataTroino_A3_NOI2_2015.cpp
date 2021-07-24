#include<iostream>
using namespace std;

/////// todo: bez map - map niama d areshi problema s golemite chisla, samo shte zabavi srednite i shte ima poveche TL
/////// todo: sled kato sme napravili tova da raboti, triava da mojem da potrsim zavisimost v rezultite

/*long long priTolkova[10000][10000];

long long otKadeVzeh;
long long kakvoVzeh;

bool pechelivshLiEHoda(long long broiVEdnata, long long broiVDrugata){
    if(broiVEdnata*3 == broiVDrugata || broiVDrugata*3 == broiVEdnata || (broiVDrugata == 0 && broiVEdnata == 0)){
        return true;
    }

    long long kakvoPishe = priTolkova[broiVEdnata][broiVDrugata];

    if(kakvoPishe > 0){
        if(kakvoPishe == 1){
            return false;
        }else{
            return true;
        }
    }

    bool imaLiPobeda = false;

    long long doKade = max(broiVEdnata, broiVDrugata);

    for(long long kolkoVzimameTuk = 1; kolkoVzimameTuk <= doKade; kolkoVzimameTuk++){
        if(kolkoVzimameTuk <= broiVEdnata){
            bool tekushto = pechelivshLiEHoda(broiVEdnata - kolkoVzimameTuk, broiVDrugata);

            if(tekushto == true){
                imaLiPobeda = true;
                otKadeVzeh = 1;
                kakvoVzeh = kolkoVzimameTuk;
                break;
            }
        }

        if(kolkoVzimameTuk <= broiVDrugata){
            bool tekushto = pechelivshLiEHoda(broiVEdnata, broiVDrugata - kolkoVzimameTuk);

            if(tekushto == true){
                imaLiPobeda = true;
                otKadeVzeh = 2;
                kakvoVzeh = kolkoVzimameTuk;
                break;
            }
        }
    }

    if(imaLiPobeda == true){
        priTolkova[broiVEdnata][broiVDrugata] = 1;
    }else{
        priTolkova[broiVEdnata][broiVDrugata] = 2;
    }

    return !imaLiPobeda;
}*/

int main(){
    /*cout<<"x ";

    for(int i = 0; i < 30; i++){
        cout<<i%10<<" ";
    }
    cout<<endl;

    for(int i = 0; i < 30; i++){
        cout<<i%10<<" ";
        for(int j = 0; j < 30; j++){
            if(pechelivshLiEHoda(i, j) == true){
                cout<<"O ";
            }else{
                cout<<". ";
            }
        }
    cout<<endl;
    }*/


    for(int t = 0; t < 3; t++){
        long long broiVEdnata;
        long long broiVDrugata;

        cin>>broiVEdnata>>broiVDrugata;

        if(broiVEdnata*3 == broiVDrugata ||
           broiVDrugata*3 == broiVEdnata ||
           (broiVEdnata == broiVDrugata && broiVEdnata%3 != 0))
        {
            cout<<0<<endl;
            continue;
        }

        if(broiVEdnata > broiVDrugata){
            cout<<1<<" ";
        }else{
            cout<<2<<" ";
            swap(broiVEdnata, broiVDrugata);
        }

        if(broiVDrugata%3 != 0){
            cout<<broiVEdnata - broiVDrugata<<endl;
        }else{
            cout<<broiVEdnata - (broiVDrugata/3)<<endl;
        }
    }

    return 0;
}
