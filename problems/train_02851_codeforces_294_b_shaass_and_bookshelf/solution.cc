#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int ans = INT_MAX;
  vector<int> thickOne, thickTwo;
  int n;
  cin >> n;
  for (int i = (int)(0); i < (int)(n); i++) {
    int a, b;
    cin >> a >> b;
    if (a == 1)
      thickOne.push_back(b);
    else
      thickTwo.push_back(b);
  }
  sort(thickTwo.begin(), thickTwo.end());
  thickTwo.push_back(0);
  reverse(thickTwo.begin(), thickTwo.end());
  sort(thickOne.begin(), thickOne.end());
  thickOne.push_back(0);
  reverse(thickOne.begin(), thickOne.end());
  int widthOne = 0, widthTwo = 0;
  for (int i = (int)(0); i < (int)(thickOne.size()); i++)
    widthOne += thickOne[i];
  for (int i = (int)(0); i < (int)(thickTwo.size()); i++)
    widthTwo += thickTwo[i];
  for (int i = (int)(0); i < (int)(thickOne.size()); i++) {
    widthOne -= thickOne[i];
    int curr = widthTwo;
    for (int j = (int)(0); j < (int)(thickTwo.size()); j++) {
      curr -= thickTwo[j];
      int abhiThick = i + 2 * j;
      if (widthOne + curr <= abhiThick) ans = min(ans, abhiThick);
    }
  }
  cout << ans << endl;
  return 0;
}
