#include <iostream>
#include <vector>
using namespace std;

int main()
{
    while(true){
        int n, k, s;
        cin >> n >> k >> s;
        if(n == 0 && k == 0 && s == 0) break;
        int x[2001], y[2001], z[2001];
        for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];
        if(k == 1){
            cout << s * s * 6 << endl;
            continue;
        }
        vector<int> v[2001];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(abs(x[i] - x[j]) < s && abs(y[i] - y[j]) < s && abs(z[i] - z[j]) < s) v[i].push_back(j);
            }
        }
        int ans = 1000000000;
        for(int i = 0; i < n; i++){
            if(v[i].size() == 0) continue;
            int sum = s * s * 6;
            bool f = true;
            int last = i;
            int next = v[i][0];
            sum += s * s * 6 -
                (s - abs(x[next] - x[last])) * (s - abs(y[next] - y[last])) * 2 -
                (s - abs(x[next] - x[last])) * (s - abs(z[next] - z[last])) * 2 -
                (s - abs(z[next] - z[last])) * (s - abs(y[next] - y[last])) * 2;
            for(int j = 2; j < k; j++){
                if(v[next].size() == 1){
                    f = false;
                    break;
                }
                if(j >= 3 && (v[next][0] == i || v[next][1] == i)){
                    f = false;
                    break;
                }
                if(v[next][0] == last){
                    last = next;
                    next = v[next][1];
                }
                else{
                    last = next;
                    next = v[next][0];
                }
                sum += s * s * 6 -
                    (s - abs(x[next] - x[last])) * (s - abs(y[next] - y[last])) * 2 -
                    (s - abs(x[next] - x[last])) * (s - abs(z[next] - z[last])) * 2 -
                    (s - abs(z[next] - z[last])) * (s - abs(y[next] - y[last])) * 2;
            }
            if(!f) continue;
            if(k >= 4 && (v[next][0] == i || v[next][1] == i)){
                sum -=
                    (s - abs(x[next] - x[i])) * (s - abs(y[next] - y[i])) * 2 +
                    (s - abs(x[next] - x[i])) * (s - abs(z[next] - z[i])) * 2 +
                    (s - abs(z[next] - z[i])) * (s - abs(y[next] - y[i])) * 2;
            }
            ans = min(ans, sum);
        }
        for(int i = 0; i < n; i++){
            if(v[i].size() < 1) continue;
            int sum = s * s * 6;
            bool f = true;
            int last = v[i][0];
            int next = i;
            for(int j = 1; j < k; j++){
                if(v[next].size() == 1){
                    f = false;
                    break;
                }
                if(j >= 3 && (v[next][0] == i || v[next][1] == i)){
                    f = false;
                    break;
                }
                if(v[next][0] == last){
                    last = next;
                    next = v[next][1];
                }
                else{
                    last = next;
                    next = v[next][0];
                }
                sum += s * s * 6 -
                    (s - abs(x[next] - x[last])) * (s - abs(y[next] - y[last])) * 2 -
                    (s - abs(x[next] - x[last])) * (s - abs(z[next] - z[last])) * 2 -
                    (s - abs(z[next] - z[last])) * (s - abs(y[next] - y[last])) * 2;
            }
            if(!f) continue;
            if(k >= 4 && (v[next][0] == i || v[next][1] == i)){
                sum -=
                    (s - abs(x[next] - x[i])) * (s - abs(y[next] - y[i])) * 2 +
                    (s - abs(x[next] - x[i])) * (s - abs(z[next] - z[i])) * 2 +
                    (s - abs(z[next] - z[i])) * (s - abs(y[next] - y[i])) * 2;
            }
            ans = min(ans, sum);
        }
        if(ans == 1000000000) cout << -1 << endl;
        else cout << ans << endl;
    }
}
