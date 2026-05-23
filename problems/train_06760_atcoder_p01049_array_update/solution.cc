#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 
void RI(){}
template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
using namespace std;
typedef long long LL;
int n,m,a,d,k;
map<int,int> mp;

int id(int x)
{
	if(!mp[x]) return x;
	return mp[x];
}
int main()
{
	int x,y,z;
	int yv,zv;
	RI(n,a,d,m);
	REP(i,1,m)
	{
		scanf("%d %d %d",&x,&y,&z);
		if(x==0)
		{
			yv = id(y);
			zv = id(z);
			mp[y] = zv;
			mp[z] = yv;
		}
		else
		{
			zv = id(z);
			mp[y] = zv;
		}
	}

	RI(k);
	k = id(k);
	printf("%lld\n", a+ 1LL*(k-1)*d);
	return 0;
}