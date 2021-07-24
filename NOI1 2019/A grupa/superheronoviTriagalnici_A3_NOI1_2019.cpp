#include<iostream>
#include<cmath>
using namespace std;

double obikolka;

int main(){
    cin>>obikolka;

    if((int)obikolka % 2 == 1){
        cout<<0<<endl;
        return 0;
    }

    int broi = 0;

    for(double a = 2; a <= obikolka/3; a+=2){
        for(double b = a; b <= 2*(obikolka/3) - a; b+=2){
            double c = obikolka - (a + b);
            //cout<<a<<" "<<b<<" "<<c<<endl;

            if(a - c > 0.0000001 || b - c > 0.0000001){
                //cout<<"ne sa strani"<<endl<<endl;
                continue;
            }

            if(c - (a + b) > -0.0000001){
                //cout<<"ne sa strani na triagalnik "<<endl<<endl;
                continue;
            }

            double p = obikolka/2;

            double lice = sqrt((p)*(p - a)*(p - b)*(p - c));

            if(ceil(lice) - lice > 0.0000001){
                //cout<<"lliceto ne e cqlo chislo "<<endl<<endl;
                continue;
            }

            double radiusVpisana = lice/p;

            if(ceil(radiusVpisana) - radiusVpisana > 0.0000001){
                //cout<<"r ne e cqlo chislo "<<endl<<endl;
                continue;
            }

            double radiusOpisana = (a*b*c)/(4*lice);

            if(ceil(radiusOpisana) - radiusOpisana > 0.0000001){
                //cout<<"R ne e cqlo chislo "<<endl<<endl;
                continue;
            }

            broi++;
            //cout<<"TOVA E OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOK"<<endl<<endl;
        }
    }

    cout<<broi<<endl;

    return 0;
}
