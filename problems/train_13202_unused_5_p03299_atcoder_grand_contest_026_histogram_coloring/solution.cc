#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 110;
const int base = 1e9+7;

int n,a[maxn];
ll f[maxn][maxn];
map<int,int> cnt;
vector<int> h;

ll pw(int a,int n) {
    if (n==0) return 1ll;
    if (n==1) return a;
    ll tmp = pw(a,n/2);
    tmp = (tmp*tmp)%base;
    if (n%2==0) return tmp;
    return (tmp*a)%base;
}

int main() {
  //  freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        if (cnt[a[i]]!=0) continue;
        h.push_back(a[i]);
        cnt[a[i]]=1;
    }
    cnt.clear();
    h.push_back(0);
    sort(h.begin(),h.end());
    h.erase(unique(h.begin(),h.end()),h.end());
    for (int j=0;j<h.size();j++) cnt[h[j]]=j;
    for (int j=0;j<h.size();j++)
        if (h[j] == 0) f[1][j] = pw(2,a[1]);
        else if (h[j] <= a[1]) f[1][j] = pw(2,a[1] - h[j]+1);
    for (int i=2;i<=n;i++) {
        if (a[i] < a[i-1]) {
            int mi = cnt[a[i]];
            for (int j=0;j<h.size();j++)
                if (h[j] <= a[i])
                    f[i][j] = (f[i-1][j] + f[i-1][mi])%base;
        } else {
            int mi = cnt[a[i-1]];
            for (int j=0;j<h.size();j++) {
                if (h[j] <= a[i-1]) f[i][j] = ((f[i-1][j] + f[i-1][mi])%base * pw(2,a[i] - a[i-1])) % base;
                else if (h[j] <= a[i]) f[i][j] = (pw(2,a[i] - h[j]+1) * f[i-1][mi]) % base;
            }
        }
    }
    cout<<f[n][0]<<endl;

}
