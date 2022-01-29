#include "hint.h"
#include<vector>
using namespace std;

vector<bool> genHint(const vector<int>& a, const vector<int>& b, const vector<int>& sol){

    vector<bool> podskazkata;

    if(a.size() < b.size()){
        int indexA = 0;
        int indexSol = 0;

        while(indexA < (int)a.size()){
            if(a[indexA] == sol[indexSol]){
                podskazkata.push_back(true);
                indexSol++;
            }else{
                podskazkata.push_back(false);
            }
            indexA++;
        }

    }else{
        int indexB = 0;
        int indexSol = 0;

        while(indexB < (int)a.size()){
            if(b[indexB] == sol[indexSol]){
                podskazkata.push_back(true);
                indexSol++;
            }else{
                podskazkata.push_back(false);
            }
            indexB++;
        }

    }

    return podskazkata;
}


vector<int> solve(const vector<int>& a, const vector<int>& b, const vector<bool>& hint){

    vector<int> reshenieto;

    if(a.size() < b.size()){

        for(int i = 0; i < (int)a.size(); i++){
            if(hint[i] == true){
                reshenieto.push_back(a[i]);
            }
        }

    }else{

        for(int i = 0; i < (int)b.size(); i++){
            if(hint[i] == true){
                reshenieto.push_back(b[i]);
            }
        }

    }

    return reshenieto;
}
