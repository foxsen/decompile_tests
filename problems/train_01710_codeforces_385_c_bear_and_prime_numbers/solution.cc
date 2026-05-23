#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
int n, m, l, t, r;
long long com[N];
bool p[N];
int freq[N];
void seive() {
  for (long long i = 2; i < N; ++i) {
    com[i] += com[i - 1];
    if (p[i]) continue;
    long long num = freq[i];
    for (long long x = i + i; x < N; x += i) {
      num += freq[x];
      p[x] = 1;
    }
    com[i] += num;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t);
    ++freq[t];
  }
  seive();
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &l, &r);
    if (r > 10000000) r = 10000000;
    if (l > 10000000) l = 10000000;
    printf("%lld\n", com[r] - com[l - 1]);
  }
}
