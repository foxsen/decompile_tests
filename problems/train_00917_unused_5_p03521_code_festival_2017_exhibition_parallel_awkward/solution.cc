#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 2005;

vector<int> G[MAX_N];
// i:隣の空きが 0, 1, 2
int dp[MAX_N][MAX_N][3][2];
int st[MAX_N], fac[MAX_N], inv2;

void make()
{
	fac[0] = fac[1] = 1;
	for(int i=2;i<MAX_N;i++){
		fac[i] = (ll)fac[i-1] * i % MOD;
	}
}

inline int mod_pow(int a, ll b)
{
    int res = 1;
    while(b){
        if(b & 1){
            res = (ll)res * a % MOD;
        }
        a = (ll)a * a % MOD;
        b >>= 1;
    }
    return res;
}

inline int add(int x,int y)
{
    return (x + y)%MOD;
}

inline int sub(int x,int y)
{
    return (x+MOD-y)%MOD;
}

inline int mul(int x,int y)
{
    return (ll)x*y%MOD;
}

void dfs(int u)
{
    st[u] = 1;
    dp[u][1][2][0] = 1;
    each(v,G[u]){
        dfs(v);
        for(int i = st[u]; i >= 1; i--){
            for(int j = st[v]; j >= 1; j--){
                dp[u][i+j][2][1] = add(dp[u][i+j][2][1], mul(dp[u][i][2][0], ((ll)dp[v][j][0][0] + dp[v][j][1][0] + dp[v][j][2][0])%MOD));
                dp[u][i+j][1][1] = add(dp[u][i+j][1][1], mul(dp[u][i][1][0], ((ll)dp[v][j][0][0] + dp[v][j][1][0] + dp[v][j][2][0])%MOD));
                dp[u][i+j][0][1] = add(dp[u][i+j][0][1], mul(dp[u][i][0][0], ((ll)dp[v][j][0][0] + dp[v][j][1][0] + dp[v][j][2][0])%MOD));
                dp[u][i+j-1][1][1] = add(dp[u][i+j-1][1][1], mul(mul(dp[u][i][2][0], dp[v][j][2][0]), 2));
                dp[u][i+j-1][1][1] = add(dp[u][i+j-1][1][1], mul(dp[u][i][2][0], dp[v][j][1][0]));
                dp[u][i+j-1][0][1] = add(dp[u][i+j-1][0][1], mul(dp[u][i][1][0], dp[v][j][2][0]));
                dp[u][i+j-1][0][1] = add(dp[u][i+j-1][0][1], mul(mul(dp[u][i][1][0], dp[v][j][1][0]), inv2));
            }
        }
        st[u] += st[v];
        srep(i,1,st[u]+1){
            rep(j,3){
                dp[u][i][j][0] = dp[u][i][j][1];
                dp[u][i][j][1] = 0;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i,n-1){
        int p;
        cin >> p;
        G[p-1].pb(i+1);
    }
    make();
    inv2 = mod_pow(2, MOD-2);
    dfs(0);
    int ans = 0;
    srep(i,1,n+1){
        if((n-i)%2){
            ans = sub(ans, mul(((ll)dp[0][i][0][0] + dp[0][i][1][0] + dp[0][i][2][0]) % MOD, fac[i]));
        }else{
            ans = add(ans, mul(((ll)dp[0][i][0][0] + dp[0][i][1][0] + dp[0][i][2][0]) % MOD, fac[i]));
        }
    }
    cout << ans << "\n";
    return 0;
}