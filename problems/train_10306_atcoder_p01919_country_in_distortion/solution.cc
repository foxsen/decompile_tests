#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Edge {
    ll to, cost;
    Edge(ll t, ll c) : to(t), cost(c) {}
};
struct Elem {
    ll dist, speed, cur;
    Elem(ll a, ll b, ll c) : dist(a), speed(b), cur(c) {}
};
bool operator>(const Elem& a, const Elem& b) {
    return a.dist != b.dist ? a.dist > b.dist : a.speed > b.speed;
}

typedef vector< vector<Edge> > Graph;
ll const INF = 1LL << 60;

int main() {
    ll dist[510][60][2];
    ll ans = INF;
    for(int i=0; i<510; i++)
        for(int j=0; j<60; j++)
            for(int k=0; k<2; k++)
                dist[i][j][k] = INF;

    int n, m; cin >> n >> m;
    Graph G(n);
    for(int i=0; i<m; i++) {
        ll a, b, t; cin >> a >> b >> t;
        a--; b--;
        G[a].push_back(Edge(b,t));
        G[b].push_back(Edge(a,t));
    }
    ll v, a, b, c;
    cin >> v >> a >> b >> c;
    priority_queue< Elem, vector<Elem>, greater<Elem> > q;

    ll cur = 0, speed = v;
    dist[0][v][0] = 0;
    q.push(Elem(0, speed, cur));
    while(!q.empty()) {
        Elem temp = q.top(); q.pop();
        cur = temp.cur, speed = temp.speed;
        ll nsp = (a * speed + b) % c;
        for(size_t i=0; i<G[cur].size(); i++) {
            Edge e = G[cur][i];
            ll d1 = dist[cur][speed][0] + e.cost * speed;
            ll d2 = dist[cur][speed][1] + e.cost * speed;
            // home to university
            if(dist[e.to][nsp][0] > d1) {
                dist[e.to][nsp][0] = d1;
                if(e.to == n-1) dist[e.to][nsp][1] = dist[e.to][nsp][0];
                q.push(Elem(d1, nsp, e.to));
            }
            // university to home
            if(dist[e.to][nsp][1] > d2) {
                dist[e.to][nsp][1] = d2;
                q.push(Elem(d2, nsp, e.to));
            }
        }
    }

    for(int i=0; i<c; i++) ans = min(ans, dist[0][i][1]);
    cout << ans << endl;
}