#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
struct Trie {
  int num;
  Trie* p[2];
} * root;
int sum[maxn], n, k;
Trie* newnode() {
  Trie* p = (Trie*)malloc(sizeof(Trie));
  memset(p, 0, sizeof(Trie));
  return p;
}
void add(int x) {
  Trie* m = root;
  for (int i = 30; i >= 0; i--) {
    int s = (x >> i) & 1;
    if (m->p[s] == 0) m->p[s] = newnode();
    m = m->p[s];
    m->num++;
  }
}
int query(int x) {
  Trie* m = root;
  int cnt = 0, i;
  for (i = 30; i >= 0; i--) {
    int s1 = (x >> i) & 1, s2 = (k >> i) & 1;
    int s = s1 ^ s2;
    if (s2 == 0) {
      if (m->p[s ^ 1]) {
        cnt += m->p[s ^ 1]->num;
      }
    }
    if (m->p[s])
      m = m->p[s];
    else
      break;
  }
  if (i == -1) cnt += m->num;
  return cnt;
}
int main() {
  scanf("%d%d", &n, &k);
  root = newnode();
  long long ans = 0;
  add(0);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &sum[i]);
    sum[i] ^= sum[i - 1];
    ans += query(sum[i]);
    add(sum[i]);
  }
  cout << ans << endl;
}
