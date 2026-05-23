#include <bits/stdc++.h>
using namespace std;
void fun2(long long int a[], long long int n) {
  for (long long int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
}
void fun(long long int a[], long long int n) {
  for (long long int i = 0; i < n; i++) cin >> a[i];
}
void vec(vector<long long int> &v, long long int n) {
  for (long long int i = 0; i < n; i++) {
    long long int x, z;
    cin >> x;
    v.push_back(x);
  }
}
void vec2(vector<long long int> &v) {
  for (auto i = v.begin(); i != v.end(); ++i) cout << *i << " ";
  cout << "\n";
}
void vecr(vector<long long int> &v) {
  for (auto i = v.rbegin(); i != v.rend(); ++i) cout << *i << " ";
  cout << "\n";
}
void set1(set<long long int> &s, long long int &n) {
  for (long long int i = 0; i < n; i++) {
    long long int x, z;
    cin >> x;
    s.insert(x);
  }
}
void set2(set<long long int> &s) {
  for (auto i = s.begin(); i != s.end(); ++i) cout << *i << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, z = 0, k;
    cin >> n >> k;
    long long int a[n];
    fun(a, n);
    for (long long int i = 0; i < n; i++) {
      if (k % 2 != 0) {
        if (k / 2 >= a[i])
          cout << "0 ";
        else
          cout << "1 ";
      } else {
        if (k / 2 == a[i]) {
          if (z == 0) {
            cout << "0 ";
            z = 1;
          } else {
            cout << "1 ";
            z = 0;
          }
        } else if (k / 2 >= a[i] + 1)
          cout << "0 ";
        else
          cout << "1 ";
      }
    }
    cout << "\n";
  }
  return 0;
}
