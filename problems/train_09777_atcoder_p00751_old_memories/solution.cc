#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<ctime>
using namespace std;
#define INF (1<<29)



class PMA{//Aho-Corasick
	struct Node{
		bool match;
		int failure;
		int len;
		int next[256];
		Node(int len):failure(-1),len(len),match(false){memset(next,-1,sizeof(next));}
	};
	vector<Node> node;

	void precompute(){
		for(int i=1;i<(int)node.size();i++){
			for(int j=0;j<256;j++){
				node[i].next[j]=_step(i,j);
			}
		}
	}
	int _step(int t,char c)const{
		while(node[t].next[c]==-1)t=node[t].failure;
		return node[t].next[c];
	}
public:
	PMA(){}
	~PMA(){
		node.clear();
	}
	int size()const{return node.size();}
	bool matched(int id)const{return node[id].match;}
	void build(const vector<string> &p){
		node.clear();
		node.push_back(Node(0));
		for(int i=0;i<(int)p.size();i++){
			const string &s=p[i];
			int t=0;
			for(int j=0;j<(int)s.size();j++){
				if(node[t].next[s[j]]==-1){
					node[t].next[s[j]]=node.size();
					node.push_back(Node(j+1));				
				}
				t=node[t].next[s[j]];
			}
			node[t].match=true;
		}
		queue<int> q;
		for(int i=0;i<256;i++){
			Node &root=node[0];
			if(root.next[i]!=-1){
				q.push(root.next[i]);
				node[root.next[i]].failure=0;
			}else root.next[i]=0;
		}
		while(!q.empty()){
			int t=q.front();q.pop();
			for(int i=0;i<256;i++){
				if(node[t].next[i]!=-1){
					q.push(node[t].next[i]);
					int r=_step(node[t].failure,i);
					int v=node[t].next[i];
					node[v].failure = r;
					if(r!=-1)node[v].match |= node[r].match;
				}
			}
		}
		precompute();
	}
	int step(int t,char c)const{
		return node[t].next[c];
	}
	int length(int t)const{
		return node[t].len;
	}
};




PMA pma;
vector<string> piece;
int pLen;
vector<string> ans;
const char C[28]=".ABCDEFGHIJKLMNOPQRSTUVWXYZ";


bool match(string &s){
	int node=0;
	int cover=-1;
	for(int i=0;i<s.size();i++){
		node=pma.step(node,s[i]);
		if(pma.matched(node))cover = i;
		else if(i-cover>pma.length(node))return false;
		//else if(pLen==i-cover)return false;
	}
	return cover==s.size()-1;
}
void search(string &s,int d){
	if(d==0){
		//cout<<s<<endl;
		if(match(s))ans.push_back(s);
		return;
	}
	//search(s,d-1);
	string t(s.begin(),s.end());
	t+=' ';
	for(int i=s.size();;i--){//insert
		for(int j=0;j<27;j++){
			t[i]=C[j];
			search(t,d-1);
		}
		if(i==0)break;
		t[i]=t[i-1];
	}
	for(int i=0;i<s.size();i++){//replace
		for(int j=0;j<27;j++){
			char c=s[i];
			s[i]=C[j];
			search(s,d-1);
			s[i]=c;
		}
	}
	t.assign(s,1,s.size()-1);
	char c = s[0];
	for(int i=0;i<t.size();i++){//remove
		search(t,d-1);
		swap(c,t[i]);
	}
	search(t,d-1);
}
int main(){
	//clock_t t=clock();
	int d,n;
	while(cin>>d>>n,d|n){
		string alter;
		cin>>alter;
		piece.clear();
		for(int i=0;i<n;i++){
			string t;
			cin>>t;
			piece.push_back(t);
			pLen=t.size();
		}
		pma.build(piece);
		ans.clear();
		search(alter,d);
		sort(ans.begin(),ans.end());
		ans.erase(unique(ans.begin(),ans.end()),ans.end());
		cout<<ans.size()<<endl;
		if(ans.size()<=5){
			for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
		}
	}
	//cout<<((double)(clock()-t)/CLOCKS_PER_SEC)<<endl;
	return 0;
}