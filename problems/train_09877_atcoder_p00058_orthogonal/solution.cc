#include<cstdio>

double point[4][2];



double p(double b)
{

	if(0>b)return -b;
	return b;
}

int main()
{
	while(true)
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<2;j++)
			{
				if(scanf("%lf",&point[i][j])==EOF)goto end;
			}
		}
	    if(((point[0][0]-point[1][0])*(point[2][0]-point[3][0])==-(point[2][1]-point[3][1])*(point[0][1]-point[1][1])))
			printf("YES\n");
		else printf("NO\n");
	}
end:
	return 0;
}