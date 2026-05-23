#include<bits/stdc++.h>
#define ll long long
const int inf=1e9;
using namespace std;
int v[200005],aux[200005];
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    sort(v+1,v+n+1);
    reverse(v+1,v+n+1);
    aux[0]=1;
    aux[1]=-1;
    int sum=0,j=1;
    for(i=0;i<=200000;i++){
        sum=sum+aux[i];
        aux[i+1]+=aux[i];
        if (sum+aux[i+1]>=k){
            printf("%d\n",i+1);
            return 0;
        }
        while(aux[i]>0 && j<=n){
            aux[i]--;
            aux[i+2]++;
            aux[i+2+v[j]/2]--;
            aux[i+2]++;
            aux[i+2+(v[j]-1)/2]--;
            j++;
            sum--;
        }
    }
    printf("-1\n");
return 0;
}
