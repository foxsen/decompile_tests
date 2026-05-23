#include <bits/stdc++.h>
using namespace std;
const int N=200000+5;
int main()
{
    int n,a[N],b[N];
    cin >> n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]),b[i]=a[i];
    sort(b,b+n);
    int x,y;
    y=b[n/2],x=b[n/2-1];
    for(int i=0;i<n;i++)
    {
        if(a[i]<=x) printf("%d\n",y);
        else if(a[i]>=y) printf("%d\n",x);
    }
    return 0;
}
