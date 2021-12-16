#include<bits/stdc++.h>
using namespace std;

pair<int, int> RangeDP(int n, vector<int>& val)
{
    vector<vector<int>> dp1(2 * n, vector<int>(2 * n, 0)), dp2(2 * n, vector<int>(2 * n, 1e9+7));
    vector<int> sum(2 * n + 1, 0);
    for (int i = 0; i < n; ++i) {
        val.push_back(val[i]);
    }

    for (int i = 0; i < 2 * n; ++i) {
        sum[i+1] = sum[i] + val[i];
        dp2[i][i] = 0;
    }

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= 2 * n - len; ++i){
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                dp1[i][j] = max(dp1[i][j], dp1[i][k] + dp1[k+1][j] + sum[j+1] - sum[i]);
                dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[k+1][j] + sum[j+1] - sum[i]);
            }
        }
    }

    int maxn = 0, minn = 1e9+7;
    for (int i = 0; i < n; ++i) {
        maxn = max(maxn, dp1[i][i+n-1]);
        minn = min(minn, dp2[i][i+n-1]);
    } 

    return make_pair(maxn, minn);
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> val(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val[i]);
    }
    // first 合并最大值 second 合并最小值
    pair<int, int> ans = RangeDP(n, val);
    printf("%d\n%d\n", ans.first, ans.second);
    return 0;
}

/*
4
4 5 9 4
*/