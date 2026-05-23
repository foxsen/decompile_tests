#include <bits/stdc++.h>
using namespace std;
int find(char alpha) {
  if (alpha >= 'a' && alpha <= 'z') return 0 + alpha - 'a';
  if (alpha >= 'A' && alpha <= 'Z') return 26 + alpha - 'A';
  if (alpha >= '0' && alpha <= '9') return 52 + alpha - '0';
  return 62;
}
int sz[800005];
char s[200005];
set<int> yes[70];
set<int>::iterator it;
void update(int node, int start, int end, int idx, int val) {
  if (start > end || start > idx || end < idx) return;
  if (start == end) {
    sz[node] += val;
    return;
  }
  int mid = (start + end) / 2;
  update(node << 1, start, mid, idx, val);
  update(node << 1 | 1, mid + 1, end, idx, val);
  sz[node] = sz[node << 1] + sz[node << 1 | 1];
}
int find(int node, int start, int end, int pos) {
  if (start > end || sz[node] < pos) return 0;
  if (start == end) {
    return start;
  }
  int mid = (start + end) / 2;
  if (sz[node << 1] >= pos) return find(node << 1, start, mid, pos);
  return find(node << 1 | 1, mid + 1, end, pos - sz[node << 1]);
}
int main() {
  int n, m, l, r;
  char alpha;
  scanf("%d%d", &n, &m);
  cin >> s + 1;
  for (int i = 1; i <= n; i++) {
    update(1, 1, n, i, 1);
    yes[find(s[i])].insert(i);
  }
  while (m--) {
    scanf("%d%d", &l, &r);
    cin >> alpha;
    int idx = find(alpha);
    l = find(1, 1, n, l);
    r = find(1, 1, n, r);
    while (!yes[idx].empty()) {
      it = yes[idx].lower_bound(l);
      if (it != yes[idx].end()) {
        if (*it <= r) {
          update(1, 1, n, *it, -1);
          yes[idx].erase(it);
        } else
          break;
      } else
        break;
    }
  }
  for (int i = 1; i <= n; i++) {
    it = yes[find(s[i])].find(i);
    if (it == yes[find(s[i])].end()) continue;
    printf("%c", s[i]);
  }
  printf("\n");
  return 0;
}
