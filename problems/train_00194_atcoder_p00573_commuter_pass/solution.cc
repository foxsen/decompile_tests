#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
#define ll long long
const ll linf = 1e15;
struct edge{
    int to;
    ll cost;
};

struct node{
    int from;
    ll cost;
    bool operator<(const node &n1) const {
        return n1.cost < cost;
    }
};

int N, M, S, T, U, V;
vector<edge> G[100010];
ll DU[100010], DV[100010], DS[100010], dp[3][100010];
bool used[100010];

void dijk(int s, ll* D){
    fill(D, D + N + 1, linf);
    priority_queue<node> pq;
    pq.push(node{s, 0});
    D[s] = 0;
    while(!pq.empty()){
        node n1 = pq.top();
        pq.pop();
        if(D[n1.from] < n1.cost) continue;
        for(auto u : G[n1.from]){
            ll cost = u.cost + n1.cost;
            if(cost < D[u.to]){
                D[u.to] = cost;
                pq.push(node{u.to, cost});
            }
        }
    }
}

ll solve(){
    dijk(U, DU), dijk(V, DV), dijk(S, DS);
    for(int i = 1; i <= N ; i++){
        dp[0][i] = DU[i];
        dp[1][i] = DV[i];
        dp[2][i] = linf;
    }

    priority_queue<node> pq;
    pq.push(node{S, 0});
    while(!pq.empty()){
        node n1 = pq.top();
        pq.pop();
        for(auto u : G[n1.from]){
            ll cost = u.cost + n1.cost;
            if(DS[u.to] < cost) continue;
            
            dp[0][u.to] = min(dp[0][u.to], dp[0][n1.from]);
            dp[1][u.to] = min(dp[1][u.to], dp[1][n1.from]);
            
            if(!used[u.to]){
                used[u.to] = true;
                pq.push(node{u.to, DS[u.to]});
            }
        }
    }

    for(int i = 1; i <= N; i++){
        dp[2][i] = min(dp[0][i] + DV[i], dp[1][i] + DU[i]);
    }
    fill(used, used + N + 1, false);

    pq.push(node{S, 0});
    while(!pq.empty()){
        node n1 = pq.top();
        pq.pop();
        for(auto u : G[n1.from]){
            ll cost = u.cost + n1.cost;
            if(DS[u.to] < cost) continue;
            
            dp[2][u.to] = min(dp[2][u.to], dp[2][n1.from]);
            
            if(!used[u.to]){
                used[u.to] = true;
                pq.push(node{u.to, DS[u.to]});
            }
        }
    }

    return min(dp[2][T], DU[V]);
}

void init(){
    cin >> N >> M >> S >> T >> U >> V;
    for(int i = 0; i < M; i++){
        int A, B;
        ll C;
        cin >> A >> B >> C;
        G[A].push_back(edge{B, C});
        G[B].push_back(edge{A, C});
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    init();
    cout << solve() << endl;
    return 0;
}
