#include <bits/stdc++.h>
using namespace std;
int get_nim(long long x) {
  if (x < 4) return 0;
  if (x < 16) return 1;
  if (x < 82) return 2;
  if (x < 6724) return 0;
  if (x < 50626) return 3;
  if (x < 2562991876LL) return 1;
  return 2;
}
int main() {
  int n, ans = 0;
  long long a;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    ans ^= get_nim(a);
  }
  if (ans)
    cout << "Furlo" << endl;
  else
    cout << "Rublo" << endl;
  return 0;
}
