#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using PII = pair<int, int>;
using VI = vector<int>;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const ll MOD = 1000000007;
ll firstOdd(ll k) {
  ll l = k / 2 + 1;
  return ((l % MOD) * ((l + 1) % MOD) - l) % MOD;
}
ll firstEven(ll k) {
  ll l = k / 2;
  return ((l % MOD) * ((l + 1) % MOD)) % MOD;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  ll l, r;
  cin >> l >> r;
  ll start[2] = {2, 1};
  int parity = 1;
  ll reached = 0;
  ll m = 1;
  ll sum = 0;
  while (reached < r) {
    if (reached + m >= l) {
      ll fst = l > reached + 1 ? l : reached + 1;
      ll snd = r < reached + m ? r : reached + m;
      if (parity) {
        ll first = (fst - reached - 1) * 2 + start[1];
        ll second = (snd - reached - 1) * 2 + start[1];
        if (second == 1)
          sum += 1;
        else
          sum = (sum + firstOdd(second) + MOD - firstOdd(first - 2)) % MOD;
      } else {
        ll first = (fst - reached - 1) * 2 + start[0];
        ll second = (snd - reached - 1) * 2 + start[0];
        sum = (sum + firstEven(second) + MOD - firstEven(first - 2)) % MOD;
      }
    }
    start[parity] = start[parity] + m * 2;
    reached = reached + m;
    parity ^= 1;
    m *= 2;
  }
  cout << sum % MOD << '\n';
}
