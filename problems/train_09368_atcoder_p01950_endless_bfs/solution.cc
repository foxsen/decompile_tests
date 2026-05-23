#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
int N, M;
vector<int> paths[1000000];
int dist[1000000][2];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 2; j++) {
            dist[i][j] = 1e9;
        }
    }
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    dist[0][0] = 0;
    queue<i_i> que;
    que.push({0, 0});
    while(!que.empty()) {
        i_i tmp = que.front();
        que.pop();
        int now = tmp.first;
        int idx = tmp.second;
        for(auto to : paths[now]) {
            if(chmin(dist[to][1-idx], dist[now][idx] + 1)) {
                que.push({to, 1 - idx});
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 2; j++) {
            chmax(ans, dist[i][j]);
        }
    }
    if(ans == 1e9) ans = 0;
    cout << ans - 1 << endl;
    return 0;
}
