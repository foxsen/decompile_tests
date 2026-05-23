#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int shell_length;
  long long int wallet_length;
  cin >> shell_length >> wallet_length;
  std::vector<long long int> vct(shell_length);
  for (long long int &i : vct) cin >> i;
  std::deque<long long int> wallet;
  while (wallet_length--) {
    long long int tmp;
    cin >> tmp;
    wallet.push_back(tmp);
  };
  long long int out = 0;
  for (long long int i : vct) {
    if (wallet.front() >= i) {
      out++;
      wallet.pop_front();
    }
    if (!wallet.size()) break;
  };
  std::cout << out;
}
