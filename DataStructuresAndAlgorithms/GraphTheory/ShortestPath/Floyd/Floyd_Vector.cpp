#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000;

// 算法事件复杂度 O(n^3)
void Floyd(vector<vector<int> >& f, int n)
{
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int> > f(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &f[i][j]);
        }
    }
    Floyd(f, n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", f[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
3
0 1 4
1 0 2
4 2 0
*/