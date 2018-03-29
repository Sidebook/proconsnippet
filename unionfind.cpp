/*
Implementation of Union Find Tree (Disjoint Set)

Node Indicies are 0-indexed

Unverified
*/

#include<vector>

using namespace std;

struct UnionFind{
    vector<int> par;
    vector<int> rank;

    void init(int n) {
        par = vector<int>(n);
        rank = vector<int>(n);

        for (int i = 0; i < n; ++i) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] > rank[y]) {
            par[y] = x;
        } else {
            par[x] = y;
            if (rank[x] == rank[y]) ++rank[x];
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};
