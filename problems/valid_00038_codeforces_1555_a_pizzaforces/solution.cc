#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int in;
  cin >> in;
  for (int i = 0; i < in; i++) solve();
  return 0;
}
void solve() {
  long long n, time, tempTime;
  cin >> n;
  if (n < 7)
    time = 15;
  else {
    tempTime = n * 2.5;
    if (tempTime % 5)
      time = (tempTime / 5) * 5 + 5;
    else
      time = tempTime;
  }
  cout << time << '\n';
}
