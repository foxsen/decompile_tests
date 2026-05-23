#include <bits/stdc++.h>
using namespace std;
int main() {
  int celulas, destino;
  cin >> celulas >> destino;
  int YES = -1;
  int vet[40000];
  for (int i = 1; i < celulas; i++) {
    cin >> vet[i];
  }
  for (int i = 1; i < celulas;) {
    i = vet[i] + i;
    if (i == destino) {
      YES = 1;
      break;
    }
  }
  if (YES == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
