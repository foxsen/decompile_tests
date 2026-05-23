#include <bits/stdc++.h>
template <class T>
bool umin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool umax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
using namespace std;
int main(int argc, char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  int T;
  cin >> T;
  for (int tc = 0; tc < (int)(T); ++tc) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < (int)(n); ++i) cin >> a[i];
    for (int i = 0; i < (int)(n); ++i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < (int)(n); ++i) cout << a[i] << " ";
    cout << "\n";
    for (int i = 0; i < (int)(n); ++i) cout << b[i] << " ";
    cout << "\n";
  }
  return 0;
}
