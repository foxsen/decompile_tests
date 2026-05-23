#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define LOCAL
using namespace std;
const int MAXN = 300000;
int t, n, p, temp;
deque<pair<int,int>> nodes;
int a[MAXN], visit[MAXN];

int32_t main()
{

    cin >> t;
    while(t--){
        memset(visit, 0, sizeof(visit));
        nodes.clear();

        cin >> n >> p;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            nodes.push_back({a[i], i});
        }
        sort(nodes.begin(), nodes.end());

        int ans = 0, remain_edge = n-1;
        while(nodes.size()){
            pair<int,int> node = nodes.front();
            //cout << node.first << ' ' << node.second << '\n';
            nodes.pop_front();
            if(node.first > p) break;
            if(visit[node.second]) continue;

            int l = node.second, r = node.second;
            //while(l > 0 && !visit[l] && a[l] % node.first == 0) l--;
            //while(r <= n && !visit[r] && a[r] % node.first == 0) r++;
            //l++; r--;
            while(l > 1 && !visit[l] && a[l-1] % node.first == 0) l--;
            while(r < n && !visit[r] && a[r+1] % node.first == 0) r++;

            for(int i = l; i <= r; i++) visit[i] = 1;
            ans += node.first * (r-l);
            remain_edge -= (r-l);
            //cout << "l r " << l << ' ' << r << '\n';
            //cout << "ans " << ans << '\n';
        }
        //cout << "remain_edge " << remain_edge << '\n';
        ans += remain_edge * p;
        cout << ans << '\n';
    }
    return 0;
}
