#include<iostream>
#define m long long
using namespace std;
#define d(s,i,n) for(int i=s;i<n;i++)
m l[90],r[90],e[90][90],f[90][90];
signed main(){m n;cin>>n;l[0]=1;r[0]=1;d(1,i,90)l[i]=r[i-1],r[i]=l[i-1]+r[i-1];d(0,i,89){e[i][0]=1,f[i][0]=1;d(1,j,90){if(i+1==j)e[i][j]=f[i][j-1],f[i][j]=f[i][j-1]*2+e[i][j-1];else e[i][j]=f[i][j-1],f[i][j]=f[i][j-1]+e[i][j-1];}}d(0,i,n){m c,d;cin>>c>>d;m a=max(c,d);m b=min(c,d);m k=0;d(0,j,90)if(a>=r[j]&&b>=l[j])k=j;m g;if(k==0)k=1,g=1;else if(k==1)if(b==1)g=a;else g=4;else{g=1;if(b>=r[k]&&a>=l[k]&&l[k]<r[k])g++;d(0,j,k)if(f[j][k]<=a&&e[j][k]<=b)g+=1+(a-f[j][k])/e[j][k];d(0,j,k)if(f[j][k]<=b&&e[j][k]<=a)g+=1+(b-f[j][k])/e[j][k];}cout<<k<<" "<<g%1000000007<<endl;}}	