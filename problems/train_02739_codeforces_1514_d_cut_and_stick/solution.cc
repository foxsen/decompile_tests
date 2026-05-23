//BISMILAHIRAHMANIR RAHIM
#include<bits/stdc++.h>
using namespace std;
struct query
{
	int l;
	int r;
	int i;
	
};
query Q[300001];
int arr[300001] , ans[300001];
int freq[300001];
int freqOfreq[300001];

int currentMax =0,block=555;

bool comp(query a,query b){
	if(a.l/block != b.l/block)
		return a.l/block < b.l/block;

	return a.r < b.r;
}

void add(int pos){
	int x = freq[arr[pos]];
	int y = x+1;

	freq[arr[pos]]++;

	freqOfreq[x]--;
	freqOfreq[y]++;

	if(y>currentMax) currentMax = y;

}
void remove(int pos){
	int x = freq[arr[pos]];
	int y = x-1;

	freq[arr[pos]]--;

	freqOfreq[x]--;
	freqOfreq[y]++;

	if(y < currentMax)while(freqOfreq[currentMax]==0)currentMax--;
	

}


int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,q;
	cin>>n>>q;
	//block = sqrt(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<q;i++){
		cin>>Q[i].l>>Q[i].r;

		Q[i].l--;
		Q[i].r--;
		Q[i].i=i;
	}

	sort(Q,Q+q,comp);

	int ML=0,MR=-1;

	for(int i=0;i<q;i++){
		int L = Q[i].l;
		int R = Q[i].r;

		while(MR<R)
			MR++,add(MR);
		
		while(ML>L)
			ML--,add(ML);

		while(MR>R)
			remove(MR),MR--;

		while(ML<L)
			remove(ML),ML++;
	

		int total = Q[i].r - Q[i].l+1;
		int mx = (total+1)/2;

		int rem = total - currentMax;

		if(currentMax<=mx){
			ans[Q[i].i] = 1;
		}
		else{
			ans[Q[i].i] = total - rem*2;
		}
	}

	for(int i=0;i<q;i++)
		cout<<ans[i]<<'\n';





	

	



}
///ALHAMDULILLAH//
