#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int LM = 1e5 + 4;
const ll INF = 1e18;

struct Data{
    int a, ac;
    int idx;
}arr[LM];

int N;
ll dp[LM];

ll tree1[LM<<1];
ll tree2[LM<<1];
void update(ll tree[], int i, ll v){
    for(tree[i+=N-1]=v;i>1;i>>=1) tree[i>>1] = min(tree[i], tree[i^1]);
}
ll get(ll tree[], int l, int r){
    ll result = INF;
    for(l+=N-1,r+=N;l<r;l>>=1,r>>=1){
        if(l&1) result = min(tree[l++], result);
        if(r&1) result = min(result, tree[--r]);
    }
    return result;
}

int main(){
    vector<int> v;
    ll ans = 0;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        int a, c;
        scanf("%d%d", &a, &c);
        arr[i] = {a, a+c, i};
        ans += c;
    }
    sort(arr+1, arr+N+1, [&](Data p, Data q){
        return p.a < q.a;
    });
    for(int i=1;i<=N;i++) v.push_back(arr[i].a);

    for(int i=1;i<=N*2;i++) tree1[i] = tree2[i] = INF;
    dp[N] = 0;
    update(tree1, N, 0);
    update(tree2, N, arr[N].a);
    for(int i=N-1;i>=1;i--){
        auto it = upper_bound(v.begin() + i, v.end(), arr[i].ac);
        int eeee = -1;
        if(it != v.end()) eeee = it - v.begin() + 1;

        if(eeee == -1){
            dp[i] = get(tree1, i+1, N);
        }
        else{
            dp[i] = min(get(tree1, i+1, eeee - 1), get(tree2, eeee, N) - arr[i].ac);
        }
        update(tree1, i, dp[i]);
        update(tree2, i, dp[i]+arr[i].a);
    }
    printf("%lld\n", dp[1] + ans);
    return 0;
}
