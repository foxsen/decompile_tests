#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto begin = clock();
  while (clock() - begin < 1900)
    ;
  {}
  vector<int> b(101);
  for (int i = 0; i < a.size(); i++) {
    b[a[i]]++;
  }
  for (int i = 0; i < 101; i++) {
    while (b[i] > 0) {
      cout << i << " ";
      b[i]--;
    }
  }
}
