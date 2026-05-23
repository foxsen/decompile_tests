#include <bits/stdc++.h>
using namespace std;
class DSU {
 public:
  int *parent;
  int elems;
  DSU(int n) {
    elems = n;
    parent = new int[elems];
    for (int i = 0; i < elems; ++i) {
      parent[i] = i;
    }
  }
  ~DSU() { delete[] parent; }
  int find(int a) {
    if (a >= elems) return 4000000;
    int p = parent[a];
    while (p < elems && p != parent[p]) {
      if (parent[p] < elems) parent[p] = parent[parent[p]];
      p = parent[p];
    }
    return p;
  }
  void merge(int a, int b) {
    int ga = find(a);
    int gb = find(b);
    parent[gb] = ga;
  }
  void print() {
    for (int i = 0; i < elems; ++i) printf(" %d", parent[i]);
    printf("\n");
  }
};
int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d%d", &n, &m);
  DSU rem(n);
  vector<int> result(n);
  for (int i = 0; i < m; ++i) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    l--;
    r--;
    x--;
    for (int j = rem.find(l); j < x; j = rem.find(j)) {
      rem.merge(x, j);
      result[j] = x + 1;
      ++j;
    }
    int next = rem.find(r + 1);
    for (int j = rem.find(x + 1); j <= r; j = rem.find(j)) {
      rem.merge(next, j);
      result[j] = x + 1;
      j++;
    }
  }
  for (int i = 0; i < n; ++i) printf(" %d", result[i]);
  printf("\n");
  return EXIT_SUCCESS;
}
