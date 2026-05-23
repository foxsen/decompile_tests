#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> v(n * 2 + 1), kal1((n * 2)), kal2(n * 2 + 1);
  for (long long i = 1; i <= n * 2; i++) {
    cin >> v[i];
    if (kal1[v[i]] == 0) {
      kal1[v[i]] = i;
    } else {
      kal2[v[i]] = i;
    }
  }
  long long x = 1, needx = 1, y = 1, needy = 1, s = 0;
  while (needx != n + 1) {
    s += abs(kal1[needx] - x);
    x = kal1[needx];
    needx++;
  }
  while (needy != n + 1) {
    s += abs(kal2[needy] - y);
    y = kal2[needy];
    needy++;
  }
  cout << s;
}
