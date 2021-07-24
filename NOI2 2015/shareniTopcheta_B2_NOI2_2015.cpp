#include<iostream>
#include<map>
using namespace std;

int broiTopcheta;
int broiDvoiki;

map<int, int> otKoiSa;
bool cvqtKoitoImame[1000000];

int main(){
    cin>>broiTopcheta>>broiDvoiki;

    int nomerche = 1;

    for(int i = 0; i < broiDvoiki; i++){
        int parvo;
        int vtoro;
        cin>>parvo>>vtoro;

        int cvqtNaNomerEno = otKoiSa[parvo];
        int cvqtNaNomerDve = otKoiSa[vtoro];

        if(cvqtNaNomerEno > 0 && cvqtNaNomerEno == cvqtNaNomerDve){
            continue;
        }
        if(cvqtNaNomerEno > 0 && cvqtNaNomerDve > 0 && cvqtNaNomerEno != cvqtNaNomerDve){
            for(map<int, int>::iterator el = otKoiSa.begin(); el != otKoiSa.end(); el++){
                if(el->second == cvqtNaNomerDve){
                    el->second = cvqtNaNomerEno;
                }
            }
            continue;
        }
        if(cvqtNaNomerEno > 0 && cvqtNaNomerDve == 0){
            otKoiSa[vtoro] = cvqtNaNomerEno;
            continue;
        }
        if(cvqtNaNomerDve > 0 && cvqtNaNomerEno == 0){
            otKoiSa[parvo] = cvqtNaNomerDve;
            continue;
        }
        if(cvqtNaNomerEno == 0 && cvqtNaNomerDve == 0){
            otKoiSa[parvo] = nomerche;
            otKoiSa[vtoro] = nomerche;
            nomerche++;
        }
    }

    int brTopkiKoitoSaOcveteniVezhe = 0;
    int razlichniIzpolzvaniCvetove = 0;

    for(map<int, int>::iterator el = otKoiSa.begin(); el != otKoiSa.end(); el++){
        if(el->second > 0){
            //cout<<i<<" "<<otKoiSa[i]<<endl;
            if(cvqtKoitoImame[el->second] == false){
                razlichniIzpolzvaniCvetove++;
                cvqtKoitoImame[el->second] = true;
            }
            brTopkiKoitoSaOcveteniVezhe++;
        }
    }

    //cout<<brTopkiKoitoSaOcveteniVezhe<<" "<<razlichniIzpolzvaniCvetove<<endl;

    int broiNuzhniCvetove = broiTopcheta - brTopkiKoitoSaOcveteniVezhe + razlichniIzpolzvaniCvetove;

    cout<<broiNuzhniCvetove<<endl;

    return 0;
}
