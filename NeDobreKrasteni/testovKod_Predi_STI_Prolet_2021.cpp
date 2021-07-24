#include<iostream>
using namespace std;
int main(){
    string bilet;
    cin>>bilet;

    int sumaParviTri = (bilet[0] - '0') + (bilet[1] - '0') + (bilet[2] - '0');
    int sumaVtoriTri = (bilet[3] - '0') + (bilet[4] - '0') + (bilet[5] - '0');

    bool parvotoUslovie = sumaParviTri==sumaVtoriTri;

    bool vtoroUslovie = bilet[1] >= bilet[3];

    if(parvotoUslovie && vtoroUslovie){
        cout<<sumaParviTri<<endl;
    }else{
        if(parvotoUslovie){
            cout<<32<<endl;
        }else{
            if(vtoroUslovie){
                cout<<31<<endl;
            }else{
                cout<<30<<endl;
            }
        }
    }

    return 0;
}
