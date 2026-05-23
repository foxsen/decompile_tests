#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define all(x) (x).begin(), (x).end()

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

template <class T>
vector<T> ReadVector(int n) {
    vector<T> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    return a;
}

template <class T>
void WriteVector(const vector<T>& a) {
    for (int i = 0; i < sz(a); ++i) {
        cout << a[i] << (i + 1 < sz(a) ? ' ' : '\n');
    }
}

void Solve() {
    int n, m;
    cin >> n >> m;

    int max_w = 0;
    vector<vector<pair<int, int>>> adj_init(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        --v1, --v2;

        adj_init[v1].pb(mp(v2, w));
        adj_init[v2].pb(mp(v1, w));
        max_w = max(max_w, w);
    }
    
    vector<vector<pair<int, int>>> adj(n * (max_w + 1));
    for (int v = 0; v < n; ++v) {
        for (int i = 0; i < sz(adj_init[v]); ++i) {
            int u = adj_init[v][i].fs;
            int w = adj_init[v][i].sc;

            adj[v * (max_w + 1)].pb(mp(u * (max_w + 1) + w, 0));
            for (int t = 1; t <= max_w; ++t) {
                adj[v * (max_w + 1) + t].pb(mp(u * (max_w + 1), sqr(t + w)));
            }
        }
    }

    int total = n * (max_w + 1);
    vector<int> d(total, inf);
    set<pair<int, int>> d_set;

    d[0] = 0;
    d_set.insert(mp(d[0], 0));

    while (!d_set.empty()) {
        int v = d_set.begin()->sc;
        d_set.erase(d_set.begin());

        for (int i = 0; i < sz(adj[v]); ++i) {
            int u = adj[v][i].fs;
            int w = adj[v][i].sc;
            if (d[u] > d[v] + w) {
                d_set.erase(mp(d[u], u));
                d[u] = d[v] + w;
                d_set.insert(mp(d[u], u));
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << (d[i * (max_w + 1)] < inf ? d[i * (max_w + 1)] : -1) << (i + 1 < n ? ' ' : '\n');
    }
    
}

int main () {
    ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    
    // clock_t start_clock = clock();
    
    // freopen("_input.txt", "rt", stdin);
    // freopen("_output.txt", "wt", stdout);

    int tc = 1;
    // cin >> tc;
    for (int ti = 0; ti < tc; ++ti) {
        Solve();
    }
    
    // double total_seconds = (double) (clock() - start_clock) / CLOCKS_PER_SEC;
    // cerr << "Working time: " << total_seconds << "s." << endl;

    return 0;
}
