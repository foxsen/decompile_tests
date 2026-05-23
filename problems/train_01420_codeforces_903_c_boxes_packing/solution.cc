#include <bits/stdc++.h>
using namespace std;
void onlinejuge() {}
int isVowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
bool ranklist(pair<int, int> &p1, pair<int, int> &p2) {
  if (p1.first > p2.first)
    return 1;
  else if (p1.first == p2.first)
    return (p1.second < p2.second);
  else
    return 0;
}
int main() {
  onlinejuge();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  map<int, int> map;
  int t, max = 0;
  cin >> t;
  while (t--) {
    int a;
    cin >> a;
    map[a]++;
    if (max < map[a]) max = map[a];
  }
  cout << max << "\n";
  return 0;
}
