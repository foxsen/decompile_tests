#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int copies, original;
  cin >> copies >> original;
  if (copies == 0 && original == 1) {
    cout << "Yes" << endl;
    exit(0);
  }
  if (copies >= original - 1) {
    if ((copies - original + 1) % 2 == 0 && original > 1) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    cout << "No" << endl;
  }
  return 0;
}
