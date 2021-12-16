#include<bits/stdc++.h>
using namespace std;

int PackageDP(int n, int m1, int m2, vector<pair<pair<int, int>, int>>& items)
{
    vector<vector<int>> dp(m1 + 1, vector<int>(m2 + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = m1; j >= items[i].first.first; --j) {
            for (int k = m2; k >= items[i].first.second; --k) {
                dp[j][k] = max(dp[j][k], dp[j - items[i].first.first][k - items[i].first.second] + items[i].second);
            }
        }
    }
    return dp[m1][m2];
}

int main()
{
    int n, m1, m2;
    // n 物品个数, m1 背包类型1容量, m2 背包类型2容量
    scanf("%d %d %d", &n, &m1, &m2);
    // first.first 表示物品消耗背包类型1大小 first.second 表示物品消耗背包类型2大小, second 表示获得的利益大小
    vector<pair<pair<int, int>, int>> items(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &items[i].first.first, &items[i].first.second, &items[i].second);
    }

    printf("%d\n", PackageDP(n, m1, m2, items));

    return 0;
}

/*
6 10 10
1 1 1
2 3 1
3 2 1
2 5 1
5 2 1
4 3 1
*/