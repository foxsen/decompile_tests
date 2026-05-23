#include <cstdio>

int n,tmp,a[200010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d",&tmp);
        a[tmp]++;
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",a[i]);
    return 0;
}