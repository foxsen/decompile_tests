#include<iostream>
#include<algorithm>
#define r(i,n) for(int i=0;i<n;i++)
#define z 100
using namespace std;
int n,a,b,q[z],l[z],la,be,an,ct[z],c[z][z];bool v[z],s[z];void d(int x,int len){if(len>be){la=x;be=len;}v[x]=1,s[x]=1;for(int i=0;i<ct[x];i++)if(!v[c[x][i]]){d(c[x][i],len+1);v[c[x][i]]=0;}}int main(){while(1){cin>>n;if(!n)break;r(i,z)ct[i]=0;r(i,n){cin>>a>>b;a--,b--;c[a][ct[a]]=b,c[b][ct[b]]=a;ct[a]++,ct[b]++;}r(i,z)s[i]=0;an=0;for(int i=0;i<z;i++)if(!s[i]){r(i,z)v[i]=0;be=0;d(i,1);r(i,z)v[i]=0;be=0;d(la,1);an=max(an,be);}cout<<an<<endl;}return 0;}