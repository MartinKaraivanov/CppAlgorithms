#include<iostream>
#include<stack>
using namespace std;

int maxY;
int maxX;

int tablica[1010][1010];

int visochinaNaHistV[1010][1010];

int broiZaqvki;

int kolkoEVisochinata(int y, int x, int gorenRed){
    return min(visochinaNaHistV[y][x], y - gorenRed + 1);
}

int maximalnoLiceVHistogramaNa(int red, int gorenRed){

    stack<int> s;

    int maximalnoLice = 0;

    for(int i = 0; i < maxX; i++){

        while(s.empty() == false){
            if(kolkoEVisochinata(red, i, gorenRed) >= kolkoEVisochinata(red, s.top(), gorenRed)){
                break;
            }else{
                int naiOtgore = kolkoEVisochinata(red, s.top(), gorenRed);
                s.pop();

                int tukaLice = 0;

                if(s.empty() == true){
                    tukaLice = i*naiOtgore;
                }else{
                    tukaLice = (i - s.top() - 1)*naiOtgore;
                }

                maximalnoLice = max(tukaLice, maximalnoLice);
            }
        }

        s.push(i);
    }

    while(s.empty() == false){
        int naiOtgore = kolkoEVisochinata(red, s.top(), gorenRed);
        s.pop();

        int tukaLice = 0;

        if(s.empty() == true){
            tukaLice = maxX*naiOtgore;
        }else{
            tukaLice = (maxX - s.top() - 1)*naiOtgore;
        }

        maximalnoLice = max(tukaLice, maximalnoLice);
    }

    return maximalnoLice;
}

int naiGolqmPravoagalnik(int gorenRed, int dolenRed){

    int otgovor = 0;

    for(int y = gorenRed; y <= dolenRed; y++){
        int naToziRed = maximalnoLiceVHistogramaNa(y, gorenRed);

        otgovor = max(otgovor, naToziRed);
    }

    return otgovor;
}

void nameriHistogramite(){
    for(int i = 0; i <= maxY; i++){
        for(int j = 0; j <= maxX; j++){
            visochinaNaHistV[i][j] = 0;
        }
    }

    for(int x = 0; x < maxX; x++){
        visochinaNaHistV[0][x] = tablica[0][x];
    }
    for(int y = 1; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            if(tablica[y][x] == 1){
                visochinaNaHistV[y][x] = tablica[y][x] + visochinaNaHistV[y - 1][x];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>maxY>>maxX;

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            cin>>tablica[y][x];
            if(tablica[y][x] == 0){
                tablica[y][x] = 1;
            }else{
                tablica[y][x] = 0;
            }
        }
    }

    nameriHistogramite();

    cin>>broiZaqvki;

    for(int i = 0; i < broiZaqvki; i++){
        int gorenRed;
        int dolenRed;
        cin>>gorenRed>>dolenRed;

        gorenRed--;
        dolenRed--;

        int otgTuka = naiGolqmPravoagalnik(gorenRed, dolenRed);

        cout<<otgTuka<<endl;
    }

    return 0;
}
