#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

int a[2000],b[2000];

int main(){
	int w,h;cin>>w>>h;
	priority_queue<int>que;
	rep(i,w){
		scanf("%d",&a[i]);
		if(a[i])que.push(a[i]);
	}
	rep(i,h){
		scanf("%d",&b[i]);
		vector<int>v;
		rep(j,b[i]){
			if(que.empty()){
				puts("0");return 0;
			}
			int p=que.top();que.pop();
			p--;
			if(p)v.push_back(p);
		}
		for(int i:v)que.push(i);
	}
	if(!que.empty())puts("0");
	else puts("1");
}
