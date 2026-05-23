#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  int n;
  while (t--) {
    cin >> n;
    vector<pair<pair<long long int, long long int>, int> > Data(n);
    for (int i = 0; i < n; i++) cin >> Data[i].first.first;
    for (int i = 0; i < n; i++) cin >> Data[i].first.second;
    for (int i = 0; i < n; i++) Data[i].second = i;
    sort(Data.begin(), Data.end());
    vector<bool> sol(n, 0);
    sol[Data[n - 1].second] = 1;
    long long int min_ganar_segundo = Data[n - 1].first.second;
    int j = n - 1;
    for (int i = n - 1; i >= 0; i--) {
      if (Data[i].first.second > min_ganar_segundo) {
        for (int k = i; k < j; k++) {
          sol[Data[k].second] = 1;
          min_ganar_segundo = min(min_ganar_segundo, Data[k].first.second);
        }
        j = i;
      }
    }
    for (int i = 0; i < n; i++) cout << sol[i];
    cout << endl;
  }
}
