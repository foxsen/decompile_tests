#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, tmp;
  cin >> n;
  vector<int> a(100001, 0);
  int counter = 0;
  int max_count = 0;
  n = n * 2;
  while (n--) {
    cin >> tmp;
    if (a[tmp] == 0) {
      ++counter;
      ++a[tmp];
    } else if (a[tmp] == 1) {
      --counter;
      ++a[tmp];
    }
    max_count = max(max_count, counter);
  }
  cout << max_count << endl;
}
