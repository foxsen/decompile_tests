#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> poi[57];

double f(double x, double y, int v)
{
	x-=poi[v].first;
	y-=poi[v].second;
	return x*x+y*y;
}

double knowxy(double x, double y)
{
	double ret=0;
	for (int i=1; i<=n; i++)
		ret=max(ret, f(x, y, i));
	return ret;
}

double knowx(double x)
{
	double bsa=-1000;
	double bsb=1000;
	for (int h=0; h<100; h++)
	{
		double bs1=(2*bsa+bsb)/3;
		double bs2=(bsa+2*bsb)/3;
		if (knowxy(x, bs1)<knowxy(x, bs2))
			bsb=bs2;
		else
			bsa=bs1;
	}
	return knowxy(x, bsa);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d%d", &poi[i].first, &poi[i].second);
	double bsa=-1000;
	double bsb=1000;
	for (int h=0; h<100; h++)
	{
		double bs1=(2*bsa+bsb)/3;
		double bs2=(bsa+2*bsb)/3;
		if (knowx(bs1)<knowx(bs2))
			bsb=bs2;
		else
			bsa=bs1;
	}
	printf("%.9lf\n", sqrt(knowx(bsa)));
	return 0;
}
