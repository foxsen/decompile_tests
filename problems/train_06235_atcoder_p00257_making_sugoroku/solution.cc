#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
#define outl(x) cout<< (x) << '\n'
#define fi first
#define se second
using pii = pair<int,int>;
using ll = long long;
#define LIM 256

vector<int> G[LIM], R[LIM];
int N, M;
int d[LIM];
bool used[LIM];
bool vi[LIM];

void f(int v)
{
    used[v] = true;
    for (const int nxt : R[v]) {
        if (!used[nxt]) f(nxt);
    }
}

bool ok(int v)
{
    bool rec = used[v];
    vi[v] = true;
    for (const int nxt : G[v]) {
        if (!vi[nxt]) rec &= ok(nxt);
    }
    return rec;
}

int main()
{
    cin.tie(0), ios::sync_with_stdio(false);

    while (cin >> M, M) {
        cin >> N;
        for (int i=0; i<=N+1; ++i)  G[i].clear(), R[i].clear();
        memset(d, 0, sizeof(d));
        memset(used, 0, sizeof(used));
        memset(vi, 0, sizeof(vi));

        for (int i=1; i<=N; ++i) cin >> d[i];

        for (int s=0; s<=N; ++s) {
            for (int j=1; j<=M;++j) {
                int t = s+j + d[s+j];
                t = min(max(t, 0), N+1);
                G[s].push_back(t);
                R[t].push_back(s);
            }
        }
        f(N+1);
        outl(ok(0)? "OK" : "NG");
    }
}


