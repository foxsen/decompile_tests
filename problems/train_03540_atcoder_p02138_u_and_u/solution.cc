#include <iostream>
using namespace std;
int main(){
  long long N, M;
  cin >> N >> M;
  long long N_ = N, M_ = M;
  //  if(N > 2*M || M > 2*N){
  //cout << 0 << endl;
  //return 0;
  //}
  int ans = 0;
  long long n = 2*N, m = 2*M;
  while(n > 0 && m > 0){
    m -= N;
    if(m <= 0) break;
    ++ans;
    M = min(m,M);
    n -= M;
    if(n <= 0) break;
    ++ans;
    N = (n+1)/2;
  }
  int ans2 = 0;
  N = N_;
  M = M_;
  n = 2*N;
  m = 2*M;
  while(n > 0 && m > 0){
    m -= N;
    if(m <= 0) break;
    ++ans2;
    M = (m+1)/2;
    n -= M;
    if(n <= 0) break;
    ++ans2;
    N = min(n,N);
  }
  cout << min(ans,ans2) << endl;
  return 0;
}

