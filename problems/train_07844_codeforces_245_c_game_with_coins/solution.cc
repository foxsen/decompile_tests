#include <bits/stdc++.h>
using namespace std;
int vet[101];
int N, res;
int main(void) {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> vet[i + 1];
  for (int i = N; i >= 1; i--)
    if (vet[i] != 0) {
      if (i != 1 && (i / 2) * 2 + 1 <= N) {
        int p = i / 2;
        int h = vet[i];
        vet[p] = max(0, vet[p] - h);
        vet[p * 2] = max(0, vet[p * 2] - h);
        vet[p * 2 + 1] = max(0, vet[p * 2 + 1] - h);
        res += h;
      } else if (i * 2 + 1 > N) {
        cout << -1;
        return 0;
      } else
        res += vet[i];
    }
  cout << res;
  return 0;
}
