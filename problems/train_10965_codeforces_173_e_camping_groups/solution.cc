#include <bits/stdc++.h>
using namespace std;
int n, m;
bool debug = false;
int k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
struct member {
  int id;
  int a, r, L, R;
  bool operator<(const member b) const { return r < b.r; }
} mb[100005];
struct query {
  int id;
  int a, r, L, R;
  bool operator<(const query b) const { return r > b.r; }
} qy[100005];
map<int, int> aid;
int cnt, ages, M, T[1048600], gcnt[100005], A[100005], R[100005];
int ans[100005];
void setage(int age) { aid[age] = 0; }
void update(int pos, int x) {
  pos = pos + M;
  while (pos >= 1) {
    T[pos] += x;
    pos >>= 1;
  }
}
int getSum(int l, int r) {
  int ans = 0;
  for (l = l + M - 1, r = r + M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
    if (~l & 1) ans += T[l ^ 1];
    if (r & 1) ans += T[r ^ 1];
  }
  return ans;
}
void update1(int pos, int x) {
  pos = pos + M;
  while (pos >= 1) {
    T[pos] = max(x, T[pos]);
    pos >>= 1;
  }
}
int getMax(int l, int r) {
  int ans = 0;
  for (l = l + M - 1, r = r + M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
    if (~l & 1) ans = max(ans, T[l ^ 1]);
    if (r & 1) ans = max(ans, T[r ^ 1]);
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    scanf("%d", &mb[i].r);
    R[i + 1] = mb[i].r;
  }
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    scanf("%d", &mb[i].a);
    mb[i].id = i + 1;
    A[i + 1] = mb[i].a;
    setage(mb[i].a);
    setage(mb[i].a + k);
    setage(mb[i].a - k);
  }
  ages = aid.size();
  for (auto &p : aid) {
    p.second = ++cnt;
  }
  for (M = 1; M + 2 < ages; M <<= 1)
    ;
  sort(mb, mb + n);
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && mb[i].r == mb[j].r) {
      update(aid[mb[j].a], 1);
      j++;
    }
    gcnt[mb[i].id] = getSum(aid[mb[i].a - k], aid[mb[i].a + k]);
  }
  memset(T, 0, sizeof T);
  scanf("%d", &m);
  for (int i = 0, a, b; i < m; i++) {
    scanf("%d%d", &a, &b);
    qy[i].r = max(R[a], R[b]);
    qy[i].id = i;
    qy[i].L = max(A[a] - k, A[b] - k);
    qy[i].R = min(A[a] + k, A[b] + k);
  }
  sort(qy, qy + m);
  for (int i = 0, j = n - 1; i < m; i++) {
    query q = qy[i];
    if (q.L > q.R) {
      continue;
    }
    while (j >= 0 && mb[j].r >= q.r) {
      update1(aid[mb[j].a], gcnt[mb[j].id]);
      j--;
    }
    ans[q.id] = getMax(aid[q.L], aid[q.R]);
  }
  for (int(i) = 0; (i) < (int)(m); (i)++)
    printf("%d\n", ans[i] == 0 ? -1 : ans[i]);
  return 0;
}
