#include <iostream>
using namespace std;


int PoDve(int x)
{
    return x * 2;
}
/*
int Faktoriel(int x)
{
    if (x<=1) {
        return 1;
    }
    else {
        return x*Faktoriel(x-1);
    }
}
*/
int Faktoriel(int x)
{
    int result = 1;
    for(int i=1; i<=x; i++){
        result = result*i;
    }

    return result;
}

void PrintResult(int res)
{
    cout << "Rezultata e: " << res;
}

int main()
{

    int a, b;
    cin >> a >> b;

    /*int y = PoDve(a);
    cout << y;*/
    PrintResult(Faktoriel(a)*Faktoriel(b));


    //long long a,b,c;
    char kakvoEVavedeno,a,b,c;
    cin>>a;
    if (a == 'x')
    {
        cout << " + ";
        cin >> b;
        cout << " = ";
        cin >> c;
    }
    else
    {
        cout<<" + ";
    }
    cin>>b;
    if(b=='x'){
        cout<<" = ";
        cin>>c;
    }else{
        cout<<" = ";
    }
    cin>>c;
    if(c=='x'){
        c=a+b;
        cout<<c;
    }
    if(a=='x'){
        a=c-b;
        cout<<a;
    }
    if(b=='x'){
        b=c-a;
        cout<<b;
    }


    return 0;
}
