#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool poMalko(char a, char b){
    if(toupper(a)<toupper(b)){
        return true;
    }
    if(toupper(a)>toupper(b)){
        return false;
    }
    if(toupper(a)==toupper(b)){
        return a>b;
    }
}

int main(){
    char bukvi[1024];
    cin>>bukvi;
    long long dyljina;
    dyljina=strlen(bukvi);
    sort(bukvi,bukvi+dyljina,poMalko);
    cout<<bukvi;

    return 0;
}
