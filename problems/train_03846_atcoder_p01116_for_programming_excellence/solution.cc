#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

int n,k;
int h[125252], s[125252], p[125252], l[125252];
int m[125];
int children[125][125];

ll arr[125][125252];
ll beg[125252];

ll tmp[125252];

int di[125252];
ll dv[125252];

void lk(int w, ll *v, ll a, ll n, ll *ret){
  REP(i,w+1)ret[i] = v[i];
  int s = 0, t = 0;
  REP(i,w+1){
    ll v = ret[i] - i*a;
    while(s<t && dv[t-1] <= v)t--;
    di[t] = i;
    dv[t] = v;
    t++;
    ret[i] = dv[s] + i*a;
    if(di[s] == i-n)s++;
  }
}

void dfs(int p, int w, ll *iv){
  // use s[p], max h[p]
  lk(w, iv, s[p], h[p], arr[p]);
  // children
  REP(i,m[p]){
    int c = children[p][i];
    dfs(c, w-l[c], iv);
    iv = arr[c];
    ll adv = (ll)l[c] * s[p];
    lk(w, iv, s[p], h[p]-l[c], tmp);
    REP(i,w+1-l[c])CHMAX(arr[p][i+l[c]], tmp[i]+adv);
  }
}

int main(){
  while(true){
    scanf("%d%d", &n, &k);
    if(n==0 && k==0)break;
    REP(i,n)scanf("%d",h+i);
    REP(i,n)scanf("%d",s+i);
    FOR(i,1,n)scanf("%d",p+i), p[i]--;
    FOR(i,1,n)scanf("%d",l+i);
    REP(i,n)m[i] = 0;
    FOR(i,1,n)children[p[i]][m[p[i]]++] = i;
    REP(i,n)sort(children[i], children[i]+m[i], [&](int a,int b){
      return l[a] < l[b];
    });
    dfs(0, k, beg);
    printf("%lld\n", arr[0][k]);
  }
  return 0;
}

