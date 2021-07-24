#include<iostream>
#include<algorithm>
using namespace std;

int abs(int x){
    if(x<0){
        return -x;
    }else{
        return x;
    }

}

bool poMalko(int a, int b){
    return a<b;
}

int main(){
    int broiChisla;
    cin>>broiChisla;
    int chisla[broiChisla];
    for(int i=0;i<broiChisla;i++){
        cin>>chisla[i];
    }

    sort(chisla,chisla+broiChisla,poMalko);

    /*
    int naiGolqmaRazlika=0;
    for(int i=1;i<broiChisla;i++){
        if (chisla[i]!=chisla[i-1]){
            int razlika = chisla[i]-chisla[i-1];
            if (razlika > naiGolqmaRazlika){
                naiGolqmaRazlika = razlika;
            }
        }
    }
    */

    int naiGolqmaRazlika=0;
    for(int i=0;i<broiChisla;i++){
        int nasheto = chisla[i];

        int naiMalkaRazlikaOtNasheto=1000000;
        for(int j=i+1;j<broiChisla;j++){
            if(chisla[j]>nasheto){
                int razlika = chisla[j]-nasheto;
                if(razlika<naiMalkaRazlikaOtNasheto){
                    naiMalkaRazlikaOtNasheto=razlika;
                }
                break;
            }
        }

        if((naiMalkaRazlikaOtNasheto>naiGolqmaRazlika) && (naiMalkaRazlikaOtNasheto!=1000000)){
            naiGolqmaRazlika=naiMalkaRazlikaOtNasheto;
        }
    }

    cout<<naiGolqmaRazlika;
    cout<<endl;

    return 0;
}
