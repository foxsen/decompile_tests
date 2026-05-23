#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long long a[100005];
	long long b[100005];

	for(int i=1;i<=n;i++)
		cin >> a[i-1] >> b[i-1];

	long long ans=0;

	for(int i=n;i>=1;i--)
	{
		ans+=(b[i-1]-((a[i-1]+ans-1)%b[i-1]+1))%b[i-1];
	}

	cout << ans << endl;
}
