#include <bits/stdc++.h>
#define pb push_back
#define f(c,a,b) for(int c=a; c<=b; c++)
#define N 200010

using namespace std;
vector <int> t[N];
int w[N], px[N], vis[N];
typedef long long ll;

bool mycmp(int a, int b){ return w[a] > w[b]; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("owo.in","r",stdin);
    int T;
    cin >> T;
    while(T--){
        int n, iu, iv;
        ll ans = 0;
        cin >> n;
        f(i,1,n) {
            cin >> w[i];
            ans += w[i];
            px[i] = i;
            vis[i] = 0;
            t[i].clear();
        }
        cout<<ans<<' ';
        sort(px+1,px+n+1,mycmp);
        f(i,1,n-1){
            cin >> iu >> iv;
            t[iu].pb(iv);
            t[iv].pb(iu);
        }
        f(i,1,n){
            int u = px[i], c=t[u].size();
            // for(int j=0; j<t[u].size(); j++){
            //     int v = t[u][j];
            //     c++;
            // }
            // if(c<=1) continue;
            // vis[u] = 1;
            f(j,1,c-1) {
                ans += w[u];
                cout<<ans<<' ';
            }
        }
        cout << endl;
    }
    return 0;
}