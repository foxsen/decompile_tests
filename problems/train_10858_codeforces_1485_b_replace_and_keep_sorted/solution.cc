#include <bits/stdc++.h>
#define rep(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
const int N = 1E5 + 10;
int a[N]; ll b[N];
int main()
{
    int n, m, k; cin >> n >> m >> k;
    rep(i, n) scanf("%d", &a[i]); a[n + 1] = k + 1;
    rep(i, n) b[i] = b[i - 1] + a[i] - a[i - 1] - 1 + a[i + 1] - a[i] - 1;
    
    while (m--) {
        int l, r; scanf("%d %d", &l, &r);
        int res = b[r - 1] - b[l]; // [l + 1, r - 1]
        res += a[l + 1] - 2 + k - a[r - 1] - 1;
        printf("%d\n", res);
    }
    return 0;
}