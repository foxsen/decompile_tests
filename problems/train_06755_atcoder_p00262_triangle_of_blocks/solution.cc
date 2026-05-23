#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

bool check(vector<int> ret)
{
	bool flag = true;
	REP(i,1,ret.size()+1)
	{
		if(i != ret[i-1]) 
		{
			flag = false;
			break;
		}
	}
	return flag;
}

int main()
{
	map<int,int> m;

	int t = 1;
	while(true)
	{
		if((t*(t+1))/2 > 100*10000) break;
		else
		{
			m[(t*(t+1))/2]++;
			t++;
		}
	}


	int n;
	while(cin >> n && n)
	{
		int ret = 0;
		vector<int> v;
		v.resize(n);

		rep(i,n)
		{
			cin >> v[i];
			ret += v[i];
		}

		if(m[ret] != 1) cout << -1 << endl;
		else
		{
			bool flag = true;

			rep(i,10000)
			{
				if(check(v)) 
				{
					cout << i << endl;
					flag = false;
					break;
				}

				rep(i,v.size()) v[i] -= 1;
				v.push_back((int)v.size());
				v.erase(remove(v.begin(),v.end(),0),v.end());
			}

			if(flag) cout << -1 << endl;
		}
	}
}