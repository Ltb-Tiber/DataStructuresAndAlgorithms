#include<bits/stdc++.h>
using namespace std;

int PackageDP(int n, int m, vector<pair<int,int>>& items)
{
    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = items[i].first; j <= m; ++j) {
            dp[j] = max(dp[j], dp[j - items[i].first] + items[i].second);
        }
    }
    return dp[m];
}

int main()
{
    int n, m;
    // n 物品个数, m 背包容量
    scanf("%d %d", &n, &m);
    // first 表示物品消耗背包大小, second 表示获得的利益大小
    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &items[i].first, &items[i].second);
    }

    printf("%d\n", PackageDP(n, m, items));

    return 0;
}

/*
3 70
71 100
69 1
1 2
*/