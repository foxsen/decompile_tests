#include <bits/stdc++.h>
using namespace std;
const int INFTY = 20000000;
const int MAX = 500100;
const int MOD = 10000000;
void coutTab(int* tab, int n) {
  for (int i = 0; i < n; i++) {
    cout << tab[i] << " ";
  }
  cout << "\n";
}
template <class T>
void coutVec(vector<T> tab) {
  for (T t : tab) {
    cout << t << " ";
  }
  cout << "\n";
}
struct Square {
  long long x1, y1;
  long long x2, y2;
  Square() : x1(0), y1(0), x2(0), y2(0){};
  Square(int _x1, int _y1, int _x2, int _y2)
      : x1(_x1), y1(_y1), x2(_x2), y2(_y2){};
};
long long field(const Square& a) { return (a.x2 - a.x1) * (a.y2 - a.y1); }
pair<bool, Square> intersect(const Square& a, const Square& b) {
  long long x1 = max(a.x1, b.x1);
  long long x2 = min(a.x2, b.x2);
  long long y1 = max(a.y1, b.y1);
  long long y2 = min(a.y2, b.y2);
  if (x1 > x2 || y1 > y2) return {false, Square()};
  return {true, Square(x1, y1, x2, y2)};
}
int main() {
  ios_base::sync_with_stdio(0);
  Square w, b1, b2;
  cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
  cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
  cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
  auto i1 = intersect(w, b1);
  auto i2 = intersect(w, b2);
  if (i1.first && i2.first) {
    cout << (field(i1.second) + field(i2.second) -
                         field(intersect(i1.second, i2.second).second) ==
                     field(w)
                 ? "NO"
                 : "YES")
         << "\n";
  } else if (i1.first) {
    cout << (field(i1.second) == field(w) ? "NO" : "YES") << "\n";
  } else if (i2.first) {
    cout << (field(i2.second) == field(w) ? "NO" : "YES") << "\n";
  } else {
    cout << "YES"
         << "\n";
  }
}
