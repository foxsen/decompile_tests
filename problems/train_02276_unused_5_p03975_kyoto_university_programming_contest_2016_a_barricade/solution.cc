#include<iostream>
using namespace std;
int main()
{
	int n,m,t=0,k,l;
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>l;
		if (l<m||l>=k) t++;
	}
	cout<<t<<endl;
	return 0;
}