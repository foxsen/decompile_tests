#include <bits/stdc++.h>
using namespace std;
const int N = 100010, INF = 0x3f3f3f3f;
int e[N], ne[N], w[N], idx;
int h[N];
int a[N], b[N];
int p[N];
int find(int x) {
  if (p[x] == x)
    return x;
  else
    return p[x] = find(p[x]);
}
void merge(int a, int b) {
  int t1 = find(a);
  int t2 = find(b);
  if (t1 != t2) p[t1] = t2;
}
using namespace std;
void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int gcd(int a, int b) { return b > 0 ? gcd(b, a % b) : a; }
bool cmp(int a, int b) { return a > b; }
inline int read() {
  int date = 0, w = 1;
  char c = 0;
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    date = date * 10 + c - '0';
    c = getchar();
  }
  return date * w;
}
bool check(int x) {
  if (x % 10 == 0) return true;
  return false;
}
int main() {
  int n;
  cin >> n;
  int k = n % 10;
  if (k <= 5)
    printf("%d\n", n - k);
  else
    printf("%d\n", n + 10 - k);
  return 0;
}
