#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using qll = queue<ll>;
using vb = vector<bool>;
using mll = map<ll, ll>;
using sll = stack<ll>;
#define REP(i,n) for(ll i(0);(i)<(n);(i)++)
#define rep(i,n) for(ll i(0);(i)<(n);(i)++)
#define ALL(a) a.begin(), a.end()
#define elnd endl //* missspell check
const ll INF = 1LL << 60;

struct edge{ ll to, cap, cost, rev;};

void add_edge(vector<vector<edge> > &G, ll from, ll to, ll cap, ll cost){
    G[from].push_back((edge){to, cap,  cost, (ll)G[to].size()});
    G[to].push_back  ((edge){from, 0, -cost, (ll)G[from].size() - 1});
}
//* minimum cost flow using Bellman-Ford
//* Graph G, source s, sink t, with target flow f
//* returns minimum cost
//* returns -1 if impossible to compute required flow
ll minCostFlowBellmanFord(vector<vector<edge> > &G, ll s, ll t, ll f){
    ll N = G.size();
    vll dist(N); //* dist: shortest distance
    vll prev_v(N), prev_e(N);//* prev_v/prev_e: previous vertex/edge to record shortest path
    
    ll res = 0;
    while( f > 0){
        //* Bellman-Ford to calculate s-t shortest path
        fill(ALL(dist), INF);
        dist[s]=0;
        bool update = true;
        while(update){
            update = false;
            REP(v, N){
                if( dist[v] == INF) continue;
                REP(i, G[v].size()){
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                        dist[e.to] = dist[v] + e.cost;
                        prev_v[e.to] = v;
                        prev_e[e.to] = i;
                        update = true;
                    }
                }
            }
        }
        
        if(dist[t] == INF){ //* s is disconnected from t, meaning f is not reachable
            return -1;
        }
        //* run flow as many as possible along shortest path
        ll d = f;
        for(ll v = t; v != s; v = prev_v[v]){
            //* v --> prev_v[v] via prev_e[v]
            d = min(d, G[prev_v[v]][prev_e[v]].cap);
        }
        f -= d;
        res += d * dist[t];
        //* update residual graph along shortest path
        for(ll v = t; v != s; v = prev_v[v]){
            edge &e = G[prev_v[v]][prev_e[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;        
}

//! minimum cost flow using Dijkstra, the initial graph should contains NO negative edge
//* Graph G, source s, sink t, with target flow f
//* returns minimum cost
//* returns -1 if impossible to compute required flow
pll minCostFlowDijkstra(vector<vector<edge> > &G, ll s, ll t, ll f){
    ll N = G.size();
    vll dist(N); //* dist: shortest distance
    vll prev_v(N), prev_e(N);//* prev_v/prev_e: previous vertex/edge to record shortest path
    vll h(N); //* potential for each vertex
    
    ll res = 0;
    fill(ALL(h), 0);
    while( f > 0){
        //* Use Dijkstra to update potential h
        priority_queue<pll, vector<pll>, greater<pll> > que;
        fill(ALL(dist), INF);
        dist[s]=0;
        que.push(pll(0, s));
        while(!que.empty()){
            pll p = que.top(); que.pop();
            ll v = p.second;
            if(dist[v] < p.first) continue;
            REP(i, G[v].size()){
                edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prev_v[e.to] = v;
                    prev_e[e.to] = i;
                    que.push(pll(dist[e.to], e.to));
                }
            }
        }
        
        if(dist[t] == INF){ //* s is disconnected from t, meaning f is not reachable
            // return -1;
            //! customized for this problem
            return pll(res, f);
        }
        REP(v, N) h[v] += dist[v];
        //* run flow as many as possible along shortest path
        ll d = f;
        for(ll v = t; v != s; v = prev_v[v]){
            //* v --> prev_v[v] via prev_e[v]
            d = min(d, G[prev_v[v]][prev_e[v]].cap);
        }
        f -= d;
        res += d * h[t];
        //* update residual graph along shortest path
        for(ll v = t; v != s; v = prev_v[v]){
            edge &e = G[prev_v[v]][prev_e[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return pll(res, 0);
}

struct train{ ll x, y, c;};

int main(){
    while(1){
        ll n; cin >> n;
        if(n == 0)
            break;
        
        vector<vector<train> > rawData(n-1);
        REP(i, n-1){
            ll m; cin >> m;
            REP(j, m){
                ll x, y, c; cin >> x >> y >> c;
                rawData[i].push_back((train){x, y, c});
            }
        }
        ll g; cin >> g;

        vector<set<pll>> dataNode(n-1);
        REP(i, n-1){
            set<pll> arrTime;
            for(auto obj: rawData[i]){
                arrTime.insert(pll(i, obj.y));
            }
            dataNode[i] = arrTime;
        }
        map<pll, ll> nodeToIdx;
        map<ll, pll> idxToNode;
        ll num_vertex = 1;
        REP(i, n-1){
            auto arrTime = dataNode[i];
            for(auto obj: arrTime){
                nodeToIdx[obj] = num_vertex;
                idxToNode[num_vertex] = obj;
                num_vertex += 2;
            }
        }
        num_vertex ++;
        vector<vector<edge> > G(num_vertex);

        REP(i, n-1){
            if(i == 0){
                for(auto data: rawData[i]){
                    ll idx = nodeToIdx[pll(0, data.y)];
                    add_edge(G, 0, idx, 1, data.c);
                }
            }
            else{
                for(auto data: rawData[i]){
                    ll idx = nodeToIdx[pll(i, data.y)];
                    for(auto data_from: dataNode[i-1]){
                        if(data_from.second <= data.x){
                            ll idx_from = nodeToIdx[pll(i-1, data_from.second)];
                            add_edge(G, idx_from+1, idx, 1, data.c);

                        }
                    }
                }
            }
        }
        for(ll v = 1; v < num_vertex-1; v+=2){
            add_edge(G, v, v+1, 1, 0);
        }

        for(auto node: dataNode.back()){
            ll idx = nodeToIdx[node];
            add_edge(G, idx, num_vertex-1, 1, 0);
        }

        pll ans = minCostFlowDijkstra(G, 0, num_vertex-1, g);
        cout<< g - ans.second <<" " << ans.first<<endl;
        

    }


    return 0;
}
