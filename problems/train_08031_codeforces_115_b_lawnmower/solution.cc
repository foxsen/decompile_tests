#include <bits/stdc++.h>
using namespace std;
int n, m, i = 0, y;
pair<int, int> take() {
  char a;
  int maxi = INT_MIN, mini = INT_MAX;
  for (int j = 0; j < n; j++) {
    cin >> a;
    if (a == 'W' && mini == INT_MAX) {
      mini = j;
      y = i + 1;
    }
    if (a == 'W' && maxi < j) {
      maxi = j;
      y = i + 1;
    }
  }
  if (maxi < 0) maxi = -1;
  if (mini > 200) mini = -1;
  return make_pair(mini, maxi);
}
int main() {
  int x, current = 0;
  int maxi, mini;
  cin >> m >> n;
  int z = 0;
  pair<int, int> p1 = take();
  pair<int, int> p;
  for (i = 0; i < m; i++) {
    if (i % 2 == 0) {
      if (p1.first == -1) {
      } else {
        z += p1.second - current;
        current += p1.second - current;
        y = i;
      }
    } else {
      if (p1.first == -1) {
      } else {
        z += current - p1.first;
        current -= current - p1.first;
      }
    }
    if (i == m - 1) break;
    pair<int, int> p = take();
    if (i % 2 == 0) {
      if (p.first == -1) {
      } else {
        if (current < p.second) {
          z += p.second - current;
          current += p.second - current;
        }
      }
    } else {
      if (p.first == -1) {
      } else {
        if (current > p.first) {
          z += current - p.first;
          current -= current - p.first;
        }
      }
    }
    p1 = p;
  }
  cout << z + y;
}
