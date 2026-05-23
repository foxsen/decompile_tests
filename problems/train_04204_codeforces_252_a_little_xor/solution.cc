#include <bits/stdc++.h>
using namespace std;
bool comp(int x, int y) { return x > y; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int tt = 1;
  long long m, n, k;
  string st;
  while (tt--) {
    cin >> n;
    int arr[n];
    for (long long i = 0; i < n; i++) cin >> arr[i];
    vector<int> vec;
    for (long long i = 0; i < n; i++) {
      int mxx = arr[i];
      vec.push_back(mxx);
      for (long long j = i + 1; j < n; j++) {
        mxx = mxx ^ arr[j];
        vec.push_back(mxx);
      }
    }
    sort(vec.begin(), vec.end());
    cout << vec.back() << endl;
  }
}
