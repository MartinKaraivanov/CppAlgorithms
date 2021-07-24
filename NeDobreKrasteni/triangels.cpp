#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int p;
    cin>>p;

    int a;
    int b;
    int c;

    int broiVazmozhniTriagalnici=0;


    for(int i=1;i<p-2;i++){
        for(int j=1;j<p-2;j++){
            a=i;
            b=j;
            c=p-(a+b);
            if( (a+b>c) && (b+c>a) && (a+c>b) && (a+b+c==p) ){
                broiVazmozhniTriagalnici++;
            }
        }
    }

    cout<<broiVazmozhniTriagalnici/3<<endl;


    return 0;
}
