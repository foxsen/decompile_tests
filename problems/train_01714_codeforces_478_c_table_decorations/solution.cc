#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t(0), mas[3];
  for (int i = 0; i < 3; i++) cin >> mas[i];
  sort(mas, mas + 3);
  if ((mas[0] + mas[1]) <= mas[2] / 2) {
    t = mas[0] + mas[1];
  } else {
    t = (mas[1] + mas[2] + mas[0]) / 3;
  }
  cout << t;
  return 0;
}
