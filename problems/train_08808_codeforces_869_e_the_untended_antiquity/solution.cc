#include <bits/stdc++.h>
using namespace std;
long long T[2510][2510][2];
long long base[2] = {2000000011, 1000000003};
long long p[2] = {10047, 10091};
long long pw[100010][2];
int val[2510][2510];
const int limit = 2;
void update(int u, int v, int id, int val) {
  int cur = v;
  for (; u < 2510; u += u & (-u)) {
    v = cur;
    for (; v < 2510; v += v & (-v)) {
      for (int ii = 0; ii < limit; ii++) {
        T[u][v][ii] += (pw[id][ii] * val) % base[ii];
        T[u][v][ii] %= base[ii];
      }
    }
  }
}
pair<long long, long long> get(int u, int v) {
  int cur = v;
  int res[limit];
  for (int i = 0; i < limit; i++) res[i] = 0;
  for (; u > 0; u -= u & (-u)) {
    v = cur;
    for (; v > 0; v -= v & (-v)) {
      for (int ii = 0; ii < limit; ii++) {
        res[ii] = (res[ii] + T[u][v][ii]) % base[ii];
      }
    }
  }
  for (int i = 0; i < limit; i++) res[i] = (res[i] + base[i]) % base[i];
  return make_pair(res[0], res[1]);
}
struct query {
  int x1, y1, x2, y2;
} q[100010];
int main() {
  srand(time(NULL));
  if (fopen("a.txt", "r")) {
    freopen("a.txt", "r", stdin);
  } else
    ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int X, Y, Q;
  cin >> X >> Y;
  cin >> Q;
  for (int i = 0; i < limit; i++) pw[0][i] = 1;
  for (int i = 1; i <= Q + 1; i++)
    for (int ii = 0; ii < limit; ii++)
      pw[i][ii] = (pw[i - 1][ii] * p[ii]) % base[ii];
  int cnt = 0;
  for (int i = 1; i <= Q; i++) {
    int type, x1, y1, x2, y2;
    cin >> type;
    if (type == 1) {
      cin >> x1 >> y1 >> x2 >> y2;
      if (x1 > x2) swap(x1, x2);
      if (y1 > y2) swap(y1, y2);
      x2++;
      y2++;
      val[x1][y1] = ++cnt;
      update(x1, y1, val[x1][y1], 1);
      update(x1, y2, val[x1][y1], -1);
      update(x2, y1, val[x1][y1], -1);
      update(x2, y2, val[x1][y1], 1);
      q[i] = {x1, y1, x2, y2};
    } else if (type == 3) {
      cin >> x1 >> y1 >> x2 >> y2;
      if (get(x1, y1) != get(x2, y2)) {
        puts("No");
      } else {
        puts("Yes");
      }
    } else {
      cin >> x1 >> y1 >> x2 >> y2;
      if (x1 > x2) swap(x1, x2);
      if (y1 > y2) swap(y1, y2);
      x2++;
      y2++;
      update(x1, y1, val[x1][y1], -1);
      update(x1, y2, val[x1][y1], 1);
      update(x2, y1, val[x1][y1], 1);
      update(x2, y2, val[x1][y1], -1);
    }
  }
}
