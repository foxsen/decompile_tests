#include <bits/stdc++.h>
using namespace std;

void prians(bool answer) {
  if(answer)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
}

long long n, d;
long long a[300005] = {0};
long long ans = 0;

int main() {
  cin >> n >> d;
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < n; ++i) ans ^= (a[i] - 1) % (d + 1);
  prians(ans != 0);
  return 0;
}
