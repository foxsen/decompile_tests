#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline long long int rand(long long int x, long long int y) {
  ++y;
  return (rng() % (y - x)) + x;
}
string to_string(char c) {
  string second(1, c);
  return second;
}
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void degug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void degug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  degug_out(T...);
}
inline long long int gcd(long long int a, long long int b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    string second, t;
    cin >> second >> t;
    if (second.length() > t.length()) {
      cout << "NO\n";
      continue;
    }
    long long int co = 0;
    bool can = 1;
    for (long long int i = 0; i < (long long int)second.length(); ++i) {
      while (i != 0 && co < t.length() && t[co] == second[i - 1] &&
             t[co] != second[i]) {
        co++;
      }
      if (co >= t.length() || t[co] != second[i]) {
        can = 0;
        break;
      }
      co++;
    }
    while (co < t.length() && t[co] == second.back()) co++;
    if (co == t.length())
      ;
    else
      can = 0;
    if (can)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
