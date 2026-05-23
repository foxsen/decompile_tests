#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int n, long long int m);
long long int power(long long int a, long long int n, long long int m) {
  if (n == 0) return 1;
  long long int x = power(a, n / 2, m);
  if (n % 2 != 0)
    return (((a * x) % m) * (x) % m) % m;
  else
    return (x * x) % m;
}
double PI = 3.14159265357;
int32_t main() {
  long long int n, i, j, x, y, m, k, t, sum, count, cnt, b, c, d, j1, z, a, o,
      temp;
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  long long int arr[n];
  map<long long int, long long int> p;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    p[arr[i]]++;
  }
  vector<long long int> v1, v2;
  for (auto i1 = p.begin(); i1 != p.end(); i1++) {
    x = i1->second;
    if (x > 2) {
      cout << "NO\n";
      return 0;
    }
    v1.push_back(i1->first);
    x--;
    if (x != 0) v2.push_back(i1->first);
  }
  cout << "YES\n";
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end(), greater<long long int>());
  cout << v1.size() << "\n";
  for (i = 0; i < v1.size(); i++) cout << v1[i] << " ";
  cout << "\n";
  cout << v2.size() << "\n";
  for (i = 0; i < v2.size(); i++) cout << v2[i] << " ";
  return 0;
}
