#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int numberOfChocolates;
  cin >> numberOfChocolates;
  int A[numberOfChocolates];
  for (int i = 0; i < numberOfChocolates; i++) {
    cin >> A[i];
  }
  if (numberOfChocolates == 1) {
    cout << 1 << endl << 0;
    return 0;
  }
  if (numberOfChocolates == 2) {
    cout << 1 << endl << 1;
    return 0;
  }
  int CounterAlis = 1;
  int CounterBob = 1;
  int SumAlis = A[0];
  int SumBob = A[numberOfChocolates - 1];
  int Comparer = numberOfChocolates;
  numberOfChocolates -= 2;
  for (;;) {
    if (numberOfChocolates == 0) break;
    if (SumAlis > SumBob) {
      SumBob += A[Comparer - CounterBob - 1];
      CounterBob++;
      numberOfChocolates--;
    } else if (SumBob > SumAlis) {
      SumAlis += A[CounterAlis];
      CounterAlis++;
      numberOfChocolates--;
    } else if (SumAlis == SumBob && numberOfChocolates > 1) {
      SumBob = A[Comparer - CounterBob - 1];
      SumAlis = A[CounterAlis];
      CounterBob++;
      CounterAlis++;
      numberOfChocolates = numberOfChocolates - 2;
    } else if (SumAlis == SumBob && numberOfChocolates == 1) {
      CounterAlis++;
      numberOfChocolates--;
    }
  }
  cout << CounterAlis << endl << CounterBob << endl;
  return 0;
}
