#include<bits/stdc++.h>
using namespace std;

pair<int, int> RangeDP(int n, vector<int> val)
{
    vector<vector<int>> dp1(n, vector<int>(n, 0)), dp2(n, vector<int>(n, 1e9+7));
    vector<int> sum(n+1, 0);
    for (int i = 0; i < n; ++i) {
        sum[i+1] = sum[i] + val[i];
        dp2[i][i] = 0;
    }

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i){
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                dp1[i][j] = max(dp1[i][j], dp1[i][k] + dp1[k+1][j] + sum[j+1] - sum[i]);
                dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[k+1][j] + sum[j+1] - sum[i]);
            }
        }
    }
    return make_pair(dp1[0][n-1], dp2[0][n-1]);
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