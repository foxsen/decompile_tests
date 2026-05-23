#include <bits/stdc++.h>
using namespace std;
int n, m, k, i, x, y, z, suma;
pair<int, pair<int, int> > r1, r2, tr0, v[35];
map<pair<int, pair<int, int> >, pair<int, pair<int, int> > > mp;
pair<int, pair<int, int> > make_triplet(int x, int y, int z) {
  return make_pair(x, make_pair(y, z));
}
int getSum(int bts) {
  int S = 0;
  int j = 0;
  for (j = 0; j < m; j++)
    if ((1 << j) & bts) S += v[j + 1].first;
  return S;
}
void bck1(int pas, int s1, int s2, int s3, int bt1, int bt2, int bt3) {
  if (pas > m) return;
  if (pas == m) {
    int minim = min(s1, min(s2, s3));
    pair<int, pair<int, int> > sum =
        make_triplet(s1 - minim, s2 - minim, s3 - minim);
    pair<int, pair<int, int> > bt = make_triplet(bt1, bt2, bt3);
    int S = -((1 << 30) - 1 + (1 << 30));
    if (mp.count(sum)) S = getSum(mp[sum].first);
    if (S < s1) mp[sum] = bt;
    return;
  }
  int i = pas + 1;
  bck1(pas + 1, s1 + v[i].first, s2 + v[i].second.first, s3, bt1 + (1 << pas),
       bt2 + (1 << pas), bt3);
  bck1(pas + 1, s1 + v[i].first, s2, s3 + v[i].second.second, bt1 + (1 << pas),
       bt2, bt3 + (1 << pas));
  bck1(pas + 1, s1, s2 + v[i].second.first, s3 + v[i].second.second, bt1,
       bt2 + (1 << pas), bt3 + (1 << pas));
}
void bck2(int pas, int s1, int s2, int s3, int bt1, int bt2, int bt3) {
  if (pas > k) return;
  if (pas == k) {
    int maxim = max(s1, max(s2, s3));
    pair<int, pair<int, int> > sum =
        make_triplet(maxim - s1, maxim - s2, maxim - s3);
    if (mp.count(sum)) {
      pair<int, pair<int, int> > sum1 = mp[sum];
      int S = getSum(sum1.first);
      if (S + s1 > suma) {
        suma = S + s1;
        r1 = sum1;
        r2 = make_triplet(bt1, bt2, bt3);
      }
    }
    return;
  }
  int i = pas + m + 1;
  bck2(pas + 1, s1 + v[i].first, s2 + v[i].second.first, s3, bt1 + (1 << pas),
       bt2 + (1 << pas), bt3);
  bck2(pas + 1, s1 + v[i].first, s2, s3 + v[i].second.second, bt1 + (1 << pas),
       bt2, bt3 + (1 << pas));
  bck2(pas + 1, s1, s2 + v[i].second.first, s3 + v[i].second.second, bt1,
       bt2 + (1 << pas), bt3 + (1 << pas));
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d", &x, &y, &z);
    v[i] = make_triplet(x, y, z);
  }
  m = (n + 1) / 2;
  bck1(0, 0, 0, 0, 0, 0, 0);
  k = n - m;
  suma = -((1 << 30) - 1 + (1 << 30));
  bck2(0, 0, 0, 0, 0, 0, 0);
  if (r1.first || r1.second.first || r1.second.second) {
    for (i = 0; i < m; i++) {
      if ((1 << i) & r1.first) printf("L");
      if ((1 << i) & r1.second.first) printf("M");
      if ((1 << i) & r1.second.second) printf("W");
      printf("\n");
    }
    for (i = 0; i < k; i++) {
      if ((1 << i) & r2.first) printf("L");
      if ((1 << i) & r2.second.first) printf("M");
      if ((1 << i) & r2.second.second) printf("W");
      printf("\n");
    }
  } else
    printf("Impossible");
  return 0;
}
