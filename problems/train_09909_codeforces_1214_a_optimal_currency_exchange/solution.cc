#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long d, e;
  cin >> d >> e;
  long long mini = n;
  long long money = n;
  long long noOfEuroes = 0;
  long long noOfDollors = 0;
  while (1) {
    money -= (noOfEuroes * e);
    if (money < 0) break;
    noOfDollors = money / d;
    money -= (noOfDollors * d);
    if (money < 0) break;
    mini = min(mini, money);
    noOfEuroes += 5;
    money = n;
  }
  cout << mini;
  return 0;
}
