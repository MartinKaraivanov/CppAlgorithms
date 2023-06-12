#include <cstdio>
#include <cstring>
#include "wall.h"
#include "stena_A2_Zimen_2017.cpp"

long long get_wall_h(int L, int R);
void change_wall(int L, int R, int dh);
void init(int N);

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    init(n);
    for (int i = 0; i < k; ++i) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int L, R, dh;
            scanf("%d %d %d", &L, &R, &dh);
            change_wall(L, R, dh);
        } else if (type == 2) {
            int L, R;
            scanf("%d %d", &L, &R);
            printf("%lld\n", get_wall_h(L, R));
        }
    }
    return 0;
}
