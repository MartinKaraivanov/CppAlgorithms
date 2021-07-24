#include<iostream>
//#include<vector>
#include<map>
using namespace std;

//vector<int> parvi;
//vector<int> vtoriVector;

struct Dannite {
    int chislo;
    int drugoChislo;
};


map<string, Dannite> m;

int main(){

    Dannite d = {555, 55};
    m["pet"] = d;

    d = {333, 33};
    m["tri"] = d;
    m["tri"].drugoChislo = 333333;

    d = {1234567890, 98765};
    m["nogo"] = d;


    for (auto a : m) {
        a.second.chislo++;
    }

    for (auto element : m) {
        cout << element.first << "     " << element.second.chislo << " " << element.second.drugoChislo << endl;
    }


    cout << endl;

    if (m.find("deset") == m.end()) {
        cout << "niama" << endl;
    }
    else{
        cout << m["deset"].chislo << " " << m["deset"].drugoChislo << endl;
    }


    return 0;
}
