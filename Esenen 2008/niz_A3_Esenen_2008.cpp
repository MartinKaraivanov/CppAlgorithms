#include<iostream>
using namespace std;

string niz;

int daljiniDumi[1000010];
int broiDumi;

int main(){

    cin>>niz;

    int indexNiz = 0;

    while(indexNiz < (int)niz.size()){
        int indexBukva = indexNiz + 1;
        int indexSravnenie = indexNiz;

        while(indexBukva < (int)niz.size() && niz[indexSravnenie] <= niz[indexBukva]){
            if(niz[indexSravnenie] < niz[indexBukva]){
                indexSravnenie = indexNiz;
            }else{
                indexSravnenie++;
            }

            indexBukva++;
        }

        while(indexNiz <= indexSravnenie){
            indexNiz += indexBukva - indexSravnenie;

            daljiniDumi[broiDumi] = indexBukva - indexSravnenie;
            broiDumi++;
        }
    }

    cout<<broiDumi<<" ";
    for(int i = 0; i < broiDumi; i++){
        cout<<daljiniDumi[i]<<" ";
    }
    cout<<endl;


    return 0;
}
