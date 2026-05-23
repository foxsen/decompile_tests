#include <bits/stdc++.h>
using namespace std;
vector<int> LP(const string& S, const string& T) {
  const int M = int((T).size());
  vector<int> last_pos_in_T(26, 0);
  const int N = int((S).size());
  vector<int> res(N, -1);
  for (int i = 0, j = 0; i < N; ++i) {
    int ch_id = S[i] - 'a';
    if (j < M && S[i] == T[j]) {
      res[i] = ++j;
      last_pos_in_T[ch_id] = j;
    } else {
      res[i] = last_pos_in_T[ch_id];
    }
  }
  return res;
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string S, T;
  cin >> S;
  cin >> T;
  vector<int> L = LP(S, T);
  reverse(S.begin(), S.end());
  reverse(T.begin(), T.end());
  vector<int> R = LP(S, T);
  reverse(R.begin(), R.end());
  for (int& x : R) x = int((T).size()) - x + 1;
  bool ok = true;
  for (int i = 0; i < int((S).size()); ++i) {
    if (L[i] < 0 || R[i] < 0 || L[i] < R[i]) {
      ok = false;
      break;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
