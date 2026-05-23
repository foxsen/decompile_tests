//45
#include<iostream>

using namespace std;

int main(){
  for(int q,b,c,cc,qq;cin>>q>>b>>c>>cc>>qq,q;){
    int a=0;
    int n=b/cc;
    int r=b-n*cc;
    for(;;){
      int nr=r;
      int nn=n;
      while(nr<c){
	nr+=cc;
	nn--;
      }
      if(nn<0||a+1+nn<q||a+1>qq)break;
      a++;
      n=nn;
      r=nr-c;
    }
    if(a+n<q||a==0){
      cout<<"NA"<<endl;
    }else{
      cout<<a<<' '<<n<<endl;
    }
  }
  return 0;
}
	 