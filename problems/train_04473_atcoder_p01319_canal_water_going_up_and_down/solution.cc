#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int N,S,K,X,UD; double L,F,D,V;
	while(scanf("%d%d%d",&N,&S,&K), N||S||K)
	{
		double T[4][1500]={0};
		
		for(int i=0; i<N; i++)
		{
			scanf("%d%lf%lf%lf%d",&X,&L,&F,&D,&UD);
			X+=100;
			
			T[1][X] = L/F;
			T[2][X] = L/D;
			
			if(UD)
			{
				swap(T[1][X],T[2][X]);
				T[3][X] = T[2][X];
			}
		}
		
		for(int s=0; s<S; s++)
		{
			scanf("%lf",&V);
			for(int p=101-s; p<K+205-s; p++)
			{
				T[0][p] = max(T[0][p+1]-T[1][p+1],max(T[0][p-1]+1.0/V,T[3][p]))+T[1][p];
				T[3][p] = T[0][p]+T[2][p];
			}
		}
		printf("%.10lf\n",T[0][K+100]);
	}
}