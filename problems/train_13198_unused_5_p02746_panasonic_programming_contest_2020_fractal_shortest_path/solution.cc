#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL Pow[40]={1};
LL calc(LL x1,LL y1,LL x2,LL y2,int d){
	if(d==-1)return abs(y2-y1);
	LL w=Pow[d];
	if(x1/w!=x2/w)return abs(x2-x1)+abs(y2-y1);
	if(x1/w==1&&abs(y1/w-y2/w)>=2){
		x1%=w,x2%=w;
		return abs(y2-y1)+min(x1+x2+2,w*2-x1-x2);
	}
	x1%=Pow[d],x2%=Pow[d];
	return calc(x1,y1,x2,y2,d-1);
}

LL cal(LL x1,LL y1,LL x2,LL y2,int level) {
    if(level==0) return abs(y1-y2);
    LL w=Pow[level-1];
    if(x1/w!=x2/w) return abs(x1-x2)+abs(y1-y2);//不同层
    if(x1/w==1&&abs(y1/w-y2/w)>=2) {//同层且在456这层
        return min(x1%w+x2%w+2,w*2-x1%w-x2%w)+abs(y1-y2);
    }
    return cal(x1%w,y1,x2%w,y2,level-1);
}
LL work(){
	LL a,b,c,d;scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	a--,b--,c--,d--;if(abs(a-c)>abs(b-d))swap(a,b),swap(c,d);
	return calc(a,b,c,d,29);
}
int main(){
	for(int i=1;i<30;i++)Pow[i]=Pow[i-1]*3;
	int t;scanf("%d",&t);
	while(t--)printf("%lld\n",work());
	return 0;
}