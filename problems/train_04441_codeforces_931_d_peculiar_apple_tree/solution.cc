#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> neighbors;
vector<int> appleSteps;
void dfs(int index, int steps) {
  appleSteps[steps]++;
  for (int i = 0; i < neighbors[index].size(); i++) {
    int neighborIndex = neighbors[index][i];
    dfs(neighborIndex, steps + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  appleSteps.resize(n + 1);
  neighbors.resize(n + 1);
  for (int i = 1; i < n; i++) {
    int input;
    cin >> input;
    input--;
    neighbors[input].push_back(i);
  }
  dfs(0, 0);
  int result = 0;
  for (int i = 0; i < appleSteps.size(); i++) {
    if (appleSteps[i] % 2 == 1) {
      result++;
    }
  }
  cout << result;
  return 0;
}
