#include <bits/stdc++.h>
using namespace std;
int main() {
  int cap_first[1010], marker_first[1010];
  int n, m;
  memset(cap_first, 0, sizeof(cap_first));
  memset(marker_first, 0, sizeof(marker_first));
  vector<vector<int> > cap_sec(1010, vector<int>(0));
  vector<vector<int> > marker_sec(1010, vector<int>(0));
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int temp1, temp2;
    cin >> temp1 >> temp2;
    marker_first[temp2]++;
    marker_sec[temp2].push_back(temp1);
  }
  for (int i = 0; i < m; i++) {
    int temp1, temp2;
    cin >> temp1 >> temp2;
    cap_first[temp2]++;
    cap_sec[temp2].push_back(temp1);
  }
  int fir_ans = 0;
  for (int i = 0; i < 1001; i++) {
    fir_ans += min(cap_first[i], marker_first[i]);
  }
  int sec_ans = 0;
  for (int i = 1; i < 1001; i++) {
    if ((cap_sec[i].empty()) || (marker_sec[i].empty())) {
      continue;
    }
    sort(marker_sec[i].begin(), marker_sec[i].end());
    sort(cap_sec[i].begin(), cap_sec[i].end());
    int marker_len = marker_sec[i].size();
    int cap_len = cap_sec[i].size();
    for (int j = 0, k = 0; (j < marker_len) && (k < cap_len);) {
      if (marker_sec[i][j] == cap_sec[i][k]) {
        sec_ans++;
        j++;
        k++;
      } else if (marker_sec[i][j] < cap_sec[i][k]) {
        j++;
      } else {
        k++;
      }
    }
  }
  cout << fir_ans << " " << sec_ans << "\n";
  return 0;
}
