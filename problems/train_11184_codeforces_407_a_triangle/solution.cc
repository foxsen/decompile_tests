#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1e5 + 5;
const int INF = (int)1e9 + 7;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int main() {
  int a, b, c, s1, s2, s3, s4;
  s1 = s2 = s3 = s4 = 0;
  vector<pair<int, int> > vec1, vec2;
  cin >> a >> b;
  c = a * a + b * b;
  for (int i = 1; i < a; i++)
    for (int j = 1; j < a; j++)
      if (i * i + j * j == a * a) {
        vec1.push_back({i, j});
      }
  for (int i = 1; i < b; i++)
    for (int j = 1; j < b; j++)
      if (i * i + j * j == b * b) {
        vec2.push_back({i, j});
      }
  if ((int)vec1.size() == 0 or (int) vec2.size() == 0) {
    cout << "NO"
         << "\n";
  } else {
    for (int i = 0; i < (int)vec1.size(); i++) {
      s1 = vec1[i].first;
      s2 = vec1[i].second;
      for (int j = 0; j < (int)vec2.size(); j++) {
        s3 = vec2[j].first;
        s4 = vec2[j].second;
        if (c == (s1 + s3) * (s1 + s3) + (s2 - s4) * (s2 - s4) and s2 != s4) {
          cout << "YES\n0 0"
               << "\n";
          cout << s1 << ' ' << s2 << "\n";
          cout << -1 * s3 << ' ' << s4 << "\n";
          return 0;
        }
      }
    }
    cout << "NO"
         << "\n";
  }
  return 0;
}
