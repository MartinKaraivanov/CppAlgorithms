#include <iostream>
#include <iomanip>
#include <vector>
#include "zapoznanstva_B1_Proleten_2022.cpp"

extern void initialize(int, int, int, int, std::vector < std::pair < int, int > >);
extern void connect(int, int, int);
extern bool question(int, int, int);

struct __Query
{
    int type;
    int x, y;
};

int __ID, __N, __M, __Q, __cnt;
std::vector < std::pair < int, int > > __friendships;
std::vector < __Query > __queries;

void read()
{
    int x, y;
    std::cin >> __ID;
    std::cin >> __N >> __M >> __Q;

    for (int i = 1 ; i <= __M ; ++i)
    {
        std::cin >> x >> y;
        __friendships.push_back({x, y});
    }

    char qtype;
    for (int i = 1 ; i <= __Q ; ++i)
    {
        std::cin >> qtype >> x >> y;
        __queries.push_back({(qtype == '?'), x, y});
        __cnt += (qtype == '?');
    }
}

void fastIO()
{
    std::ios_base :: sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main ()
{
    std::string res;
    fastIO();
    read();

    res.reserve(__cnt);
    double begTime = clock();
    initialize(__ID, __N, __M, __Q, __friendships);
    for (int i = 0 ; i < __Q ; ++i)
    {
        if (__queries[i].type == 0) connect(__ID, __queries[i].x, __queries[i].y);
        else
        {
            bool curr = question(__ID, __queries[i].x, __queries[i].y);
            if (curr) res += "YES\n";
            else res += "NO\n";
        }
    }

    double endTime = clock();
    std::cout << res;
    // std::cerr << "time: " << std::fixed << std::setprecision(5) << (endTime - begTime) / CLOCKS_PER_SEC << '\n';
    return 0;
}
