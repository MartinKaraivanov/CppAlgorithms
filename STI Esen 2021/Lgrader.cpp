#include <iostream>
#include <cassert>
#include <vector>
#include <iomanip>
//#include "cut.cpp"
#include "razreji_A1_STI_Esen_2021.cpp"

const int __maxn = 1e6 + 10;
int __n, __k;
std::vector < int > __h;

void fast_io() {

    std::ios_base :: sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cerr.tie(nullptr);

}

void validate() {

    assert((1 <= __k) && (__k <= __n) && (__n <= 1000000));

    for (int i = 0 ; i < __n ; ++i)
        assert((1 <= __h[i]) && (__h[i] <= 1000000000));

}

void read() {

    std::cin >> __n >> __k;
    __h.resize(__n);

    for (int i = 0 ; i < __n ; ++i)
        std::cin >> __h[i];

}

extern long long init (std::vector < int > , int );

int main () {

    // fast_io();
    read();
    validate();

    double __beg_time = clock();

    long long res = init(__h, __k);

    double __end_time = clock();

    std::cout << res << '\n';
    std::cerr << fixed << setprecision(6) << "contestant time: " << (__end_time - __beg_time) / CLOCKS_PER_SEC << '\n';

    return 0;

}
