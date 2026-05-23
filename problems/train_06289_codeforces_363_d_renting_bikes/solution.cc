#include <bits/stdc++.h>
using namespace std;
long long perso[100010], bike[100010], n, m, a;
pair<int, int> check2(long long k, long long s) {
  long long count = 0, sum = 0;
  for (int i = n - k, j = 0; j < k and i < n; j++, i++) {
    if (perso[i] >= bike[j]) {
      count++;
      sum += bike[j];
    } else {
      if (s + perso[i] >= bike[j]) {
        s -= bike[j] - perso[i];
        sum += perso[i];
        count++;
      } else
        break;
    }
  }
  sum -= s;
  pair<int, int> p = pair<int, int>(count, sum);
  return p;
}
pair<int, int> check(long long k, long long s) {
  long long count = 0, sum = 0;
  for (int i = n - k, j = 0; i < n and j < k; i++, j++) {
    if (s >= bike[j]) {
      count++;
      s -= bike[j];
    } else {
      if (s + perso[i] >= bike[j]) {
        sum += bike[j] - s;
        s = 0;
        count++;
      } else
        break;
    }
  }
  if (count == k) {
    return pair<int, int>(count, sum);
  } else {
    pair<int, int> p = check2(k, a);
    return p;
  }
}
int main() {
  while (cin >> n >> m >> a) {
    for (int i = 0; i < n; i++) scanf("%d", &perso[i]);
    for (int i = 0; i < m; i++) scanf("%d", &bike[i]);
    sort(perso, perso + n);
    sort(bike, bike + m);
    long long low = 0, high = min(n, m), mid, ans = 0, sum = 0, x, y;
    pair<int, int> c;
    while (low <= high) {
      mid = (low + high) / 2;
      c = check(mid, a);
      x = c.first;
      y = c.second;
      if (x == mid) {
        low = mid + 1;
        if (mid > ans) {
          ans = mid;
          sum = y;
        }
        if (mid == ans) {
          sum = min(sum, y);
        }
      } else
        high = mid - 1;
    }
    printf("%lld %lld\n", ans, sum);
  }
}
