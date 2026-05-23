#include <iostream>
#include <vector>
using namespace std;
constexpr long long int Mod = 1e9 + 7;

vector< vector<long long int> > matrix_product(vector< vector<long long int> > &A, vector< vector<long long int> > &B){
  int n = A.size(), m = B[0].size(), l = A[0].size();
  vector< vector<long long int> > ret(n,vector<long long int>(m, 0));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      for(int k = 0; k < l; ++k){
        ret[i][j] += (A[i][k]*B[k][j])%Mod;
        ret[i][j] %= Mod;
      }
    }
  }
  return ret;
}

vector< vector<long long int> > matrix_pow(const vector< vector<long long int> > &P, long long int N){
  vector< vector<long long int> > ret(P.size(),vector<long long int>(P.size(),0LL)), t = P;
  for(int i = 0; i < P.size(); ++i) ret[i][i] = 1LL;
  int k = 0;
  while((1LL<<k) <= N){
    if((N>>k)&1){
      ret = matrix_product(ret,t);
    }
    ++k;
    t = matrix_product(t,t);
  }
  return ret;
}

long long int Fibonacci(long long int t){
  vector< vector<long long int> > A(2, vector<long long int>(2, 1LL));
  A[1][1] = 0LL;
  vector< vector<long long int> > F(1, vector<long long int>(2, 1LL)), A_ = matrix_pow(A, t);
  F[0][1] = 0LL;
  return matrix_product(F, A_)[0][0]%Mod;
}

int main(){
  long long int K;
  cin >> K;
  long long int ok = -1, ng = 2e9;
  while(ng - ok > 1){
    long long int m = (ok + ng)/2;
    if((m/2)*(m/2+1) + (m%2)*(m/2+1) < K) ok = m;
    else ng = m;
  }
  //cout << "ok = " << ok << endl;
  long long int d = K - (ok/2)*(ok/2+1) - (ok%2)*(ok/2+1), x = ok + 3 - 2*d, y = 2*d - 1;
  //cout << "x, y = (" << x << ", " << y << ")" << endl;
  if((ok+1)%2 && x < y){
    x += 1;
    y -= 1;
  }
  //cout << "x, y = (" << x << ", " << y << ")" << endl;
  cout << (Fibonacci(x)*Fibonacci(y))%Mod << endl;
  return 0;
}


