#include <bits/stdc++.h>
using std::endl;
using std::make_pair;
using std::max;
using std::pair;
using std::set;
using std::upper_bound;
const int MAX_SEQ_SIZE = 100 * 1000;
const int MAX_NUM = 100 * 1000;
const int MAX_S = 300 * 1000;
const int MIN_E = 1000;
const int MAX_N = MAX_SEQ_SIZE;
const int MAX_M = MAX_SEQ_SIZE;
static int solve(const int nn, const int ss, const int ee, const int* arrA,
                 const set<pair<int, int> >& num2bi) {
  static int dp[(MAX_S / MIN_E) + 2];
  const int act_num = (ss / ee);
  int bucks = 0;
  const set<pair<int, int> >::const_iterator n2bi_e = num2bi.end();
  for (int a_ind = 1; a_ind <= nn; ++a_ind) {
    const int the_number = arrA[a_ind];
    pair<int, int> n2bi_pair(the_number, 0);
    for (int action_index = act_num, profit = act_num + 1; profit > 0;
         --profit, --action_index) {
      const int dp_curr = dp[action_index];
      if (!dp_curr && action_index) continue;
      n2bi_pair.second = dp_curr;
      const set<pair<int, int> >::const_iterator n2bi_it =
          num2bi.upper_bound(n2bi_pair);
      if (n2bi_it == n2bi_e || n2bi_it->first != the_number) continue;
      const int b_ind = n2bi_it->second;
      if ((profit * ee) + a_ind + b_ind <= ss) bucks = max(bucks, profit);
      int& dp_prev = dp[profit];
      if (dp_prev == 0 || dp_prev > b_ind) dp_prev = b_ind;
    }
  }
  return bucks;
}
int main(void) {
  std::ios_base::sync_with_stdio(false);
  using std::cin;
  using std::cout;
  if (!cin.good()) return 1;
  int N, M, S, E;
  cin >> N >> M >> S >> E;
  static int arrA[MAX_N + 1];
  for (int i = 1; i <= N; i++) cin >> arrA[i];
  set<pair<int, int> > num2bi;
  {
    int num;
    for (int i = 1; i <= M; i++) {
      cin >> num;
      num2bi.insert(make_pair(num, i));
    }
  }
  if (!cin.eof() && !cin.good()) return 2;
  const int ans = solve(N, S, E, arrA, num2bi);
  cout << ans << endl;
  return 0;
}
