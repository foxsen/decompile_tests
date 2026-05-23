#include <iostream>
using namespace std;
 
typedef long long ll;
 
int main() {
  ll n,m,k;
  cin >> n >> m >> k;
  n%=10;
  m%=4;
 
  int a=n,d[4];
  for(int i=0; i<4; i++){
    d[i]=a;
    a=a*n%10;
  }
 
  ll ans=0;
  for(int i=0; i<4; i++) {
    ans+=k/4*d[m*i%4];
    if(i<k%4) ans+=d[m*i%4];
  }
  cout << ans << endl;
  return 0;
}
