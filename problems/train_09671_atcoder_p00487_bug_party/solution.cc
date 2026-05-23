#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
pair<int,int> a[300010],c;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;
int main(){int n,r=0;cin>>n;for(int i=0;i<n;i++)cin>>a[i].x>>a[i].y;sort(a,a+n);long long s=0;for(int i=0;i<n;i++){s+=a[i].x,c.x=a[i].y,c.y=a[i].x;Q.push(c);while(!Q.empty()){if(s<=Q.size()*Q.top().x)break;s-=Q.top().y,Q.pop();}if(r<Q.size())r=Q.size();}cout<<r<<endl;return 0;}