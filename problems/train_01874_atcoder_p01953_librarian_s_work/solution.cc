#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define pb push_back
typedef long long ll;
typedef pair<ll,ll>P;
#define fi first
#define sc second
#define mp make_pair
int n,c;
vector<int>za[(1<<18)];
vector<ll>sum[(1<<18)];
vector<ll>num[(1<<18)];
int a[100005],cc[100005];
void add(int i,int v){
	i += (1<<17)-1;
	za[i].pb(v);
}
void make(){
	for(int i=(1<<18)-1;i>=(1<<17)-1;i--){
		sort(za[i].begin(),za[i].end());
		za[i].erase(unique(za[i].begin(),za[i].end()),za[i].end());
		sum[i].resize(za[i].size()+1,0);
		num[i].resize(za[i].size()+1,0);
	}
	for(int i=(1<<17)-2;i>=0;i--){
		za[i].resize(za[i*2+1].size()+za[i*2+2].size());
		merge(za[i*2+1].begin(),za[i*2+1].end(),za[i*2+2].begin(),za[i*2+2].end(),za[i].begin());
		za[i].erase(unique(za[i].begin(),za[i].end()),za[i].end());
		sum[i].resize(za[i].size()+1,0);
		num[i].resize(za[i].size()+1,0);
	}
}
int f(int x){ return x&-x;}
void addsum(int pos,int k,int a){
	for(int i=k;i<sum[pos].size();i+=f(i)) sum[pos][i]+=a;
}
void addnum(int pos,int k,int a){
	for(int i=k;i<num[pos].size();i+=f(i)) num[pos][i]+=a;
}
ll sumsum(int pos,int k){
	ll res = 0;
	for(int i=k;i>0;i-=f(i)) res+=sum[pos][i];
	return res;
}
ll sumnum(int pos,int k){
	ll res = 0;
	for(int i=k;i>0;i-=f(i)) res+=num[pos][i];
	return res;
}
ll query(int a,int b,int k,int l,int r,int aa){
	if(r<a||b<l) return 0;
	if(a<=l&&r<=b){
		int x = lower_bound(za[k].begin(),za[k].end(),aa)-za[k].begin();
		ll v = sumsum(k,x)*1LL*c + sumnum(k,x)*1LL*aa; //cout<<sumsum(k,x)<<" " << sumnum(k,x)<<endl;
		v += (sumsum(k,sum[k].size()-1)-sumsum(k,x)) + (sumnum(k,sum[k].size()-1)-sumnum(k,x))*1LL*c*aa;
		/*if(v){
				cout<<(sumnum(k,sum[k].size()-1)-sumnum(k,x))<<endl;
				cout<<(sumsum(k,sum[k].size()-1)-sumsum(k,x))<<endl;
				cout<<a<<b<<endl;
				cout<<"===="<<endl;
		}*/
		return v;
	}
	return query(a,b,k*2+1,l,(l+r)/2,aa)+query(a,b,k*2+2,(l+r)/2+1,r,aa);
}
void make2(int a,int b){
	a += (1<<17)-1;
	int c = lower_bound(za[a].begin(),za[a].end(),b)-za[a].begin()+1;
	addsum(a,c,b); addnum(a,c,1);
	while(a){
		a = (a-1)/2;
		c = lower_bound(za[a].begin(),za[a].end(),b)-za[a].begin()+1;
		addsum(a,c,b); addnum(a,c,1);
	}
}
int main(){
	cin>>n>>c;
	rep(i,n)cin>>a[i]>>cc[i];
	rep(i,n){
		add(a[i],cc[i]);
	}
	make(); ll ret = 0; //return 0;
	for(int i=0;i<n;i++){
		ret += query(a[i]+1,(1<<17)-1,0,0,(1<<17)-1,cc[i]);
		//cout<<ret<<endl;
		make2(a[i],cc[i]);
	}
	cout<<ret<<endl;
}

