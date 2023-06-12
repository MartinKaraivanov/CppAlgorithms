#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int stranaKvadrat;

int broiTochki;

struct Koordinati{
    int x;
    int y;
};

Koordinati tochki[1000010];

bool koqEPoNapred(Koordinati a, Koordinati b){
    if(a.x < b.x){
        return true;
    }
    if(a.x > b.x){
        return false;
    }
    return a.y < b.y;
}

int minYNachalo[1000010];
int maxYNachalo[1000010];

int minYKrai[1000010];
int maxYKrai[1000010];

int main(){

    //cin>>stranaKvadrat>>broiTochki;

    scanf("%i %i", &stranaKvadrat, &broiTochki);

    for(int i = 1; i <= broiTochki; i++){
        //cin>>tochki[i].x>>tochki[i].y;
        scanf("%i %i", &tochki[i].x, &tochki[i].y);
    }

    sort(tochki + 1, tochki + broiTochki + 1, koqEPoNapred);

    minYNachalo[0] = stranaKvadrat;
    for(int i = 1; i <= broiTochki; i++){
        minYNachalo[i] = min(minYNachalo[i - 1], tochki[i].y);
        maxYNachalo[i] = max(maxYNachalo[i - 1], tochki[i].y);
    }

    minYKrai[broiTochki + 1] = stranaKvadrat;
    for(int i = broiTochki; i >= 1; i--){
        minYKrai[i] = min(minYKrai[i + 1], tochki[i].y);
        maxYKrai[i] = max(maxYKrai[i + 1], tochki[i].y);
    }

    int lqvKrai = -1;
    int desenKrai = stranaKvadrat;
    int x;
    int y;

    while(lqvKrai + 1 < desenKrai)
	{
		int sredata = (desenKrai + lqvKrai)/2;
		bool stavaLi = false;

		int j = 1;

		for(int i = 1; i <= broiTochki; i++){
			while(j <= broiTochki){
                if(tochki[j].x - tochki[i].x > 2*sredata || stavaLi == true){
                    break;
                }
                j++;
			}

			int minY = min(minYNachalo[i-1], minYKrai[j]);
			int maxY = max(maxYNachalo[i-1], maxYKrai[j]);

			if(maxY - minY <= 2 * sredata)
			{
				stavaLi = true;
				x = min(tochki[i].x + sredata, stranaKvadrat);
				y = min(minY + sredata, stranaKvadrat);
				break;
			}
		}

		if(stavaLi == true){
			desenKrai = sredata;
		}else{
			lqvKrai = sredata;
		}
	}

    //cout<<desenKrai<<" "<<x<<" "<<y<<endl;
    printf("%i %i %i \n", desenKrai, x, y);

    return 0;
}

