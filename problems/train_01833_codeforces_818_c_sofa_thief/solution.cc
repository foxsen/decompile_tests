#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long big = inf * 1LL * inf;
const int maxn = 1e6;
vector<int> vert[100010], hori[100010];
int cntVert[100010], cntHori[100010], topBefore[100010];
struct Sofa {
  int x1, y1, x2, y2;
  Sofa() {}
  Sofa(int a, int b, int c, int d) : x1(a), y1(b), x2(c), y2(d) {}
  bool isVert() { return x1 == x2; }
  bool isHori() { return y1 == y2; }
} sofas[100010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int d;
  cin >> d;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < d; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    sofas[i] = Sofa(x1, y1, x2, y2);
    if (x1 == x2) {
      vert[x1].push_back(i);
      hori[(min(y1, y2))].push_back(i);
      cntVert[x1]++;
    } else {
      hori[y1].push_back(i);
      vert[min(x1, x2)].push_back(i);
      cntHori[y1]++;
    }
  }
  for (int row = 1; row <= m; ++row) {
    topBefore[row] = topBefore[row - 1] + hori[row].size();
  }
  int cntl, cntr, cntt, cntb;
  cin >> cntl >> cntr >> cntt >> cntb;
  int toTheLeft = 0;
  for (int col = 1; col <= n; ++col) {
    if (!vert[col].size()) continue;
    for (int id : vert[col]) {
      Sofa sofa = sofas[id];
      int toTheRight, toTheTop, toTheBottom;
      if (sofa.isVert()) {
        toTheRight = d - toTheLeft - cntVert[col];
        toTheTop = topBefore[min(sofa.y1, sofa.y2)] - 1;
        toTheBottom = d - topBefore[min(sofa.y1, sofa.y2)] +
                      hori[min(sofa.y1, sofa.y2)].size() -
                      cntHori[min(sofa.y1, sofa.y2)] - 1;
        if (toTheLeft == cntl and toTheRight == cntr and toTheTop == cntt and
            toTheBottom == cntb) {
          cout << id + 1;
          return 0;
        }
      } else {
        toTheRight = d - toTheLeft - cntVert[col] - 1;
        toTheTop = topBefore[sofa.y1] - hori[sofa.y1].size();
        toTheBottom = d - toTheTop - cntHori[sofa.y1];
        if (cntl == toTheLeft + vert[col].size() - 1 and cntr == toTheRight and
            cntt == toTheTop and cntb == toTheBottom) {
          cout << id + 1;
          return 0;
        }
      }
    }
    toTheLeft += vert[col].size();
  }
  cout << -1;
  return 0;
}
