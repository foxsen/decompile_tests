#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int p, r, t;
int l[310], nl[310];
int n[310][310], nn[310][310];
pii a[200010];
int cnt[310];

bool check(int mid){
	for (int i = 1; i <= r; i++){
		nl[i] = l[i];
	}
	for (int i = 1; i <= p; i++){
		cnt[i] = 0;
		for (int j = 1; j <= r; j++){
			nn[i][j] = n[i][j], cnt[i] += n[i][j];
		}
	}
	for (int i = 0; i <= mid; i++){
		int P = a[i].fi, R = a[i].se;
		nl[R]--, nn[P][R]--, cnt[P]--;
		if (cnt[P] == 0){
			for (int j = 1; j <= r; j++){
				nl[j] += n[P][j];
			}
		}
	}
	int pd = 1;
	while (pd){
		pd = 0;
		for (int i = 1; i <= p; i++){
			int flag = 1, ppp = 1;
			for (int j = 1; j <= r; j++){
				if (nl[j] < nn[i][j]){
					flag = 0;
					break;
				}
				if (nn[i][j]) ppp = 0;
			}
			if (!flag || ppp) continue;
			for (int j = 1; j <= r; j++){
				nl[j] += n[i][j] - nn[i][j];
				nn[i][j] = 0;
			}
			pd = 1;
		}
	}
	for (int i = 1; i <= p; i++){
		for (int j = 1; j <= r; j++){
			if (nn[i][j]) return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d%d%d", &p, &r, &t);
	for (int i = 1; i <= r; i++){
		scanf("%d", &l[i]);
	}
	for (int i = 1; i <= p; i++){
		for (int j = 1; j <= r; j++){
			scanf("%d", &n[i][j]);
		}
	}
	for (int i = 0; i < t; i++){
		scanf("%d%d", &a[i].fi, &a[i].se);
	}
	if (!check(t - 1)){
		printf("-1\n");
		return 0;
	}
	int l = 0, r = t - 1;
	while (l < r){
		int mid = l + r >> 1;
		if (!check(mid)) l = mid + 1;
		else r = mid;
	}
	printf("%d\n", l + 1);
	return 0;
}

