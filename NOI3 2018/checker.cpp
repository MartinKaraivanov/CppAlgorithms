#include <cstdio>
#include <vector>

using namespace std;

long long calcHash(int n, int m, const vector<vector<char> > &table){
    long long ans = n*m, mod = 1000000007, a=945741440, b=479699241;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            ans = ( ans*2 + (table[i][j]=='#') )%mod;
        }
    }
    return ((ans * a) + b) % mod + 1;
}

int main(int argc, char *argv[]) {
    int rez, n, m;
    char c[128];
    vector<vector<char> > table;
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[3], "r");
    if (!in) {
        fprintf(stderr,"In-file %s not found\n",argv[1]);
        printf("0\n");
        return 0;
    }
    if (!out) {
        fprintf(stderr,"Out-file %s not found\n",argv[3]);
        printf("0\n");
        return 0;
    }
    fscanf(in, "%d %d", &n, &m);
    table.resize(n);
    for (int i=0; i<n; ++i){
        table[i].resize(m);
        fscanf(in, "%s", c);
        for (int j=0; j<m; ++j){
            table[i][j] = c[j];
        }
    }
    fscanf(out,"%d",&rez);
    if (rez == calcHash(n, m, table)){
        fprintf(stderr,"You win!\n");
        printf("1\n");
    }
    else if(rez == 0){
        fprintf(stderr,"You lost!\n");
        printf("0\n");
    }else{
        fprintf(stderr, "Please play correctly!");
        printf("0\n");
    }
    return 0;
}
