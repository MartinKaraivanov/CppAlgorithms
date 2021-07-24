#include<iostream>
#include "corridor.h"
using namespace std;

step solve(char cellValue){
    int vKoiCisulSme = get_memory(0);
    step otgovor;
    if(vKoiCisulSme == 0){
        if(cellValue == '0'){
            otgovor = {'t', 30};
        }else{
            int kolkoSmeIzminali = get_memory(1);
            if(kolkoSmeIzminali < 205){
                set_memory(1, kolkoSmeIzminali + 1);
                otgovor = {'r', 11};
            }else{
                set_memory(1, 0);
                set_memory(0, 1);
                otgovor = {'t', 23};
            }
        }
    }else{
        int kolkoSmeIzminali = get_memory(1);
        if(cellValue == '0'){
            if(kolkoSmeIzminali == 0){
                set_memory(1, kolkoSmeIzminali + 1);
                otgovor = {'r', 34};
            }else{
                otgovor = {'a', kolkoSmeIzminali};
            }
        }else{
            set_memory(1, kolkoSmeIzminali + 1);
            otgovor = {'r', 12};
        }
    }

    return otgovor;
}
