#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(vector<T> A) {
  for (auto i : A) {
    cout << i << " ";
  }
  cout << endl;
}
template <typename T>
void print(vector<vector<T>> A) {
  for (auto i : A) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}
template <typename T, typename T1>
void print(map<T, T1> A) {
  for (auto i : A) {
    cout << i.first << " ---> " << i.second;
    cout << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    for (int i = 0; i < n; i++) {
      string sub = s.substr(i, n);
      ans += sub[i];
    }
    cout << ans << endl;
  }
  return 0;
}
