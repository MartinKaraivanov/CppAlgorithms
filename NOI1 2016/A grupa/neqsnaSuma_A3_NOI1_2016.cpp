#include<iostream>
#include<vector>
using namespace std;

struct DanniZaVrahstaneto{
    char bit;
    char prenos;
};

string parvo;
string vtoro;

vector<char> bitoveParvo;
vector<char> bitoveVtoro;

DanniZaVrahstaneto kakvoSheETuk(char edinBit, char drugBit, char prenos){
    DanniZaVrahstaneto zaVrasht;

    if(edinBit == '0'){
        if(drugBit == '0'){
            if(prenos == '0'){
                //000
                zaVrasht = {'0', '0'};
            }else{
                if(prenos == '1'){
                    //001
                    zaVrasht = {'1', '0'};
                }else{
                    //00?
                    zaVrasht = {'?', '0'};
                }
            }
        }else{
            if(drugBit == '1'){
                if(prenos == '0'){
                    //010
                    zaVrasht = {'1', '0'};
                }else{
                    if(prenos == '1'){
                        //011
                        zaVrasht = {'0', '1'};
                    }else{
                        //01?
                        zaVrasht = {'?', '?'};
                    }
                }
            }else{
                if(prenos == '0'){
                    //0?0
                    zaVrasht = {'?', '0'};
                }else{
                    if(prenos == '1'){
                        //0?1
                        zaVrasht = {'?', '?'};
                    }else{
                        //0??
                        zaVrasht = {'?', '?'};
                    }
                }
            }
        }
    }else{
        if(edinBit == '1'){
            if(drugBit == '0'){
                if(prenos == '0'){
                    //100
                    zaVrasht = {'1', '0'};
                }else{
                    if(prenos == '1'){
                        //101
                        zaVrasht = {'0', '1'};
                    }else{
                        //10?
                        zaVrasht = {'?', '?'};
                    }
                }
            }else{
                if(drugBit == '1'){
                    if(prenos == '0'){
                        //110
                        zaVrasht = {'0', '1'};
                    }else{
                        if(prenos == '1'){
                            //111
                            zaVrasht = {'1', '1'};
                        }else{
                            //11?
                            zaVrasht = {'?', '1'};
                        }
                    }
                }else{
                    if(prenos == '0'){
                        //1?0
                        zaVrasht = {'?', '?'};
                    }else{
                        if(prenos == '1'){
                            //1?1
                            zaVrasht = {'?', '1'};
                        }else{
                            //1??
                            zaVrasht = {'?', '?'};
                        }
                    }
                }
            }
        }else{
            if(drugBit == '0'){
                if(prenos == '0'){
                    //?00
                    zaVrasht = {'?', '0'};
                }else{
                    if(prenos == '1'){
                        //?01
                        zaVrasht = {'?', '?'};
                    }else{
                        //?0?
                        zaVrasht = {'?', '?'};
                    }
                }
            }else{
                if(drugBit == '1'){
                    if(prenos == '0'){
                        //?10
                        zaVrasht = {'?', '?'};
                    }else{
                        if(prenos == '1'){
                            //?11
                            zaVrasht = {'?', '1'};
                        }else{
                            //?1?
                            zaVrasht = {'?', '?'};
                        }
                    }
                }else{
                    if(prenos == '0'){
                        //??0
                        zaVrasht = {'?', '?'};
                    }else{
                        if(prenos == '1'){
                            //??1
                            zaVrasht = {'?', '?'};
                        }else{
                            //???
                            zaVrasht = {'?', '?'};
                        }
                    }
                }
            }
        }
    }

    return zaVrasht;
}

int main(){
    cin>>parvo>>vtoro;

    bitoveParvo.push_back('0');
    bitoveVtoro.push_back('0');

    if(parvo.size() < vtoro.size()){
        for(unsigned int i = 0; i < vtoro.size() - parvo.size(); i++){
            bitoveParvo.push_back('0');
        }
    }else{
        for(unsigned int i = 0; i < parvo.size() - vtoro.size(); i++){
            bitoveVtoro.push_back('0');
        }
    }

    for(unsigned int i = 0; i < parvo.size(); i++){
        bitoveParvo.push_back(parvo[i]);
    }

    for(unsigned int i = 0; i < vtoro.size(); i++){
        bitoveVtoro.push_back(vtoro[i]);
    }

    vector<char> otgovor;

    otgovor.resize(bitoveParvo.size());

    char prenos = '0';

    for(unsigned int i = bitoveParvo.size() - 1; i > 0; i--){
        DanniZaVrahstaneto zaTuk = kakvoSheETuk(bitoveParvo[i], bitoveVtoro[i], prenos);

        otgovor[i] = zaTuk.bit;
        prenos = zaTuk.prenos;
    }

    if(prenos != '0'){
        cout<<prenos;
    }

    for(unsigned int i = 1; i < otgovor.size(); i++){
        cout<<otgovor[i];
    }

    cout<<endl;

    return 0;
}
