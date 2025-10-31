/**
 *    author:  Vi Gia Huy
**/

#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> p, freq;
    vector<vector<int>> d;
    DSU(int _n = 0) {
        init(_n);
    }
    void init(int _n) {
        p.assign(_n + 1, 0);
        freq.assign(_n + 1, 1);
        d.assign(_n + 1, vector<int>());
        for (int i = 1; i <= _n; i++) p[i] = i;
        for (int i = 1; i <= _n; i++) d[i].push_back(i);
    }
    int find(int u) {
        if (p[u] == u) return u;
        return p[u] = find(p[u]);
    }
    void add(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) return;
        p[ru] = rv;
        freq[rv] += freq[ru];
        for (int x : d[ru]) d[rv].push_back(x);
        return;
    }
    int cnt(int u) {
        return freq[find(u)];
    }
    bool check(int u, int v) {
        return find(u) == find(v);
    }
};

void sol() {
    int n, q; cin >> n >> q;
    DSU dsu(n);
    while (q--) {
        char type; cin >> type;
        if (type == '1') {
            int u, v; cin >> u >> v;
            dsu.add(u, v);
        } else if (type == '2') {
            int u; cin >> u;
            cout << dsu.cnt(u) << "\n";
        } else if (type == '3') {
            int u; cin >> u;
            int ru = dsu.find(u);
            for (int x : dsu.d[ru]) cout << x << " ";
            cout << "\n"; 
        } else {
            int u, v; cin >> u >> v;
            if (dsu.check(u, v)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // freopen("dsu.inp", "r", stdin);
    // freopen("dsu.out", "w", stdout);
    int T = 1;
    //cin >> T;
    while (T--) sol();
    return 0;
}