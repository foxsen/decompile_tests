#include <bits/stdc++.h>
using namespace std;
map<long long, long long> ct;
long long get(long long x) {
  long long st = 1;
  long long ans = 0;
  while (x > 0) {
    ans += (x & 1) * st;
    x /= 10;
    st *= 10;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long n;
  cin >> n;
  string s;
  long long x;
  for (long long i = 0; i < n; i++) {
    cin >> s >> x;
    if (s == "+") {
      ct[get(x)]++;
    } else if (s == "-") {
      ct[get(x)]--;
    } else {
      cout << ct[x] << "\n";
    }
  }
  return 0;
}
