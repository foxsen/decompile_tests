#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
long long google_itr = 1;
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) long long idx,
               __attribute__((unused)) long long LINE_NUM) {
  cerr << "\n";
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, long long idx, long long LINE_NUM, Head H,
               Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
const long long mod = 1e9 + 7;
const long long inf = 1e18;
void virus() {
  string seq, ans = "";
  cin >> seq;
  map<char, long long> cnt;
  for (auto i : seq) cnt[i]++;
  set<char> uniq(seq.begin(), seq.end());
  long long totUniq = uniq.size();
  if (totUniq == 0 or totUniq == 1) {
    cout << 0 << "\n"
         << ""
         << "\n";
    return;
  }
  if (totUniq == 2 or totUniq == 3) {
    if (cnt['L'] != 0 and cnt['R'] != 0)
      cout << 2 << "\n"
           << "LR\n";
    else if (cnt['U'] != 0 and cnt['D'] != 0)
      cout << 2 << "\n"
           << "UD\n";
    else
      cout << 0 << '\n'
           << ""
           << "\n";
    return;
  }
  long long minLR = min(cnt['L'], cnt['R']), minUD = min(cnt['U'], cnt['D']);
  auto charPush = [&](long long f, char ch) {
    for (auto i = 0; i < f; i++) ans.push_back(ch);
  };
  charPush(minLR, 'L');
  charPush(minUD, 'U');
  charPush(minLR, 'R');
  charPush(minUD, 'D');
  cout << ans.size() << "\n";
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    auto start = high_resolution_clock::now();
    virus();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
  }
  return 0;
}
