#include <bits/stdc++.h>
using namespace std;
int d[200010];
int a[200010];
int ok[400010];
long long freq[200010];
long long acc[200010];
int cop[200010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  vector<int> v;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      v.push_back(i);
      if (i * i != n) {
        v.push_back(n / i);
      }
    }
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  long long ans = 0;
  for (int i = 1; i < v.size(); i++) {
    int l = v[i];
    int p = 0, fp = -1;
    for (int j = 0; j < l; j++) {
      d[j] = 0;
    }
    for (int j = 0; j < n; j++) {
      d[p] = max(d[p], a[j]);
      if (++p >= l) p -= l;
    }
    p = 0;
    for (int j = 0; j < n; j++) {
      ok[j] = a[j] == d[p];
      if (!ok[j]) fp = j;
      if (++p >= l) p -= l;
    }
    p = l;
    while (p < n) {
      if (!cop[p]) {
        cop[p] = i;
      }
      p += l;
    }
    if (fp != -1) {
      for (int j = 0; j <= n + 1; j++) {
        freq[j] = acc[j] = 0;
      }
      p = fp;
      do {
        int np = p + 1, cnt = 0;
        if (np >= n) np -= n;
        while (ok[np]) {
          ++cnt;
          if (++np >= n) np -= n;
        }
        freq[1] += cnt;
        acc[1]++;
        acc[cnt + 1]--;
        p = np;
      } while (p != fp);
      long long s = 0, add = 0;
      for (int j = 1; j <= n; j++) {
        s += freq[j];
        add += acc[j];
        if (cop[j] == i) {
          ans += s;
        }
        s -= add;
      }
    } else {
      for (int j = 1; j < n; j++) {
        if (cop[j] == i) {
          ans += n;
        }
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
