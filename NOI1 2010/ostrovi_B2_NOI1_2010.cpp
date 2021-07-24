#include<iostream>
#include<queue>
using namespace std;

struct Danni{
    int x;
    int y;
    int cvqt;
};

int maxY;
int maxX;

int kakvoImaTam[110][110];

int cvetche[110][110];
int broiCvetove = 1;

int main(){
    cin>>maxY>>maxX;

    for(int x = 0; x <= maxX + 1; x++){
        kakvoImaTam[x][0] = 1;
        kakvoImaTam[x][maxY + 1] = 1;
    }

    for(int y = 0; y <= maxY + 1; y++){
        kakvoImaTam[0][y] = 1;
        kakvoImaTam[maxX + 1][y] = 1;
    }

    for(int y = 1; y <= maxY; y++){
        for(int x = 1; x <= maxX; x++){
            cin>>kakvoImaTam[x][y];
        }
    }

    /*for(int y = 0; y <= maxY + 1; y++){
        for(int x = 0; x <= maxX + 1; x++){
            cout<<kakvoImaTam[x][y]<<" ";
        }
        cout<<endl;
    }

    for(int y = 0; y <= maxY + 1; y++){
        for(int x = 0; x <= maxX + 1; x++){
            cout<<cvetche[x][y]<<" ";
        }
        cout<<endl;
    }*/

    queue<Danni> q;

    for(int y = 0; y <= maxY + 1; y++){
        for(int x = 0; x <= maxX + 1; x++){

            if(cvetche[x][y] == 0 && kakvoImaTam[x][y] == 1){
                Danni nachalno = {x, y, broiCvetove};
                q.push(nachalno);

                //cout<<x<<" "<<y<<endl;

                while(q.empty() == false){
                    Danni naiOtpred = q.front();
                    q.pop();

                    int xche = naiOtpred.x;
                    int yche = naiOtpred.y;
                    int cvqtche = naiOtpred.cvqt;

                    if(cvetche[xche][yche] > 0){
                        continue;
                    }

                    //cout<<xche<<" "<<yche<<" "<<cvqtche<<endl;

                    cvetche[xche][yche] = cvqtche;

                    if(xche - 1 >= 0){
                        if(kakvoImaTam[xche - 1][yche] == 1 && cvetche[xche - 1][yche] == 0){
                            Danni zaDob = {xche - 1, yche, cvqtche};
                            q.push(zaDob);
                        }
                        if(yche + 1 <= maxY + 1 && kakvoImaTam[xche - 1][yche + 1] == 1 && cvetche[xche - 1][yche + 1] == 0){
                            Danni zaDob = {xche - 1, yche + 1, cvqtche};
                            q.push(zaDob);
                        }
                        if(yche - 1 >= 0 && kakvoImaTam[xche - 1][yche - 1] == 1 && cvetche[xche - 1][yche - 1] == 0){
                            Danni zaDob = {xche - 1, yche - 1, cvqtche};
                            q.push(zaDob);
                        }
                    }

                    if(xche + 1 <= maxX + 1){
                        if(kakvoImaTam[xche + 1][yche] == 1 && cvetche[xche + 1][yche] == 0){
                            Danni zaDob = {xche + 1, yche, cvqtche};
                            q.push(zaDob);
                        }
                        if(yche + 1 <= maxY + 1 && kakvoImaTam[xche + 1][yche + 1] == 1 && cvetche[xche + 1][yche + 1] == 0){
                            Danni zaDob = {xche + 1, yche + 1, cvqtche};
                            q.push(zaDob);
                        }
                        if(yche - 1 >= 0 && kakvoImaTam[xche + 1][yche - 1] == 1 && cvetche[xche + 1][yche - 1] == 0){
                            Danni zaDob = {xche + 1, yche - 1, cvqtche};
                            q.push(zaDob);
                        }
                    }

                    if(yche + 1 <= maxY + 1){
                        if(kakvoImaTam[xche][yche + 1] == 1 && cvetche[xche][yche + 1] == 0){
                            Danni zaDob = {xche, yche + 1, cvqtche};
                            q.push(zaDob);
                        }
                    }

                    if(yche - 1 >= 0){
                        if(kakvoImaTam[xche][yche - 1] == 1 && cvetche[xche][yche - 1] == 0){
                            Danni zaDob = {xche, yche - 1, cvqtche};
                            q.push(zaDob);
                        }
                    }

                }

                broiCvetove++;
            }
        }
    }

    /*for(int y = 0; y <= maxY + 1; y++){
        for(int x = 0; x <= maxX + 1; x++){
            cout<<cvetche[x][y]<<" ";
        }
        cout<<endl;
    }*/

    cout<<broiCvetove-2<<endl;

    return 0;
}
