#include<iostream>
using namespace std;
long long r,d,x;
int main()
{
	cin>>r>>d>>x;
	for(int i=1;i<=10;i++)
	{
		x=r*x-d;
		cout<<x<<endl;
	}
	return 0;
} 