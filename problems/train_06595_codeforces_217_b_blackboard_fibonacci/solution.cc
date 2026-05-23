#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000100;
const int INF = 1000000007;
int n, r;
int wyn = -1;
vector<int> stos;
vector<int> wynikowy;
void readData() { scanf("%d%d", &n, &r); }
void sprawdz(int g, int d, int dep) {
  if (dep < 0) return;
  int k;
  if (dep == 0) {
    if ((g == 1) && (d == 1)) {
      if (wyn < (int)stos.size()) {
        wynikowy = stos;
        wyn = (int)stos.size();
      }
    }
    return;
  }
  if (min(g, d) == 1) {
    if (max(g, d) == 1) return;
    stos.push_back(1);
    sprawdz(1, 1, dep - max(g, d) + 1);
  }
  if (min(g, d) == 0) return;
  if (g > d) {
    k = g / d;
    dep -= k;
    g -= k * d;
    stos.push_back(dep + 1);
    sprawdz(g, d, dep);
  } else {
    k = d / g;
    dep -= k;
    d -= k * g;
    stos.push_back(dep + 1);
    sprawdz(g, d, dep);
  }
}
int main() {
  int c;
  readData();
  for (int i = 1; i <= (r); ++i) {
    stos.clear();
    sprawdz(r, i, n - 1);
    stos.clear();
    sprawdz(i, r, n - 1);
  }
  if (wyn == -1) {
    printf("IMPOSSIBLE\n");
  } else {
    printf("%d\n", n - 1 - wyn);
    c = 1;
    for (int i = 0; i < (n); ++i) {
      if (!wynikowy.empty()) {
        if (wynikowy.back() == i) {
          wynikowy.pop_back();
          c = 1 - c;
        }
      }
      if (c == 0) {
        printf("B");
      } else {
        printf("T");
      }
    }
    printf("\n");
  }
}
