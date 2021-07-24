#include "absent.h"
#define MAX_QUERIES 12000

#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "absent.cpp"

const int MAXN = 1024;

int _n, _m;
int _a[MAXN];
int _query_number = 0;

bool get_bit(int i, int j)
{
    _query_number++;
    printf("get_bit: %d %d\n", i, j);

    if (_query_number > MAX_QUERIES)
    {
        printf("Too many questions\n");
        exit(0);
    }
    if (i <= 0 or i > _n - 1 or j <= 0 or j > 10)
    {
        printf("Question is not valid\n");
        exit(0);
    }

    int ans = (_a[i] & (1 << (10 - j))) ? 1 : 0;
    return ans;
}

void submit_absent(int m)
{
    printf("submit_absent: %d\n", m);

    if (m != _m) printf("Incorrect number of absent student\n");
    else printf("Correct with total question used: %d\n", _query_number);

    exit(0);
}

int main()
{
    scanf("%d%d", &_n, &_m);

    printf("%d %d\n", _n , _m);
    for (int i = 1; i < _n; ++ i)
    {
        scanf("%d", &_a[i]);
    }

    play(_n);

    return 0;
}

