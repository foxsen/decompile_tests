#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <cstdio>
using namespace std;

ll floor_sum(ll n,ll m,ll a,ll b){
  ll ans=0;
  if(a>=m){
    ans+=(n-1)*n*(a/m)/2;
    a%=m;
  }
  if(b>=m){
    ans+=n*(b/m);
    b%=m;
  }

  ll y_max=(a*n+b)/m;
  if(y_max==0) return ans;
  ans+=floor_sum(y_max,a,m,a*n-y_max*m+b);
  return ans;
}

int main(){
  int t;
  scanf("%d",&t);
  
  while(t--){
    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    printf("%lld\n",floor_sum(n,m,a,b));
  }
  
  return 0;
}