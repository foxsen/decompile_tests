#include <bits/stdc++.h>
using namespace std;
class graph {
  int v;
  list<int>* adj;

 public:
  graph(int x) {
    this->v = x;
    adj = new list<int>[v];
  }
  void add_edge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  void count_colors(int a, int& n, int color[], int color_ar[]);
};
void graph::count_colors(int a, int& n, int color[], int color_ar[]) {
  list<int>::iterator itr;
  int x = 0;
}
int main() {
  int n, m, c, x, y;
  cin >> n >> m;
  int color[100001] = {0}, Ar[100001] = {0}, g[100001] = {0};
  for (int i = 0; i < n; i++) {
    cin >> color[i];
    g[color[i]] = 1;
  }
  map<pair<int, int>, int> mp;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    if (mp[make_pair(color[x - 1], color[y - 1])] == 0 &&
        color[x - 1] != color[y - 1]) {
      Ar[color[x - 1]]++;
    }
    if (mp[make_pair(color[y - 1], color[x - 1])] == 0 &&
        color[x - 1] != color[y - 1]) {
      Ar[color[y - 1]]++;
    }
    mp[make_pair(color[x - 1], color[y - 1])] = 1;
    mp[make_pair(color[y - 1], color[x - 1])] = 1;
  }
  int max1 = INT_MIN, color1;
  for (int i = 0; i < 100001; i++) {
    if (g[i] == 1) {
      if (Ar[i] > max1) {
        max1 = Ar[i];
        color1 = i;
      }
    }
  }
  cout << color1;
}
