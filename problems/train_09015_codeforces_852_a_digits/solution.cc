#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
class CerrDummy {
} cerrDummy;
template <class T>
CerrDummy& operator<<(CerrDummy& cd, const T&) {
  return cd;
}
using charTDummy = char;
using traitsDummy = char_traits<charTDummy>;
CerrDummy& operator<<(CerrDummy& cd,
                      basic_ostream<charTDummy, traitsDummy>&(
                          basic_ostream<charTDummy, traitsDummy>&)) {
  return cd;
}
using pi = pair<ll, ll>;
using vi = vector<ll>;
using ld = long double;
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  for (ll i = ll(0); i < ll((ll)v.size()); i++) {
    if (i) os << ",";
    os << v[i];
  }
  os << "}";
  return os;
}
ll read() {
  ll i;
  scanf("%" SCNd64, &i);
  return i;
}
void printSpace() { printf(" "); }
void printEoln() { printf("\n"); }
void print(ll x, ll suc = 1) {
  printf("%" PRId64, x);
  if (suc == 1) printEoln();
  if (suc == 2) printSpace();
}
string readString() {
  static char buf[3341000];
  scanf("%s", buf);
  return string(buf);
}
char* readCharArray() {
  static char buf[3341000];
  static ll bufUsed = 0;
  char* ret = buf + bufUsed;
  scanf("%s", ret);
  bufUsed += strlen(ret) + 1;
  return ret;
}
template <class T, class U>
void chmax(T& a, U b) {
  if (a < b) a = b;
}
template <class T, class U>
void chmin(T& a, U b) {
  if (b < a) a = b;
}
template <class T>
T Sq(const T& t) {
  return t * t;
}
void Yes(bool ex = true) {
  cout << "YES" << endl;
  if (ex) exit(0);
}
void No(bool ex = true) {
  cout << "NO" << endl;
  if (ex) exit(0);
}
const ll infLL = LLONG_MAX / 3;
const ll inf = infLL;
bool waf(string s, bool show) {
  ll n = s.size();
  for (ll bit = ll(0); bit < ll(1 << (n - 1)); bit++) {
    ll sum = 0, cur = 0;
    for (ll i = ll(0); i < ll(n); i++) {
      if (i > 0 && (bit >> (i - 1)) & 1) {
        sum += cur;
        cur = 0;
      }
      cur = cur * 10 + s[i] - '0';
    }
    sum += cur;
    string tmp = to_string(sum);
    ll d = 0;
    for (auto c : tmp) d += c - '0';
    if (d < 10) {
      if (show) {
        {
          string t;
          for (ll i = ll(0); i < ll(n); i++) {
            if (i > 0 && (bit >> (i - 1)) & 1) {
              t += '+';
            }
            t += s[i];
          }
          cout << t << endl;
        }
        {
          string t;
          for (ll i = ll(0); i < ll(tmp.size()); i++) {
            if (i) t += '+';
            t += tmp[i];
          }
          cout << t << endl;
        }
      }
      return true;
    }
  }
  return false;
}
signed main() {
  ll n = read();
  string s;
  if (n > 0) {
    s = readString();
  } else {
    if (n == -1) {
      n = 23;
      s += '1';
      for (ll i = ll(1); i < ll(n); i++) s += '9';
    } else {
      n = 199999;
      for (ll i = ll(0); i < ll(n); i++) s += '9';
    }
  }
  cerrDummy << s << endl;
  for (ll b = 100; b >= 1; b--) {
    string t;
    ll sum = 0, cur = 0;
    for (ll i = ll(0); i < ll(n); i++) {
      if (i && rand() % b) {
        sum += cur;
        cur = 0;
        t += '+';
      }
      t += s[i];
      cur *= 10;
      cur += (s[i] - '0');
    }
    sum += cur;
    if (!waf(to_string(sum), false)) continue;
    cout << t << endl;
    waf(to_string(sum), true);
    break;
  }
}
