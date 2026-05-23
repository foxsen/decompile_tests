#include<bits/stdc++.h>
using namespace std;
#define ran 100001
bool f[ran];int p[ran],s[ran];int lp;
int main(){
	f[0] = f[1] = true;
	for(int i=2; i<ran; i++){
		if(!f[i]){
			p[lp++] = i;
		}
		for(int j=0; j<lp; j++){
			int x = i*p[j];
			if(x>=ran)break;
			f[x] = true;
			if(i%p[j]==0)break;
		}
	}
	for(int i=3; i<ran; i++){
		s[i] = s[i-1];
		if(!f[i] && !f[(i+1)/2]){
			s[i]++;
		}
	}
	int q;
	for(scanf("%d",&q); q--;){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",s[y]-s[x-1]);
	}
	return 0;
}
