#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, m;
  cin >> n >> k >> m;
  vector<long long int> a(n);
  vector<int> blockLen, blockCity;
  long long int gone = 0, last = 0, consec = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[last];
    if (last == 0 || a[last] == a[last - 1])
      consec++;
    else {
      blockCity.push_back(a[last - 1]);
      blockLen.push_back(consec);
      consec = 1;
    }
    if (consec == k) {
      if (blockLen.size() == 0) {
        consec = 0;
      } else {
        consec = blockLen[blockLen.size() - 1];
        blockLen.pop_back();
        blockCity.pop_back();
      }
      last -= k;
      gone += k * m;
    }
    last++;
  }
  if (consec > 0) {
    blockLen.push_back(consec);
    blockCity.push_back(a[last - 1]);
  }
  for (int i = 0; i < (int)blockLen.size(); i++) {
  }
  long long int nOrig = n;
  n = last;
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  int idLeft = 0, idRight = blockCity.size() - 1;
  while (idRight > idLeft) {
    if (blockCity[idLeft] == blockCity[idRight]) {
      gone += (blockLen[idLeft] + blockLen[idRight]) / k * k * (m - 1);
      if ((blockLen[idLeft] + blockLen[idRight]) % k == 0) {
        idLeft++;
        idRight--;
      } else {
        break;
      }
    } else {
      break;
    }
  }
  if (idLeft == idRight) {
    gone += (m * blockLen[idLeft]) / k * k;
    if ((m * blockLen[idLeft]) % k == 0) {
      gone = nOrig * m;
    }
  }
  cout << nOrig * m - gone << endl;
}
