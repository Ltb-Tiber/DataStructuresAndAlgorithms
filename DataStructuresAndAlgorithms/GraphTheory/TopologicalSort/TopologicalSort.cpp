#include<bits/stdc++.h>
using namespace std;

bool ToplogicalSort(int n, int m, vector<vector<int>>& G, vector<int>& ans)
{
    queue<int> que;
    // 如果需要最大最小字典序则使用优先队列
    // priority_queue<int, vector<int>, greater<int> > que;
    vector<int> degree(n);
    vector<bool> vis(n, false);

    for (int i = 0; i < n; ++i) {
        for (int v : G[i]) {
            ++degree[v];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (degree[i] == 0) {
            que.push(i);
            vis[i] = true;
        }
    }

    while(!que.empty()) {
        int u = que.front();
        que.pop();
        ans.push_back(u);
        for (int v : G[u]) {
            --degree[v];
            if (degree[v] == 0) {
                que.push(v);
                vis[v] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) return false;
    }

    return true;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> G(n + 1);
    vector<int> ans;
    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
    }
    if(ToplogicalSort(n, m, G, ans)) {
        printf("Toplogical Sort Successful:\n");
        for (int i = 0; i < n; ++i) {
            printf("%d ", ans[i]);
        }
    }
    return 0;
}

/*
13 15
0 1
0 5
0 6
2 0
2 3
3 5
5 4
6 4
7 6
8 7
6 9
9 10
9 11
9 12
11 12
*/