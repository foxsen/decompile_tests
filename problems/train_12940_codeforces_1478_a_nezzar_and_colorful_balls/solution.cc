#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> cnt(n+1, 0);
        for(int i=0; i<n; i++){
            int x; cin >> x;
            cnt[x]++;
        }
        
        cout << *max_element(cnt.begin(), cnt.end()) << "\n"; 
    }
    return 0;
}
