// 2011/02/02 Tazoe

#include <iostream>
#include <string>
using namespace std;

struct score{
	string nam;
	int win;
	int los;
	int drw;
	int ord;
	int pnt;
};

int main()
{
	bool flg = false;

	while(true){
		int n;
		cin >> n;
		if(n==0)
			break;

		if(flg)
			cout << endl;
		else
			flg = true;

		struct score tem[10];
		for(int i=0; i<n; i++){
			cin >> tem[i].nam >> tem[i].win >> tem[i].los >> tem[i].drw;
			tem[i].ord = i;
		}

		for(int i=0; i<n; i++)
			tem[i].pnt = tem[i].win*3+tem[i].drw;

		for(int i=0; i<n-1; i++)
			for(int j=i+1; j<n; j++)
				if(tem[i].pnt<tem[j].pnt||(tem[i].pnt==tem[j].pnt&&tem[i].ord>tem[j].ord)){
					struct score tmp = tem[i];
					tem[i] = tem[j];
					tem[j] = tmp;
				}

		for(int i=0; i<n; i++)
			cout << tem[i].nam << ',' << tem[i].pnt << endl;
	}

	return 0;
}