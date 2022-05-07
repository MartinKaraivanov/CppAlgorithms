#include "automation.h"
#include <iostream>
#include <stdio.h>
#include "avtomatizaciq_A3_Proleten_2019.cpp"
using namespace std;

struct query
{
    int cm;
    int l,r,k;
};



int inp_arr[2000011];
query queries[2000111];

int main()
{
    int i,j;
    int n,q;
    int subtask;

    scanf("%d",&subtask);
    scanf("%d %d",&n,&q);

    for (i=0;i<n;i++)
    {
        scanf("%d",&inp_arr[i]);
    }

    for (i=1;i<=q;i++)
    {
        int cm,l,r,k;

        scanf("%d %d %d",&queries[i].cm,&queries[i].l,&queries[i].r);

        if (queries[i].cm != 1)
        {
            scanf("%d",&queries[i].k);
        }
    }

    init(subtask, n, inp_arr);

    for (i=1;i<=q;i++)
    {
        if (queries[i].cm == 1)
            printf("%lld\n",getSum(queries[i].l, queries[i].r));
        else if (queries[i].cm == 2)
            setValues(queries[i].l, queries[i].r, queries[i].k);
        else
            divideValues(queries[i].l, queries[i].r, queries[i].k);
    }

    return 0;
}
