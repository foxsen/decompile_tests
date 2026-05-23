#include <bits/stdc++.h>
using namespace std;
template <typename t1, typename t2>
using umap = unordered_map<t1, t2>;
template <typename t>
using uset = unordered_set<t>;
struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2>& p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);
    return h1 ^ h2;
  }
};
template <class Container>
void split3(const std::string& str, Container& cont, char delim = ' ') {
  std::size_t current, previous = 0;
  current = str.find(delim);
  while (current != std::string::npos) {
    cont.push_back(str.substr(previous, current - previous));
    previous = current + 1;
    current = str.find(delim, previous);
  }
  cont.push_back(str.substr(previous, current - previous));
}
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
void zf(string& s, vector<long long>& z) {
  long long l = 0, r = 0;
  for (long long i = 1; i < s.size(); i++) {
    if (r >= i) {
      z[i] = min(z[i - l], r - i + 1);
    }
    while (z[i] + i < s.size() && s[z[i]] == s[z[i] + i]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
}
vector<long long> zf(string& a, string& b, string delimiter = "$") {
  string s = b + delimiter + a;
  vector<long long> z(s.size(), 0);
  long long l = 0, r = 0;
  for (long long i = 1; i < s.size(); i++) {
    if (r >= i) {
      z[i] = min(z[i - l], r - i + 1);
    }
    while (z[i] + i < s.size() && s[z[i]] == s[z[i] + i]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}
const long long INF = 1e9 + 1;
const long long MOD = 1e9 + 7;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  long long t;
  cin >> t;
  cin.ignore();
  for (long long _ = 0; _ < t; _++) {
    string s;
    getline(cin, s);
    long long ab = 0, ba = 0;
    for (long long i = 0; i < s.size() - 1; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b') {
        ab++;
      }
      if (s[i] == 'b' && s[i + 1] == 'a') {
        ba++;
      }
    }
    if (ba == ab) {
      cout << s << "\n";
    } else if (ba > ab) {
      cout << 'a' << s.substr(1) << "\n";
    } else {
      cout << 'b' << s.substr(1) << "\n";
    }
  }
  return 0;
}
