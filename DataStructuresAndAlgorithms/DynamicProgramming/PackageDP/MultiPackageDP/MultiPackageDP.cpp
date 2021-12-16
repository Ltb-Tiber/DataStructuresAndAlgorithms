#include<bits/stdc++.h>
using namespace std;

int PackageDP(int n, int m, vector<pair<int, pair<int, int>>>& items)
{
    vector<pair<int, int>> new_items;
    for (int i = 0; i < n; ++i) {
        int k = items[i].first, cost = items[i].second.first, val = items[i].second.second;
        int base = 1;
        while(k >= base) {
            new_items.push_back(make_pair(cost * base, val * base));
            k -= base;
            base *= 2;
        }
        if (k) {
            new_items.push_back(make_pair(cost * k, val * k));
        }
    }

    n = new_items.size();

    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= new_items[i].first; --j) {
            dp[j] = max(dp[j], dp[j - new_items[i].first] + new_items[i].second);
        }
    }
    return dp[m];
}

int main()
{
    int n, m;
    // n 物品个数, m 背包容量
    scanf("%d %d", &n, &m);
    // first 表示物品个数 second.first 表示物品消耗背包大小, second.second 表示获得的利益大小
    vector<pair<int, pair<int, int>>> items(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &items[i].second.first, &items[i].second.second, &items[i].first);
    }

    printf("%d\n", PackageDP(n, m, items));

    return 0;
}

/*
4 20
3 9 3
5 9 1
9 4 2
8 1 3
*/