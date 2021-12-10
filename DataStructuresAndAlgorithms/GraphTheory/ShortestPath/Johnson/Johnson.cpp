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
            if (dis[e.v] > dis[u] + e.w) {
                dis[e.v] = dis[u] + e.w;
                ++cnt[e.v];
                if (cnt[e.v] >= n) return false;
                if (!vis[e.v]) {
                    que.push(e.v);
                    vis[e.v] = true;
                }
            }
        }
    }
    return true;
}

void Johnson(vector<vector<Edge> >& G, int n, int m, vector<vector<int> >& dis)
{
    for (int i = 1; i <= n; ++i) {
        G[0].push_back({i, 0});
    }

    SPFA(G, n, m, 0, dis[0]);

    for (int i = 1; i <= n; ++i){
        for (Edge& e : G[i]) {
            e.w = e.w + dis[0][i] - dis[0][e.v];
        }
    }

    for (int i = 1; i <= n; ++i){
        Dijkstra(G, n, m, i, dis[i]);
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

    vector<vector<int> > dis(n + 1);

    Johnson(G, n, m, dis);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", dis[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
算法原理：
    Johnson 是用来求全源最短路的算法，其思想是先建立虚拟节点连向
其他所有节点，且边权为 0，利用 SPFA 算法求得虚拟节点的单源最短路，
利用虚拟节点的单源最短路来优化边权，将负边权转化成正的边权，然后利
用 Dijkstra 算法求 n 遍单源最短路即可得到全源最短路。
    利用虚拟节点单源最短路优化边权可行是因为其思路来自于势能，势能
的大小只与相对位置有关。又因为三角形两边之和大于第三边，所以边权一
定为正。
*/

/*
3 3
1 2 1
2 3 2
1 3 4
*/