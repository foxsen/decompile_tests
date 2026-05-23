#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

struct Panel{
  string name;
  int x1,y1,x2,y2;
  Panel *parent;
  vector<Panel> child;

  void init(){name="";x1=y1=x2=y2=0;parent=NULL;child.clear();}
};

Panel list;
pair<string,int>ans;
int maxDepth;

void parse(string s)
{
  stringstream ss;
  for(int i=0;i<s.size();i++)if(s[i]==','||s[i]=='<'||s[i]=='>')s[i]=' ';
  ss.str(s);

  stack<string>st;

  Panel *now=&list;
  ss>>list.name>>list.x1>>list.y1>>list.x2>>list.y2;
  st.push(list.name);

  while(!st.empty()){
    Panel p={"",0,0,0,0,NULL};
    ss>>p.name;
    if(p.name[0]=='/'){
      st.pop();
      now=(*now).parent;
      continue;
    }
    st.push(p.name);
    p.parent=now;
    ss>>p.x1>>p.y1>>p.x2>>p.y2;
    (*now).child.push_back(p);
    now=&(*now).child[(*now).child.size()-1];
  }

}

void solve(Panel p, int x, int y, int depth)
{
  if(x<p.x1 || p.x2<x || y<p.y1 || p.y2<y)return;
  if(maxDepth<depth){
    maxDepth=depth;
    ans.first=p.name;
    ans.second=p.child.size();
  }
  vector<Panel>::iterator it;
  for(it=p.child.begin();it!=p.child.end();it++)solve(*it,x,y,depth+1);
}

int main()
{
  string s;
  int n,x,y;
  while(cin>>n,n){
    cin>>s;
    list.init();
    parse(s);
    for(int i=0;i<n;i++){
      cin>>x>>y;
      maxDepth=-1;
      solve(list,x,y,0);
      if(maxDepth==-1){
	ans.first="OUT OF MAIN PANEL";
	ans.second=1;
      }
      cout<<ans.first<<" "<<ans.second<<endl;
    }
  }
}