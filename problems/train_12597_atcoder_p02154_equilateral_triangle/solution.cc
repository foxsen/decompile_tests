#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;
struct Point{
	double x,y;
};
int n;
Point a[11111];
Point b[11111];
void conv(double theta)
{
	double C=cos(-theta);
	double S=sin(-theta);
	for(int i=0;i<n;i++)
	{
		b[i].x=a[i].x*C-a[i].y*S;
		b[i].y=a[i].x*S+a[i].y*C;
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].x>>a[i].y;
	double ans=1e150;
	for(int i=0;i<n;i++)
	{
		int I=(i+1)%n;
		double now=hypot(a[I].x-a[i].x,a[I].y-a[i].y);
		double theta=atan2(a[I].y-a[i].y,a[I].x-a[i].x);
		//cout<<theta<<endl;
		conv(theta+5*M_PI/6);
		if(0&&i==0)
		{
			cout<<endl<<"debug"<<endl;
			for(int j=0;j<n;j++)cout<<b[j].x<<" "<<b[j].y<<endl;
			cout<<"debug"<<endl;
		}
		//double mx=1e150;
		//for(int j=0;j<n;j++)mx=min(mx,i==j?1e150:b[j].x-b[i].x);
		double mx=0;
		for(int j=0;j<n;j++)mx=max(mx,b[j].x-b[i].x);
		//cout<<mx<<" ";
		now+=mx/cos(M_PI/6);
		conv(theta+M_PI/6);
		if(0&&i==0)
		{
			cout<<endl<<"debug"<<endl;
			for(int j=0;j<n;j++)cout<<b[j].x<<" "<<b[j].y<<endl;
			cout<<"debug"<<endl;
		}
		mx=0;
		for(int j=0;j<n;j++)mx=max(mx,I==j?0:b[j].x-b[I].x);
		//cout<<mx<<endl;
		now+=mx/cos(M_PI/6);
		ans=min(ans,now);
	}
	cout<<fixed<<setprecision(9)<<ans<<endl;
}

