#include<iostream>
#include<string>
#include<set>
#include<iterator>
#include<algorithm>
#include<vector>

using namespace std;

typedef basic_string<bool> BS;
const BS T=BS(1,true);
const BS F=BS(1,false);

char str[999];
char *p;

struct Cell{
  Cell *l,*r;
  BS bs;
  set<BS> sbs;
  int num,den;
  Cell():l(),r(),num(),den(1){
    while(*p==' '){
      p++;
    }
    if(*p=='x'){
      p++;
      bs=T+F;
    }else{
      p++;
      l=new Cell();
      r=new Cell();
      if(*r>*l){
	swap(l,r);
      }
      vector<BS> u,i;
      set_union(begin(l->sbs),end(l->sbs),begin(r->sbs),end(r->sbs),back_inserter(u));
      set_intersection(begin(l->sbs),end(l->sbs),begin(r->sbs),end(r->sbs),back_inserter(i));
      num=i.size();
      den=u.size();
      sbs=set<BS>(begin(u),end(u));
      bs=T+l->bs+r->bs+F;
    }
    p++;
    sbs.insert(bs);
  }
  bool operator>(const Cell &c)const{
    if(num*c.den!=c.num*den){
      return num*c.den<c.num*den;
    }else if(l==nullptr&&c.l==nullptr){
      return false;
    }else if(*l>*c.l||*c.l>*l){
      return *l>*c.l;
    }else{
      return *r>*c.r;
    }
  }
  void print(bool left){
    if(l==nullptr){
      cout<<'x';
    }else{
      cout<<'(';
      if(!left){
	swap(l,r);
      }
      l->print(true);
      cout<<' ';
      r->print(false);
      cout<<')';
    }
  }
  ~Cell(){
    delete l;
    delete r;
  }
};


int main(){
  while(cin.getline(str,999),str[0]!='0'){
    p=str;
    Cell c;
    c.print(true);
    cout<<endl;
  }
}