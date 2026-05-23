#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int ans = 0;
signed main() {
  std::ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> data;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    data.push_back(tmp);
  }
  int f = data[k - 1];
  int i = k;
  while (i < n) {
    if (data[i] != f) {
      cout << "-1";
      return 0;
    }
    i++;
  }
  int tmp = 0;
  int j = k - 2;
  while (j >= 0) {
    if (data[j] != f) {
      tmp = j + 1;
      break;
    }
    j--;
  }
  cout << tmp;
  return 0;
}
