#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <set>
#include <cmath>
#include <string>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll rt[30];

int main()
{
	ll D;
	scanf("%lld",&D);
	rt[0]=1;
	for(int i=1;i<30;i++) rt[i]=rt[i-1]*10LL;
	ll ret=0;
	//2桁以上のものだけ
	for(int i=2;i<=20;i++)
	{
		int k=i/2;
		for(int S=0;S<1<<k;S++)
		{
			ll way=i%2==1?10:1,zan=D;
			for(int j=0;j<k;j++)
			{
				ll d=llabs(zan)%10LL;
				if(zan<0)
				{
					d=10-d;
					d%=10;
				}
				if(S>>j&1)
				{
					//x,x+dにする
					ll nm=10LL-d;
					if(j==0) nm--;
					way*=nm;
					zan+=d*rt[i-2*j-1];
					zan-=d;
				}
				else
				{
					//x,x+d-10にする
					ll nm=d;
					if(j==0) nm--;
					if(nm<0)
					{
						way=0;
						break;
					}
					way*=nm;
					zan-=(10LL-d)*rt[i-2*j-1];
					zan+=(10LL-d);
				}
				zan/=10LL;
			}
			if(zan==0) ret+=way;
		}
	}
	printf("%lld\n",ret);
	return 0;
}
