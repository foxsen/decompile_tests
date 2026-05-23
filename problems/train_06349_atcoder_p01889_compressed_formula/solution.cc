#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T,T MOD = 1000000007>
struct Mint{
  T v;
  Mint():v(0){}
  Mint(signed v):v(v){}
  Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}

  Mint pow(long long k){
    Mint res(1),tmp(v);
    while(k){
      if(k&1) res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }
  
  static Mint add_identity(){return Mint(0);}
  static Mint mul_identity(){return Mint(1);}
  
  Mint inv(){return pow(MOD-2);}
  
  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}
  
  Mint operator+(Mint a) const{return Mint(v)+=a;};
  Mint operator-(Mint a) const{return Mint(v)-=a;};
  Mint operator*(Mint a) const{return Mint(v)*=a;};
  Mint operator/(Mint a) const{return Mint(v)/=a;};

  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;}

  // find x s.t. a^x = b
  static T log(T a,T b){
    const T sq=40000;
    unordered_map<T, T> dp;
    dp.reserve(sq);
    Mint res(1);
    for(Int r=0;r<sq;r++){
      if(!dp.count(res.v)) dp[res.v]=r;
      res*=a;
    }
    Mint p=Mint(a).inv().pow(sq);
    res=b;
    for(Int q=0;q<=MOD/sq+1;q++){
      if(dp.count(res.v)){
        T idx=q*sq+dp[res.v];
        if(idx>0) return idx;
      }
      res*=p;
    }
    assert(0);
    return T(-1);
  }
  
  static Mint comb(long long n,Int k){
    Mint num(1),dom(1);
    for(Int i=0;i<k;i++){
      num*=Mint(n-i);
      dom*=Mint(i+1);
    }
    return num/dom;
  }
};


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  using M = Mint<Int>;
  struct T{
    // a + b * c
    M a,b,c;
    T():a(0),b(1),c(0){}    
    T(M a,M b,M c):a(a),b(b),c(c){}
    T add(char x){
      T res;
      if(x=='+'){
        res.a=a+b*c;
        res.b=M(1);
        res.c=M(0);
        return res;
      }
      if(x=='-'){        
        res.a=a+b*c;
        res.b=-M(1);
        res.c=M(0);
        return res;
      }      
      if(x=='*'){
        res.a=a;
        res.b=b*c;
        res.c=M(0);
        return res;
      }
      assert(isdigit(x));
      
      res.a=a;
      res.b=b;
      res.c=M(c.v*10LL+(x-'0'));      
      return res;
    }
  };
  auto eval=[&](T x){return x.a+x.b*x.c;};
  
  Int n;
  cin>>n;

  T ans;
  for(Int i=0;i<n;i++){
    Int r;
    string s;
    cin>>r>>s;

    if(r==1){      
      for(char c:s) ans=ans.add(c);
      continue;
    }
    
    Int l=s.size();
    auto pp=min(s.find('+'),s.find('-'));    
    auto pm=s.find('*');

    
    // DEBUG
    if(0&&pp!=string::npos){
      for(Int j=0;j<r;j++)
        for(char c:s) ans=ans.add(c);        
      continue;
    }

    if(pp==string::npos&&pm==string::npos){            
      T res;
      for(char c:s) res=res.add(c);
      
      M po=M(10).pow(l);
      ans.c*=M(10).pow(r*l);
      ans.c+=eval(res)*(po.pow(r)-M(1))/(po-M(1));
      
    }else if(pp==string::npos){
      assert(pm!=string::npos);
      Int m=pm;
      for(Int j=0;j<m;j++)
        ans=ans.add(s[j]);
      
      T res;
      for(Int j=m+1;j<l;j++)
        res=res.add(s[j]);
      for(Int j=0;j<m;j++)
        res=res.add(s[j]);

      M mul=eval(res).pow(r-1);
      ans=ans.add(s[m]);
      ans.c=mul;

      for(Int j=m;j<l;j++)
        ans=ans.add(s[j]);
      
    }else{
      assert(pp!=string::npos);
      Int m=pp;
      for(Int j=0;j<m;j++)
        ans=ans.add(s[j]);
      
      T res;
      for(Int j=m;j<l;j++)
        res=res.add(s[j]);
      for(Int j=0;j<m;j++)
        res=res.add(s[j]);
      //cout<<eval(res).v<<endl;

      M add=eval(res)*M(r-1);
      ans=ans.add('+');
      ans.c=add;
      
      for(Int j=m;j<l;j++)
        ans=ans.add(s[j]);      
    }    
  }
  cout<<eval(ans).v<<endl;
  return 0;
}

