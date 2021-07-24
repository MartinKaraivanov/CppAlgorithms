#include<iostream>
#include<queue>
using namespace std;
int main (){
	long long N;
	cin >> N;
	long long chasNaIdvane[N];
	long long mPrestoi[N];
	long long horaKasa1 = 0, horaKasa2 = 0;
	for(long long i = 0; i < N; i++) {
    	cin >> chasNaIdvane[i] >> mPrestoi[i];
	}
	queue<long long> mTrugvaneKasa1, mTrugvaneKasa2;
	for(long long i = 0; i < N; i++) {
    	if(mTrugvaneKasa1.front() <= chasNaIdvane[i]) {
        	mTrugvaneKasa1.pop();
        	horaKasa1++;
    	}
    	if(mTrugvaneKasa2.front() <= chasNaIdvane[i]) {
        	mTrugvaneKasa2.pop();
        	horaKasa2++;
    	}
    	if(mTrugvaneKasa1.empty()) {
        	mTrugvaneKasa1.push(chasNaIdvane[i] + mPrestoi[i]);
    	} else {
        	if(mTrugvaneKasa2.empty()) {
            	mTrugvaneKasa2.push(chasNaIdvane[i] + mPrestoi[i]);
        	} else {
            	if(mTrugvaneKasa2.size() < mTrugvaneKasa1.size()) {
			mTrugvaneKasa2.push(chasNaIdvane[i]+ mPrestoi[i]);
            	} else {
                	mTrugvaneKasa1.push(chasNaIdvane[i] + mPrestoi[i]);
            	}
        	}
    	}
	}
	if(horaKasa1 + mTrugvaneKasa1.size() > horaKasa2 + mTrugvaneKasa2.size()) {
    	cout << horaKasa1 + mTrugvaneKasa1.size();
	} else {
    	cout << horaKasa2 + mTrugvaneKasa2.size();
	}
}
