#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i,x,n) for(int i = x;i <= n;++i)	
#define forr(i,x,n)	for(int i = n;i >= x;--i)

const int N = 2e5+7;
const ll INF = 1e18;
int a[N],b[N];
ll L[N],R[N];

bool check(vector<ll> a)
{
	forn(i,1,a.size() - 1)
	{
		if(a[i] < a[i - 1])	return 0;
		a[i] -= a[i - 1];
	}
	return a.back() == 0;
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
		int n;scanf("%d",&n);
		vector<ll> a(n + 17,0),b(n + 17,0);
		forn(i,1,n)	scanf("%lld",&a[i]),b[i] = a[i];
		if(n == 1)
		{
			puts("NO");
			continue;
		}
		int ok = 0;
		if(check(a))	ok = 1;
		swap(a[1],a[2]);		if(check(a))	ok = 1;swap(a[1],a[2]);
		swap(a[n],a[n - 1]);	if(check(a))	ok = 1;swap(a[n],a[n - 1]);
		
		forn(i,1,n)	L[i] = R[i] = -INF;
		
		forn(i,1,n)	if(b[i] < b[i - 1])	break;else	L[i] = b[i] -= b[i - 1];
		forn(i,1,n)	b[i] = a[i];
		forr(i,1,n)	if(b[i] < b[i + 1])	break;else	R[i] = b[i] -= b[i + 1];
		
		forn(i,2,n - 2)
		{
			vector<ll> t = {L[i - 1],a[i + 1],a[i],R[i + 2]};
			if(L[i - 1] == -INF || R[i + 2] == -INF)	continue;
			if(check(t))	{ok = 1;break;}
		}
		
		if(ok)	puts("YES");
		else 	puts("NO");
    }
    return 0;
}
