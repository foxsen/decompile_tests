#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cctype>
#include <stack>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 50005;
const int M = 405;
typedef unsigned long long ULL;
 
int cnt, n;

bool times;

struct Bitset {
    ULL a[M];
    Bitset () {
        memset(a , 0 , sizeof(a));
    }
    Bitset operator & (const Bitset &R) const {
        Bitset res = *this;
        for (int i = 0 ; i < M ; ++ i)
            res.a[i] &= R.a[i];
        return res;
    }
    void set(int x) {
        if (!times) {
            if (x >= 25000)
                return;            
        } else {
            if (x < 25000)
                return;
            x -= 25000;
        }
        a[x >> 6] |= 1ULL << (x & 63);
    }
 
    void Sset() {
        for (int i = 0; i < M; ++i)
            a[i] |= ~0ULL;
    }
 
    int operator == (const Bitset &A) const {
        for (int i = 0; i < M; ++i)
            if (a[i] != A.a[i]) return 0;
        return 1;
    }
 
    int low() {
        for (int i = 0; i < M; ++i) {
            if (a[i] != 0) {
                for (int j = 0; j < 64; ++j)
                    if (a[i] >> j & 1) return (i << 6) | j;  
            }
        }
        return 1 << 30;
    }
 
    void  print() {
        for (int i = 0; i < n; ++i)
            printf("%llu ", a[i >> 6] >> (i & 63) & 1);
        puts("");
    }
} bit[N];
 
int  m , pre[N] , mcnt;
 
struct Edge {
    int y, nex;
}edge[N * 20];
 
int mark[N], dfn[N], color[N];
 
stack<int> sta;
vector<int> top[N];
vector<int> query[N];
bool u[N];
void dfs(int x) {
    static int sum = 0;
    mark[x] = dfn[x] = ++sum;
    sta.push(x); u[x] = 1;
    for (int k = pre[x]; k != -1; k = edge[k].nex){
        int y = edge[k].y;
        if (!dfn[y]) {
            dfs(y);
            mark[x] = min(mark[x], mark[y]);
        } else if (u[y]) {
            mark[x] = min(mark[x], dfn[y]);
        }
    }
    if (mark[x] == dfn[x]) {
        int y = -1;
        ++cnt;
        while (y != x) {
            y = sta.top();
            sta.pop();
            u[y] = 0;
            color[y] = cnt;
            mark[y] = 1 << 30;
            top[cnt].push_back(y);
            //   printf("!!%d %d\n", cnt, y);
        }
    }
}
 
pair<int, int> C[N];
int num[N] , res[N] , Q;
int bo[N];
int m1[N * 10], m2[N * 10];
 
int main() {
 
    // cout << (sizeof(bit) >> 20) << endl;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
        scanf("%d%d", m1 + i, m2 + i);
    for (int i = 0; i < n; ++i) { 
        scanf("%d", &C[i].first);
        C[i].second = i;
    }
    sort(C, C + n);
    for (int i = 0; i < n; ++i) {
        num[C[i].second] = i;
    }
    memset(pre, -1, sizeof(pre));
    for (int i = 0 ; i < m ; ++ i) {
        int x = m1[i], y = m2[i];
        //scanf("%d%d", &x, &y);
        --x;
        --y;
        x = num[x];
        y = num[y];
        //printf("%d    %d\n", x, y);
        edge[mcnt] = (Edge) {y, pre[x]};
        pre[x] = mcnt++;
    }
    for (int i = 0; i < n; ++i)
        if (dfn[i] == 0) dfs(i);
    scanf("%d" , &Q);
    for (int i = 0 ; i < Q ; ++ i) {        
        int K;
        scanf("%d", &K);
        query[i].resize(K);
        for (int j = 0 ; j < K ; ++ j) {
            int x;
            scanf("%d" , &x);
            query[i][j] = num[x - 1];
        }
        res[i] = 1 << 30;
    }
    times = 0;
    for (int i = 0; i < n; ++i) {
        if (i != num[0]) {
            bit[i].Sset();
        }
    }
    bit[num[0]].set(num[0]);
    for (int i = cnt; i > 0; --i) {
        queue<int> que;
        for (int j = 0; j < top[i].size(); ++j) {
            que.push((top[i][j]));
        }
        while (!que.empty()) {
            int x = que.front(); que.pop();
            bo[x] = 0;
            for (int k = pre[x]; k != -1; k = edge[k].nex) {
                int y = edge[k].y;
                if (color[y] != color[x]) continue;
                static Bitset tmp;
                tmp = bit[y];
                bit[y] = bit[y] & bit[x];
                bit[y].set(y);
                if (!(tmp == bit[y]) && !bo[y]) {
                    bo[y] = 1;
                    que.push(y);
                }
            }
        }
        for (int j = 0; j < top[i].size(); ++j) {
            int x = top[i][j];
            for (int k = pre[x]; k != -1; k = edge[k].nex) {
                int y = edge[k].y;                 
                if (color[x] != color[y]) {
                    bit[y] = bit[y] & bit[x];
                    bit[y].set(y);
                }
            }
        }
    }
    for (int i = 0 ; i < Q ; ++ i) {
        int K = query[i].size();
        static Bitset tmp;
        tmp.Sset();
        for (int j = 0; j < K; ++ j) {
            int x = query[i][j];
            tmp = tmp & bit[x];
        }
        res[i] = min(res[i] , tmp.low());
    }

    times = 1;
    for (int i = 0; i < n; ++i) {
        if (i != num[0]) {
            bit[i].Sset();
        }
    }
    bit[num[0]].set(num[0]);
    for (int i = cnt; i > 0; --i) {
        queue<int> que;
        for (int j = 0; j < top[i].size(); ++j) {
            que.push((top[i][j]));
        }
        while (!que.empty()) {
            int x = que.front(); que.pop();
            bo[x] = 0;
            for (int k = pre[x]; k != -1; k = edge[k].nex) {
                int y = edge[k].y;
                if (color[y] != color[x]) continue;
                static Bitset tmp;
                tmp = bit[y];
                bit[y] = bit[y] & bit[x];
                bit[y].set(y);
                if (!(tmp == bit[y]) && !bo[y]) {
                    bo[y] = 1;
                    que.push(y);
                }
            }
        }
        for (int j = 0; j < top[i].size(); ++j) {
            int x = top[i][j];
            for (int k = pre[x]; k != -1; k = edge[k].nex) {
                int y = edge[k].y;                 
                if (color[x] != color[y]) {
                    bit[y] = bit[y] & bit[x];
                    bit[y].set(y);
                }
            }
        }
    }
    for (int i = 0 ; i < Q ; ++ i) {
        int K = query[i].size();
        static Bitset tmp;
        tmp.Sset();
        for (int j = 0; j < K; ++ j) {
            int x = query[i][j];
            tmp = tmp & bit[x];
        }
        res[i] = min(res[i] , tmp.low() + 25000);
        printf("%d\n" , C[res[i]].first);
    }
    return 0;
}