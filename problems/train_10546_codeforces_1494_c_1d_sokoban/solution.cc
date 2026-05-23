#include <bits/stdc++.h>
#include <climits>
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define li long int
#define lli long long int
#define ulli unsigned long long int
#define pb push_back
#define loop(a,b,i) for(int i=a ; i<b ; i++)
#define rev_loop(a,b,i) for(int i=a ; i>=b ; i--)
#define MAX(a,b) (a>b)?a:b
#define lele(arr, n) loop(0,n,i) cin>>arr[i];
#define MAXN 1000005
#define MOD 998244353
#define EXTREME 1e9
#define newline cout<<"\n";

using namespace std;

int calc(const vector<int> &a, const vector<int> &b){
    int n = a.size();
    int m = b.size();
    vector<int> su(n + 1);
    int r = m - 1;
    for (int i = n - 1; i >= 0; --i){
        su[i] = su[i + 1];
        while (r >= 0 && b[r] > a[i]) --r;
        if (r >= 0 && b[r] == a[i]) ++su[i];
    }
    int ans = 0;
    int j = 0;
    r = 0;
    loop(0, m, l){
        while (j < n && a[j] <= b[l] + j) ++j;
        while (r < m && b[r] - b[l] < j) ++r;
        ans = max(ans, r - l + su[j]);
    }
    return ans;
}

int main() {
    int t;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    scanf("%d", &t);
    loop(0, t, _){
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> a(n), b(m);
        loop(0, n, i) scanf("%d", &a[i]);
        loop(0, m ,i) scanf("%d", &b[i]);
        vector<int> al, bl, ar, br;
        loop(0, n, i){
            if (a[i] < 0) al.push_back(-a[i]);
            else ar.push_back(a[i]);
        }
        loop(0, m, i){
            if (b[i] < 0) bl.push_back(-b[i]);
            else br.push_back(b[i]);
        }
        reverse(al.begin(), al.end());
        reverse(bl.begin(), bl.end());
        printf("%d\n", calc(al, bl) + calc(ar, br));
    }
    return 0;
}