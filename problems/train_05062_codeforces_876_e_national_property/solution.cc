#include <bits/stdc++.h>
using namespace std;
struct Sides {
  int u, v, next;
} s[100000 + 5];
queue<int> q;
map<int, int> tr[100000 + 5], Map[100000 + 5];
vector<int> v[100000 + 5];
int tag[100000 + 5];
int first[100000 + 5], ind;
int n, m, cnt, size;
void insert(int u, int v) {
  s[ind] = (Sides){u, v, first[u]}, first[u] = ind++;
}
void Insert(int x) {
  int p = 0;
  for (int i = 0; i < v[x].size(); i++) {
    int t = v[x][i];
    for (map<int, int>::iterator i = Map[p].upper_bound(t); i != Map[p].end();
         i = Map[p].upper_bound(t))
      tag[i->first] = true, Map[p].erase(i);
    map<int, int>::iterator k = Map[p].end();
    if (k != Map[p].begin()) {
      k--;
      insert(t, k->first);
    }
    Map[p][t] = 1;
    if (!tr[p][t]) tr[p][t] = ++size;
    p = tr[p][t];
  }
}
int compare(int x, int y) {
  if (!tag[x]) x += m;
  if (!tag[y]) y += m;
  if (x == y) return 0;
  return x < y ? -1 : 1;
}
int check(int x) {
  int l1 = v[x].size(), l2 = v[x + 1].size();
  for (int i = 0; i < l1 && i < l2; i++)
    if (compare(v[x][i], v[x + 1][i]) == -1)
      return 1;
    else if (compare(v[x][i], v[x + 1][i]) == 1)
      return 0;
  if (l1 > l2)
    return 0;
  else
    return 1;
}
bool Recheck() {
  for (int i = 1; i < n; i++)
    if (!check(i)) return false;
  return true;
}
void Topsort() {
  for (int i = 1; i <= m; i++)
    if (tag[i]) q.push(i);
  while (!q.empty()) {
    int sd = q.front();
    q.pop();
    for (int i = first[sd]; i != -1; i = s[i].next)
      if (!tag[s[i].v]) tag[s[i].v] = 1, q.push(s[i].v);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  memset(first, (-1), sizeof(first));
  for (int i = 1; i <= n; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 1; j <= k; j++) {
      int t;
      scanf("%d", &t);
      v[i].push_back(t);
    }
    Insert(i);
  }
  Topsort();
  if (!Recheck())
    puts("No");
  else {
    for (int i = 1; i <= m; i++) cnt += tag[i];
    printf("Yes\n%d\n", cnt);
    for (int i = 1; i <= m; i++)
      if (tag[i]) printf("%d ", i);
  }
  return 0;
}
