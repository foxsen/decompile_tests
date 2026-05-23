#include <bits/stdc++.h>
using namespace std;
vector<string> vec_splitter(string s) {
  for (char& c : s) c = c == ',' ? ' ' : c;
  stringstream ss;
  ss << s;
  vector<string> res;
  for (string z; ss >> z; res.push_back(z))
    ;
  return res;
}
void debug_out(vector<string> args, int idx) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, Head H, Tail... T) {
  if (idx > 0) cerr << ", ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, T...);
}
void localTest() {}
const long long N = 2e5 + 5;
long long A[N], has[N];
int main() {
  localTest();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long mx = 0, cnt = 0, ele = 0;
  for (long long i = 1; i <= n; ++i) {
    cin >> A[i];
    has[A[i]]++;
    mx = max(mx, has[A[i]]);
  }
  for (long long i = 1; i <= 100; ++i) {
    if (has[i] == mx) {
      ++cnt;
      ele = i;
    }
  }
  if (cnt > 1) {
    cout << n << "\n";
  } else {
    long long ans = 0;
    for (long long i = 1; i <= 100; ++i) {
      if (i == ele) {
        continue;
      }
      unordered_map<long long, long long> dp;
      dp[0] = 0;
      long long sum = 0;
      for (long long j = 1; j <= n; ++j) {
        if (A[j] == ele) {
          sum++;
        } else if (A[j] == i) {
          sum--;
        }
        if (dp.find(sum) != dp.end()) {
          ans = max(ans, j - dp[sum]);
        } else {
          dp[sum] = j;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
