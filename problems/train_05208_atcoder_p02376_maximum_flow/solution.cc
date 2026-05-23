#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>

using namespace std;

struct Edge{
    int to, capacity, revIndex;
};

vector<bool> used;

int findPass(vector<vector<Edge>>& edge, int node, int t, int flow){
    if(node == t){
        return flow;
    }
    used[node] = true;
    for(Edge& e: edge[node]){
        if(!used[e.to] && e.capacity > 0){
            int f = findPass(edge, e.to, t, min(flow, e.capacity));
            if(f > 0){
                e.capacity -= f;
                edge[e.to][e.revIndex].capacity += f;
                return f;
            }
        }
    }

    return 0;
} 

int main(){

    int V, E;
    cin >> V >> E;
    vector<vector<Edge>> edge(V);

    int u, v, c;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> c;
        edge[u].emplace_back((Edge){v, c, (int)edge[v].size()});
        edge[v].emplace_back((Edge){u, 0, (int)edge[u].size() - 1});
    }

    int ans = 0;
    while(true){
        used = vector<bool>(V, false);
        int flow = findPass(edge, 0, V - 1, 20000);
        if(flow == 0){
            break;
        }
        ans += flow;
    }
    
    cout << ans << endl;

    return 0;
}
