#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string wrd;
    cin >> wrd;
    int arr[200] = {};
    for (int i = 0; i < s.size(); i++) {
      arr[s[i]] = i;
    }
    int time = 0;
    for (int i = 1; i < wrd.length(); i++) {
      time += abs(arr[wrd[i]] - arr[wrd[i - 1]]);
    }
    cout << time << endl;
  }
}
