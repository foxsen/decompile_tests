#include<iostream>
#include<vector>
using namespace std;

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int> > edge(10001);
    vector<int> state(V, 0);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        edge[s].push_back(t);
        state[t]++;
    }
    vector<int> ans;
    for (int i = 0; i < V; i++) {
        if (state[i] == 0) ans.push_back(i);
    }
    for (int i = 0, s = ans.size(); i < s; i++) {
        int a = ans[i];
        for (int j = 0, ss = edge[a].size(); j < ss; j++) {
            int t = edge[a][j];
            state[t]--;
            if (state[t] == 0) {
                ans.push_back(t);
                s++;
            }
        }
        cout << a << endl;
    }

    return 0;
}

