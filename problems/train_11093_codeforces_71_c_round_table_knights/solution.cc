#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  set<int> s;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      s.insert(i);
      s.insert(n / i);
    }
  }
  s.erase(1);
  s.erase(2);
  vector<int> v(s.begin(), s.end());
  for (int i = 0; i < v.size(); i++) {
    int key = v.at(i);
    for (int j = 1; j <= (n / key); j++) {
      int k = j;
      int count = 0;
      while ((k <= n)) {
        if (arr[k] == 1) {
          k = k + (n / key);
          count++;
        } else {
          break;
        }
      }
      if (count == key) {
        cout << "YES"
             << "\n";
        return 0;
      }
    }
  }
  cout << "NO"
       << "\n";
  return 0;
}
