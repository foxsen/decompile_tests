#include <bits/stdc++.h>
using namespace std;
int distance(int a, int b, int x, int y) {
  return ((a - x) * (a - x) + (b - y) * (b - y));
}
bool check(vector<int> cod) {
  int d1, d2, d3;
  unsigned int i = 0;
  for (i = 0; i < cod.size(); i += 1) {
    cod[i] -= 1;
    d1 = distance(cod[0], cod[1], cod[2], cod[3]);
    d2 = distance(cod[0], cod[1], cod[4], cod[5]);
    d3 = distance(cod[2], cod[3], cod[4], cod[5]);
    cod[i] += 1;
    if (d1 == 0 or d2 == 0 or d3 == 0) continue;
    if ((d1 == d2 + d3) or (d2 == d1 + d3) or (d3 == d2 + d1)) {
      return 1;
    }
  }
  for (i = 0; i < cod.size(); i += 1) {
    cod[i] += 1;
    d1 = distance(cod[0], cod[1], cod[2], cod[3]);
    d2 = distance(cod[0], cod[1], cod[4], cod[5]);
    d3 = distance(cod[2], cod[3], cod[4], cod[5]);
    cod[i] -= 1;
    if (d1 == 0 or d2 == 0 or d3 == 0) continue;
    if ((d1 == d2 + d3) or (d2 == d1 + d3) or (d3 == d2 + d1)) {
      return 1;
    }
  }
  return 0;
}
int main() {
  vector<int> cod;
  unsigned int i;
  for (i = 0; i < 6; i += 1) {
    int temp;
    cin >> temp;
    cod.push_back(temp);
  }
  int d1, d2, d3;
  d1 = distance(cod[0], cod[1], cod[2], cod[3]);
  d2 = distance(cod[0], cod[1], cod[4], cod[5]);
  d3 = distance(cod[2], cod[3], cod[4], cod[5]);
  if ((d1 == d2 + d3) or (d2 == d1 + d3) or (d3 == d2 + d1)) {
    cout << "RIGHT" << endl;
    return 0;
  } else if (check(cod))
    cout << "ALMOST" << endl;
  else
    cout << "NEITHER" << endl;
  return 0;
}
