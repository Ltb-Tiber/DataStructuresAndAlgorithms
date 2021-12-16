#include<bits/stdc++.h>
using namespace std;

struct Mnemonic_Search {
    vector<vector<int>> ans;
    // n 指有多少要选择东西, m 指范围有多大
    int n, m ;
    Mnemonic_Search(int _n,int _m):n(_n), m(_m), ans(_n + 1, vector<int>(_m + 1, 0)) {}

    // a 中放的是某件物品的代价和好处值
    int dfs(int pos, int t, vector<pair<int,int>>& a) {
        //cout << "pos = " << pos << ", t = " << t << endl;
        if (pos == n) return ans[pos][t] = 0;
        if (ans[pos][t]) return ans[pos][t];
        int a1 = dfs(pos + 1, t, a), a2 = 0;
        if (t >= a[pos].first) a2 = dfs(pos + 1, t - a[pos].first, a) + a[pos].second;
        return ans[pos][t] = max(a1, a2);
    }
};

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    vector<pair<int,int> > a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    Mnemonic_Search ms(n, m);
    printf("%d\n", ms.dfs(0, m, a));
    return 0;
}

/*
70 3
71 100
69 1
1 2
*/