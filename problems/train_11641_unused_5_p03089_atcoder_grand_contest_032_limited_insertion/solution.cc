#include<cstdio>
#include<algorithm>
int main(){
  int n,b[100],a[100];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&b[i]);
    if(b[i]>=i+2){
      printf("-1");
      return 0;
    }
  }
  //b[i]==iなる最も大きいiを選んで取り除く
  //という操作で選んだ数列のreverse
  for(int ia=n-1;ia>=0;ia--){
    int ib=ia;
    while(b[ib]<ib+1)ib--;
    a[ia]=b[ib];
    while(ib<ia){
      b[ib]=b[ib+1];
      ib++;
    }
  }
  for(int i=0;i<n;i++)printf("%d\n",a[i]);
  return 0;
}