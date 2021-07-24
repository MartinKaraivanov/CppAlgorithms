#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a;
    int b;
    int c;
    int d;

    cin>>a>>b>>c>>d;

    int razliki[12];

    razliki[0]=abs((10*a+b)-(10*c+d));
    razliki[1]=abs((10*a+b)-(10*d+c));
    razliki[2]=abs((10*b+a)-(10*c+d));
    razliki[3]=abs((10*b+a)-(10*d+c));
    razliki[4]=abs((10*a+c)-(10*b+d));
    razliki[5]=abs((10*a+c)-(10*d+b));
    razliki[6]=abs((10*c+a)-(10*b+d));
    razliki[7]=abs((10*c+a)-(10*d+b));
    razliki[8]=abs((10*a+d)-(10*b+c));
    razliki[9]=abs((10*a+d)-(10*c+b));
    razliki[10]=abs((10*d+a)-(10*b+c));
    razliki[11]=abs((10*d+a)-(10*c+b));

    int naiMalkaRazlika=100;

    for(int i=0;i<12;i++){
        if(razliki[i]<naiMalkaRazlika){
            naiMalkaRazlika=razliki[i];
        }
    }

    cout<<naiMalkaRazlika<<endl;

    return 0;
}
