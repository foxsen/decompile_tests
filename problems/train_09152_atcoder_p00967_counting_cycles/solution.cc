#include <bits/stdc++.h>

using namespace std;

using Edge = int;
using Edges = vector<Edge>;
using Graph = vector<Edges>;

Graph Compression(const int n, const int m, vector<set<int>> &g) {
    stack<int> st;
    for (int v = 0; v < n; ++v)
        if (g[v].size() == 1) st.push(v);

    while (!st.empty()) {
        int cur = st.top(), dst = *g[cur].begin();
        st.pop();
        g[cur].clear();
        g[dst].erase(cur);
        if (g[dst].size() == 1) st.push(dst);
    }

    for (int v = 0; v < n; ++v)
        if (g[v].size() == 2) st.push(v);

    while (!st.empty()) {
        int cur = st.top(); st.pop();

        if (g[cur].size() != 2) continue;
        int d1 = *g[cur].begin(), d2 = *g[cur].rbegin();

        if (d1 == d2 || g[d1].count(d2) != 0) continue;

        g[cur].clear();
        g[d1].erase(cur);
        g[d2].erase(cur);

        g[d1].insert(d2);
        g[d2].insert(d1);

        if (g[d1].size() == 2) st.push(d1);
        if (g[d2].size() == 2) st.push(d2);
    }

    map<int, int> idx_v;
    int size = 0;
    for (int v = 0; v < n; ++v)
        if (2 <= g[v].size()) idx_v[v] = size++;

    Graph h(size);
    for (int v = 0; v < n; ++v) {
        if (idx_v.count(v) == 0) continue;

        int cur = idx_v[v];
        for (int dst : g[v]) {
            if (idx_v.count(dst) == 0) continue;
            h[cur].emplace_back(idx_v[dst]);
        }
    }

    return h;
}

int Backtrack(const int s, const int nb, const int p, const int cur, vector<bool> &visited, const Graph &g) {
    int res = 0;

    for (auto dst : g[cur]) {
        if (dst == p || dst < s) continue;
        if (dst == s && nb <= cur)
            ++res;
        else if (!visited[dst]) {
            visited[dst] = true;
            res += Backtrack(s, nb, cur, dst, visited, g);
            visited[dst] = false;
        }
    }

    return res;
}

int CountingCycles(Graph g) {
    const int n = g.size();

    if (n <= 1) return 0;

    vector<bool> visited(n, false);
    int cnt = 0;
    for (int s = 0; s < n; ++s) {
        visited[s] = true;
        for (auto dst : g[s]) {
            if (dst < s) continue;
            visited[dst] = true;
            cnt += Backtrack(s, dst, s, dst, visited, g);
            visited[dst] = false;
        }
        visited[s] = false;
    }

    return cnt;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, u, v;

    cin >> n >> m;
    vector<set<int>> g(n);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        g[u - 1].insert(v - 1);
        g[v - 1].insert(u - 1);
    }

    cout << CountingCycles(Compression(n, m, g)) << endl;

    return 0;
}

