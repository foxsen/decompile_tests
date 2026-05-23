#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
ostream& operator<<(ostream& out, pair<S, T> const& p) {
  out << '(' << p.first << ", " << p.second << ')';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& v) {
  int l = v.size();
  for (int i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}
template <typename T>
void trace(const char* name, T&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
const long long LIM = 1e18;
string s =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string p1 = "What are you doing while sending '";
string p2 = "'? Are you busy? Will you send '";
string p3 = "'?";
vector<long long> len;
long long a, b, c;
void pre() {
  len.push_back(s.length());
  a = p1.length();
  b = p2.length();
  c = p3.length();
  while (len.back() < LIM) {
    long long res = len.back();
    res <<= 1;
    res += a + b + c;
    len.push_back(res);
  }
}
char get(int n, long long k) {
  if (n > len.size()) {
    if (k <= a) {
      return p1[k - 1];
    }
    return get(n - 1, k - a);
  }
  if (n == 0) return s[k - 1];
  if (k <= a) {
    return p1[k - 1];
  } else if (k <= a + len[n - 1]) {
    return get(n - 1, k - a);
  } else if (k <= a + len[n - 1] + b) {
    return p2[k - a - len[n - 1] - 1];
  } else if (k <= a + len[n - 1] + b + len[n - 1]) {
    return get(n - 1, k - a - len[n - 1] - b);
  } else {
    return p3[k - a - len[n - 1] - b - len[n - 1] - 1];
  }
}
void solve() {
  int n;
  long long k;
  cin >> n >> k;
  if (n < len.size() and len[n] < k) {
    cout << '.';
    return;
  }
  char c = get(n, k);
  if (c == '\'') c = '"';
  cout << c;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  pre();
  int q;
  cin >> q;
  while (q--) solve();
  cout << endl;
  return 0;
}
