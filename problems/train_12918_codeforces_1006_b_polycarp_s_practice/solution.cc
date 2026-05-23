#include <bits/stdc++.h>
using namespace std;
int mp[2004], ans[2003], pos[2003];
int main() {
  int n, k, sum = 0, kod = 0;
  scanf("%d%d", &n, &k);
  queue<int> kop;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ans[i]);
    pos[i] = ans[i];
  }
  sort(pos + 1, pos + 1 + n);
  for (int i = n; i >= n - k + 1; i--) mp[pos[i]]++;
  for (int i = 1; i <= n; i++) {
    if (mp[ans[i]]) {
      sum += ans[i];
      mp[ans[i]]--;
      k--;
      if (!k) {
        kop.push(n - kod);
        break;
      }
      kop.push(i - kod);
      kod = i;
    }
  }
  cout << sum << endl;
  while (!kop.empty()) {
    cout << kop.front() << " ";
    kop.pop();
  }
  puts("");
  return 0;
}
