#include <bits/stdc++.h> 

using namespace std;
#define int long long
int x;
vector<int>rev;
int ptr=0;
#undef int
int main(){
	#define int long long
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>x;
	int k;cin>>k;
	rev.push_back(0);
	for(int i=0;i<k;i++){
		int t;cin>>t;
		rev.push_back(t);
	}
	int q;cin>>q;
	int d=0,u=x,dans=0,uans=x;
	for(int i=0;i<q;i++){
		int t,a;cin>>t>>a;
		while(ptr<rev.size()-1&&t>=rev[ptr+1]){
			if(ptr%2==0){
				dans-=(rev[ptr+1]-rev[ptr]);
				if(dans<0){
					d+=(-dans);
					dans=0;
				}
				if(d>u){
					d=u;uans=0;
				}else{
					uans-=(rev[ptr+1]-rev[ptr]);
				}
			}else{
				uans+=(rev[ptr+1]-rev[ptr]);
				if(uans>x){
					u-=(uans-x);
					uans=x;
				}
				if(u<d){
					u=d;dans=x;
				}else{
					dans+=(rev[ptr+1]-rev[ptr]);
				}
			}
			ptr++;
		}
		if(ptr%2==0){
			if(a>=u){
				cout<<max(0LL,uans-(t-rev[ptr]))<<"\n";
			}else if(a<=d){
				cout<<max(0LL,dans-(t-rev[ptr]))<<"\n";
			}else{
				int stans=(a-d)+dans;
				cout<<max(0LL,stans-(t-rev[ptr]))<<"\n";
			}
		}else{
			if(a>=u){
				cout<<min(x,uans+(t-rev[ptr]))<<"\n";
			}else if(a<=d){
				cout<<min(x,dans+(t-rev[ptr]))<<"\n";
			}else{
				int stans=(a-d)+dans;
				cout<<min(x,stans+(t-rev[ptr]))<<"\n";
			}
		}
	}
	return 0;
}