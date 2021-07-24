#include<iostream>
#include<cmath>
using namespace std;

long long koeChislo;

int main(){
    cin>>koeChislo;

    long long broiPredstavqniq = 1;

    long long doKadeVartim = sqrt(koeChislo) + 500000;

    for(long long n = 2; n <= doKadeVartim; n++){
        long long a = (koeChislo - ((n - 1)*n)/2)/n;

        //cout<<n<<" "<<a<<endl;

        if(a > 0 && ((a + a + n - 1)*n)/2 == koeChislo){
            broiPredstavqniq++;
            //cout<<n<<endl;
        }
    }

    cout<<broiPredstavqniq<<endl;

    return 0;
}
