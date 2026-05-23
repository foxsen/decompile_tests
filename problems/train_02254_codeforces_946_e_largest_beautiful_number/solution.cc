#include <bits/stdc++.h>
using namespace std;
class Timer {
 private:
  string scope_name;
  chrono::high_resolution_clock::time_point start_time;

 public:
  Timer(string name) : scope_name(name) {
    start_time = chrono::high_resolution_clock::now();
  }
  ~Timer() {
    auto stop_time = chrono::high_resolution_clock::now();
    auto length =
        chrono::duration_cast<chrono::microseconds>(stop_time - start_time)
            .count();
    double mlength = double(length) * 0.001;
    ;
  }
};
const long long MOD = 1000000007;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int iNF = 0x3f3f3f3f;
int t;
string s;
int cnt[11];
bool pow10() {
  bool al = true;
  for (int i = 1; i < int(s.size()) - 2 + 1; i += 1) {
    al &= s[i] == '0';
  }
  return al && s.front() == '1' && (s.back() == '1' || s.back() == '0');
}
int main() {
  ;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> s;
    ;
    if (pow10()) {
      for (int i = 0; i < int(s.size()) - 2; i += 1) {
        cout << 9;
      }
      cout << '\n';
    } else {
      memset(cnt, (0), sizeof(cnt));
      for (auto c : s) {
        cnt[c - '0']++;
      }
      string ans = s;
      for (int i = int(s.size()) - 1; i >= 0; i -= 1) {
        cnt[s[i] - '0']--;
        ;
        bool flag = false;
        if (s[i] != '0') {
          for (int ts = s[i] - '0' - 1; ts >= 0; ts -= 1) {
            ans[i] = ts + '0';
            cnt[ts]++;
            set<int> od;
            for (int d = 0; d < 10; d += 1) {
              if (cnt[d] & 1) {
                od.insert(d);
              }
            }
            cnt[ts]--;
            int fre = int(s.size()) - i - 1;
            if (int(od.size()) > fre) {
              continue;
            }
            if ((fre - int(od.size())) & 1) {
              continue;
            }
            vector<int> odd;
            for (auto c : od) {
              odd.emplace_back(c);
            }
            int x = fre - int(od.size());
            for (int j = 1; j < x + 1; j += 1) {
              ans[i + j] = '9';
            }
            for (int j = 0; j < int(od.size()); j += 1) {
              ans[j + x + i + 1] = odd.back() + '0';
              odd.pop_back();
            };
            cout << ans << '\n';
            flag = true;
            break;
          }
        }
        if (flag) {
          break;
        }
      }
    }
  }
  return 0;
}
