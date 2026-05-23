#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define ins insert
#define er erase
#define bg begin()
#define ed end()
#define X first
#define Y second
#define fin(name) freopen(name, "r", stdin)
#define fout(name) freopen(name, "w", stdout)
#define files(name) fin(name".in"); fout(name".out")
#define enter cout << "\n"
#define space cout << " "
#define endl "\n"
#define fi(st,n) for (int i = (st); i <= (n); ++i)
#define fj(st,n) for (int j = (st); j <= (n); ++j)
#define fk(st,n) for (int k = (st); k <= (n); ++k)
#define fq(st,n) for (int q = (st); q <= (n); ++q)
#define fw(st,n) for (int w = (st); w <= (n); ++w)
#define ff(i, st, n) for (int (i) = (st); (i) <= (n); ++(i))
#define ei(st,n) for (int i = (st); i >= (n); --i)
#define ej(st,n) for (int j = (st); j >= (n); --j)
#define ek(st,n) for (int k = (st); k >= (n); --k)
#define ef(i, st, n) for (int (i) = (st); (i) >= (n); --(i))
#define ri(st,n) for (int i = (st); i < (n); ++i)
#define rj(st,n) for (int j = (st); j < (n); ++j)
#define rk(st,n) for (int k = (st); k < (n); ++k)
#define rq(st,n) for (int q = (st); q < (n); ++q)
#define rf(i, st, n) for (int (i) = (st); (i) < (n); ++(i))
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define y1 dsklmlvmd

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = (int)1e9;
const dbl eps = (dbl) 1e-8;
const int mod = (int) 10000007;
const int maxn = (int) 2 * 1e4 + 5;
//const dbl M_PI = (dbl)2 * (dbl)acos(0);

//cout<<fixed<<setprecision(10);
//srand(time(0));

ll ans;
ll n, a[maxn], st, s, tok;
pair <ll, ll> d[maxn][11];

int main() {
//    fin("t.in");
    sync;
    cin >> n;
    fi(1, n) {
    	cin >> a[i];
    }
    ans = 0;
    st = 1;
    fi(0, 18) {
    	memset(d, -1, sizeof d);
    	d[1][0].X = 0;
    	d[1][0].Y = 0;
    	fj(1, n) {
    		fk(0, 9) {
    			d[j + 1][k] = d[j][k];
    		}
    		fk(0, 9) {
    			if (d[j][k].X == -1)
    				continue;

    			s = d[j][k].X + a[j];
    			tok = ((ll)k + (s / st)) % 10;
    			if (d[j + 1][tok].X == -1)
    				d[j + 1][tok] = mp(s % st, s % st);
  				d[j + 1][tok].X = min(d[j + 1][tok].X, s % st);
  				d[j + 1][tok].Y = max(d[j + 1][tok].Y, s % st);

    			s = d[j][k].Y + a[j];
    			tok = ((ll)k + (s / st)) % 10;
    			if (d[j + 1][tok].X == -1)
    				d[j + 1][tok] = mp(s % st, s % st);
  				d[j + 1][tok].X = min(d[j + 1][tok].X, s % st);
  				d[j + 1][tok].Y = max(d[j + 1][tok].Y, s % st);

    		}
    	}
    	ej(9, 1) {
    		if (d[n + 1][j].X != -1) {
    			ans += j;
//    			cout << j << endl;
    			break;
    		}
    	}
    	st *= 10;
    }
    cout << ans << endl;
    return 0;
}