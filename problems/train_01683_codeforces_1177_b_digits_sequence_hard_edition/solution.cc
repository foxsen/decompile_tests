#include <bits/stdc++.h>
using namespace std;
class Debugger {
 public:
  Debugger(const std::string& _separator = ", ")
      : first(true), separator(_separator) {}
  template <typename ObjectType>
  Debugger& operator,(const ObjectType& v) {
    if (!first) cerr << separator;
    cerr << v;
    first = false;
    return *this;
  }
  ~Debugger() { cerr << "\n"; }

 private:
  bool first;
  string separator;
};
template <typename T1, typename T2>
inline ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
inline ostream& operator<<(ostream& os, const vector<T>& v) {
  bool first = true;
  os << "[";
  for (unsigned long long i = 0; i < v.size(); i++) {
    if (!first) os << ", ";
    os << v[i];
    first = false;
  }
  return os << "]";
}
template <typename T>
inline ostream& operator<<(ostream& os, const set<T>& v) {
  bool first = true;
  os << "[";
  for (typename set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
    if (!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}
template <typename T1, typename T2>
inline ostream& operator<<(ostream& os, const map<T1, T2>& v) {
  bool first = true;
  os << "[";
  for (typename map<T1, T2>::const_iterator ii = v.begin(); ii != v.end();
       ++ii) {
    if (!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}
long long n;
string ans = "";
long long kol(long long n) {
  long long ans = 9;
  for (long long i = 1; i < n; i++) {
    ans *= 10;
  }
  return ans;
}
long long poww(long long a, long long b) {
  long long res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = (res * a);
    a *= a;
  }
  return res;
}
long long nuj = 0;
long long sig = 0;
long long fff(long long n) {
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    ans += kol(i) * i;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  ;
  cin >> n;
  long long raz = 1;
  while (nuj < n) {
    nuj += kol(raz) * raz;
    raz++;
  }
  while (1) {
    if (nuj < n) break;
    raz--;
    nuj -= kol(raz) * raz;
  }
  long long nc = poww(10, raz - 1) - 1;
  long long nac = poww(10, raz - 1);
  long long konec = 0;
  long long ciss = raz;
  while (ciss--) {
    konec = konec * 10 + 9;
  }
  long long minn = LLONG_MAX;
  while (nac <= konec) {
    long long mid = (nac + konec) / 2;
    long long kol = (mid - nc) * raz + nuj;
    if (kol >= n) {
      minn = min(mid, minn);
      konec = mid - 1;
    } else {
      nac = mid + 1;
    }
  }
  string nujj = to_string(minn);
  long long ost = n - (nuj + ((minn - 1) - nc) * raz);
  cout << nujj[ost - 1] << "\n";
  return 0;
}
