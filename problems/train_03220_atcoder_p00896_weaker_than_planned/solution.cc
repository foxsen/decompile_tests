#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

char a[256];
int ans;

char m[256];
int used[256]={0};

void search(int n,int now,vector<string> &in,const vector<string> &words){
  if (ans >= 2)return;
  if (n == now){
    ans++;
    rep(i,256)a[i]=m[i];
    return;
  }
  rep(i,(int)words.size()){
    string cur = in[now];
    string tar = words[i];
    if (tar.size() != cur.size())continue;
    //check
    bool isok=true;
    rep(j,(int)cur.size()){
      //cout << j << " " << cur[j] <<" " << tar[j] <<" " << used[cur[j]] <<" " << used[tar[j]] << endl;
      if (used[(int)cur[j]] == -1 && used[(int)tar[j]] == -1){
	used[(int)tar[j]]=now;
	used[(int)cur[j]]=now;
	m[(int)cur[j]]=tar[j];
	m[(int)tar[j]]=cur[j];
      }else if (used[(int)cur[j]] == -1     || used[(int)tar[j]] == -1)isok=false;
      else  if (   m[(int)cur[j]] == tar[j] && m[(int)tar[j]] == cur[j])assert(used[cur[j]] != -1 && used[tar[j]] != -1);
      else isok=false;
    }
    //search
    if (isok){
      search(n,now+1,in,words);
    }
    //backtrack
    rep(j,(int)cur.size()){
      if (used[(int)cur[j]] == now && used[tar[j]] == now){
	used[(int)cur[j]]=-1,used[(int)tar[j]]=-1;
      }
    }
  }
}

bool cmp(const string & a,const string &b){
  if (a.size() != b.size())return a.size() > b.size();
  return a < b;
}

int main(){
  int n;
  while(cin>>n && n){
    rep(i,256)used[i]=-1;
    ans=0;

    vector<string> words(n),inp;
    rep(i,n)cin>>words[i];
    sort(words.begin(),words.end());
    words.erase(unique(words.begin(),words.end()),words.end());
    sort(words.begin(),words.end(),cmp);
    string in;getline(cin,in);
    getline(cin,in);
    string tmp = in;
    rep(i,(int)tmp.size())if (tmp[i] == '.')tmp[i]=' ';
    stringstream sin(tmp);
    while(sin>>tmp)inp.push_back(tmp);
    sort(inp.begin(),inp.end());
    inp.erase(unique(inp.begin(),inp.end()),inp.end());
    sort(inp.begin(),inp.end(),cmp);
    
    search(inp.size(),0,inp,words);
    assert(ans > 0);
    if (ans != 1)cout <<"-." << endl;//" " << ans << endl;
    else {
      rep(i,(int)in.size()){
	if (isupper(in[i]))cout<<a[in[i]];
	else cout << in[i];
      }
      cout << endl;
    }
  }
  return 0;
}