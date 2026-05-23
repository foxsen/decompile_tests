#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
ll n,w[10000];

int main(){
	while(cin>>n){
		if(!n)return 0;
		for(int i=0;i<n;i++)cin>>w[i];
		sort(w,w+n);
		ll ans=0;
		for(int i=0;i<n;i++)ans+=w[i]*(n-1-i);
		cout<<ans<<endl;
	}
}