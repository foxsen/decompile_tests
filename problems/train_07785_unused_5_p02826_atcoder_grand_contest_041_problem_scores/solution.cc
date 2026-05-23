#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;
const int inf = 1e9;
const ll INF = 1e18;
const db eps = 1e-10;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define ep emplace
#define mem(a) memset(a, 0, sizeof(a))
#define copy(a, b) memcpy(a, b, sizeof(b))
#define PA cout << "pass\n"
#define lowbit(x) (x & -x)
#define all(x) x.begin(), x.end()
#define TM cout << db(clock()) / CLOCKS_PER_SEC << '\n'

const int maxn = 5050;
int f[maxn];

int n, mod;
void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> mod;
    f[0] = 1;
    for(int i = 2; i <= n; i++){
        int t = min(i - 1, n + 2 - i);
        for(int j = t; j <= n; j++){
            add(f[j], f[j -  t]);
        }
    }
    int res = 0;
    for(int i = 0; i <= n; i++) add(res, 1ll * f[i] * (n - i) % mod);
    cout << res << '\n';
    return 0;
}