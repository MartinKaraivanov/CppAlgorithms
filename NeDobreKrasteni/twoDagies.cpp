#include<iostream>
using namespace std;
int main(){
    int nachaloNaA;
    int kraiNaA;
    int nachaloNaB;
    int kraiNaB;

    cin>>nachaloNaA>>kraiNaA>>nachaloNaB>>kraiNaB;

    bool presichatLiSe;

    if( ((nachaloNaA>=nachaloNaB) && (nachaloNaA<=kraiNaB)) ||
        ((kraiNaA>=nachaloNaB) && (kraiNaA<=kraiNaB)) ||
        ((nachaloNaB>=nachaloNaA) && (nachaloNaB<=kraiNaA)) ||
        ((kraiNaB>=nachaloNaA) && (kraiNaB<=kraiNaA)) ){

        presichatLiSe=true;
    }else{
        if(kraiNaA<nachaloNaA){
            kraiNaA+=360;
        }
        if(kraiNaB<nachaloNaB){
            kraiNaB+=360;
        }
        if( ((nachaloNaA>=nachaloNaB) && (nachaloNaA<=kraiNaB)) ||
            ((kraiNaA>=nachaloNaB) && (kraiNaA<=kraiNaB)) ||
            ((nachaloNaB>=nachaloNaA) && (nachaloNaB<=kraiNaA)) ||
            ((kraiNaB>=nachaloNaA) && (kraiNaB<=kraiNaA)) ){

            presichatLiSe=true;
        }else{
            presichatLiSe=false;
        }
    }

    cout<<presichatLiSe;

    return 0;
}
