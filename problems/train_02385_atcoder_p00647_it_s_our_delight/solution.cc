#include<cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	for(int n;scanf("%d",&n),n;){
		int ans[3]={},tot[3]={};
		rep(_,n){
			int h,m,m2; scanf("%d:%d%d",&h,&m,&m2);
			if(m2<m) m2+=60;

			int t=60*h+m;
			if     (11<=h && h<15){ tot[0]++; if(m2-m<=8) ans[0]++; }
			else if(18<=h && h<21){ tot[1]++; if(m2-m<=8) ans[1]++; }
			else if(21<=h || h< 2){ tot[2]++; if(m2-m<=8) ans[2]++; }
		}

		char *s[]={"lunch","dinner","midnight"};
		rep(i,3){
			if(tot[i]==0) printf("%s no guest\n",s[i]);
			else          printf("%s %d\n",s[i],100*ans[i]/tot[i]);
		}
	}

	return 0;
}