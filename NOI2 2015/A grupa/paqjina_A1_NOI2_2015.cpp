#include<iostream>
#include<cmath>
using namespace std;

long long radius;
long long nePoDalgaOtKolko;
long long kolkoVarha;

const double pi = 3.14159265359;

double otGradusivradiani(double gradus){
    return (gradus*(pi/180));
}

double razstoqnieMejduDveTochki(long long prezKolkoSa){
    return (double)2*radius*sin(otGradusivradiani(((double)(prezKolkoSa + 1)/(double)(2*kolkoVarha))*360.0));
}

int main(){
    cin>>radius>>nePoDalgaOtKolko>>kolkoVarha;

    long long broiOshitiOtsechki = 0;

    /*long long doKade = (kolkoVarha - 1)/2;

    for(long long p = 0; p <= doKade; p++){
        //cout<<p<<endl;

        double razstoqnieto = razstoqnieMejduDveTochki(p);

        if(razstoqnieto > nePoDalgaOtKolko){
            break;
        }

        broiOshitiOtsechki += kolkoVarha;

        if(kolkoVarha % 2 == 0 && p == doKade){
            broiOshitiOtsechki -= kolkoVarha/2;
        }
    }*/

    long long lqvKrai = 0;
    long long desenKrai = kolkoVarha/2;

    while(lqvKrai < desenKrai){
        long long poSredata = (lqvKrai + desenKrai)/2;

        if(razstoqnieMejduDveTochki(poSredata) > nePoDalgaOtKolko){
            desenKrai = poSredata;
        }else{
            lqvKrai = poSredata + 1;
        }
    }

    broiOshitiOtsechki = lqvKrai*kolkoVarha;

    if(kolkoVarha % 2 == 0 && !(razstoqnieMejduDveTochki((kolkoVarha-1)/2) > nePoDalgaOtKolko)){
        broiOshitiOtsechki -= kolkoVarha/2;
    }

    cout<<broiOshitiOtsechki<<endl;

    return 0;
}
