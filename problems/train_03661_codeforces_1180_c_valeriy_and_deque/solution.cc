#include <bits/stdc++.h>
const long long int INF = (long long int)1e9;
const double EPS = 0.000000000001;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long int n, q;
  cin >> n >> q;
  deque<long long int> deq;
  long long int max_n = -1;
  for (long long int i = 0; i < n; ++i) {
    long long int temp;
    cin >> temp;
    max_n = max(max_n, temp);
    deq.push_back(temp);
  }
  vector<pair<long long int, long long int> > operations_prev;
  while (deq.front() != max_n) {
    long long int a, b;
    a = deq.front();
    deq.pop_front();
    b = deq.front();
    deq.pop_front();
    operations_prev.push_back({a, b});
    if (a > b) {
      deq.push_front(a);
      deq.push_back(b);
    } else {
      deq.push_front(b);
      deq.push_back(a);
    }
  }
  vector<long long int> arr(n - 1);
  deq.pop_front();
  for (long long int i = 0; i < n - 1; ++i) {
    arr[i] = deq.front();
    deq.pop_front();
  }
  for (long long int i = 0; i < q; ++i) {
    long long int temp;
    cin >> temp;
    if (temp <= operations_prev.size()) {
      cout << operations_prev[temp - 1].first << ' '
           << operations_prev[temp - 1].second << '\n';
    } else {
      temp -= operations_prev.size() + 1;
      temp = (temp % (n - 1));
      cout << max_n << ' ' << arr[temp] << '\n';
    }
  }
}
