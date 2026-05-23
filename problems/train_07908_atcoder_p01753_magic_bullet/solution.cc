#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;
typedef struct {
    double x, y, z;
} P;

double dot(P a, P b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

P diff(P f, P t)
{
    return P{ t.x - f.x, t.y - f.y, t.z - f.z };
}

P mul(P a, double s)
{
    return P{ a.x*s, a.y*s, a.z*s };
}

double dist(P a)
{
    return pow(dot(a, a), 0.5);
}

const double EPS = 1e-8;

int main()
{
    int n, q; cin >> n >> q;
    vector<P> p(n);
    vector<double> r(n);
    vector<ll> l(n);
    loop (n, i) cin >> p[i].x >> p[i].y >> p[i].z >> r[i] >> l[i];

    // あいうえお
    loop (q, i) {
        P s, t;
        cin >> s.x >> s.y >> s.z >> t.x >> t.y >> t.z;

        // かきくけこ
        P st = diff(s, t), ts = diff(t, s);
        P n_st = mul(st, 1.0/dist(st));
        ll ans = 0;
        loop (n, j) {
            P sp = diff(s, p[j]), tp = diff(t, p[j]);
            if (dot(sp, st) < 0 || dot(tp, ts) < 0) continue;
            P n_sp = mul(n_st, dot(sp, n_st));
            double R = dist(diff(sp, n_sp));
            if (R < r[j] + EPS) ans += l[j];
        }
        cout << ans << endl;
    }
    return 0;
}