#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}

namespace ae86
{
	const int bufl = 1<<15;

	char buf[bufl],*s=buf,*t=buf;

	inline int fetch()
	{
		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
		return *s++;
	}

	inline int ty()
	{
		int a=0,b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}
}
using ae86::ty;

const double eps = 1e-8;

inline int dcmp(double x){if(-eps<x && x<eps)return 0;return x>0?1:-1;}

struct points
{
	double x,y;
	points(double _x=0,double _y=0){x=_x,y=_y;}

	inline friend points operator + (points a,points b){return points(a.x+b.x,a.y+b.y);}
	inline friend points operator - (points a,points b){return points(a.x-b.x,a.y-b.y);}
	inline friend points operator * (points a,double b){return points(a.x*b,a.y*b);}
	inline friend points operator / (points a,double b){return points(a.x/b,a.y/b);}

	inline friend int operator == (points a,points b){return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0;}

	void takein(){x=ty(),y=ty();}
	void print(char ends='\n'){printf("%.12lf %.12lf",x,y),putchar(ends);}
};

inline double dox(points a,points b){return a.x*b.x+a.y*b.y;}
inline double cox(points a,points b){return a.x*b.y-a.y*b.x;}
inline double length(points a){return sqrt(dox(a,a));}
inline double distan(points a,points b){return length(a-b);}

inline points pervec(points a){if(dcmp(length(a))<=0)return points(0,0);return a/length(a);}

inline int isponl(points p,points a,points b)
{
	return dcmp(cox(p-a,p-b))==0 && distan(a,p)<=distan(a,b) && distan(b,p)<=distan(a,b);
}

inline int iscrashed(points al,points ar,points bl,points br)
{
	double amix=min(al.x,ar.x),amxx=max(al.x,ar.x),amiy=min(al.y,ar.y),amxy=max(al.y,ar.y);
	double bmix=min(bl.x,br.x),bmxx=max(bl.x,br.x),bmiy=min(bl.y,br.y),bmxy=max(bl.y,br.y);
	
	if(amxx<bmix || bmxx<amix || amxy<bmiy || bmxy<amiy)return 0;
	if(isponl(al,bl,br) || isponl(ar,bl,br) || isponl(bl,al,ar) || isponl(br,al,ar))return 1;

	if(dcmp(cox(al-bl,br-bl))!=dcmp(cox(ar-bl,br-bl))
		&& dcmp(cox(bl-al,ar-al))!=dcmp(cox(br-al,ar-al)))return 1;
	return 0;
}

inline points crash(points al,points ar,points bl,points br)
{
	points a=ar-al,b=br-bl;
	double bas=cox(al-bl,b)/cox(b,a);
	return al+a*bas;
}

inline points ortho(points p,points a,points b)
{
	points c=a+pervec(b-a);
	double dis=dox(p-a,c-a);
	points tar=a+(c-a)*dis;
	return tar;
}

inline double distanpl(points p,points a,points b)
{
	if(isponl(p,a,b))return 0;
	points ort=ortho(p,a,b);
	if(isponl(ort,a,b))return distan(p,ort);
	return min(distan(p,a),distan(p,b));
}

const int _ = 107;

int n;
points p[_];

void finder()
{
	points a;
	a.takein();
	points b=a;
	b.x+=998244353;
	b.y+=19260817;

	int ans=0;
	for(int i=1;i<=n;i++)
	{
		points c=p[i],d=p[i+1];
		if(isponl(a,c,d)){ans=1;break;}
		
		points aper=pervec(b-a),cper=pervec(c-d);
		if(!iscrashed(a,b,c,d))continue;
		if(aper==cper || (points()-aper)==cper)continue;
		ans^=2;
	}

	printf("%d\n",ans);
}

int main()
{
	n=ty();
	for(int i=1;i<=n;i++)p[i].takein();
	p[0]=p[n],p[n+1]=p[1],p[n+2]=p[2];

	int q=ty();
	while(q--)finder();
	
	return 0;
}

