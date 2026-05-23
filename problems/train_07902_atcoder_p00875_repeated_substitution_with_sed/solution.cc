#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstdio>
#include <ctime>
#include <assert.h>
#include <chrono>
#include <random>
#include <numeric>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

int n;

string a[11],b[11];
string s,t;

int solve(){
	set<string> st;
	queue<pair<string,int>> q;
	q.push({s,0});
	st.insert(s);
	while(q.size()){
		auto p=q.front(); q.pop();
		if(t==p.first)return p.second;
		string ss=p.first;
		for(int i=0;i<n;i++){
			string r="";
			for(int j=0;j<ss.size();j++){
				if(a[i]==ss.substr(j,a[i].size())){
					r+=b[i];
					j+=(int)(a[i].size()-1);
				}
				else{
					r+=ss[j];
				}
			}
			if(t.size()<r.size())continue;
			if(st.find(r)==st.end()){
				st.insert(r);
				q.push({r,p.second+1});
			}
		}
	}
	return -1;
}

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	while(cin >> n,n){
		for(int i=0;i<n;i++){
			cin >> a[i] >> b[i];
		}
		cin >> s >> t;
		printf("%d\n",solve());
	}
}
