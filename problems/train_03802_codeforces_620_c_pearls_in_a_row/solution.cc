#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i;
  scanf("%lld", &n);
  long long int arr[n];
  for (long long int i = 0; i < n; i++) scanf("%lld", &arr[i]);
  long long int ans = 0;
  map<long long int, long long int> mp;
  long long int a = 1, b;
  vector<long long int> vec;
  for (long long int i = 0; i < n; i++) {
    if (mp.find(arr[i]) != mp.end() && mp[arr[i]] == ans) {
      ans++;
      b = i + 1;
      vec.push_back(a);
      vec.push_back(b);
      a = i + 2;
    } else
      mp[arr[i]] = ans;
  }
  if (ans == 0)
    cout << "-1";
  else {
    vec[vec.size() - 1] = n;
    cout << ans << "\n";
    for (i = 0; i < vec.size(); i = i + 2)
      printf("%lld %lld\n", vec[i], vec[i + 1]);
  }
  return 0;
}
