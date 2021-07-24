#include <iostream>
#include <math.h>
using namespace std;

int zgavaniyq(int x){
     int result = 0;
     while(x>1){
        x = x/2 + x%2;
        result++;
    }
    return result;
}

int main (){
    int m,n,zgavane;
    cin>>m>>n;
    zgavane = zgavaniyq(m) + zgavaniyq(n);
    //zgavane = ceil(log2(m)) + ceil(log2(n));
    cout<<zgavane;

return 0;
}
