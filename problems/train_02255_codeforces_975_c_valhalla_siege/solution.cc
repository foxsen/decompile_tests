#include <bits/stdc++.h>
using namespace std;
vector<long long int> pref, k, a;
int n;
int count(long long &cur, int &j, int i) {
  if (k[i] > cur) {
    long long x = k[i] - cur + pref[j];
    j = lower_bound(pref.begin(), pref.end(), x) - pref.begin();
    if (j != n)
      cur = pref[j] - x;
    else {
      cur = 0;
      j = n - 1;
    }
  } else
    cur -= k[i];
  if (cur == 0) {
    j = (j + 1) % n;
    cur = a[j];
  }
  return n - j;
}
int main() {
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a.push_back(x);
  }
  int j = 0;
  long long int cur = a[j];
  pref.push_back(a[0]);
  for (int i = 1; i < n; i++) pref.push_back(pref[i - 1] + a[i]);
  for (int i = 0; i < q; i++) {
    long long k_i;
    scanf("%lld", &k_i);
    k.push_back(k_i);
    printf("%d\n", count(cur, j, i));
  }
  return 0;
}
