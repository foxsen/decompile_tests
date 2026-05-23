#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int m;
  cin >> n >> m;
  vector<int> price(n);
  for (int i = 0; i < n; ++i) {
    cin >> price[i];
  }
  sort(price.begin(), price.end());
  map<string, int> fruit;
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    ++fruit[s];
  }
  vector<int> sum_fruit;
  for (map<string, int>::iterator it = fruit.begin(); it != fruit.end(); ++it) {
    sum_fruit.push_back(it->second);
  }
  sort(sum_fruit.begin(), sum_fruit.end());
  int min = 0;
  int q = fruit.size() - 1;
  for (int i = 0; i < fruit.size(); ++i) {
    min += price[i] * sum_fruit[q];
    --q;
  }
  int max = 0;
  int l = n - 1;
  for (int i = fruit.size() - 1; i >= 0; --i) {
    max += sum_fruit[i] * price[l];
    --l;
  }
  cout << min << " " << max << endl;
}
