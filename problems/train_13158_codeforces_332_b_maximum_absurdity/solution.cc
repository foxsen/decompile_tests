#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, temp, idx = 0;
  long long sum = 0;
  cin >> n >> k;
  vector<long long> s;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);
    sum += temp;
    if ((i + 1) >= k) {
      s.push_back(sum);
      sum -= v[idx++];
    }
  }
  int l = s.size();
  vector<long long> Max(l);
  vector<int> pos(l);
  Max[l - 1] = s[l - 1];
  pos[l - 1] = l - 1;
  for (int i = l - 2; i >= 0; i--) {
    if (s[i] >= Max[i + 1]) {
      Max[i] = s[i];
      pos[i] = i;
    } else {
      Max[i] = Max[i + 1];
      pos[i] = pos[i + 1];
    }
  }
  long long MAX = -1;
  for (int i = 0; i < s.size() - k; i++)
    if (s[i] + Max[i + k] > MAX) MAX = s[i] + Max[i + k];
  for (int i = 0; i < s.size() - k; i++)
    if (s[i] + Max[i + k] == MAX) {
      cout << (i + 1) << " " << (pos[i + k] + 1) << endl;
      break;
    }
}
