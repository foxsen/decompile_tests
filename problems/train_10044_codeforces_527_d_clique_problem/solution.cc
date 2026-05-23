#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  pair<int, int> arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    cin >> arr[i].second;
  }
  sort(arr, arr + n);
  int size = 1;
  int co = arr[0].first;
  int we = arr[0].second;
  long long val = co + we;
  priority_queue<long long> pq;
  pq.push(val);
  for (int i = 1; i < n; i++) {
    long long a = arr[i].first - arr[i].second,
              b = arr[i].first + arr[i].second;
    if (a >= pq.top()) {
      pq.push(b);
    } else {
      long long c = pq.top();
      pq.pop();
      if (pq.empty()) {
        if (c < b)
          pq.push(c);
        else
          pq.push(b);
      } else {
        if (b < c && a >= pq.top()) {
          pq.push(b);
        } else
          pq.push(c);
      }
    }
  }
  cout << pq.size() << endl;
  return 0;
}
