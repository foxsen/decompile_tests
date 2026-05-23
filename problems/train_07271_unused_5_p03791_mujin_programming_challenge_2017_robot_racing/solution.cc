#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int mm=1000000007;
int i,j,k,n,a[200001],f[200001],w;
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=2,f[1]=1,w=0;i<=n;i++){
		k=(a[i-1]+1)/2;w=max(w,i-k-1);
		f[i]=(ll)f[i-1]*(ll)(i-w)%mm;
	}
	printf("%d\n",f[n]);
	return 0;
}