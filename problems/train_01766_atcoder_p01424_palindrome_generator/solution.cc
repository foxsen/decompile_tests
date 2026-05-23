#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

int min(int a,unsigned int b){
	return min(a,(int)b);
}
int min(unsigned int a,int b){
	return min((int)a,b);
}

struct edge{
	int to,cost;
	edge(){}
	edge(int a,int b):to(a),cost(b){}
};

vector<edge> G[210210];
vector<edge> rG[210210];

int V;
int N;
string strs[100];

int encode(int i,int j,int a,int l){
	if(l==0){
		return i*2100+j*21;
	}
	if(a==0){//left
		return i*2100+j*21+l;
	}
	if(a==1){//right
		return i*2100+j*21+10+l;
	}
}

vector<int> prv[100],nxt[100];

bool isPalin(string str){
	for(int i=0;i<str.size();i++){
		if(str[i]!=str[str.size()-i-1]) return false;
	}
	return true;
}

bool match(string str1,string str2){
	if(str1.size()!=str2.size()){
		fprintf(stderr,"invalid call for match\n");
		fprintf(stderr,"%s %s\n",str1.c_str(),str2.c_str());
		exit(0);
	}
	for(int i=0;i<str1.size();i++){
		if(str1[i]!=str2[str2.size()-i-1]) return false;
	}
	return true;
}

void getGraph(){
	V=(2100*(N-1)+21*(N-1)+21)+2;
	for(int le=0;le<N;le++){
		for(int ri=0;ri<N;ri++){
			//no remaining chars
			int v=encode(le,ri,0,0);
			for(int i=0;i<nxt[ri].size();i++){
				int id=nxt[ri][i];
				int s=strs[nxt[ri][i]].size();
				int nv=encode(le,id,1,s);
				G[v].push_back(edge(nv,s));
			}
			for(int i=0;i<prv[le].size();i++){
				int id=prv[le][i];
				int s=strs[id].size();
				int nv=encode(id,ri,0,s);
				G[v].push_back(edge(nv,s));
			}
			
			//left is unmatched
			for(int l=1;l<=strs[le].size();l++){
				int v=encode(le,ri,0,l);
				for(int i=0;i<nxt[ri].size();i++){
					int id=nxt[ri][i];
					int m=min(l,strs[id].size());
					int s=strs[id].size();
					string str1=strs[le].substr(l-m,m);
					string str2=strs[id].substr(0,m);
					bool flg=match(str1,str2);
					if(!flg) continue;
					if(l>m){
						int nv=encode(le,id,0,l-m);
						G[v].push_back(edge(nv,s));
					}/*else if(l==m&&m==strs[id].size()){
						int nv=encode(le,id,0,0);
						G[v].push_back(edge(nv,m));
					}*/else{
						int nv=encode(le,id,1,s-m);
						G[v].push_back(edge(nv,s));
					}
				}
			}
			
			//right is unmatched
			for(int l=1;l<=strs[ri].size();l++){
				int v=encode(le,ri,1,l);
				for(int i=0;i<prv[le].size();i++){
					int id=prv[le][i];
					int m=min(l,strs[id].size());
					string str1=strs[id].substr(strs[id].size()-m,m);
					string str2=strs[ri].substr(strs[ri].size()-l,m);
					int s=strs[id].size();
					bool flg=match(str1,str2);
					if(!flg) continue;
					if(l>m){
						int nv=encode(id,ri,1,l-m);
						G[v].push_back(edge(nv,s));
					}/*else if(l==m&&m==strs[id].size()){
						int nv=encode(id,ri,0,0);
						G[v].push_back(edge(nv,m));
					}*/else{
						int nv=encode(id,ri,0,s-m);
						G[v].push_back(edge(nv,s));
					}
				}
			}
		}
	}
	//from empty string
	for(int i=0;i<N;i++){
		//palindrome
		if(isPalin(strs[i])){
			int v=encode(i,i,0,0);
			G[V-2].push_back(edge(v,strs[i].size()));
		}
		
		//left is unmatched
		for(int l=1;l<=strs[i].size();l++){
			string str;
			if(l==strs[i].size()) str="";
			else str=strs[i].substr(l,1000);
			if(!isPalin(str)) continue;
			int v=encode(i,i,0,l);
			G[V-2].push_back(edge(v,strs[i].size()));
		}
		
		//right is unmatched
		for(int l=1;l<=strs[i].size();l++){
			string str=strs[i].substr(0,strs[i].size()-l);
			if(!isPalin(str)) continue;
			int v=encode(i,i,1,l);
			G[V-2].push_back(edge(v,strs[i].size()));
		}
	}
	//to goal
	for(int le=0;le<N;le++) for(int ri=0;ri<N;ri++){
		int v=encode(le,ri,0,0);
		G[v].push_back(edge(V-1,0));
	}
	for(int v=0;v<V;v++){
		for(int j=0;j<G[v].size();j++){
			rG[G[v][j].to].push_back(edge(v,G[v][j].cost));
		}
	}
}

bool from_s[220220];
bool from_t[220220];

queue<int> que;
void reachable(int s,bool *res,bool rev){
	while(!que.empty()) que.pop();
	que.push(s);
	for(int i=0;i<V;i++) res[i]=false;
	res[s]=true;
	while(!que.empty()){
		int v=que.front();
		que.pop();
		if(!rev){
			for(int i=0;i<G[v].size();i++){
				int nxt=G[v][i].to;
				if(res[nxt]) continue;
				res[nxt]=true;
				que.push(nxt);
			}
		}else{
			for(int i=0;i<rG[v].size();i++){
				int nxt=rG[v][i].to;
				if(res[nxt]) continue;
				res[nxt]=true;
				que.push(nxt);
			}
		}
	}
}

bool is_valid[220220];

int cmp[220220];
bool used[220220];

vector<int> vs;
void dfs(int v){
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		int nxt=G[v][i].to;
		if(!is_valid[nxt]) continue;
		if(used[nxt]) continue;
		dfs(nxt);
	}
	vs.push_back(v);
}

void rdfs(int v,int k){
	used[v]=true;
	cmp[v]=k;
	for(int i=0;i<rG[v].size();i++){
		int nxt=rG[v][i].to;
		if(!is_valid[nxt]) continue;
		if(used[nxt]) continue;
		rdfs(nxt,k);
	}
}

void scc(){
	for(int i=0;i<V;i++) used[i]=false;
	for(int i=0;i<V;i++){
		if(!is_valid[i]) continue;
		if(used[i]) continue;
		dfs(i);
	}
	for(int i=0;i<V;i++) used[i]=false;
	int k=0;
	for(int i=(int)vs.size()-1;i>=0;i--){
		int v=vs[i];
		if(!is_valid[v]) continue;
		if(used[v]) continue;
		rdfs(v,k++);
	}
}

int cnt[220220];
bool checkInf(){
	for(int i=0;i<V;i++){
		if(!is_valid[i]) continue;
		cnt[cmp[i]]++;
		if(cnt[cmp[i]]>=2) return true;
	}
	return false;
}

int dp[220220];
int prvs[220220];
void rec(int v){
	if(dp[v]!=-1) return;
	int M=0;
	int p=-1;
	for(int i=0;i<rG[v].size();i++){
		int prv=rG[v][i].to;
		if(!is_valid[prv]) continue;
		int c=rG[v][i].cost;
		rec(prv);
		if(M<dp[prv]+c) p=prv;
		M=max(M,dp[prv]+c);
	}
	prvs[v]=p;
	dp[v]=M;
}

int solve(){
	getGraph();
	reachable(V-2,from_s,false);
	reachable(V-1,from_t,true);
	if(from_s[V-1]==false) return 0;
	for(int i=0;i<V;i++) is_valid[i]=from_s[i]&from_t[i];
	scc();
	bool is_inf=checkInf();
	if(is_inf) return -1;
	for(int i=0;i<V;i++) dp[i]=-1;
	dp[V-2]=0;
	rec(V-1);
	int res=dp[V-1];
	return res;
}

void input(){
	int M;
	scanf("%d%d",&N,&M);
	char ch[20];
	for(int i=0;i<N;i++){
		scanf("%s",ch);
		strs[i]=string(ch);
	}
	for(int i=0;i<M;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		nxt[u].push_back(v);
		prv[v].push_back(u);
	}
}

int main(){
	input();
	int ans=solve();
	printf("%d\n",ans);
	return 0;
}