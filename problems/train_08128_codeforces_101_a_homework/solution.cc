#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int K;
  cin >> K;
  vector<pair<int, char> > freq(26);
  for (int i = 0; i < int(26); ++i) freq[i].second = char(i + 'a');
  for (__typeof((S).begin()) it = (S).begin(); it != (S).end(); ++it)
    ++freq[*it - 'a'].first;
  sort(freq.begin(), freq.end());
  int omit = 0;
  while (omit < 26 && K >= freq[omit].first) K -= freq[omit++].first;
  cout << 26 - omit << endl;
  for (__typeof((S).begin()) it = (S).begin(); it != (S).end(); ++it) {
    bool omitted = false;
    for (int n = 0; n < int(omit); ++n)
      if (freq[n].second == *it) omitted = true;
    if (!omitted) cout << *it;
  }
  cout << endl;
}
