#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long dim = 200000, sum = 0;
  int bin[400000] = {0};
  while (n > 0) {
    bin[dim] = n % 2;
    sum += bin[dim];
    n = n / 2;
    dim++;
  }
  dim--;
  if (sum > k) {
    cout << "No" << endl;
  } else {
    int q = k - sum;
    while (!bin[dim] && dim >= 0) {
      dim--;
    }
    while (bin[dim] <= q) {
      bin[dim - 1] += 2 * bin[dim];
      q -= bin[dim];
      bin[dim] = 0;
      while (!bin[dim] && dim >= 0) {
        dim--;
      }
    }
    int i;
    for (i = 0; i < 400000; i++) {
      if (bin[i] != 0) {
        break;
      }
    }
    while (q) {
      bin[i]--;
      bin[i - 1] += 2;
      i--;
      q--;
    }
    cout << "Yes" << endl;
    for (int i = dim; i >= 0; i--) {
      while (bin[i]--) {
        cout << i - 200000 << " ";
      }
    }
  }
  return 0;
}
