#include "absent.h"

#include <cstdio>
#include <cstdlib>
#include <cassert>

bool get_bit(int i, int j)
{
    if (i == 0)
    {
        printf("1\n0\n");
		fflush(stdout);
        exit(0);
    }

    printf("%d %d\n", i, j);
    fflush(stdout);

    int res, ret;
    ret = scanf("%d", &res);
    if (ret != 1) exit(0);
    else return res;
}

void submit_absent(int m)
{
    printf("0 %d\n", m);
    fflush(stdout);
    fclose(stdout);
    exit(0);
}

int main(int argc, char ** argv)
{
    freopen(argv[2], "r", stdin);
    freopen(argv[1], "w", stdout);

    int n;
    assert(scanf("%d", &n) == 1);
    play(n);

    return 0;
}

