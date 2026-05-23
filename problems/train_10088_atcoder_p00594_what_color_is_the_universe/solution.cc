#include<stdio.h>
#include<map>
int main()
{
	int n,x,i,f;
	while(scanf("%d",&n),n)
	{
		typedef std::map<int,int>M;
		M m;
		for(f=i=0;i<n;++i)scanf("%d",&x),m[x]++;
		for(M::iterator t=m.begin();t!=m.end();++t)
			if(t->second>n/2)f=printf("%d\n",t->first);
		if(!f)puts("NO COLOR");
	}
	return 0;
}