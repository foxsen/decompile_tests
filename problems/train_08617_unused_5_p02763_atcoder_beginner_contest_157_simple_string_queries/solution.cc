#include <bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define VI vector<int>
#define pii pair<int,int>
using namespace std;
set<int> app[30];
const int MAXN = 5e5;
char S[MAXN+10];
int n, q;
char Q[2];
void q1(){
	int p;
	scanf("%d %s", &p, Q);
	char v = Q[0];
	p--;

	app[S[p]-'a'].erase(p);
	S[p] = v;
	app[S[p]-'a'].insert(p);
}

int q2(){
	int l, r;
	scanf("%d %d", &l, &r); l--; r--;
	int tot = 0;
	for(int i = 0; i < 26; i++){
		auto lb = app[i].lower_bound(l);
		if(lb != app[i].end() && *lb <= r) tot++;
	}
	return tot;
}
int main(){
	scanf("%d %s %d", &n, S, &q);
	for(int i = 0; i < n; i++){
		app[S[i]-'a'].insert(i);
	}
	for(int i = 0; i < q; i++){
		int qi;
		scanf("%d", &qi);
		if(qi == 1) q1();
		else printf("%d\n", q2());
	}
	return 0;
}