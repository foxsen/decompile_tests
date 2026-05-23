#include<iostream>
#include<algorithm>
using namespace std;
int N,M;
int main()
{
	while(cin>>N>>M,N)
	{
		int ans=0;
		for(int i=0;i<N;i++)
		{
			int A;cin>>A;
			ans+=min(A,M/N);
		}
		cout<<ans<<endl;
	}
}

