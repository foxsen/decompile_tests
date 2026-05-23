//0038 Poker Hand

#include<iostream>
#include<algorithm>
using namespace std;


int main(void)
{
	const int N = 5;
	while(1)
	{
		int hand[N];
		char dummy;
		int i, j;
		for(i = 0; i < N; i++)
		{
			if(i)
				cin >> dummy;
			cin >> hand[i];
		}
		if(!cin)
			break;

		sort(hand, hand+N);

		if(hand[0] == hand[3] ||
			hand[1] == hand[4])
			cout << "four card" << endl;
		else if( (hand[0] == hand[1] && hand[2] == hand[4]) ||
				(hand[0] == hand[2] && hand[3] == hand[4]) )
			cout << "full house" << endl;
		else if( (hand[0] == 1 && hand[1] == 10 && hand[2] == 11 && hand[3] == 12 && hand[4] == 13) ||
			(hand[0]+1==hand[1] && hand[1]+1==hand[2] && hand[2]+1==hand[3] && hand[3]+1==hand[4]) )
			cout << "straight" << endl;
		else if( (hand[0] == hand[2] || hand[1] == hand[3] || hand[2] == hand[4]) )
			cout << "three card" << endl;
		else if( (hand[0]==hand[1] && hand[2]==hand[3]) ||
				(hand[0]==hand[1] && hand[3]==hand[4]) ||
				(hand[1]==hand[2] && hand[3]==hand[4]) )
			cout << "two pair" << endl;
		else if( hand[0]==hand[1] || hand[1]==hand[2] || hand[2]==hand[3] || hand[3]==hand[4] )
			cout << "one pair" << endl;
		else
			cout << "null" << endl;
	}
	return 0;
}