#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const ld eps = 1e-9;
const ll MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}
const bool comp (const P &p1, const P &p2) {
  if(p1.first == p2.first) {
    return p1.second < p2.second;
  } else {
    return p1.first > p2.first;
  }
}
P min(const P &p1, const P &p2) {
  if(comp(p1, p2)) return p1;
  else return p2;
}
void solve(int n) {
  vi p(n);
  int ma = 0;
  for(int i=0;i<n;++i) {
    cin >> p[i];
    ma = max(ma, p[i]);
  }
  ma = 1000;
  vector<P> d(n*ma+1, {-INF, INF});
  d[0] = {0, 0};
  for(int i=0;i<n;++i) {
    int mod = p[i] % 1000;
    vector<P> dnxt(n*ma+1, {-INF, INF});
    for(int j=0;j<=n*ma;++j) {
      if(d[j] == make_pair(-INF, INF)) continue;
      if(1 <= mod && mod <= 500) {
        dnxt[j+500-mod] = min(dnxt[j+500-mod], {d[j].first + 1, d[j].second + p[i]});
      } else {
        dnxt[j] = min(dnxt[j], d[j]);
        if(mod == 0 && j >= 500) dnxt[j-500] = min(dnxt[j-500], {d[j].first + 1, d[j].second + p[i]});
        if(mod != 0 && j >= mod - 500) dnxt[j-(mod - 500)] = min(dnxt[j - (mod - 500)], {d[j].first + 1, d[j].second + p[i]});
        if(mod != 0) dnxt[j+1000-mod] = min(dnxt[j+1000-mod], {d[j].first, d[j].second + p[i]});
      }
    }
    d = dnxt;
  }
  P ans = {-INF, INF};
  for(int i=0;i<=n*ma;++i) {
    ans = min(ans, d[i]);
  }
  cout << ans.first << " " << ans.second << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  while(1) {
    int n; cin >> n;
    if(n == 0) break;
    solve(n);
  }
}

