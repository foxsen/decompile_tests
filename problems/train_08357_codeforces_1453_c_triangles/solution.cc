#include<bits/stdc++.h>
long long res[10],n,i,j,h,k,t[10],d[10],m,l[10],r[10],test,mt[10][2002],md[10][2002],mr[10][2002],ml[10][2002];
int a[2005][2005];
char c;
using namespace std;
int main()
{
    cin>>test;
    for(h=1;h<=test;h++)
    {
        cin>>n;
        for(i=0;i<=9;i++)
        {
            res[i]=0;
            t[i]=n+1;l[i]=n+1;
            r[i]=0;d[i]=0;
            for(j=1;j<=n;j++)
            {
                mt[i][j]=n+1,ml[i][j]=n+1;
                mr[i][j]=0;
                md[i][j]=0;
            }
        }
        for(i=1;i<=n;i++) for(j=1;j<=n;j++)
        {
            cin>>c;
            a[i][j]=c-'0';
            t[a[i][j]]=min(t[a[i][j]],i);
            l[a[i][j]]=min(l[a[i][j]],j);
            d[a[i][j]]=max(d[a[i][j]],i);
            r[a[i][j]]=max(r[a[i][j]],j);
            mt[a[i][j]][j]=min(mt[a[i][j]][j],i);
            ml[a[i][j]][i]=min(ml[a[i][j]][i],j);
            md[a[i][j]][j]=max(md[a[i][j]][j],i);
            mr[a[i][j]][i]=max(mr[a[i][j]][i],j);
        }

        for(i=1;i<=n;i++) for(j=1;j<=n;j++)
        {
            if (md[a[i][j]][j]!=n+1) res[a[i][j]]=max(res[a[i][j]],(md[a[i][j]][j]-i)*max(n-j,j-1));
            if (mt[a[i][j]][j]!=0) res[a[i][j]]=max(res[a[i][j]],(i-mt[a[i][j]][j])*max(n-j,j-1));
            if (ml[a[i][j]][i]!=0) res[a[i][j]]=max(res[a[i][j]],(j-ml[a[i][j]][i])*max(n-i,i-1));
            if (mr[a[i][j]][i]!=n+1) res[a[i][j]]=max(res[a[i][j]],(mr[a[i][j]][i]-j)*max(n-i,i-1));
            res[a[i][j]]=max(res[a[i][j]],max(n-i,i-1)*max(j-l[a[i][j]],r[a[i][j]]-j));
            res[a[i][j]]=max(res[a[i][j]],max(n-j,j-1)*max(i-t[a[i][j]],d[a[i][j]]-i));
        //    if (a[i][j]==2) cout<<"asd "<<max(n-j,j-1)<<" "<<max(i-t[a[i][j]],d[a[i][j]]-i)<<endl;
        }
        for(i=0;i<=9;i++) cout<<res[i]<<' ';cout<<endl;
    }
}
                