#include <bits/stdc++.h>
using namespace std;
int n;
long long t;
int a[200100];
int minn = INT_MAX;
long long countt = 0;
pair<long long, long long> round() {
  long long s = 0;
  long long num = 0;
  for (int i = 0; i < n; i++) {
    if (t >= a[i]) {
      countt++;
      num++;
      t -= a[i];
      s += a[i];
    }
  }
  return make_pair(s, num);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    minn = min(minn, a[i]);
  }
  while (t >= minn) {
    long long r, num;
    tie(r, num) = round();
    countt += (t / r) * num;
    t = (t % r);
  }
  cout << countt << endl;
  return 0;
}
