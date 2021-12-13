#include<bits/stdc++.h>
using namespace std;

int find(int x, vector<int>& fa)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x], fa);
}

vector<vector<pair<int,int> > > Kruskal(int n, int m, vector<pair<int,pair<int, int> > >& G, vector<int>& fa)
{
    sort(G.begin(), G.end());
    vector<vector<pair<int,int> > > Tree(n + 1);
    for (int i = 0; i < m; ++i) {
        int u = find(G[i].second.first, fa), v = find(G[i].second.second, fa);
        if (u != v) {
            Tree[u].push_back({v, G[i].first});
            Tree[v].push_back({u, G[i].first});
            fa[u] = v;
            // printf("The egde be choosed: %d %d %d\n", u, v, G[i].first);
        }
    }
    return Tree;
}

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> fa(n + 1);
    vector<pair<int,pair<int, int> > > G(m);
    for (int i = 0, u, v, w; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        G[i] = make_pair(w, make_pair(u, v));
    }
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }

    vector<vector<pair<int,int> > > Tree = Kruskal(n, m, G, fa);
    return 0;
}

/*
6 10
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6
*/