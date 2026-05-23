#include <bits/stdc++.h>
using namespace std;
long long n, m, ladder, lift, v, q;
vector<long long> lads, lifts;
long long sa(long long xa, long long ya, long long xb, long long yb,
             vector<long long>& lads, long long v) {
  long long xrun = abs(xa - xb);
  long long ydist = abs(ya - yb);
  if (ya == yb) {
    return xrun;
  }
  long long anw = 1e18;
  long long arp = upper_bound(lads.begin(), lads.end(), xa) - lads.begin();
  long long alp = arp - 1;
  long long brp = upper_bound(lads.begin(), lads.end(), xb) - lads.begin();
  long long blp = brp - 1;
  vector<long long> alll = {alp, arp, blp, brp};
  for (long long c : alll) {
    if (c >= 0 && c < lads.size()) {
      anw =
          min(anw, abs(lads[c] - xa) + abs(lads[c] - xb) + (ydist + v - 1) / v);
    }
  }
  return anw;
}
int main() {
  ios::sync_with_stdio(0);
  cout.precision(10);
  cin >> n >> m >> ladder >> lift >> v;
  lads.resize(ladder);
  lifts.resize(lift);
  for (int i = 0; i < ladder; i++) cin >> lads[i];
  for (int i = 0; i < lift; i++) cin >> lifts[i];
  cin >> q;
  for (int i = 0; i < q; i++) {
    long long x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout << min(sa(x1, y1, x2, y2, lads, 1), sa(x1, y1, x2, y2, lifts, v))
         << endl;
  }
}
