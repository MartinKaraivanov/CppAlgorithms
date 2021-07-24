#include<iostream>
#include<cmath>
using namespace std;

int xParvoNachalo;
int yParvoNachalo;
int xParvoKrai;
int yParvoKrai;

int xVtoroNachalo;
int yVtoroNachalo;
int xVtoroKrai;
int yVtoroKrai;

int main(){
    cin>>xParvoNachalo>>yParvoNachalo>>xParvoKrai>>yParvoKrai;
    cin>>xVtoroNachalo>>yVtoroNachalo>>xVtoroKrai>>yVtoroKrai;

    if(xParvoNachalo > xParvoKrai){
        swap(xParvoNachalo, xParvoKrai);
    }

    if(yParvoNachalo > yParvoKrai){
        swap(yParvoNachalo, yParvoKrai);
    }

    if(xVtoroNachalo > xVtoroKrai){
        swap(xVtoroNachalo, xVtoroKrai);
    }

    if(yVtoroNachalo > yVtoroKrai){
        swap(yVtoroNachalo, yVtoroKrai);
    }

    //cout<<xParvoNachalo<<" "<<yParvoNachalo<<" "<<xParvoKrai<<" "<<yParvoKrai<<endl;
    //cout<<xVtoroNachalo<<" "<<yVtoroNachalo<<" "<<xVtoroKrai<<" "<<yVtoroKrai<<endl;


    if(xParvoNachalo == xParvoKrai && xVtoroNachalo == xVtoroKrai){
        if(yParvoNachalo > yVtoroKrai){
            cout<<abs(xParvoNachalo - xVtoroNachalo) + abs(yParvoNachalo - yVtoroKrai)<<endl;

            return 0;
        }

        if(yParvoKrai < yVtoroNachalo){
            cout<<abs(xParvoNachalo - xVtoroNachalo) + abs(yVtoroNachalo - yParvoKrai)<<endl;

            return 0;
        }

        cout<<abs(xParvoNachalo - xVtoroNachalo)<<endl;

        return 0;
    }

    if(xParvoNachalo == xParvoKrai && yVtoroNachalo == yVtoroKrai){
        if(yParvoKrai <  yVtoroNachalo){
            if(xParvoKrai < xVtoroNachalo){
                cout<<abs(xVtoroNachalo - xParvoKrai) + abs(yVtoroNachalo - yParvoKrai)<<endl;

                return 0;
            }

            if(xParvoKrai > xVtoroKrai){
                cout<<abs(xParvoKrai - xVtoroKrai) + abs(yVtoroKrai - yParvoKrai)<<endl;

                return 0;
            }

            cout<<abs(yVtoroKrai - yParvoKrai)<<endl;

            return 0;
        }

        if(yParvoNachalo > yVtoroKrai){
            if(xParvoNachalo < xVtoroNachalo){
                cout<<abs(xVtoroNachalo - xParvoNachalo) + abs(yParvoNachalo - yVtoroNachalo)<<endl;

                return 0;
            }

            if(xParvoNachalo > xVtoroKrai){
                cout<<abs(xParvoNachalo - xVtoroKrai) + abs(yParvoNachalo - yVtoroKrai)<<endl;

                return 0;
            }

            cout<<abs(yParvoNachalo - yVtoroKrai)<<endl;

            return 0;
        }

        if(xVtoroNachalo > xParvoNachalo){
            cout<<abs(xParvoNachalo - xVtoroNachalo)<<endl;
            return 0;
        }

        if(xParvoNachalo > xVtoroKrai){
            cout<<abs(xParvoNachalo - xVtoroKrai)<<endl;

            return 0;
        }

        cout<<0<<endl;

        return 0;
    }

    if(yParvoNachalo == yParvoKrai && xVtoroNachalo == xVtoroKrai){
        if(yVtoroKrai <  yParvoNachalo){
            if(xVtoroKrai < xParvoNachalo){
                cout<<abs(xParvoNachalo - xVtoroKrai) + abs(yParvoNachalo - yVtoroKrai)<<endl;

                return 0;
            }

            if(xVtoroKrai > xParvoKrai){
                cout<<abs(xVtoroKrai - xParvoKrai) + abs(yParvoKrai - yVtoroKrai)<<endl;

                return 0;
            }

            cout<<abs(yParvoKrai - yVtoroKrai)<<endl;

            return 0;
        }

        if(yVtoroNachalo > yParvoKrai){
            if(xVtoroNachalo < xParvoNachalo){
                cout<<abs(xParvoNachalo - xVtoroNachalo) + abs(yVtoroNachalo - yParvoNachalo)<<endl;

                return 0;
            }

            if(xVtoroNachalo > xParvoKrai){
                cout<<abs(xVtoroNachalo - xParvoKrai) + abs(yVtoroNachalo - yParvoKrai)<<endl;

                return 0;
            }

            cout<<abs(yVtoroNachalo - yParvoKrai)<<endl;

            return 0;
        }

        if(xParvoNachalo > xVtoroNachalo){
            cout<<abs(xVtoroNachalo - xParvoNachalo)<<endl;
            return 0;
        }

        if(xVtoroNachalo > xParvoKrai){
            cout<<abs(xVtoroNachalo - xParvoKrai)<<endl;

            return 0;
        }

        cout<<0<<endl;

        return 0;
    }

    if(yParvoNachalo == yParvoKrai && yVtoroNachalo == yVtoroKrai){
        if(xParvoNachalo > xVtoroKrai){
            cout<<abs(yParvoNachalo - yVtoroNachalo) + abs(xParvoNachalo - xVtoroKrai)<<endl;

            return 0;
        }

        if(xParvoKrai < xVtoroNachalo){
            cout<<abs(yParvoNachalo - yVtoroNachalo) + abs(xVtoroNachalo - xParvoKrai)<<endl;

            return 0;
        }

        cout<<abs(yParvoNachalo - yVtoroNachalo)<<endl;


        return 0;
    }

    return 0;
}
