#include <bits/stdc++.h>
using namespace std;
long long lookup[51];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long init = 1;
  for (int i = 0; i < 51; i++) {
    lookup[i] = init;
    init *= 2;
  }
  int n;
  cin >> n;
  long long out = 0;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == 'B') out += (lookup[i]);
  }
  cout << out;
  return 0;
}
