#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n;
  vector<long long> sm(n);
  for (int i = 0; i < n; i++) {
    cin >> sm[i];
  }
  sort(sm.begin(), sm.end());
  long long now = 1;
  for (int i = 0; i < sm.size(); i++) {
    if (sm[i] >= now) sm[i] = now, now++;
  }
  cout << now;
}
