#include <bits/stdc++.h>

#define int long long

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
    	int N;
    	cin >> N;

    	if(N == 1)
    	{
    		cout << 0 << '\n';
    	}
    	else if(N == 2)
    	{
    		cout << 1 << '\n';
    	}
    	else if(N == 3)
    	{
    		cout << 2 << '\n';
    	}
    	else if(N&1)
    	{
    		cout << 3 << '\n';
    	}
    	else
    	{
    		cout << 2 << '\n';
    	}
    }

    return 0;
}