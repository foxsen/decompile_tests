#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int N = 1e5;
int nn, value;
long long ar[N];
vector<int> v, cur, nex, lucky;
int main(void) {
  cin >> nn;
  for (int i = 0; i < nn; ++i) cin >> ar[i];
  for (int i = 0; i < nn; ++i) {
    if (ar[i] % 2 == 0)
      cout << ar[i] - 1 << " ";
    else
      cout << ar[i] << " ";
  }
}
