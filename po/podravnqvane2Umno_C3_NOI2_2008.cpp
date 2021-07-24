#include<iostream>
using namespace std;

int broiRedove;

int kolkoDumiImaTuka(string redove){
    int brDm=0;
    bool vDumaLiSum=false;

    for(int i=0;i<redove.size();i++){
        if((redove[i]!=' ') && (vDumaLiSum==false)){
            vDumaLiSum=true;
        }
        if((redove[i]==' ') && (vDumaLiSum==true)){
            vDumaLiSum=false;
            brDm++;
        }
    }
    if(redove[redove.size()-1]!=' '){
        return brDm+1;
    }else{
        return brDm;
    }
}

int kolkoNeIntervaliImaTuka(string redove){
    int brNeInt=0;
    for(int i=0;i<redove.size();i++){
        if(redove[i]!=' '){
            brNeInt++;
        }
    }
    return brNeInt;
}

void pravene(string redove, int nomerNaRed){
    int broiNeIntervali=kolkoNeIntervaliImaTuka(redove);
    int broiDumi=kolkoDumiImaTuka(redove);
    bool vDumaLiSum=false;

    int broiNuzhniIntervali;
    if(nomerNaRed<broiRedove-1){
        broiNuzhniIntervali=60-broiNeIntervali;
    }else{
        broiNuzhniIntervali=broiDumi-1;
    }
    int broiMestaZaPostavqne=broiDumi-1;
    bool daSeMahamLi=false;
    int otKade;

    //cout<<broiDumi<<" "<<broiNeIntervali<<" "<<broiNuzhniIntervali<<" "<<broiMestaZaPostavqne<<endl;

    for(int i=0;daSeMahamLi==false;i++){
        if((redove[i]!=' ') && (vDumaLiSum==false)){
            vDumaLiSum=true;
        }
        if(redove[i]!=' '){
            cout<<redove[i];
        }
        if((redove[i]==' ') && (vDumaLiSum==true)){
            vDumaLiSum=false;
            if(broiNuzhniIntervali%broiMestaZaPostavqne==0){
                for(int j=0;j<broiNuzhniIntervali/broiMestaZaPostavqne;j++){
                    cout<<" ";
                }
                broiNuzhniIntervali=broiNuzhniIntervali-(broiNuzhniIntervali/broiMestaZaPostavqne);
                broiMestaZaPostavqne--;
            }else{
                for(int j=0;j<=broiNuzhniIntervali/broiMestaZaPostavqne;j++){
                    cout<<" ";
                }
                broiNuzhniIntervali=broiNuzhniIntervali-((broiNuzhniIntervali/broiMestaZaPostavqne)+1);
                broiMestaZaPostavqne--;
            }
        }
        if(broiMestaZaPostavqne==0){
            daSeMahamLi=true;
            otKade=i;
        }
    }
    for(int i=otKade;i<redove.size();i++){
        if(redove[i]!=' '){
            cout<<redove[i];
        }
    }
    cout<<endl;
}

int main(){
    cin>>broiRedove;

    string zaUnishtozhavane;
    getline(cin, zaUnishtozhavane);

    for(int red=0;red<broiRedove;red++){
        string redove;
        getline(cin, redove);

        pravene(redove, red);
    }

    return 0;
}
