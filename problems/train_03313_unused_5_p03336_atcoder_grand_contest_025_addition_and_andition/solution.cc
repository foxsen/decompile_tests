using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000010
int n,m,k;
char str[N];
int s[N],t[N];
struct Node{
	Node *pre,*suc;
	int s,n;
} *fir,*lst;
Node *ins(Node *p,int s,int n=1){
	Node *nw=new Node;
	*nw={p,p->suc,s,n};
	if (p->suc)
		p->suc->pre=nw;
	else
		lst=nw;
	p->suc=nw;
	return nw;
}
Node *check(Node *p){
	if (p->n==0){
		p->pre->suc=p->suc;
		if (p->suc)
			p->suc->pre=p->pre;
		else
			lst=p->pre;
		return p->pre;
	}
	if (p->pre && p->s==p->pre->s){
		p->pre->n+=p->n;
		p->pre->suc=p->suc;
		if (p->suc)
			p->suc->pre=p->pre;
		else
			lst=p->pre;
		return p->pre;
	}
	return p;
}
int ans[N*2],cnt;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",str);
	for (int i=0;i<n;++i)
		s[i]=str[n-1-i]-'0';
	scanf("%s",str);
	for (int i=0;i<m;++i)
		t[i]=str[m-1-i]-'0';
	n=max(n,m);	
	fir=lst=new Node;
	*lst=(Node){NULL,NULL,0,1000000000};
	for (int i=n-1;i>=0;--i)
		if (s[i]==1 && t[i]==1){
			int z=k;
			Node *p=lst;
			while (z){
				while (1){
					Node *q=check(p);
					if (q==p) break;
					p=q;
				}
				if (p->n==0){
					p->pre->suc=p->suc;
					if (p->suc) 
						p->suc->pre=p->pre;
					else
						lst=p->pre;
					p=p->pre;
					continue;
				}
				if (p->s==0){
					if (p->n<=z){
						z-=p->n;
						p=p->pre;
						if (z==0)
							ins(p,3,1);
					}
					else{
						p->n-=z;
						Node *q=ins(p,0,z);
						ins(p,3,1);
						break;
					}
				}
				else{
					while (1){
						Node *q=check(p->pre);
						if (q==p->pre) break;
						p->pre=q;
					}
					if (p->s==1){
						if (p->pre->s==0){
							p->s=0,p->n--;
							Node *q=ins(p,2,1),*r=ins(q,0,1);
							p->pre->n--;
							check(p->pre);
							ins(p->pre,1,1);
							check(p);
							break;
						}
						else{
							p->s=0,p->n--;
							Node *q=ins(p,2,1),*r=ins(q,0,1);
							p->pre->n--;
							p=p->pre;
							z--;
							check(p->suc);
							if (z==0)
								ins(p,3,1);
							p=check(p);
						}
					}
					else if (p->s==2){
						if (p->pre->s==0){
							p->s=0,p->n--;
							Node *q=ins(p,1,1),*r=ins(q,0,1);
							p->pre->n--;
							check(p->pre);
							ins(p->pre,2,1);
							check(p);
							break;
						}
						else{
							p->s=0,p->n--;
							Node *q=ins(p,1,1),*r=ins(q,0,1);
							p->pre->n--;
							p=p->pre;
							z--;
							check(p->suc);
							if (z==0)
								ins(p,3,1);
							p=check(p);
						}
					}
//				else
//					printf("fuck\n");
				}
			}
		}
		else{
			int f=s[i]|t[i]<<1;
			if (f==lst->s)
				lst->n++;
			else
				lst=ins(lst,f,1);
		}
	for (Node *p=lst;p!=fir;p=p->pre)
		for (int i=0;i<p->n;++i)
			ans[cnt++]=p->s;
	bool bz=0;
	for (int i=cnt-1;i>=0;--i){
		bz|=ans[i]&1;
		if (bz)
			putchar('0'+(ans[i]&1));
	}
//	if (bz==0)
//		putchar('0');
	putchar('\n');
	bz=0;
	for (int i=cnt-1;i>=0;--i){
		bz|=ans[i]>>1;
		if (bz)
			putchar('0'+(ans[i]>>1));
	}
//	if (bz==0)
//		putchar('0');
	return 0;
}



















