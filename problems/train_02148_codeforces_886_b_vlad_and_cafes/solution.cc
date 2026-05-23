#include <bits/stdc++.h>
using namespace std;
void checkDefine();
long long int n;
long long int a[200005];
set<long long int> myset;
int main() {
  cin >> n;
  for (int i = (0), _b = (n - 1); i <= _b; i++) {
    cin >> a[i];
  }
  long long int res = -1;
  for (int i = (n - 1), _b = (0); i >= _b; i--) {
    long long int pre = myset.size();
    myset.insert(a[i]);
    if (myset.size() > pre) {
      res = a[i];
    }
  }
  cout << res;
  return 0;
}
void checkDefine() {
  long long int n, a[200005];
  map<long long int, long long int> m;
  cin >> n;
  for (int i = (0), _b = (n - 1); i <= _b; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  string s;
  cin >> s;
  {
    cout << "s"
         << " = ";
    cout << (s) << endl;
  };
  {
    cout << "a"
         << " = ";
    for (int _ = 0, _a = (n); _ < _a; _++) cout << a[_] << ' ';
    cout << endl;
  };
  {
    cout << "\"------------\""
         << " = ";
    cout << ("------------") << endl;
  };
  for (__typeof(m.begin()) it = m.begin(); it != m.end(); ++it) {
    cout << it->first << " " << it->second << endl;
  }
}
