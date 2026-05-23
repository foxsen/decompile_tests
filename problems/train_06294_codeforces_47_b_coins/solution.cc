#include <bits/stdc++.h>
using namespace std;
int main() {
  string result;
  vector<int> weights_points(3, 0);
  for (int i = 0; i < 3; ++i) {
    cin >> result;
    if (result[1] == '>')
      ++weights_points[result[0] - 'A'];
    else if (result[1] == '<')
      ++weights_points[result[2] - 'A'];
  }
  if (weights_points[0] == weights_points[1] &&
      weights_points[0] == weights_points[2])
    cout << "Impossible\n";
  else {
    string output;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j)
        if (weights_points[j] == i) cout << (char)('A' + j);
    }
  }
  return 0;
}
