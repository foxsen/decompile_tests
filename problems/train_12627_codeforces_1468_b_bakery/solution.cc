#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson lc[rt], l, mid
#define rson rc[rt], mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 2e5 + 5;
const int lim = 1e9 + 7;
const int inf = 0x3f3f3f3f;
int mx[maxn*32], lc[maxn*32], rc[maxn*32], tot = 0, root = 0;
void update(int &rt, int l, int r, int pos, int val){
    if(!rt){
        rt = ++tot;
    }
    if(l == r){
        mx[rt] = max(mx[rt], val); return;
    }
    if(pos <= mid) update(lson, pos, val);
    else update(rson, pos, val);
    mx[rt] = max(mx[lc[rt]], mx[rc[rt]]);
    return;
}
int qry(int rt, int l, int r, int L, int R){
    if(!rt) return 0;
    if(L <= l && r <= R) return mx[rt];
    int res = 0;
    if(L <= mid) res = max(res, qry(lson, L, R));
    if(R > mid) res = max(res, qry(rson, L, R));
    return res;
}
int n, m;
int a[maxn];
ll s[maxn], key[maxn];
bool check(int x, int i){
    int pos = qry(root, 1, lim, 1, x);
    ll val = s[pos] + (ll)(i-pos)*x;
    return val >= s[i];
}
int ask[maxn], ans[maxn];
#define P pair<int,int>
vector<P> fuck;
set<int> mp;
int main()
{
    cin>>n>>m;
    fors(i,1,n+1) scanf("%d", &a[i]), s[i] = s[i-1] + a[i];
    fors(i,1,m+1) scanf("%d", &ask[i]);
    if(n==1){
        fors(i,1,m+1) printf("0 "); return 0;
    }
    update(root, 1, lim, 1, 0);
    fors(i,1,n){
        int l = 1, r = lim;
        while(l <= r){
            if(check(mid, i)) key[i] = mid, r = mid-1;
            else l = mid+1;
        }
        update(root, 1, lim, key[i], i);
        //cout<<"i:"<<i<<" key:"<<key[i]<<endl;
        fuck.pb(P(key[i], i));
    }
    sort(fuck.begin(), fuck.end());
    int cur = 0;
    fors(i,0,n+1) mp.insert(i);
    int p = fuck.size()-1;
    for(int i = m; i >= 1; --i){
        while(p >= 0 && fuck[p].first > ask[i]){
            int x = fuck[p].second;
            auto it = mp.lower_bound(x);
            auto ip = it;
            int l = *(--it), r = *(++ip);
            cur = max(r-l-1, cur); mp.erase(x);
            p--;
        }
        ans[i] = cur;
    }
    fors(i,1,m+1) printf("%d ", ans[i]);
	return 0;
}
