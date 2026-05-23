//https://atcoder.jp/contests/abc134/tasks/abc134_d
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
vector<int>v[N];
#define ll long long 
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1,x,y;i<=n;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
	}
	ll sum=0;
	priority_queue<int>q;
	for(int j=1;j<=m;j++)  
	{
		for(int i=0;i<v[j].size();i++) 
		 q.push(v[j][i]);
		if(q.empty())continue;
		sum+=q.top();
		q.pop();
	}
	cout<<sum<<endl;
	return 0;
} 