#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb         push_back

class Tree{
public:
  Tree *l,*r;
  char c;
  int x,y;
  int d;
  Tree():l(NULL),r(NULL),d(0){;}
};

//parsig
Tree *parse(string &in,int &p);
void destoroy(Tree *in);
bool getdata(string &in);

//debug
void travarse(Tree *in);

const int R = 200,C=500;
char m[R][C];

int get_space(int dl,int *l,int dr,int *r){
  int ret=0;
  for(int i=0;i<min(dr,dl);i++){
    ret=max(ret,l[i]+r[i]+2);//kankaku + below the node
    if (i+1 != dl){
      ret=max(ret,l[i+1]+r[i]+1);
    }
    if (i+1 != dr){
      ret=max(ret,l[i]+r[i+1]+1);
    }
  }
  return ret;
}

void merge(int dl,int *l,int dr,int *r,int dist,int opdist){
  int i=0;
  for(i=0;i<dl;i++){
    l[i]+=dist;
  }

  for(;i<dr;i++){//higher ??
    l[i]=r[i]-opdist;
  }
}

int make_pos(Tree *now,int *l,int *r){//return height
  int height=0;
  l[0]=0;
  r[0]=0;
  if (now->l == NULL){//0 node
    height=0;
  }else if (now->r == NULL){//1 node
    height=make_pos(now->l,l+1,r+1);
  }else{//two node
    int tl[R],tr[R];
    int dl = make_pos(now->l,l+1,tr);
    int dr = make_pos(now->r,tl ,r+1);
    
    now->d = get_space(dr,tl,dl,tr);

    int depth = max(dl,dr);
    merge(dl,l+1,depth,tl,(now->d+0)/2,(now->d+1)/2);
    merge(dr,r+1,depth,tr,(now->d+1)/2,(now->d+0)/2);
    height = depth;
    
  }
  return height+1;
}


void put_tree(int depth,int x,Tree *now){
  m[depth][x]=now->c;
  if (now->l == NULL){
  }else if (now ->r == NULL){
    m[depth+1][x]='-';
    put_tree(depth+2,x,now->l);
  }else {
    for(int i=x-now->d/2;i <= x+(now->d+1)/2 ; i++)
      m[depth+1][i]='-';
    put_tree(depth+2,x-now->d/2,now->l);
    put_tree(depth+2,x+(now->d+1)/2,now->r);
  }
}

int main(){
  int tc = 1;
  while(true){
    string in="";
 
    bool isend=getdata(in);
    fill(&m[0][0],&m[R][0],' ');
    int p = 0;
    Tree *root = parse(in,p);
    
    
    int tl[R],tr[R];
    rep(i,R)tl[i]=tr[i]=-1;


    
    cout << tc++<<":"<<endl;
    int tmp=make_pos(root,tl,tr);
    //    travarse(root);
    int findwid=0;
    rep(i,tmp){
      if (tl[i]<0)findwid=max(findwid,-tl[i]);
      else findwid=max(findwid,tl[i]);
      if (tr[i]<0)findwid=max(findwid,-tr[i]);
      else findwid=max(findwid,tr[i]);
    }

    put_tree(0,findwid+1,root);
    
    int l,r,u,d;
    for(d=0;d<R;d++){
      bool flag=false;
      rep(j,C)if(m[d][j] != ' '){flag=true;break;}
      if (flag){break;}
    }

    for(u=R-1;u>=0;u--){
      bool flag=false;
      rep(j,C)if (m[u][j] != ' '){flag=true;break;}
      if (flag){u++;break;}
    }

    for(l=0;l<C;l++){
      bool flag = false;
      REP(i,d,u)if (m[i][l] != ' '){flag=true;break;}
      if (flag){break;}
    }
    
    for(r =C-1;r>=0;r--){
      bool flag=false;
      REP(i,d,u)if (m[i][r] != ' '){flag=true;break;}
      if (flag){r++;break;}
    }
    
    for(int i=u-1;i>=d;i--){
      r = 0;
      rep(j,C)if (m[i][j] != ' ')r=j+1;
      REP(j,l,r)cout << m[i][j];
      cout << endl;
    }

    
    destoroy(root);

    if (isend)break;
  }
}


//parsing
Tree* parse(string &in,int &p){
  Tree *now;
  now = new Tree();
  now->c = in[p];

  p++;
  if (p < in.size() && in[p] != '('){//leaf
    ;
  }else{//
    p++;
    now->l = parse(in,p);
    if (in[p] == ')'){
    }else if (in[p] == ','){
      p++;
      int tmp = 0;
      now->r=parse(in,p);
    }
    p++;
  }
  return now;
}



void destoroy(Tree *in){
  if (in->l != NULL)destoroy(in->l);
  if (in->r != NULL)destoroy(in->r);
  free(in);
}

bool getdata(string &in){
  bool isend=false;
  while(true){
    char c = getchar();
    if (c == ';')break;
    if (c == '.'){
      isend=true;
      break;
    }    
    if (isalpha(c) || c == '(' || c == ')' || c == ',')in+=c;
  }
  return isend;
}



void travarse(Tree *in){
  cout << in->c <<" dist " << in->d;
  if (in->l != NULL)cout << " l: "<<in->l->c;
  if (in->r != NULL)cout << " r: "<<in->r->c;
  cout << endl;
  if (in->l != NULL)travarse(in->l);
  if (in->r != NULL)travarse(in->r);
}