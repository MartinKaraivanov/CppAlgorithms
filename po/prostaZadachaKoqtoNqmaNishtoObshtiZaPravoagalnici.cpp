#include<iostream>
using namespace std;
int main(){
    int xGorenLqvPrazen;
    int yGorenLqVPrazen;
    int xDolenDesenPrazen;
    int yDolenDesenPrazen;
    int xGorenLqvPalen;
    int yGorenLqvPalen;
    int xDolenDesenPalen;
    int yDolenDesenPalen;

    cin>>xGorenLqvPrazen>>yGorenLqVPrazen>>xDolenDesenPrazen>>yDolenDesenPrazen>>xGorenLqvPalen>>yGorenLqvPalen>>xDolenDesenPalen;
    cin>>yDolenDesenPalen;

    if((xGorenLqvPalen<=xGorenLqvPrazen) && (yGorenLqvPalen<=yGorenLqVPrazen) &&
        (xDolenDesenPalen>=xDolenDesenPrazen) && (yDolenDesenPalen>=yDolenDesenPrazen))
    {
        cout<<0<<endl;
        return 0;
    }

    if(((xGorenLqvPalen>=xGorenLqvPrazen) && (xGorenLqvPalen<xDolenDesenPrazen) &&
        (yGorenLqvPalen>=yGorenLqVPrazen) && (yGorenLqvPalen<yDolenDesenPrazen)) ||

       ((xDolenDesenPalen>=xGorenLqvPrazen) && (xDolenDesenPalen<xDolenDesenPrazen) &&
        (yGorenLqvPalen>=yGorenLqVPrazen) && (yGorenLqvPalen<yDolenDesenPrazen))  ||

       ((xGorenLqvPalen>=xGorenLqvPrazen) && (xGorenLqvPalen<xDolenDesenPrazen) &&
        (yDolenDesenPalen>=yGorenLqVPrazen) && (yDolenDesenPalen<yDolenDesenPrazen))  ||

       ((xDolenDesenPalen>=xGorenLqvPrazen) && (xDolenDesenPalen<xDolenDesenPrazen) &&
        (yDolenDesenPalen>=yGorenLqVPrazen) && (yDolenDesenPalen<yDolenDesenPrazen)) )
    {
        if(yGorenLqvPalen>yGorenLqVPrazen){
            cout<<xGorenLqvPrazen<<" "<<yGorenLqVPrazen<<" "<<xDolenDesenPrazen<<" "<<yGorenLqvPalen-1<<endl;
        }
        if(yDolenDesenPalen<yDolenDesenPrazen){
            cout<<xGorenLqvPrazen<<" "<<yDolenDesenPalen+1<<" "<<xDolenDesenPrazen<<" "<<yDolenDesenPrazen<<endl;
        }
        if(xGorenLqvPalen>xGorenLqvPrazen){
            cout<<xGorenLqvPrazen<<" "<<yGorenLqVPrazen<<" "<<xGorenLqvPalen-1<<" "<<yDolenDesenPrazen<<endl;
        }
        if(xDolenDesenPalen<xDolenDesenPrazen){
            cout<<xDolenDesenPalen+1<<" "<<yGorenLqVPrazen<<" "<<xDolenDesenPrazen<<" "<<yDolenDesenPrazen<<endl;
        }
    }else{
        cout<<xGorenLqvPrazen<<" "<<yGorenLqVPrazen<<" "<<xDolenDesenPrazen<<" "<<yDolenDesenPrazen<<endl;
    }

    return 0;
}
