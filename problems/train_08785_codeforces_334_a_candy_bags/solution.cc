#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int len = pow(n, 2);
  vector<int> akash;
  for (int i = 1; i <= len; i++) {
    akash.push_back(i);
  }
  for (int i = 0; i < n; i++) {
    int temp1 = n / 2;
    while (temp1--) {
      long int index = akash.size() - 1;
      cout << akash[0] << " " << akash[index] << " ";
      akash.erase(akash.begin());
      akash.erase(akash.begin() + index - 1);
    }
    cout << endl;
  }
  return 0;
}
