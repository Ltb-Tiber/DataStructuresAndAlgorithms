#include<bits/stdc++.h>
using namespace std;

struct Prufer {

    void dfs(int u, vector<vector<int> >& G, vector<int>& fa) {
        for (int v : G[u]) {
            if (fa[u] != v) {
                fa[v] = u;
                dfs(v, G, fa);
            }
        }
    }

    vector<int> prufer_encode(vector<vector<int> >& G, int root) {
        int n = G.size();
        vector<int> fa(n);
        fa[root] = -1;
        dfs(root, G, fa);

        int ptr = -1;
        vector<int> degree(n);
        for (int i = 0; i < n; ++i) {
            degree[i] = G[i].size();
            if (degree[i] == 1 && ptr == -1) ptr = i;
        }

        vector<int> encode_tree(n-2);
        int leaf = ptr;
        for (int i = 0; i < n - 2; ++i) {
            int next = fa[leaf];
            encode_tree[i] = next;
            if (--degree[next] == 1 && leaf > next) {
                leaf = next;
            }else {
                ++ptr;
                while(degree[ptr] != 1) ++ptr;
                leaf = ptr;
            }
        }
        return encode_tree;
    }

    vector<pair<int, int> > prufer_decode(vector<int>& encode_tree, int root) {
        int n = encode_tree.size() + 2;
        vector<int> degree(n, 1);
        for (int u : encode_tree) {
            ++degree[u];
        }

        int ptr = 0;
        while (degree[ptr] != 1) ++ptr;
        int leaf = ptr;
        vector<pair<int, int> > edges;
        for (int u : encode_tree) {
            edges.push_back({leaf, u});
            if (--degree[u] == 1 && ptr > u) {
                leaf = u;
            }else {
                ++ptr;
                while (degree[ptr] != 1) ++ptr;
                leaf = ptr;
            }
        }
        edges.push_back({leaf, root});
        return edges;
    }
};

int main()
{
    return 0;
}