#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  int q;
  while(cin>>q,q){
    using D = deque<int>;
    auto mv=
      [&](D &a,D &b,D &ax,D &ay,D &bx,D &by){
	if(!bx.empty()&&bx.back()==b.back()) bx.pop_back();
	if(!by.empty()&&by.back()==b.back()) by.pop_back();	  
	
	a.emplace_back(b.back());
	b.pop_back();
	
	if(ax.empty()||ax.back()>a.back()) ax.emplace_back(a.back());
	if(ay.empty()||ay.back()<a.back()) ay.emplace_back(a.back());
      };

    D a,b;
    D ax,ay,bx,by;
    
    while(q--){
      int t,x=-1;
      cin>>t;
      if(t==0||t==4||t==5||t==8||t==9) cin>>x;     

      if(t==0){	
	while(!bx.empty()&&bx.front()>x) bx.pop_front();
	while(!by.empty()&&by.front()<x) by.pop_front();
	b.emplace_front(x);
	bx.emplace_front(x);
	by.emplace_front(x);
      }
      
      if(t==1){
	if(!ax.empty()&&ax.back()==a.back()) ax.pop_back();
	if(!ay.empty()&&ay.back()==a.back()) ay.pop_back();
	cout<<a.back()<<endl;
	a.pop_back();
      }

      if(t==2) cout<<ax.back()<<endl;
      if(t==3) cout<<bx.back()<<endl;

      if(t==4) cout<<ax[ax.size()-x]<<endl;
      if(t==5) cout<<bx[bx.size()-x]<<endl;
            
      if(t==6) cout<<ay.back()<<endl;
      if(t==7) cout<<by.back()<<endl;
      
      if(t==8) cout<<ay[ay.size()-x]<<endl;
      if(t==9) cout<<by[by.size()-x]<<endl;
      
      while(a.size()<b.size())   mv(a,b,ax,ay,bx,by);
      while(a.size()>b.size()+1) mv(b,a,bx,by,ax,ay);

    }
    cout<<"end"<<endl;
  }
  return 0;
}

