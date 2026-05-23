#include <bits/stdc++.h>
using namespace std;
int main() {
  int flag = 0;
  long long int n, m, d, temp;
  cin >> n >> m >> d;
  vector<long long int> a;
  cin >> temp;
  a.push_back(temp);
  for (long long int i = 1; i < m * n; i++) {
    long long int check;
    cin >> check;
    if (abs(temp - check) % d != 0) {
      flag = 1;
      break;
    }
    a.push_back(check);
  }
  if (flag == 1)
    cout << -1;
  else {
    sort(a.begin(), a.end());
    long long int mid = a.size() / 2;
    long long int x = a[mid], ans = 0;
    for (int i = 0; i < a.size(); i++) ans += abs(a[i] - x) / d;
    cout << ans;
  }
  return 0;
}
