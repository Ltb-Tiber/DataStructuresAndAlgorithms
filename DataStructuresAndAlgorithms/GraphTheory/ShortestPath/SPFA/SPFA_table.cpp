#include<bits/stdc++.h>
using namespace std;
const int MAXN = 9999999;
struct Edge {
    // v is a node of the egde, w is the weight of the egde.
    int v, w;
};

// @Param G 存储图的邻接表
// @Param n 图的点个数
// @Param m 图的边个数
// @Param s 源点
// @Param dis 存储最短路的数组
// @Return true 表示成功求得最短路，false 表示图中存在负环，无法求最短路
// 算法事件复杂度 O(nm)
bool SPFA(vector<vector<Edge> >& G, int n, int m, int s, vector<int>& dis)
{
    queue<int> que;
    vector<bool> vis(n + 1);
    vector<int> cnt (n + 1, 0);
    dis.resize(n + 1, MAXN);
    dis[s] = 0;
    que.push(s);
    vis[s] = true;
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for (Edge e : G[u]) {
            int v = e.v, w = e.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                ++cnt[v];
                if (cnt[v] >= n) return false;
                if (!vis[v]) {
                    que.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return true;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    // 邻接表存图
    vector<vector<Edge> > G(n + 1);

    for (int i = 1, u, v, w; i <= m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        // 默认为无向图
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    vector<int> dis;

    if(SPFA(G, n, m, 1, dis)) {
        for (int i = 1; i <= n; ++i) {
            printf("%d ", dis[i]);
        }
        printf("\n");
    }

    return 0;
}

/*
3 3
1 2 1
2 3 2
1 3 4
*/