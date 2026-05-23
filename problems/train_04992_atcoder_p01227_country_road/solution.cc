#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
const int maxn=2e5+5;

int main() 
{

    int t;
    cin >> t;

    rep(w,t){
        int n,k,ans;

        cin >> n >> k;

        int A[n];
        int X[n-1];
    
        rep(i,n){
            cin >> A[i];
            if(i)X[i-1] = A[i] - A[i-1];       
        }

        sort(X,X+n-1);
        reverse(X,X+n-1);

        ans = A[n-1] - A[0];

        rep(i,min(k-1,n-1)){
            ans -= X[i];
        }
    
        cout << ans << endl;
    }

    return 0;
}

