#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define fillarray(array, value, begin, end) fill((array) + (begin), (array) + (end) + 1, value)
#define fillvector(v, value) fill((v).begin(), (v).end(), value)
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
#define vecfirst (*vec.begin())
#define veclast (*vec.rbegin())
#define vecall(v) (v).begin(), (v).end()
#define vecupsort(v) (sort((v).begin(), (v).end()))
#define vecdownsort(v, type) (sort(vecall(v), greater<type>()))
#define veccmpsort(v, cmp) (sort(vecall(v), cmp))
using namespace std;
const int N = 100050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
    printf("\n\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
    system("pause");
#endif
}
int n, k, a[N];
vector<int> e[N];
int f[N][45], g[N][45];
void dfsf(int u, int fa)
{
    f[u][0] = a[u];
    for (auto v : e[u])
    {
        if (v == fa)
            continue;
        dfsf(v, u);
        for (int i = 1; i < 2 * k; ++i)
            f[u][i] ^= f[v][i - 1];
        f[u][0] ^= f[v][2 * k - 1];
    }
}
void dfsg(int u, int fa)
{
    if (fa)
    {
        g[u][0] = (g[fa][2 * k - 1] ^ f[u][0] ^ f[u][2 * k - 2]);
        g[u][1] = (g[fa][0] ^ f[u][1] ^ f[u][2 * k - 1]);
        for (int i = 2; i < 2 * k; ++i)
        {
            g[u][i] = (g[fa][i - 1] ^ f[u][i] ^ f[u][i - 2]);
        }
    }
    else
    {
        for (int i = 0; i < 2 * k; ++i)
            g[u][i] = f[u][i];
    }
    for (auto v : e[u])
    {
        if (v == fa)
            continue;
        dfsg(v, u);
    }
}

inline void solve()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        e[x].push_back(y), e[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    dfsf(1, 0);
    dfsg(1, 0);
    for (int u = 1; u <= n; ++u)
    {
        int xorsum = 0;
        for (int i = k; i < 2 * k; ++i)
            xorsum ^= g[u][i];
        printf("%d ", max(min(xorsum, 1), 0));
    }
}

int main()
{
    TIME__START = clock();
    int Test = 1;
    // scanf("%d", &Test);
    while (Test--)
    {
        solve();
        // if (Test)
        //     putchar('\n');
    }
    TIME__END = clock();
    program_end();
    return 0;
}