#include <bits/stdc++.h>
using namespace std;
long long int N, M, K;
int main(void) {
  cin >> N >> M >> K;
  if (K > N) {
    long long int Sol = 1LL;
    for (int i = 0; i < N; i++) Sol = (Sol * M) % 1000000007LL;
    cout << Sol << endl;
    return 0;
  }
  if (K == N) {
    long long int Sol = 1LL;
    for (int i = 0; i < (N + 1) / 2; i++) Sol = (Sol * M) % 1000000007LL;
    cout << Sol << endl;
    return 0;
  }
  if (K == 1) {
    long long int Sol = 1LL;
    for (int i = 0; i < N; i++) Sol = (Sol * M) % 1000000007LL;
    cout << Sol << endl;
    return 0;
  }
  if (K % 2 == 1) {
    cout << (M * M) % 1000000007LL << endl;
    return 0;
  }
  cout << M << endl;
  return 0;
}
