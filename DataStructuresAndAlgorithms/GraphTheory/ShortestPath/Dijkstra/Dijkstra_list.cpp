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
void Dijkstra(Front_chain_star& G, int n, int m, int s, vector<int>& dis)
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
        for (int i = G.head[u]; ~i; i = G.Next[i]) {
            int v = G.to[i], w = G.weight[i];
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                que.push({v, dis[v]});
            }
        }
    }
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