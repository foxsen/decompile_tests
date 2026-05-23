#include <bits/stdc++.h>
using namespace std;
struct line {
  long long k, b;
  long double value(long double x) { return k * x + b; }
};
long double intersect(line a, line b) {
  return 1.0L * (b.b - a.b) / (a.k - b.k);
}
struct convex_hull_trick {
  vector<line> lines;
  vector<long double> pts = {-1e9};
  convex_hull_trick() {}
  void add(line l) {
    if (lines.empty()) {
      lines.push_back(l);
      return;
    }
    while (lines.size() > 1 &&
           l.value(pts.back()) < lines.back().value(pts.back())) {
      lines.pop_back();
      pts.pop_back();
    }
    pts.push_back(intersect(l, lines.back()));
    lines.push_back(l);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  vector<long long> d(n - 1);
  for (int i = 0; i < (int)(n - 1); i++) cin >> d[i];
  vector<long long> h(m), t(m);
  for (int i = 0; i < (int)(m); i++) cin >> h[i] >> t[i];
  vector<long long> D(n);
  for (int i = 0; i < (int)(n - 1); i++) {
    D[i + 1] = D[i] + d[i];
  }
  vector<long long> S(m);
  for (int i = 0; i < (int)(m); i++) {
    S[i] = t[i] - D[h[i] - 1];
  }
  vector<int> ind(m);
  iota(ind.begin(), ind.end(), 0);
  sort(ind.begin(), ind.end(), [&S](int i, int j) { return S[i] < S[j]; });
  vector<long long> Ss(m + 1);
  for (int i = 0; i < (int)(m); i++) {
    Ss[i + 1] = Ss[i] + S[ind[i]];
  }
  for (int i = 0; i < (int)(m); i++) {
    cerr << S[ind[i]] << " ";
  }
  cerr << endl;
  vector<long long> dp(m);
  for (int ip = 0; ip < (int)(m); ip++) {
    int i = ind[ip];
    dp[ip] = (ip + 1) * S[i] - Ss[ip + 1];
  }
  for (int ip = 0; ip < (int)(m); ip++) cerr << dp[ip] << " ";
  cerr << endl;
  for (int q = (int)(2); q < (int)(p + 1); q++) {
    convex_hull_trick cht;
    int j = 0;
    for (int ip = 0; ip < (int)(m); ip++) {
      int i = ind[ip];
      cht.add({-(ip + 1), Ss[ip + 1] + dp[ip]});
      if (ip > 0) {
        j = min<int>(j, cht.pts.size() - 1);
        while (j < (int)cht.pts.size() - 1 && cht.pts[j + 1] < S[i]) {
          j++;
        }
        dp[ip] = min<long long>(
            dp[ip], S[i] * (ip + 1) - Ss[ip + 1] + cht.lines[j].value(S[i]));
      }
    }
  }
  cout << dp[m - 1] << endl;
  return 0;
}
