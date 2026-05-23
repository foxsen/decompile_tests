#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long MOD = 1e9 + 7;
const int MAXN = 2e5 + 100;
int st[4 * 3 * MAXN];
int v, c, maks, nyak;
string second;
bool sudah[3 * MAXN];
bool isvocal(char x) {
  return x == 'a' || x == 'A' || x == 'i' || x == 'I' || x == 'u' || x == 'U' ||
         x == 'e' || x == 'E' || x == 'o' || x == 'O';
}
void update(int p, int l, int r, int pos, int val) {
  if (l == r) {
    st[p] = val;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    update(p << 1, l, mid, pos, val);
  else
    update(p << 1 | 1, mid + 1, r, pos, val);
  st[p] = min(st[p << 1], st[p << 1 | 1]);
}
int query(int p, int l, int r, int x, int y) {
  if (l > y || r < x) return INF;
  if (l >= x && r <= y) return st[p];
  int mid = (l + r) >> 1;
  return min(query(p << 1, l, mid, x, y), query(p << 1 | 1, mid + 1, r, x, y));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 12 * MAXN; i++) st[i] = INF;
  cin >> second;
  sudah[0 + 400000] = 1;
  update(1, 0, 600000, 0 + 400000, -1);
  for (int i = 0; i < second.size(); i++) {
    if (isvocal(second[i]))
      v++;
    else
      c++;
    int x = v - 2 * c;
    int res = query(1, 0, 600000, x + 400000, 600000);
    if (i - res > maks) {
      maks = i - res;
      nyak = 1;
    } else if (i - res == maks)
      nyak++;
    if (sudah[x + 400000]) continue;
    sudah[x + 400000] = 1;
    update(1, 0, 600000, x + 400000, i);
  }
  if (maks == 0)
    cout << "No solution";
  else
    cout << maks << ' ' << nyak << '\n';
}
