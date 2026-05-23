#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main() {
	lli t;
	cin>>t;
	while(t--)
	{
	    lli n;
	    cin>>n;
	    lli cnt=0;
	    for(int i=1;i<=n;i=i*10+1)
	    {
	        for(int j=1;j<=9;j++)
	        {
	            if(i*j<=n)
	            {
	                cnt++;
	            }
	        }
	    }
	    cout<<cnt<<endl;
	}
	return 0;
}
