#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int n) {
  long long int res = 1;
  while (n > 0) {
    if (n & 1)
      res = ((res % 1000000007) * (a % 1000000007)) % 1000000007, n--;
    else
      a = ((a % 1000000007) * (a % 1000000007)) % 1000000007, n /= 2;
  }
  return res;
}
bool is_substring(string s1, string s2) {
  long long int l1 = s1.size();
  long long int l2 = s2.size();
  if (l2 > l1) return false;
  for (long long int i = 0; i < l1 - l2; i++) {
    string sub = s1.substr(i, i + l2);
    if (sub == s2) {
      return true;
    }
  }
  return false;
}
bool is_subsequence(string s1, string s2) {
  long long int l1 = s1.size();
  long long int l2 = s2.size();
  if (l2 > l1) return false;
  long long int i = 0, j = 0;
  while (i < l1 && j < l2) {
    if (s1[i] == s2[j]) j++;
    i++;
  }
  if (j == l2)
    return true;
  else
    return false;
}
void solve() {
  string s1, s2;
  cin >> s1 >> s2;
  string s3 = s1, s4 = s2;
  if (is_subsequence(s1, s2))
    cout << "automaton";
  else {
    sort(s3.begin(), s3.end());
    sort(s4.begin(), s4.end());
    if (s3 == s4)
      cout << "array";
    else {
      if (s1.size() >= s2.size()) {
        long long int cnt = 0;
        map<char, long long int> mp1, mp2;
        for (long long int i = 0; i < s1.size(); i++) mp1[s1[i]]++;
        for (char c : s2) mp2[c]++;
        for (auto i : mp2) {
          if (mp2[i.first] > mp1[i.first]) cnt++;
        }
        if (cnt == 0)
          cout << "both";
        else
          cout << "need tree";
      } else
        cout << "need tree";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    solve();
  }
}
