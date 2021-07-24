#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX = 256;

int price[MAX], n;
int dyn[MAX][MAX][MAX], nxt[MAX][MAX][MAX];

int recurse(int year, int left, int right) {
    if (left > right) return 0;

    if (dyn[year][left][right] != -1)
        return dyn[year][left][right];

    int winLeft = recurse(year + 1, left + 1, right) + year * price[left];

    int winRight = recurse(year + 1, left, right - 1) + year * price[right];


    nxt[year][left][right] = (winLeft < winRight) ? 1 : 0;
    return dyn[year][left][right] = std::max(winLeft, winRight);
}

int main(void) {
    fscanf(stdin, "%d", &n);
    for (int i = 0; i < n; i++)
        fscanf(stdin, "%d", &price[i]);

    memset(dyn, -1, sizeof(dyn));
    int ans = recurse(1, 0, n - 1);

    fprintf(stdout, "%d\n", ans);
    int year = 1, left = 0, right = n - 1;
    while (left <= right) {
        if (nxt[year][left][right] == 0)
            year++, left++, fprintf(stdout, "left");
        else
            year++, right--, fprintf(stdout, "right");
        fprintf(stdout, "%c", left <= right ? ' ' : '\n');
    }
    return 0;
}

/*#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX = 256;

int price[MAX], n;
int dyn[MAX][MAX][MAX];

int recurse(int year, int left, int right) {
    if (left > right) return 0;

    if (dyn[year][left][right] != -1)
        return dyn[year][left][right];

    int winLeft = recurse(year + 1, left + 1, right) + year * price[left];

    int winRight = recurse(year + 1, left, right - 1) + year * price[right];


    return dyn[year][left][right] = max(winLeft, winRight);
}

int main(){

    for(int a=0;a<MAX;a++){
        for(int b=0;b<MAX;b++){
            for(int c=0;c<MAX;c++){
                dyn[a][b][c]=-1;
            }
        }
    }

    int broiButilki;
    cin>>broiButilki;

    int parvonachalnaCena[broiButilki];
    for(int i=0;i<broiButilki;i++){
        cin>>parvonachalnaCena[i];
    }

    return 0;
}*/

