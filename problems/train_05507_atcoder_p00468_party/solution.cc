#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N,M;
	while(cin>>N>>M, N||M)
	{

		vector<int> v[500];
		for(int i=0; i<M; i++)
		{
			int a,b;
			cin>>a>>b;
			v[a-1].push_back(b-1);
			v[b-1].push_back(a-1);
		}

		bool f[500]={0};
		for(int i=0; i<v[0].size(); i++)
		{
			f[v[0][i]]=1;
			for(int j=0; j<v[v[0][i]].size(); j++)
			{
				f[v[v[0][i]][j]]=1;
			}
		}

		int ans=0;
		for(int i=1; i<N; i++)
		{
			if(f[i]) ans++;
		}
		
		cout << ans << endl;
	}
}