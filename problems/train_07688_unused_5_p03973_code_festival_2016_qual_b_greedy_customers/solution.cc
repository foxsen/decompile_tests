#include <cstdio>
int N;
int A[100010];

int main(int argc, const char * argv[]) {
  scanf("%d", &N);
  for(int i=0;i<N;++i) {
    scanf("%d", &A[i]);
  }
  
  long long answer = 0;
  int last = 2;
  for(int i=0;i<N;++i) {
    if (i==0) {
      answer += A[0]-1;
      continue;
    }
    if (A[i]==last) {
      last++;
      continue;
    }
    answer += (A[i]-1) / last;
  }
  
  printf("%lld\n", answer);
return 0;
}