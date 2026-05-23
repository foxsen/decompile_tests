#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,L;
  cin >> N >>L;
  if(L-1>=0)
    cout << (L-1)*(N-1)+(N+2)*(N-1)/2;
  else if(L+N-1<=0)
    cout << (L-1)*(N-1)+N*(N-1)/2;
  else
    cout << (L-1)*N+N*(N+1)/2;
}