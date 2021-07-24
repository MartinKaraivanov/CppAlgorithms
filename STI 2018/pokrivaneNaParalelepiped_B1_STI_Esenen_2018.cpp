#include<iostream>
using namespace std;

int dopalnitelniKubcheta;

int main(){
    cin>>dopalnitelniKubcheta;

    int minimalnaPovarhnina = 1000000000;
    int minimalenObem = 1000000000;

    int aOtg = 0;
    int bOtg = 0;
    int cOtg = 0;

    for(int a = 1; a <= dopalnitelniKubcheta/4; a++){
        for(int b = 1; b <= a; b++){
            if(a*b > dopalnitelniKubcheta){
                break;
            }
            for(int c = 1; c <= b; c++){
                int tukaKubcheta = dopalnitelniKubcheta;

                int parviSloi = 2*(a*b + b*c + a*c);

                //cout<<a<<" "<<b<<" "<<c<<": "<<endl;

                //cout<<parviSloi<<endl;

                tukaKubcheta -= parviSloi;

                int sloi = 2;

                while(tukaKubcheta > 0){
                    int tekushtSloi = 4*(a + b + c + (sloi - 2))*(sloi - 1) + parviSloi;
                    //cout<<sloi<<" "<<tekushtSloi<<" "<<tukaKubcheta<<endl;
                    tukaKubcheta -= tekushtSloi;
                    sloi++;
                }

                if(tukaKubcheta == 0){
                    if(parviSloi < minimalnaPovarhnina){
                        minimalnaPovarhnina = parviSloi;

                        minimalenObem = a*b*c;

                        aOtg = a;
                        bOtg = b;
                        cOtg = c;
                    }else{
                        if(parviSloi == minimalnaPovarhnina){
                            if(a*b*c < minimalenObem){
                                minimalenObem = a*b*c;

                                aOtg = a;
                                bOtg = b;
                                cOtg = c;
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<aOtg<<"x"<<bOtg<<"x"<<cOtg<<endl;

    return 0;
}
