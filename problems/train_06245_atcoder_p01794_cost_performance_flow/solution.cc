#include <bits/stdc++.h>
using namespace std;
using ll = __int128_t;
using ld = long double;
constexpr int INF = 1 << 30;
vector<int> F, C;
class CostFlow
{
public:
    struct Edge
    {
        int from, to, revind, capacity, flow, cost;
        bool reversed;
    };
    CostFlow(const int v) : V{v}, edge(v), dist(v), pot(v, 0), prev_v(v), prev_e(v) {}
    void addEdge(const int from, const int to, const int capacity, const int cost)
    {
        edge[from].push_back(Edge{from, to, (int)edge[to].size(), capacity, 0, cost, false});
        edge[to].push_back(Edge{to, from, (int)edge[from].size() - 1, capacity, capacity, -cost, true});
    }
    int minCostFlow(const int s, const int t, int f)
    {
        using P = pair<int, int>;
        int res = 0;
        vector<int> potential(V, 0);
        for (int flow = 0; f > 0;) {
            priority_queue<P, vector<P>, greater<P>> q;
            fill(dist.begin(), dist.end(), INF);
            dist[s] = 0;
            q.push(make_pair(0, s));
            while (not q.empty()) {
                const P p = q.top();
                q.pop();
                const int v = p.second;
                if (dist[v] < p.first) { continue; }
                for (int i = 0; i < edge[v].size(); i++) {
                    const auto& e = edge[v][i];
                    if (e.capacity > e.flow and dist[e.to] > dist[v] + e.cost + potential[v] - potential[e.to]) {
                        dist[e.to] = dist[v] + e.cost + potential[v] - potential[e.to];
                        prev_v[e.to] = v, prev_e[e.to] = i;
                        q.push(make_pair(dist[e.to], e.to));
                    }
                }
            }
            if (dist[t] == INF) { return res; }  // return -1; の場合もある
            for (int v = 0; v < V; v++) { potential[v] += dist[v]; }
            int d = f;
            for (int v = t; v != s; v = prev_v[v]) {
                const auto& e = edge[prev_v[v]][prev_e[v]];
                d = min(d, e.capacity - e.flow);
            }
            f -= d, res += d * potential[t], flow += d;
            F.push_back(flow), C.push_back(res);
            for (int v = t; v != s; v = prev_v[v]) {
                auto& e = edge[prev_v[v]][prev_e[v]];
                e.flow += d, edge[v][e.revind].flow -= d;
            }
        }
        return res;
    }
    const int V;
    vector<vector<Edge>> edge;

private:
    vector<int> dist, pot;
    vector<int> prev_v, prev_e;
};
class Rational
{
public:
    using T = ll;
    using F = ld;

private:
    static T gcd(const T a, const T b) { return (b != 0) ? gcd(b, a % b) : a; }
    static T lcm(const T a, const T b) { return (a / gcd(a, b)) * b; }

public:
    Rational() = default;
    Rational(const T N) : N{N} {}
    Rational(const T N_, const T D_) : N{N_}, D{D_}
    {
        assert(D_ != 0);
        const T g = gcd(N, D);
        N /= g, D /= g;
    }
    Rational operator-() const { return Rational{-N, D}; }
    Rational operator+(const Rational& r) const
    {
        const T newd = lcm(D, r.D);
        const T newn = newd / D * N + newd / r.D * r.N;
        return Rational{newn, newd};
    }
    Rational operator-(const Rational& r) const
    {
        const T newd = lcm(D, r.D);
        const T newn = newd / D * N - newd / r.D * r.N;
        return Rational{newn, newd};
    }
    Rational operator*(const Rational& r) const
    {
        const T g1 = gcd(N, r.D);
        const T g2 = gcd(D, r.N);
        return Rational{(N / g1) * (r.N / g2), (D / g2) * (r.D / g1)};
    }
    Rational operator/(const Rational& r) const
    {
        const T g1 = gcd(N, r.N);
        const T g2 = gcd(D, r.D);
        return Rational{(N / g1) * (r.D / g2), (D / g2) * (r.N / g1)};
    }
    Rational operator+(const T s) const { return (*this) + Rational{s}; }
    Rational operator-(const T s) const { return (*this) - Rational{s}; }
    Rational operator*(const T s) const { return (*this) * Rational{s}; }
    Rational operator/(const T s) const { return (*this) / Rational{s}; }
    bool operator==(const Rational& r) const { return N * r.D == D * r.N; }
    bool operator<(const Rational& r) const { return N * r.D < D * r.N; }
    bool operator>(const Rational& r) const { return N * r.D > D * r.N; }
    F getRaw() const { return (F)(N) / D; }
    pair<T, T> data() const { return {N, D}; }

private:
    T N = 0;
    T D = 1;
};
inline Rational operator+(const Rational::T s, const Rational& r) { return r + s; }
inline Rational operator-(const Rational::T s, const Rational& r) { return Rational{s} - r; }
inline Rational operator*(const Rational::T s, const Rational& r) { return r * s; }
inline Rational operator/(const Rational::T s, const Rational& r) { return Rational{s} / r; }
ostream& operator<<(ostream& os, const Rational& r)
{
    const auto p = r.data();
    return (os << (long long)p.first << "/" << (long long)p.second);
}
int main()
{
    int N, M;
    cin >> N >> M;
    CostFlow f(N);
    int S, T;
    cin >> S >> T;
    S--, T--;
    for (int i = 0; i < M; i++) {
        int a, b, u, c;
        cin >> a >> b >> u >> c;
        a--, b--;
        f.addEdge(a, b, u, c);
    }
    F.push_back(0), C.push_back(0);
    f.minCostFlow(S, T, INF);
    const auto FF = F.back();
    const int sz = F.size();
    Rational ans = INF;
    for (int i = 0; i < sz - 1; i++) {
        const Rational f = F[i], c = C[i], t{C[i + 1] - C[i], F[i + 1] - F[i]};
        const auto alpha = (-t * c + t * t * f + FF) / (t * t + 1);
        const auto x = alpha < F[i] ? F[i] : alpha > F[i + 1] ? F[i + 1] : alpha;
        const auto ff = t * (x - f) + c;
        ans = min(ans, (FF - x) * (FF - x) + ff * ff);
    }
    cout << (ans == INF ? 0 : ans) << endl;
    return 0;
}

