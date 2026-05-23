#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

vector<int> v[101010];
ll a[101010];
ll mi;
ll ans;

void init(int x,int p){
    for(auto to:v[x]){
        if(to==p)continue;
        init(to,x);
        a[x]+=a[to];
    }
}
void dfs(int x,int p){
    mi = min(mi,a[x]);
    ans += a[x];
    for(auto to:v[x]){
        if(to==p)continue;
        a[to]+=a[x];
        dfs(to,x);
    }
}



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    rep(i,n)cin>>a[i];
    rep(i,n){
        int x;cin>>x;
        a[i]=-x+a[i];
    }
    init(0,-1);
    dfs(0,-1);
    cout<<ans+n*-mi<<endl;
    
    return 0;
}
