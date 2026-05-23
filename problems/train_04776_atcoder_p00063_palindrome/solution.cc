#include <iostream>
#include <string>
int main(){
	int c=0;
	std::string s;
	while(std::cin>>s)
		if (s== std::string(s.rbegin(),s.rend())) c++;
	std::cout<<c<<"\n";
}