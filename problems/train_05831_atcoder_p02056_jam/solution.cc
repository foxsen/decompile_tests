#include <bits/stdc++.h>
#pragma GCC Optimize("Ofast")

using namespace std;
#define int long long

#define impl(x, last) x == last ? 0 : 63 - __builtin_clz(x ^ last)
struct RadixHeap {
    int last, size_;
    vector<tuple<int, int, bool>> bucket_[64];
    RadixHeap() : last(0), size_(0){}
    void emplace(int x, int val, bool hoge){
        size_++, bucket_[impl(x, last)].emplace_back(x, val, hoge);
    }
    tuple<int, int, bool> pop(bool flag = true){
        if(bucket_[0].empty()){
            int id = 1;
            while(bucket_[id].empty()) id++;
            last = get<0>(*min_element(bucket_[id].begin(), bucket_[id].end()));
            for(auto val : bucket_[id]){
                bucket_[impl(get<0>(val), last)].push_back(val);
            }
            bucket_[id].clear();
        }
        auto res = bucket_[0].back();
        if(flag) size_--, bucket_[0].pop_back();
        return res;
    }
    tuple<int, int, bool> top(){
        return pop(false);
    }
    bool empty(){
        return !size_;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ps(n), cs(n), js(n);
    vector<vector<int>> kidx(k);
    for (int i = 0; i < n; i++) {
        cin >> ps[i];
    }
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        c--;
        cs[i] = c;
        kidx[c].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> js[i];
    }

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    vector<vector<int>> dp(n, vector<int>(2, 2e18));
    dp[0][0] = 0;
    dp[0][1] = -ps[0];
//    priority_queue<tuple<int, int, bool>, vector<tuple<int, int, bool>>, greater<>> que;
//    tuple<int, int, bool> : cost, v, bought
    RadixHeap que;

    que.emplace(0, 0, 0);
    que.emplace(-ps[0], 0, 1);

    while (!que.empty()) {
        auto top = que.pop();

        int cost = get<0>(top);
        int v = get<1>(top);
        bool bought = get<2>(top);

        if (cost > dp[v][bought]) continue;
        for (auto &e : adj[v]) {
            int to = e.first, dist = e.second;
            if (bought) {
                if (cost + dist < dp[to][bought]) {
                    dp[to][bought] = cost + dist;
                    que.emplace(dp[to][bought], to, bought);
                }
            } else {
                if (cost + dist < dp[to][bought]) {
                    dp[to][bought] = cost + dist;
                    que.emplace(dp[to][bought], to, bought);
                }
                if (cost + dist - ps[to] < dp[to][1]) {
                    dp[to][1] = cost + dist - ps[to];
                    que.emplace(dp[to][1], to, 1);
                }
            }
        }
    }

    for (int i = 0; i < k; i++) {
        int nin = 2e18;
        for (int v : kidx[i]) {
            if (dp[v][0] + dp[v][1] - js[v] < nin) {
                nin = dp[v][0] + dp[v][1] - js[v];
            }
        }
        cout << -nin << '\n';
    }
}
