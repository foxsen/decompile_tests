#include<bits/stdc++.h>
#define mo 100000007
using namespace std;
long long read(){
    long long xx=0,flagg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
int n,m,len,i,x,y,a[1500005],flag[1500005],ch[1500005][3],top,ans[1500005];
char s[200005];
void buildtree(int v,int w,int ww){
	if(w==m){
		a[v]=ww;
		return;
	}
	top++;
	ch[v][0]=top;
	top++;
	ch[v][1]=top;
	top++;
	ch[v][2]=top;
	buildtree(ch[v][0],w*3,ww);
	buildtree(ch[v][1],w*3,ww+w);
	buildtree(ch[v][2],w*3,ww+w*2);
}
void ytree(int v,int w,int ww){
	if(w==m){
		ans[a[v]]=ww;
		return;
	}
	if(flag[v]==1){
		swap(ch[v][1],ch[v][2]);
		flag[ch[v][0]]^=1;
		flag[ch[v][1]]^=1;
		flag[ch[v][2]]^=1;
	}
	ytree(ch[v][0],w*3,ww);
	ytree(ch[v][1],w*3,ww+w);
	ytree(ch[v][2],w*3,ww+w*2);
}
int main(){
	//freopen("domino.in","r",stdin);
	//freopen("domino.out","w",stdout);
	n=read();
	scanf("%s",s+1);
	len=strlen(s+1);
	m=1;
	for(i=1;i<=n;i++)
		m*=3;
	buildtree(0,1,0);
	for(i=1;i<=len;i++){
		if(s[i]=='S')
			flag[0]^=1;
		else{
			x=0;
			while(ch[x][0]!=0){
				if(flag[x]==1){
					swap(ch[x][1],ch[x][2]);
					flag[ch[x][0]]^=1;
					flag[ch[x][1]]^=1;
					flag[ch[x][2]]^=1;
					flag[x]=0;
				}
				y=ch[x][2];
				ch[x][2]=ch[x][1];
				ch[x][1]=ch[x][0];
				ch[x][0]=y;
				x=y;
			}
		}
	}
	ytree(0,1,0);
	for(i=0;i<m;i++)
		pus(ans[i],1);
	cout<<endl;
    return 0;
}