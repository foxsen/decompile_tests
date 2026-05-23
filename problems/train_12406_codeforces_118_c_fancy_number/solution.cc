#include <bits/stdc++.h>
using namespace std;
int main() {
  pair<int, int> p[10009];
  int n, k, mini = 1000009;
  string str, temp, fin = "";
  cin >> n >> k >> str;
  for (int i = 0; i <= 9; i++) {
    temp = str;
    for (int j = 0; j < n; j++)
      p[j] = make_pair(abs(temp[j] - '0' - i),
                       temp[j] - '0' >= i ? -(n - j) : n - j);
    sort(p, p + n);
    int sum = 0, x;
    for (int j = 0; j < k; j++) {
      sum = sum + p[j].first;
      x = p[j].second;
      if (x < 0) x = abs(x);
      x = n - x;
      temp[x] = i + '0';
    }
    if (mini > sum || (temp < fin && sum == mini)) mini = sum, fin = temp;
  }
  cout << mini << endl << fin;
}
