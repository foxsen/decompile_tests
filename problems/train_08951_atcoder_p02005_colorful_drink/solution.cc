#include<iostream>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
map<string,priority_queue<int,vector<int>,greater<int> > >M;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;int a;cin>>s>>a;
		M[s].push(a);
	}
	cin>>m;
	int now=0;
	for(;m--;)
	{
		string s;cin>>s;
		while(M[s].size()>0&&M[s].top()<=now)M[s].pop();
		if(M[s].size()>0)
		{
			now=M[s].top();
			M[s].pop();
		}
		else
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
}

