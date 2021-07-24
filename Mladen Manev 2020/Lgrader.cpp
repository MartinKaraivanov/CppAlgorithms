#include "house.h"
#include "house.cpp"
#define MAX_QUERIES 20

#include <cstdio>
#include <cstdlib>
#include <cassert>

const int MAXN = 200005;

int _t, _n, _a[MAXN];
std::vector<int> _g[MAXN];
int _cnt = 0;

int get_neighbour(int v)
{
    _cnt++;
    printf("get_neighbour: %d\n", v);

    if (_cnt > MAX_QUERIES)
    {
        printf("Questions limit exceeded");
        exit(0);
    }
    if (v < 1 or v > _n)
    {
        printf("Invalid question\n");
        exit(0);
    }

    int ans = -1;
    for (int i = 0; i < _g[v].size(); ++ i)
    {
        if (_a[_g[v][i]] > _a[v])
        {
            ans = _g[v][i];
            break;
        }
    }

    printf("answer: %d\n", ans);
    return ans;
}

void submit_house(int h)
{
    printf("submit_house: %d\n", h);
    if (h < 1 or h > _n)
    {
        printf("Incorrect answer\n");
        exit(0);
    }
    for (int i = 0; i < _g[h].size(); ++ i)
    {
        if (_a[_g[h][i]] > _a[h])
        {
            printf("Incorrect answer\n");
            exit(0);
        }
    }

    printf("Correct answer\n");
    printf("Questions used: %d\n", _cnt);
}

int main()
{
    scanf("%d", &_t);
    for (int i = 1; i <= _t; ++ i)
    {
        scanf("%d", &_n);
        for (int i = 1; i <= _n; ++ i)
        {
            scanf("%d", &_a[i]);
        }

        std::vector<std::pair<int, int>> e;
        for (int j = 1; j < _n; ++ j)
        {
            int u, v;
            assert(scanf("%d%d", &u, &v) == 2);
            e.emplace_back(u, v);
            _g[u].push_back(v);
            _g[v].push_back(u);
        }

        _cnt = 0;
        play(_n, e);

        for (int i = 1; i <= _n; ++ i)
        {
            _g[i].clear();
        }
    }

    return 0;
}
