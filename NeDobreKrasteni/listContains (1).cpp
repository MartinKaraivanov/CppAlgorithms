#include <iostream>
using namespace std;
int main(){
long long vuvedeni[10],iskano,i,n;
cout<<"vuvedi 10 chisla";
cout<<endl;
for(i=0;i<10;i++){
    cin>>vuvedeni[i];
}
cout<<"ko shtesh ue?";
cout<<endl;
cin>>iskano;
for(i=0;i<10;i++){
    if(vuvedeni[i]==iskano){
        cout<<"ima go!";
        return 0;
    }
}
if(vuvedeni[i]!=iskano){
    cout<<"nema go";
}

return 0;
}
