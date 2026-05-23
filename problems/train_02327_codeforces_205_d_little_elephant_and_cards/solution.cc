#include <bits/stdc++.h>
using namespace std;
inline string substring(string _t, int F, int T) { return _t.substr(F, T - F); }
template <class _T>
inline string tostr(const _T& a) {
  ostringstream os("");
  os << a;
  return os.str();
}
template <class T>
T sqr(T x) {
  return x * x;
}
double LOG(long long int N, long long int B) {
  return (log10l(N)) / (log10l(B));
}
template <class _T>
inline char tochr(const _T& a) {
  return (char)(((int)'0') + a);
}
template <class _T>
inline int CompareDouble(const _T& a, const _T& b) {
  if (a < b - 1.0e-11)
    return -1;
  else
    return 1;
  return 0;
}
int main() {
  int n;
  cin >> n;
  vector<int> a;
  vector<int> b;
  map<int, int> mya;
  map<int, int> myb;
  map<int, int> my;
  for (int i = 0, _n = (n); i < _n; i++) {
    int a1, b1;
    cin >> a1 >> b1;
    a.push_back(a1);
    b.push_back(b1);
    mya[a1]++;
    if (a1 != b1) {
      myb[b1]++;
    }
    my[a1]++;
    my[b1]++;
  }
  map<int, int>::iterator it;
  map<int, int>::iterator itb;
  int m = 1 << 20;
  for (it = my.begin(); it != my.end(); it++) {
    int a1 = mya[(*it).first];
    int b1 = myb[(*it).first];
    if (a1 + b1 >= (n + 1) / 2) {
      if (a1 >= (n + 1) / 2) {
        cout << "0" << endl;
        return 0;
      } else {
        if (((n + 1) / 2 - a1) < m) {
          m = ((n + 1) / 2 - a1);
        }
      }
    }
  }
  if (m == 1 << 20)
    cout << "-1" << endl;
  else
    cout << m << endl;
}
