#include<cstdio>
#include<vector>

#define	pb	push_back

using namespace std;

typedef	vector<int>	vi;

int main(){
	static bool era[1000000];
	for(int i=2;i<100;i++){
		if(!era[i])	for(int j=i*i;j<1000000;j+=i)	era[j]=true;
	}

	vi pr;
	for(int i=2;i<1000000;i++)	if(!era[i])	pr.pb(i);
	int n=pr.size();

	for(long long L;scanf("%lld",&L),L;){
		if(L==1){ puts("1"); continue; }

		vi q;
		int old=-1;
		for(int i=0;i<n&&L>1;){
			if(L%pr[i]==0){
				L/=pr[i];
				if(old==i)	q.back()++;
				else		q.pb(1);
				old=i;
			}
			else	i++;
		}
		if(L>1)	q.pb(1);

		int prod=1;
		for(int i=0;i<q.size();i++)	prod*=(2*q[i]+1);
		printf("%d\n",(prod-1)/2+1);
	}

	return 0;
}