#include<iostream>
#include<cmath>
using namespace std;

long long xSkakalec;
long long ySkakalec;
long long xParvi;
long long yParvi;
long long xVtori;
long long yVtori;

int main(){
    cin>>xSkakalec>>ySkakalec>>xParvi>>yParvi>>xVtori>>yVtori;

    if(xParvi > xVtori){
        swap(xParvi, xVtori);
    }

    if(yParvi > yVtori){
        swap(yParvi, yVtori);
    }

    ///cout<<xParvi<<" "<<yParvi<<endl<<xVtori<<" "<<yVtori;

    if((xSkakalec>= xParvi) && (xSkakalec <= xVtori) && (ySkakalec >= yParvi) && (ySkakalec <= yVtori)){
        cout<<0<<endl;
        return 0;
    }

    if((xSkakalec <= xParvi) && (xSkakalec <= xVtori) && (ySkakalec >= yParvi) && (ySkakalec <= yVtori)){
        cout<<abs(xParvi - xSkakalec)<<endl;
        return 0;
    }

    if((xSkakalec >= xParvi) && (xSkakalec <= xVtori) && (ySkakalec <= yParvi) && (ySkakalec <= yVtori)){
        cout<<abs(yParvi - ySkakalec)<<endl;
        return 0;
    }

    if((xSkakalec >= xParvi) && (xSkakalec >= xVtori) && (ySkakalec >= yParvi) && (ySkakalec <= yVtori)){
        cout<<abs(xSkakalec - xVtori)<<endl;
        return 0;
    }

    if((xSkakalec >= xParvi) && (xSkakalec <= xVtori) && (ySkakalec >= yParvi) && (ySkakalec >= yVtori)){
        cout<<abs(ySkakalec - yVtori)<<endl;
        return 0;
    }

    if((xSkakalec <= xParvi) && (xSkakalec <= xVtori) && (ySkakalec <= yParvi) && (ySkakalec <= yVtori)){
        long long parvaStrana = abs(xParvi - xSkakalec);
        long long vtoraStrana = abs(yParvi - ySkakalec);
        long double direktno = sqrt(parvaStrana*parvaStrana + vtoraStrana*vtoraStrana);
        long long nagore = ceil(direktno);
        cout<<nagore<<endl;
        return 0;
    }

    if((xSkakalec >= xParvi) && (xSkakalec >= xVtori) && (ySkakalec <= yParvi) && (ySkakalec <= yVtori)){
        long long parvaStrana = abs(xSkakalec - xVtori);
        long long vtoraStrana = abs(yParvi - ySkakalec);
        long double direktno = sqrt(parvaStrana*parvaStrana + vtoraStrana*vtoraStrana);
        long long otg = ceil(direktno);
        cout<<otg<<endl;
        return 0;
    }

    if((xSkakalec >= xParvi) && (xSkakalec >= xVtori) && (ySkakalec >= yParvi) && (ySkakalec >= yVtori)){
        long long parvaStrana = abs(xSkakalec - xVtori);
        long long vtoraStrana = abs(ySkakalec - yVtori);
        long double direktno = sqrt(parvaStrana*parvaStrana + vtoraStrana*vtoraStrana);
        long long nagore = ceil(direktno);
        cout<<nagore<<endl;
        return 0;
    }

    if((xSkakalec <= xParvi) && (xSkakalec <= xVtori) && (ySkakalec >= yParvi) && (ySkakalec >= yVtori)){
        long long parvaStrana = abs(xParvi - xSkakalec);
        long long vtoraStrana = abs(ySkakalec - yVtori);
        long double direktno = sqrt(parvaStrana*parvaStrana + vtoraStrana*vtoraStrana);
        long long nagore = ceil(direktno);
        cout<<nagore<<endl;
        return 0;
    }

    return 0;
}
