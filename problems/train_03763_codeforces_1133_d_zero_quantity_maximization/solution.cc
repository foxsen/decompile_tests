#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
pair<int, int> make(int a, int b) {
  int g = gcd(a, b);
  return {a / g, b / g};
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < n; j++) cin >> b[j];
  map<pair<int, int>, int> cnt;
  int l = 0, Max = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0 && b[i] == 0) {
      l++;
      continue;
    }
    if (a[i] == 0) {
      continue;
    }
    pair<int, int> p = make(a[i], b[i]);
    if (b[i] == 0) {
      p = {0, 0};
    }
    cnt[p]++;
    Max = max(Max, cnt[p]);
  }
  cout << Max + l;
  return 0;
}
