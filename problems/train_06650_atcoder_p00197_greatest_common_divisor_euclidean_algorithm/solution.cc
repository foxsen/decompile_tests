#include <iostream>
typedef long long int llint;

llint step = 0;
llint getgcd(llint a, llint b){
  if(b==0)return a;
  step++;
  return getgcd(b, a%b);
}

int main(){
  llint a, b;
  while(std::cin >> a >> b, a && b){
    llint gcd = 0;
    step = 0;
    if(a > b)gcd = getgcd(a, b);
    else gcd = getgcd(b, a);
    std::cout << gcd << " " << step << std::endl;
  }
}