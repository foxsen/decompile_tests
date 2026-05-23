#include <bits/stdc++.h>
using namespace std;
void Pagla() {
  int i, j;
  int n;
  cin >> n;
  vector<long long int> a, b;
  for (i = 0; i < n; i++) {
    int num;
    cin >> num;
    a.push_back(num);
  }
  b = a;
  vector<pair<int, int>> pos;
  sort(b.begin(), b.end());
  int k = 0;
  int kk = 0;
  int left = 0;
  int right = 0;
  bool flag = true;
  flag = true;
  int ans = 0;
  for (i = 0; i < n; i++) {
    int num = b[i];
    for (j = i; j < n; j++) {
      if (a[j] == num) {
        right = j;
        break;
      }
    }
    if (right == i) continue;
    ans++;
    pos.push_back(make_pair(i, right));
    int temp = a[right];
    for (j = right; j > i; j--) {
      a[j] = a[j - 1];
    }
    a[i] = temp;
  }
  cout << pos.size() << "\n";
  for (i = 0; i < pos.size(); i++) {
    cout << pos[i].first + 1 << " " << pos[i].second + 1 << " "
         << pos[i].second - pos[i].first << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    Pagla();
  }
  return 0;
}
