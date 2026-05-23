#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N=3005;
ll dp[N][N];

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int& x:a){
		scanf("%d",&x);
	}
	
	for(int L=n-1;L>=0;--L){
		for(int R=L;R<n;++R){
				if(L==R){
					dp[L][R] = a[L];
				}else{
					dp[L][R] = max(a[L] - dp[L+1][R],a[R] - dp[L][R-1]);
				}
		}
	}
	printf("%lld\n", dp[0][n-1]);
    return 0;
}
