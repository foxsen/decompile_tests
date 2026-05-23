#include<iostream>
using namespace std;
string s;
int K,L,N;
int dp[1<<17][101];
int main()
{
	cin>>K>>s;
	N=s.size();
	L=N/(K+1);
	if(N%(K+1)==0)
	{
		string ans=s.substr(0,L);
		for(int i=L;i<N;i+=L)ans=max(ans,s.substr(i,L));
		cout<<ans<<endl;
	}
	else if(K<100)
	{
		int A=N%(K+1);
		for(int i=0;i<=N;i++)for(int j=0;j<=A;j++)dp[i][j]=-1;
		dp[0][A]=-2;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<=A;j++)
			{
				if(dp[i][j]==-1)continue;
				if(i+L<=N)
				{
					if(j==A)dp[i+L][j]=-2;
					else if(dp[i+L][j]==-1)dp[i+L][j]=dp[i][j];
					else
					{
						if(s.substr(dp[i+L][j],L+1)>s.substr(dp[i][j],L+1))dp[i+L][j]=dp[i][j];
					}
				}
				if(j>0&&i+L+1<=N)
				{
					int now;
					if(j==A)now=i;
					else
					{
						if(s.substr(i,L+1)<s.substr(dp[i][j],L+1))now=dp[i][j];
						else now=i;
					}
					if(dp[i+L+1][j-1]==-1)dp[i+L+1][j-1]=now;
					else
					{
						if(s.substr(dp[i+L+1][j-1],L+1)>s.substr(now,L+1))dp[i+L+1][j-1]=now;
					}
				}
			}
		}
		cout<<s.substr(dp[N][0],L+1)<<endl;
	}
	else
	{
		string ans(L+1,'9');
		for(int i=0;i<=L;i++)
		{
			int l=0,r=9;
			while(r-l>1)
			{
				int m=l+r>>1;
				ans[i]=m+'0';
				bool flag=true;
				int id=0;
				for(int j=0;j<=K;j++)
				{
					if(s.substr(id,L+1)<=ans)
					{
						id+=L+1;
					}
					else id+=L;
					if(id>=N)break;
				}
				if(id>=N)r=m;
				else l=m;
			}
			ans[i]=r+'0';
		}
		cout<<ans<<endl;
	}
}