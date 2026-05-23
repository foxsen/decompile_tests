#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define INF 2e+9
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> PP;

int siz,segMax[300000],segAdd[300000],bit[300010];

void b_add(int i,int x){
	while(i <= siz){
		bit[i] += x;
		i += i & -i;
	}
}

int sum(int i){
	int s = 0;
	while(i){
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int a,int b,int x,int k = 0,int l = 0,int r = siz){
	if(b <= l || r <= a) return;
	if(a <= l && r <= b){
		segAdd[k] += x;
		return;
	}
	add(a,b,x,k * 2 + 1,l,(l + r) / 2);
	add(a,b,x,k * 2 + 2,(l + r) / 2,r);
	segMax[k] = max(segMax[k * 2 + 1] + segAdd[k * 2 + 1],segMax[k * 2 + 2] + segAdd[k * 2 + 2]);
}

int get(int a,int b,int k = 0,int l = 0,int r = siz){
	if(b <= l || r <= a) return 0;
	if(a <= l && r <= b) return segMax[k] + segAdd[k];
	return max(get(a,b,k * 2 + 1,l,(l + r) / 2),get(a,b,k * 2 + 2,(l + r) / 2,r)) + segAdd[k];
}

signed main(){
	int n,a[100000],ma = -1,mi = INF,tent = 0,ans = 0;
	bool used[100000] = {};
	vector<int> ls,rs,la,ra,as;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		as.push_back(a[i]);
	}
	sort(as.begin(),as.end());
	as.erase(unique(as.begin(),as.end()),as.end());
	for(int i = 0;i < n;i++) a[i] = lower_bound(as.begin(),as.end(),a[i]) - as.begin();
	for(int i = 0;i < n;i++){
		if(ma < a[i]){
			ma = a[i];
			ls.push_back(i);
			la.push_back(a[i]);
			used[i] = true;
		}
	}
	for(int i = n - 1;i >= 0;i--){
		if(mi > a[i]){
			mi = a[i];
			rs.push_back(i);
			ra.push_back(a[i]);
			used[i] = true;
		}
	}
	reverse(rs.begin(),rs.end());
	reverse(ra.begin(),ra.end());
	siz = 1;
	while(siz < n) siz *= 2;
	for(int i = 0;i < n;i++){
		tent += i - sum(a[i] + 1);
		b_add(a[i] + 1,1);
	}
	vector<PP> evt1[100001],evt2[100001];
	for(int i = 0;i < n;i++){
		if(!used[i]){
			int l1 = upper_bound(la.begin(),la.end(),a[i]) - la.begin();
			int l2 = upper_bound(ls.begin(),ls.end(),i) - ls.begin() - 1;
			int r1 = upper_bound(rs.begin(),rs.end(),i) - rs.begin();
			int r2 = lower_bound(ra.begin(),ra.end(),a[i]) - ra.begin() - 1;
			if(l1 <= l2 && r1 <= r2){
				evt1[r1].push_back(mp(2,mp(l1,l2)));
				evt2[r2].push_back(mp(-2,mp(l1,l2)));
			}
			if(l1 > 0 && la[l1 - 1] == a[i]){
				evt1[r1].push_back(mp(1,mp(l1 - 1,l1 - 1)));
				evt2[r2].push_back(mp(-1,mp(l1 - 1,l1 - 1)));
			}
			if(r2 < (int)rs.size() - 1 && ra[r2 + 1] == a[i]){
				evt1[r2 + 1].push_back(mp(1,mp(l1,l2)));
				evt2[r2 + 1].push_back(mp(-1,mp(l1,l2)));
			}
		}
	}
	for(int i = 0;i < n;i++){
		for(PP p : evt1[i]) add(p.second.first,p.second.second + 1,p.first);
		ans = max(ans,get(0,siz));
		for(PP p : evt2[i]) add(p.second.first,p.second.second + 1,p.first);
	}
	if(!tent) cout << ((ls.size() == n) ? 1 : 0) << endl;
	else cout << tent - ans - 1 << endl;
	return 0;
}