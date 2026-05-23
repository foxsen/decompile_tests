#include <iostream> //üoÍ
#include <string>   //¶ñ
#include <vector>   //®Izñ
#include <sstream>  //¶ñtH[}bg

using namespace std;

int main(){
	int n, num;
	cin >> n;
	while(1){
		if(n == 0){ break; }
		vector<int> vec1, vec2;
		for(int i=0;i<n;i++){
			cin >> num;
			vec1.push_back(num);
			cin >> num;
			vec2.push_back(num);
		}
		int x;
		int flag = 1;
		int w = 0;
		for(int j=0;j<vec1.size();j++){
			int min = 9999999;
			for(int i=0;i<vec2.size();i++){
				if(vec2[i]!=-1 && min > vec2[i]){
					min = vec2[i];
					x = i;
				}
			}
			w += vec1[x];
			
			if(w>vec2[x]){
				flag = 0;
				break;
			}
			vec2[x] = -1;
		}
		if(flag==1){ cout << "Yes" << endl; }
		else{ cout << "No" << endl; }

		cin >> n;
		
	}
	
		
		

	return 0;
	
}