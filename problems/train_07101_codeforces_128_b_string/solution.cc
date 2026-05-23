#include <bits/stdc++.h>
using namespace std;
string s;
struct compare {
  bool operator()(pair<int, int> a, pair<int, int> b) const {
    int l1 = a.second - a.first, l2 = b.second - b.first;
    if (l1 == l2) return s[a.second - 1] < s[b.second - 1];
    if (l1 + 2 <= l2) return false;
    if (l2 + 2 <= l1) return true;
    if (l1 > l2)
      if (s[a.second - 2] == s[b.second - 1])
        return false;
      else
        return s[a.second - 2] < s[b.second - 1];
    if (l2 > l1)
      if (s[a.second - 1] == s[b.second - 2])
        return true;
      else
        return s[a.second - 1] < s[b.second - 2];
  }
};
multiset<pair<int, int>, compare> Se;
int main() {
  cin >> s;
  long long k;
  cin >> k;
  for (int i = 0; i < (int)s.length(); i++) Se.insert(pair<int, int>(i, i + 1));
  long long len = (long long)s.length();
  if (k > len * (len + 1ll) / 2ll) {
    cout << "No such line." << endl;
    return 0;
  }
  for (int i = 0; i < k; i++) {
    pair<int, int> P = *(Se.begin());
    Se.erase(Se.begin());
    if (i == k - 1) {
      for (int j = P.first; j < P.second; j++) cout << s[j];
      cout << endl;
    }
    P.second++;
    if (P.second <= (int)s.length()) Se.insert(P);
  }
  return 0;
}
