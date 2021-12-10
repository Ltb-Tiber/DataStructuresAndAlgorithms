#include<bits/stdc++.h>
using namespace std;
const int MAXN = 9999999;
struct Front_chain_star {
    vector<int> head, to, Next, weight;
    int cnt;
    Front_chain_star(int n, int m):head(n+1, -1), to(2*m+7, 0), Next(2*m+7, 0), weight(2*m+7), cnt(0) {}
    void add_edge(int u, int v, int w) {
        Next[++cnt] = head[u];
        head[u] = cnt;
        weight[cnt] = w;
        to[cnt] = v;
    }
};

// @Param G 存储图的邻接表
// @Param n 图的点个数
// @Param m 图的边个数
// @Param s 源点
// @Param dis 存储最短路的数组
// @Return true 表示成功求得最短路，false 表示图中存在负环，无法求最短路
// 算法事件复杂度 O(nm)
bool SPFA(Front_chain_star& G, int n, int m, int s, vector<int>& dis)
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
        for (int i = G.head[u]; ~i; i = G.Next[i]) {
            int v = G.to[i], w = G.weight[i];
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
    // 链向星存图
    Front_chain_star G(n, m);

    for (int i = 1, u, v, w; i <= m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        // 默认为无向图
        G.add_edge(u, v, w);
        G.add_edge(v, u, w);
    }

    vector<int> dis;

    SPFA(G, n, m, 1, dis);

    for (int i = 1; i <= n; ++i) {
        printf("%d ", dis[i]);
    }

    return 0;
}

/*
3 3
1 2 1
2 3 2
1 3 4
*/