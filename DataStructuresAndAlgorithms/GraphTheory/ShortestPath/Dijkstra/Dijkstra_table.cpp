#include<bits/stdc++.h>
using namespace std;
const int MAXN = 9999999;
struct Edge {
    // v is a node of the egde, w is the weight of the egde.
    int v, w;
};

struct Node {
    // u is a node, dis is the distance.
    int u, dis;
    bool operator > (const Node& a) const {
        return dis > a.dis;
    }
};

// @Param G 存储图的邻接表
// @Param n 图的点个数
// @Param m 图的边个数
// @Param s 源点
// @Param dis 存储最短路的数组
// 算法事件复杂度 O(mlogm)
void Dijkstra(vector<vector<Edge> >& G, int n, int m, int s, vector<int>& dis)
{
    priority_queue<Node, vector<Node>, greater<Node> > que;
    vector<bool> vis(n + 1);
    dis.resize(n + 1, MAXN);
    dis[s] = 0;
    que.push({s, 0});
    while(!que.empty()) {
        int u = que.top().u;
        que.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (Edge e : G[u]) {
            if (dis[e.v] > dis[u] + e.w) {
                dis[e.v] = dis[u] + e.w;
                que.push({e.v, dis[e.v]});
            }
        }
    }
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

    Dijkstra(G, n, m, 1, dis);

    for (int i = 1; i <= n; ++i) {
        printf("%d ", dis[i]);
    }
    printf("\n");

    return 0;
}

/*
3 3
1 2 1
2 3 2
1 3 4
*/