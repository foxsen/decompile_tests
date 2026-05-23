#include<cstdio>
#include<algorithm>
#define ls p<<1,l,m
#define rs p<<1|1,m+1,r
using namespace std;
const int N=3e5+5,P=4*N;
int nn,mm,n,i,x,y,k;
struct arr{int x,y;}a[N];
bool operator < (arr A,arr B){return A.x<B.x;}
int read(){
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
int tl,tr;
struct stack{int x,k;}ql[N],qr[N];
int mx[P],ad[P];
void change(int p,int l,int r){
	if (x<=l&&r<=y){ad[p]+=k;mx[p]+=k;return;}
	int m=l+r>>1;
	if (x<=m) change(ls);if (y>m) change(rs);
	mx[p]=ad[p]+max(mx[p<<1],mx[p<<1|1]);
}
void build(int p,int l,int r){
	if (l==r){mx[p]=mm-a[l].x;return;}
	int m=l+r>>1;build(ls);build(rs);
	ad[p]=0;mx[p]=ad[p]+max(mx[p<<1],mx[p<<1|1]);
}
int work(){
	sort(a+1,a+n+1);int res=0;
	tl=1;ql[0].x=-1;ql[1]=(stack){0,0};
	tr=1;qr[0].x=-1;qr[1]=(stack){0,mm};
	build(1,0,n);int mid=mm>>1;
	for (i=1;i<=n;i++){
		res=max(res,(mx[1]+a[i].x)*2);
		if (a[i].y<=mid){
			for (;tl&&a[i].y>ql[tl].k;tl--)
				x=ql[tl-1].x+1,y=ql[tl].x,
				k=ql[tl].k-a[i].y,change(1,0,n);
			ql[++tl]=(stack){i-1,a[i].y};
		}
		else{
			for (;tr&&a[i].y<qr[tr].k;tr--)
				x=qr[tr-1].x+1,y=qr[tr].x,
				k=a[i].y-qr[tr].k,change(1,0,n);
			qr[++tr]=(stack){i-1,a[i].y};
		}
		ql[++tl]=(stack){i,0};qr[++tr]=(stack){i,mm};
	}
	return max(res,(mx[1]+nn)*2);
}
int main(){
	nn=read();mm=read();
	for (n=read(),i=1;i<=n;i++)
		a[i]=(arr){read(),read()};
	int ans=work();swap(nn,mm);
	for (i=1;i<=n;i++) swap(a[i].x,a[i].y);
	ans=max(ans,work());
	printf("%d",ans);
}