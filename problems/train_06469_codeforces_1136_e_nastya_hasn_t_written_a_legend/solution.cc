#include <bits/stdc++.h>
using namespace std;
const long long int infinite = 1000000000000000000LL;
const int limit = 1000000;
const int tope = 1 << 20;
const int first = 1 << 19;
long long int add[tope];
long long int sum[tope];
long long int amount[tope];
void recompute(int pos) {
  sum[pos] = sum[2 * pos] + add[2 * pos] * amount[2 * pos] + sum[2 * pos + 1] +
             add[2 * pos + 1] * amount[2 * pos + 1];
}
void addbetween(int pos0, int pos1, long long int val) {
  pos0 += first;
  pos1 += first;
  add[pos0] += val;
  if (pos0 < pos1) add[pos1] += val;
  while (pos0 / 2 < pos1 / 2) {
    if (pos0 % 2 == 0) add[pos0 + 1] += val;
    pos0 /= 2;
    recompute(pos0);
    if (pos1 % 2 == 1) add[pos1 - 1] += val;
    pos1 /= 2;
    recompute(pos1);
  }
  while (pos0 > 1) {
    pos0 /= 2;
    recompute(pos0);
  }
}
long long int sumbetween(int pos0, int pos1) {
  pos0 += first;
  pos1 += first;
  long long int s = add[pos0];
  long long int am0 = 1;
  long long int am1 = 0;
  if (pos0 < pos1) {
    s += add[pos1];
    am1 = 1;
  }
  while (pos0 / 2 != pos1 / 2) {
    if (pos0 % 2 == 0) {
      s += sum[pos0 + 1] + add[pos0 + 1] * amount[pos0 + 1];
      am0 += amount[pos0 + 1];
    }
    pos0 /= 2;
    s += add[pos0] * am0;
    if (pos1 % 2 == 1) {
      s += sum[pos1 - 1] + add[pos1 - 1] * amount[pos1 - 1];
      am1 += amount[pos1 - 1];
    }
    pos1 /= 2;
    s += add[pos1] * am1;
  }
  am0 += am1;
  while (pos0 > 1) {
    pos0 /= 2;
    s += add[pos0] * am0;
  }
  return s;
}
long long int getval(int pos) { return sumbetween(pos, pos); }
int n;
set<int> libre;
long long int a[limit];
long long int k[limit];
int cases;
void write(set<int> s) {
  for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    cout << (*it) << ",";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  for (int i = tope - 1; i >= 1; i--)
    if (first <= i)
      amount[i] = 1;
    else
      amount[i] = amount[2 * i] + amount[2 * i + 1];
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    addbetween(i, i, a[i]);
  }
  a[0] = -infinite;
  k[0] = -infinite;
  a[n + 1] = infinite;
  addbetween(n + 1, n + 1, infinite);
  for (int i = 1; i <= n - 1; i++) cin >> k[i];
  for (int i = 1; i <= n + 1; i++)
    if (a[i - 1] + k[i - 1] < a[i]) libre.insert(i);
  cin >> cases;
  for (int cas = 0; cas < cases; cas++) {
    char t;
    cin >> t;
    if (t == '+') {
      int pos;
      long long int x;
      cin >> pos >> x;
      if (x == 0) continue;
      libre.insert(pos);
      for (;;) {
        if (x == 0) break;
        set<int>::iterator it = libre.find(pos);
        it++;
        int pos2 = *it;
        int pos1 = pos2 - 1;
        long long int val1 = getval(pos1);
        long long int val2 = getval(pos2);
        if (val1 + x + k[pos1] < val2) {
          addbetween(pos, pos1, x);
          x = 0;
          break;
        } else {
          long long int X = val2 - (val1 + k[pos1]);
          addbetween(pos, pos1, X);
          x -= X;
          libre.erase(pos2);
        }
      }
    } else {
      int l, r;
      cin >> l >> r;
      cout << sumbetween(l, r) << endl;
    }
  }
}
