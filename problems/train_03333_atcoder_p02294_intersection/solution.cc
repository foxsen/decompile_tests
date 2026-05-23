#include <iostream>
using namespace std;
struct Point 
{
	int x;
	int y;
};

bool inLine(Point a, Point b, Point c)
{
	if(b.x<=max(a.x,c.x) && b.x>=min(a.x,c.x) && b.y<=max(a.y,c.y) && b.y>=min(a.y,c.y)) return true;
	return false;
}

int orientation(Point a, Point b, Point c)
{
	int val = (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
	//counterclockwise
	if(val<0) return -1;
	//clockwise
	else if(val>0) return 1;
	//coliar
	return 0;	
}

bool intersect(Point a, Point b, Point c, Point d)
{
	int o1 = orientation(a,b,c);
	int o2 = orientation(a,b,d);	
	int o3 = orientation(c,d,a);
	int o4 = orientation(c,d,b);

	if(o1!=o2 && o3!=o4) return true;
	if(o1==0 && inLine(a,c,b)) return true;
        if(o2==0 && inLine(a,d,b)) return true;
	if(o3==0 && inLine(c,a,d)) return true;
	if(o4==0 && inLine(c,b,d)) return true;
	return false;	
}

int main()
{
	int q;
	int p1x,p1y,p2x,p2y;
	int q1x,q1y,q2x,q2y;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>p1x>>p1y>>p2x>>p2y;
		cin>>q1x>>q1y>>q2x>>q2y;

		struct Point p1 = {p1x,p1y};
		struct Point p2 = {p2x,p2y};
		struct Point q1 = {q1x,q1y};
		struct Point q2 = {q2x,q2y};
		cout<<intersect(p1,p2,q1,q2)<<endl;
	}
	return 0;
}

