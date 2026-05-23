#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<functional>
#include<stack>
#include<queue>
#include <iomanip>
#include<map>
#include<limits>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<utility>
#include<complex>
#include<cstdlib>
#include<set>
#include<cctype>

#define DBG cerr << '!' << endl;
#define REP(i,n) for(int (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(int (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(int (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(10)

using namespace std;

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;

typedef vector<vector<pair<int,int> > >  Mat;

string str;
int n,pointer;

Mat calMat(Mat a,Mat b);
Mat readSequence();
int readNum();
Mat init();

int ans[101][101];

Mat init()
{
	Mat ret;
	REP(i,n)
	{
		vector<pair<int,int> > tmp;
		REP(j,n)
		{
			tmp.PB(MP(i,j));
		}
		ret.PB(tmp);
	}
	return ret;
}

int readNum()
{
	int ret = 0;
	while(isdigit(str[pointer]))
	{
		ret *= 10;
		ret += str[pointer] - '0';
		pointer++;
	}
	return ret;
}

Mat makeShift(char c,int q)
{
	Mat ret = init();
	q--;
	pair<int,int> tmp;
	if(c == 'U')
	{
		tmp = ret[n-1][q];
		for(int i = n-1;i > 0;i--)ret[i][q] = ret[i-1][q];
		ret[0][q] = tmp;
	}
	else if(c == 'D')
	{
		tmp = ret[0][q];
		for(int i = 0;i < n-1;i++)ret[i][q] = ret[i+1][q];
		ret[n-1][q] = tmp;
	}
	else if(c == 'R')
	{
		tmp = ret[q][0];
		for(int i = 0;i < n-1;i++)ret[q][i] = ret[q][i+1];
		ret[q][n-1] = tmp;
	}
	else
	{
		tmp = ret[q][n-1];
		for(int i = n-1;i > 0;i--)ret[q][i] = ret[q][i-1];
		ret[q][0] = tmp;
	}
	return ret;
}

Mat power(Mat m,int n)
{
	Mat tmp = m;
	Mat ret = init();
	while(n)
	{
		if(n & 1)
		{
			ret = calMat(ret,tmp);
		}
		tmp = calMat(tmp,tmp);
		n >>= 1;
	}
	return ret;
}

Mat readSequence()
{
	Mat ret = init();
	
	while(pointer < str.size())
	{
		if(str[pointer] == '(')
		{
			pointer++;
			ret = calMat(ret,readSequence());
		}
		else if(str[pointer] == ')')
		{
			pointer++;
			int num = readNum();
			ret = power(ret,num);
			return ret;
		}
		else
		{
			char c = str[pointer];
			pointer++;
			int num = readNum();
			Mat mat = makeShift(c,num);
			ret = calMat(ret,mat);
		}
	}
	return ret;
}

Mat calMat(Mat a,Mat b)
{
	Mat ret = a;
	REP(i,n)
	{
		REP(j,n)
		{
			ret[i][j] = b[a[i][j].FI][a[i][j].SE];
		}
	}
	return ret;
}


int main()
{
	int l;
	cin >> n >> l;
	cin >> str;
	
	Mat mat = readSequence();
	int num = 1;
	REP(i,n)
	{
		REP(j,n)
		{
			ans[mat[i][j].FI][mat[i][j].SE] = num;
			num++;
		}
	}
	
	REP(i,n)
	{
		REP(j,n-1)
		{
			cout << ans[i][j] << ' ';
		}
		cout << ans[i][n-1] << endl;
	}
	
	return 0;
}