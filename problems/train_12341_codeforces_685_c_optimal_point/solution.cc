#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &s, const pair<A, B> &p) {
  return s << "(" << p.first << "," << p.second << ")";
}
template <typename T>
ostream &operator<<(ostream &s, const vector<T> &c) {
  s << "[ ";
  for (auto it : c) s << it << " ";
  s << "]";
  return s;
}
const int MAXN = 101010;
const long long INF = 6LL << 60;
const long long BND = 1LL << 60;
int T, N;
long long px[MAXN], py[MAXN], pz[MAXN];
long long rel[2][2][2];
bool check(long long dis, bool output = false) {
  for (int p = 0; p < 2; p++) {
    long long al = -dis - rel[1][1][0], ar = dis + rel[0][0][1];
    long long bl = -dis - rel[1][0][1], br = dis + rel[0][1][0];
    long long cl = -dis - rel[0][1][1], cr = dis + rel[1][0][0];
    long long sl = -dis - rel[1][1][1], sr = dis + rel[0][0][0];
    if (!!(al % 2) != p) al++;
    if (!!(bl % 2) != p) bl++;
    if (!!(cl % 2) != p) cl++;
    if (!!(sl % 2) != p) sl++;
    if (!!(ar % 2) != p) ar--;
    if (!!(br % 2) != p) br--;
    if (!!(cr % 2) != p) cr--;
    if (!!(sr % 2) != p) sr--;
    if (al > ar or bl > br or cl > cr or sl > sr) continue;
    long long a = al, b = bl, c = cl;
    if (a + b + c > sr) continue;
    if (a + b + c < sl) a += min(sl - a - b - c, ar - a);
    if (a + b + c < sl) b += min(sl - a - b - c, br - b);
    if (a + b + c < sl) c += min(sl - a - b - c, cr - c);
    if (a + b + c < sl) continue;
    long long x = (a + b) / 2, y = (a + c) / 2, z = (b + c) / 2;
    if (output) cout << x << " " << y << " " << z << "\n";
    return true;
  }
  return false;
}
void calc() {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) rel[i][j][k] = INF;
  for (int v = 0; v < N; v++) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          long long val = px[v] * (i ? -1 : 1) + py[v] * (j ? -1 : 1) +
                          pz[v] * (k ? -1 : 1);
          rel[i][j][k] = min(rel[i][j][k], val);
        }
      }
    }
  }
  long long lb = 0, rb = BND * 3;
  while (lb < rb) {
    long long mb = (lb + rb) / 2;
    if (check(mb))
      rb = mb;
    else
      lb = mb + 1;
  }
  check(lb, true);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> px[i] >> py[i] >> pz[i];
    calc();
  }
  return 0;
}
