#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll A[500005];
ll dp[500005];

void I_m_Beast()
{	
	int n;
	cin>>n;
	assert(1<=n && n<=500000);
	string s;
	cin>>s;
	for(int i=1;i<=n;i++) {
		// cin>>A[i];
		A[i]=s[i-1]-'0';
		assert(0<=A[i] && A[i]<=1000000);
	}
	A[0]=-1;
	ll cum[n+1],idx[n+1];
	cum[0]=idx[0]=0;

	for(int i=1;i<=n;i++) {
		if(A[i]==0)
			idx[i]=i;
		else
			idx[i]=idx[i-1];
		cum[i]=cum[i-1]+A[i];
		dp[i]=0;
	}
	dp[0]=0;
	for(int i=3;i<=n;i++) {
		dp[i]=dp[i-1];
		if(A[i]!=0) {
			if(A[i-1]==0 && A[i-2]!=0) {
				int x=idx[i-2];
				dp[i]=max(dp[i],dp[x]+cum[i-3]-cum[x]+max(A[i],A[i-2]));
				if(x+1!=i-2)
				dp[i]=max(dp[i],dp[x+1]+cum[i-3]-cum[x+1]+max(A[i],A[i-2]));
			}
			else if(A[i-1]!=0) {
				int x=idx[i];
				if(x>1 && A[x-1]!=0)
				dp[i]=max(dp[i],dp[x-2]+cum[i]-cum[x+1]+max(A[x-1],A[x+1]));
			}
		}
	}
	cout<<dp[n]<<endl;
	return ;
}

int main()
{
	fastio;
	int t=1;
	// cin>>t;
	assert(1<=t && t<=1000);
	while(t--)
	{
		I_m_Beast();
	}	
	return 0;	
}
