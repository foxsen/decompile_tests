#include <bits/stdc++.h>
using namespace std;
int a[200010], n, m, block, Maxs, M;
inline int Read() {
  char c = getchar();
  int num = 0;
  while ('0' > c || c > '9') c = getchar();
  while ('0' <= c && c <= '9') num = num * 10 + c - '0', c = getchar();
  return (num);
}
int heap[200010], top, del[510], num[200010], big[510], numb, fre[200010];
inline void Up(int x) {
  while (x && heap[x] < heap[x / 2]) swap(heap[x], heap[x / 2]), x /= 2;
}
inline void Down(int x) {
  while (x * 2 <= top) {
    int s = x * 2;
    if (s + 1 <= top && heap[s] > heap[s + 1]) s++;
    if (heap[x] > heap[s])
      swap(heap[x], heap[s]), x = s;
    else
      break;
  }
}
inline void Chg(int x, int del) {
  num[fre[x]]--;
  fre[x] += del;
  num[fre[x]]++;
}
inline int Solv() {
  int f = 0, sum = 0;
  top = 0;
  for (int i = 1; i <= Maxs; i++) del[i] = 0;
  for (int i = 1; i <= numb; i++)
    if (fre[big[i]] > Maxs) heap[++top] = fre[big[i]], Up(top);
  for (int i = 1; i <= Maxs; i++)
    if (num[i] + del[i]) {
      int res = num[i] + del[i];
      if (f) {
        res--;
        sum += f + i;
        if (f + i <= Maxs)
          del[f + i]++;
        else
          heap[++top] = f + i, Up(top);
      }
      sum += i * (res - (res % 2 != 0));
      if (i + i <= Maxs)
        del[i + i] += res / 2;
      else
        for (int j = 1; j <= res / 2; j++) heap[++top] = i + i, Up(top);
      if (res % 2 == 0)
        f = 0;
      else
        f = i;
    }
  if (top + (f > 0) <= 1) {
    heap[1] = 0;
    return (sum);
  }
  if (f) {
    sum += f + heap[1];
    heap[1] += f;
    Down(1);
  }
  while (top > 1) {
    int a1 = heap[1];
    heap[1] = heap[top], heap[top--] = 0;
    Down(1);
    int a2 = heap[1];
    heap[1] = heap[top], heap[top--] = 0;
    Down(1);
    sum += a1 + a2;
    heap[++top] = a1 + a2, Up(top);
  }
  heap[1] = 0;
  return (sum);
}
struct Que {
  int l, r, t;
} q[200010];
int ans[200010];
bool cmp(Que a, Que b) {
  return (a.l / block < b.l / block ||
          a.l / block == b.l / block && a.r / block < b.r / block);
}
int main() {
  n = Read();
  for (; block * block <= n; block++)
    ;
  for (int i = 1; i <= n; i++) {
    a[i] = Read();
    num[a[i]]++;
    M = max(M, a[i]);
    if (num[a[i]] == Maxs + 1) big[++numb] = a[i];
  }
  for (; Maxs * Maxs <= n * 2; Maxs++)
    ;
  m = Read();
  memset(num, 0, sizeof(num));
  for (int i = 1; i <= m; i++) q[i].l = Read(), q[i].r = Read(), q[i].t = i;
  sort(q + 1, q + 1 + m, cmp);
  int l = 0, r = 0;
  for (int i = 1; i <= m; i++) {
    while (r < q[i].r) r++, Chg(a[r], 1);
    while (q[i].r < r) Chg(a[r], -1), r--;
    while (l < q[i].l) Chg(a[l], -1), l++;
    while (q[i].l < l) l--, Chg(a[l], 1);
    ans[q[i].t] = Solv();
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
