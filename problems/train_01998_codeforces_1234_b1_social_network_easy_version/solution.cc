#include <bits/stdc++.h>
const int N = 200 + 5;
int n, k;
int id[N];
std::queue<int> q;
std::map<int, bool> map;
void print() {
  if (q.empty()) return;
  int t = q.front();
  q.pop();
  print();
  printf("%d ", t);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &id[i]);
  for (int i = 1; i <= n; i++) {
    if (map[id[i]]) continue;
    if (q.size() == k) {
      map[q.front()] = 0;
      q.pop();
    }
    q.push(id[i]);
    map[id[i]] = 1;
  }
  printf("%d\n", q.size());
  print();
  return 0;
}
