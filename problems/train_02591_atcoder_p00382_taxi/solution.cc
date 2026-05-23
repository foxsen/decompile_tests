#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> C(N);
    int i,j;
    int m,c;
    for(i=0;i<N;i++) {
        cin >> m;
        for(j=0;j<m;j++) {
            cin >> c;
            C[i].push_back(c);
        }
    }
    priority_queue<int> q;
    long long ans = 0;
    for(i=0;i<N;i++) {
        for(j=0;j<C[N-i-1].size();j++)q.push(C[N-i-1][j]);
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
}
