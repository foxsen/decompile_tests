#include <cstdio>
#include <cstring>
using namespace std;

unsigned char R[1000000][10][3];

int main()
{
	int x,y,c,t;
	while(scanf("%d %d",&x,&y), (x||y))
	{
		memset(R,0,sizeof(R));
		for(c=1; 1; c++)
		{

			x*=10;
			t=x/y;
			x%=y;

			if(R[x][t][0] || R[x][t][1] || R[x][t][2])
			{
				break;
			}

			R[x][t][0] = 0xFF&(c);
			R[x][t][1] = 0xFF&(c>>8);
			R[x][t][2] = 0xFF&(c>>16);
		}

		c = (x ? c : c-1);
		y = R[x][t][0] | (R[x][t][1]<<8) | (R[x][t][2]<<16);
		printf("%d %d\n",y-1,c-y);
	}

	return 0;
}