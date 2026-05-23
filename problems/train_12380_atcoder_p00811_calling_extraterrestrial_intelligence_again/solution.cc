#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> make_prime(int N){
  bool p[N+1];
  memset(p, true, sizeof(p));
  p[0] = p[1] = false;
  for(int i = 0 ; i*i < N ; i++){
    if(p[i]){
      for(int j = 2*i ; j < N ; j += i){
	p[j] = false;
      }
    }
  }
  vector<int> ret;
  for(int i = 0 ; i <= N ; i++){
    if(p[i]) ret.push_back(i);
  }
  return ret;
}
 
int main(){
  vector<int> prime = make_prime(100000);
  int m, a, b;
  while(cin >> m >> a >> b, m|a|b){
    double a_b = (double)a / (double)b;
    int max_p = 0;
    int ans1, ans2;
    for(int i = 0 ; i < prime.size() ; i++){
      if(prime[i]*prime[i] > m) break;
      for(int j = i ; j < prime.size() ; j++){
	int M = prime[i]*prime[j];
	if(M > m) break;
	if( (M <= m) && (a_b <= (double)prime[i] / (double)prime[j]) ){
	  if(max_p <= M){
	    max_p = M;
	    ans1 = prime[i], ans2 = prime[j];
	  }
	}
      }
    }
    cout << ans1 << ' ' << ans2 << endl;
  }

  return 0;
}