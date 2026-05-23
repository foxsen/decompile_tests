#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
const int MAX = 100010;
int N, M;
typedef pair<int,int> pii;

struct union_find{
    int rnk[MAX], par[MAX], w[MAX];

    union_find(int n){ rep(i,n) rnk[i] = 1, par[i] = i, w[i] = 0;}

    pii weight(int x){
        if(x == par[x]) return pii(x,0);
        pii ret = weight(par[x]);
        return pii((par[x]=ret.first), (w[x]+=ret.second));
    }
    int find(int x){ return weight(x).first;}
    void unite(int a, int b, int k){
        int x = find(a), y = find(b);
        k -= w[b]-w[a];
        if(x == y) return;
        if(rnk[x] > rnk[y]){
            par[y] = x;
            w[y] = k;
        }
        else{
            par[x] = y;
            w[x] = -k;
            if(rnk[x] == rnk[y]) rnk[y]++;
        }
    }
    bool same(int x, int y){ return find(x)==find(y);}
};

void solve(){
    union_find uf(N);
    int a, b, w; char c;
    rep(i,M){
        cin >> c >> a >> b; a--; b--;
        if(c=='!'){
            cin >> w;
            uf.unite(a,b,w);
        }
        else {
            if(!uf.same(a,b)) puts("UNKNOWN");
            else cout << uf.w[b]-uf.w[a] << endl;
        }
    }
}

int main(){
    while(cin >> N >> M, N and M) solve();
    return 0;
}