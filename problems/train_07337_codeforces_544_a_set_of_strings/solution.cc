#include <bits/stdc++.h>
using namespace std;
inline bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first != b.first) return a.first > b.first;
  return a.second < b.second;
}
int a[200005], b[200005];
char s[200005], r[200005];
int test;
int main() {
  int t, n, m, k, l, x, y, z, flag, count, d, mx, mn;
  long long int sum, prod;
  scanf("%d%s", &k, s);
  n = strlen(s);
  for (int i = 0; i < n; i++) {
    a[s[i] - 'a']++;
  }
  count = 0;
  for (int i = 0; i < 26; i++) {
    if (a[i]) count++;
  }
  if (count >= k) {
    printf("YES\n");
    int i = 0;
    while (k > 1) {
      if (!b[s[i] - 'a']) {
        b[s[i] - 'a'] = 1;
        while (b[s[i] - 'a']) {
          printf("%c", s[i]);
          i++;
        }
      }
      printf("\n");
      k--;
    }
    for (int j = i; j < n; j++) printf("%c", s[j]);
  } else
    printf("NO\n");
  for (int i = 0; i < 26; i++) a[i] = b[i] = 0;
  return 0;
}
