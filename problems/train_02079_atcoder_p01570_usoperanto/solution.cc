#include<bits/stdc++.h>  
using namespace std;  
typedef long long LL;  
#define pll pair<LL, LL>  
#define pii pair<int, int>  
#define X first  
#define Y second  
#define MAXN 1000010//1e3  
#define lson l, mid, (rt << 1)  
#define rson mid + 1, r, (rt << 1 | 1)  
const double eps = 1e-10;  
int n;  
vector<int> root, edge[MAXN];  
LL value[MAXN], cost[MAXN];  
bool cmp(int i, int j) {  
    return value[i] < value[j];  
}  
void init() {  
    root.clear();  
    for(int i = 0; i <= n; i++) {  
        edge[i].clear();  
        cost[i] = -1;  
    }  
}  
void solve(int rt) {  
    queue<int> q;  
    stack<int> s;  
    q.push(rt); s.push(rt);  
    while(!q.empty()) {  
        int tmp = q.front();  
        q.pop();  
        int len = edge[tmp].size();  
        for(int i = 0; i < len; i++) {  
            q.push(edge[tmp][i]);  
            s.push(edge[tmp][i]);  
        }  
    }  
    while(!s.empty()) {  
        int tmp = s.top();  
        s.pop();  
        sort(edge[tmp].begin(), edge[tmp].end(), cmp);  
        int len = edge[tmp].size();  
        cost[tmp] = 0LL;  
        LL res = 0;  
        for(int i = 0; i < len; i++) {  
            cost[tmp] += res + cost[edge[tmp][i]];  
            res += value[edge[tmp][i]];  
        }  
        value[tmp] += res;  
    }  
}  
int main() {  
    while(~scanf("%d", &n)) {  
        init();  
        int x;  
        for(int i = 0; i < n; i++) {  
            scanf("%lld%d", &value[i], &x);  
            if(x == -1) root.push_back(i);  
            else edge[x].push_back(i);  
        }  
        int len = root.size();  
        LL ans = 0;  
        for(int i = 0; i < len; i++) {  
            solve(root[i]);  
            ans += cost[root[i]];  
        }  
        printf("%lld\n", ans);  
    }  
    return 0;  
}  