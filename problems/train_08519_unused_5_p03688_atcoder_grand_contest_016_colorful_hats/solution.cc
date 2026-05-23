#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int n,a[100000],mi = 10000000,ma = -1;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=0;i<n;i++){
		mi = min(mi,a[i]);
		ma = max(ma,a[i]);
	}
	switch(ma-mi){
		case 0:{
			if(mi==n-1||(2*mi<=n&&mi>0)) printf("Yes\n");
			else printf("No\n");
			break;
		}
		case 1:{
			int x = 0;
			for(int i=0;i<n;i++) if(a[i]==mi) x++;
			if(2*(ma-x)<=n-x&&ma-x>0) printf("Yes\n");
			else printf("No\n");
			break;
		}
		default:{
			printf("No\n");
			break;
		}
	}
}
