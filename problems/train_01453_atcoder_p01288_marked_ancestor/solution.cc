#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
int q, n, v;
char c;
int p[100005];
int main() {
    while ((~scanf("%d %d", &n, &q)) && q && n) {
        for (int i = 2; i <= n; ++i) scanf("%d", &p[i]);
        p[1] = 1;
        ll ans = 0;
        for (int i = 0; i < q; ++i) {
            scanf("\n%c %d", &c, &v);
            if (c == 'M') p[v] = v;
            else {
                while (p[v] != v) v = p[v];
                ans += v;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

