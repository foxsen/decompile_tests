#include<stdio.h>
int n,a,b,s;
int main(){
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++){
        int t=(i/10)%10+i%10+(i/100)%10+(i/1000)%10+(i/10000)%10;
        if(a<=t&&t<=b) s+=i;
    }
    printf("%d\n",s);
}
