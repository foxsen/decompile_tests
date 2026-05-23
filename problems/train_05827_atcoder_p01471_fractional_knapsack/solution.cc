#include<stdio.h>
#include<algorithm>
using namespace std;
pair<double,pair<int,int> > p[110000];
pair<double,pair<int,int> > q[110000];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int sz=0;
	int s2=0;
	double val=0;
	for(int i=0;i<a;i++){
		int w,v;
		scanf("%d%d",&w,&v);
		if(v>=0&&w<=0){
			val+=v;
			b-=w;
		}else if(v<=0&&w>=0){
			continue;
		}else if(v>0){
			p[sz++]=make_pair((double)w/v,make_pair(w,v));
		}else{
			b-=w;
			val+=v;
			p[sz++]=make_pair((double)w/v,make_pair(-w,-v));
		}
	}
	std::sort(p,p+sz);
	std::sort(q,q+s2);
	int lb=b;
	double tmp=val;
	double ret=0;
	int at=0;
	for(int i=0;i<=s2;i++){
		while(at<sz&&b-p[at].second.first>=0){
			b-=p[at].second.first;
			val+=(double)p[at].second.second;
			at++;
		}
		if(at<sz)ret=max(ret,val+(double)p[at].second.second*b/p[at].second.first);
		else ret=max(ret,val);
		if(i<s2){
			b-=q[i].second.first;
			val+=q[i].second.second;
		}
	}
	at=0;
	val=tmp;
	b=lb;
	for(int i=0;i<sz;i++){
		val+=p[i].second.second;
		b-=p[i].second.first;
		while(at<s2&&b-q[at].second.first<0){
			b-=q[at].second.first;
			val+=(double)q[at].second.second;
			at++;
		}
	//	printf("%f %d %d\n",val,b,at);
		if(at>=s2)break;
		if(b<0)ret=max(ret,val+(double)b/q[at].second.first*q[at].second.second);
		else ret=max(ret,val);
	}
	printf("%.12f\n",ret);
}