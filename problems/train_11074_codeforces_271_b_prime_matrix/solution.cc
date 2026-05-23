#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b) { return (a < b); }
int main() {
  long long int s = 100010;
  bool a[s];
  memset(a, true, s);
  a[1] = false;
  for (int i = 2; i * i < s; i++) {
    if (a[i]) {
      for (int j = i + i; j < s; j += i) a[j] = false;
    }
  }
  long long int m, n;
  cin >> m >> n;
  long long int row[501] = {0}, col[501] = {0};
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      long long int x;
      cin >> x;
      long long int k = x;
      while (!a[k]) {
        k++;
      }
      row[i] += k - x;
      col[j] += k - x;
    }
  }
  int min_row_ele = *(min_element(row, row + m));
  int min_col_ele = *(min_element(col, col + n));
  cout << min(min_row_ele, min_col_ele);
  return 0;
}
