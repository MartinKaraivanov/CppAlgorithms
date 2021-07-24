#define MAX_QUERIES_100 3000
#define MAX_QUERIES_20 12000

#include <cstdio>
#include <csignal>

const int MAXN = 1024;

int n, m;
int a[MAXN];

int main(int argc, char ** argv)
{
    signal(SIGPIPE, SIG_IGN);

    FILE  *fifo_to_user, *fifo_from_user;

	fifo_to_user = fopen(argv[1], "w");
	fifo_from_user = fopen(argv[2], "r");

    freopen("input.txt", "r", stdin);

    scanf("%d%d", &n, &m);
    fprintf(fifo_to_user, "%d\n", n);
    fflush(fifo_to_user);

    for (int i = 1; i < n; ++ i)
    {
        scanf("%d", &a[i]);
    }

    int cnt = 0;
    while (true)
    {
        int ret, i, j;
        ret = fscanf(fifo_from_user, "%d%d", &i, &j);

        if (ret != 2)
        {
            printf("0\n");
            fprintf(stderr, "Contestant did not submit answer");
            return 0;
        }

        if (i == 0)
        {
            if (m != j)
            {
                printf("0\n");
                fprintf(stderr, "Incorrect number of absent student");
                return 0;
            }

            if (cnt <= MAX_QUERIES_100)
			{
				printf("1.0\n");
				fprintf(stderr, "Correct with fewer than 3000 questions");
			}
			if (cnt > MAX_QUERIES_100)
			{
				printf("0.2\n");
				fprintf(stderr, "Correct with more than 3000 questions");
			}

            return 0;
        }

        if (cnt == MAX_QUERIES_20)
        {
            printf("0.0\n");
            fprintf(stderr, "Too many questions");
            return 0;
        }
        if (i <= 0 or i > n - 1 or j <= 0 or j > 10)
        {
            printf("0\n");
            fprintf(stderr, "Question is not valid");
            return 0;
        }

        int ans = (a[i] & (1 << (10 - j))) ? 1 : 0;

        fprintf(fifo_to_user, "%d\n", ans);
        fflush(fifo_to_user);

		cnt++;
    }

    return 0;
}
