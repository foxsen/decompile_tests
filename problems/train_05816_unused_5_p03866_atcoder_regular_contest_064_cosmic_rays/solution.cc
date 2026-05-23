#include <bits/stdc++.h>
using namespace std;

typedef double dbl;
struct vec { dbl x, y; };
vec operator-(vec v1, vec v2) { return { v1.x - v2.x, v1.y - v2.y }; }
dbl len(vec v) { return hypot(v.x, v.y); }
dbl dis(vec v1, vec v2) { return len(v2 - v1); }
struct cir { vec v; dbl r; };

const int N = 1002;
cir c[N];

dbl dis(cir c1, cir c2) { return max(0., dis(c1.v, c2.v) - c1.r - c2.r); }

dbl w[N][N], d[N]; bool vis[N];

int main(void) {
    vec s, t;
    scanf("%lf%lf%lf%lf", &s.x, &s.y, &t.x, &t.y);
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lf%lf%lf", &c[i].v.x, &c[i].v.y, &c[i].r);
    c[0].v = s; c[n + 1].v = t;

    for (int i = 0; i <= n + 1; ++i)
        for (int j = 0; j <= n + 1; ++j)
            w[i][j] = dis(c[i], c[j]);
    
    for (int i = 1; i <= n + 1; ++i) d[i] = DBL_MAX;
    int u = 0;
    while (u != n + 1) {
        int r = -1; dbl dr = DBL_MAX; vis[u] = 1;
        for (int v = 0; v <= n + 1; ++v) {
            if (vis[v]) continue;
            dbl dv = d[u] + w[u][v];
            d[v] = min(d[v], dv);
            if (d[v] < dr) dr = d[v], r = v;
        }
        u = r;
    }

    printf("%.15f\n", d[n + 1]);

    return 0;
}