#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define chmax(a, b) a = (a >= b ? a : b)
#define chmin(a, b) a = (a <= b ? a : b)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define ceil(a, b) a / b + !!(a % b)
ll pow(ll a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }

using P = complex<double>;
struct S { P p1, p2; };
double dot(P a, P b) { return real(conj(a) * b); }
double cross(P a, P b) { return imag(conj(a) * b); }
const double eps = 1e-8;

double norm(P a) { return real(a) * real(a) + imag(a) * imag(a); }
double abs(P a) { return sqrt(norm(a)); }

int main() {
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    
    P p0 = P(x1, y1), p1 = P(x2, y2);
    
    if (abs(max(r1, r2) - min(r1, r2) - abs(p0 - p1)) < eps) cout << 1 << endl; // 内接
    else if (max(r1, r2) - min(r1, r2) - abs(p0 - p1) > eps) cout << 0 << endl; // 内包
    else if (abs(p0 - p1) < r1 + r2) cout << 2 << endl; // 交わる
    else if (abs(p0 - p1) == r1 + r2) cout << 3 << endl; // 外接
    else if (abs(p0 - p1) > r1 + r2) cout << 4 << endl; // 離れてる
    
}

