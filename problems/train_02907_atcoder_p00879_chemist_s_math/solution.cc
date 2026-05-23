#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

#define ABS(n) (n<0?-(n):(n))

typedef int Atom;
map<string, Atom> d;
Atom Acnt;
string expr;
int p;

class Aexpr
{
public:
	Atom a;
	int n;
	
	Aexpr(Atom a, int n)
	:a(a),n(n)
	{}
};

typedef vector<Aexpr> Mole;

Atom parseAtom()
{
	string tmp;
	if(isupper(expr[p]))
	{
		tmp+=expr[p];
		p++;
	}
	else return -1;
	
	if(islower(expr[p]))
	{
		tmp+=expr[p];
		p++;
	}
	
	if(d.count(tmp)) return d[tmp];
	
	d.insert(make_pair(tmp, Acnt));
	Acnt++;
	
	return Acnt-1;
}

int parseInt()
{
	int n=0;
	while(isdigit(expr[p]))
	{
		n*=10;
		n+=(expr[p]-'0');
		p++;
	}
	
	if(n==0) return 1;
	return n;
}

Mole parseAexpr()
{
	Mole m;
	while(isalpha(expr[p]) || expr[p]=='(')
	{
		if(expr[p]=='(')
		{
			p++;
			Mole tmp=parseAexpr();
			p++;
			int n=parseInt();

			for(int i=0; i<tmp.size(); i++)
			{
				tmp[i].n*=n;
				m.push_back(tmp[i]);
			}
		}
		else
		{
			Atom a=parseAtom();
			int n=parseInt();
			m.push_back(Aexpr(a,n));
		}
	}
	return m;
}

vector<Mole> parse()
{
	vector<Mole> ret;
	while(expr[p]!='-'&&expr[p]!='.')
	{
		ret.push_back(parseAexpr());
		if(expr[p]=='+') p++;
	}
	
	return ret;
}


typedef vector<vector<int> > matrix;

int gcd(int a, int b)
{
	return b != 0 ? gcd(b, a % b) : a;
}

void reduce(vector<int>& a)
{
	int tmp=a[0];
	for(int i=1; i<a.size(); i++)
	{
		tmp = gcd(a[i],tmp);
	}

	if(tmp!=0)
	for(int i=0; i<a.size(); i++)
	{
		a[i]/=tmp;
	}
}

void print(const matrix& m)
{
	for(int h=0; h<m.size(); h++)
	{
		for(int w=0; w<m[h].size(); w++)
		{
			cout.width(8);
			cout << m[h][w];
		}
		cout << '\n';
	}
	cout << '\n';
}

bool sweep(matrix& m)
{
	int h=m.size();
	int w=m[0].size();

	bool ret = true;
	for(int line=0; line<min(w,h); line++)
	{
		int maxline=line;
		for(int i=line+1; i<h; i++)
		{
			if(fabs(m[maxline][line])<fabs(m[i][line]))
			{
				maxline = i;
			}
		}
		
		if(m[maxline][line]==0)
		{
			ret = false;
			break;
		}
		swap(m[line],m[maxline]);

		if(m[line][line]<0)
		{
			for(int j=0; j<w; j++)
			{
				m[line][j] *= -1;
			}
		}
		
		int lcm,m1,m2;
		for(int i=0; i<h; i++)
		{
			if(i!=line && m[i][line]!=0)
			{
				m1 = m[line][line];
				m2 = m[i   ][line];
				lcm = m1/gcd(m1,m2)*m2;
				m1 = lcm/m1;
				m2 = lcm/m2;

				for(int j=0; j<w; j++)
				{
					m[i][j] = m[i][j]*m2 - m[line][j]*m1;
				}

				reduce(m[i]);
			}
		}
		reduce(m[line]);
	}

	for(int i=0; i<min(w,h); i++)
	{
		if(m[i][i]<0)
		for(int j=0; j<w; j++)
		{
			m[i][j] *= -1;
		}
	}

	int lcm = 1;
	for(int i=0; i<min(w,h); i++)
	{
		if(m[i][i]==0) break;
		lcm = m[i][i]/gcd(lcm,m[i][i])*lcm;
	}
	for(int i=0; i<min(w,h); i++)
	{
		if(m[i][i]==0) break;
		m[i].back()	*= lcm/m[i][i];	
		m[i][i]		 = lcm;
	}
	return ret;
}

int SearchAtom(Mole& m, Atom n)
{
	for(int i=0; i<m.size(); i++)
	{
		if(m[i].a==n) return m[i].n;
	}
	return 0;
}

int main()
{
	while(cin >> expr, expr!=".")
	{
		Acnt=0;
		p=0;
		d.clear();
		
		vector<Mole> l=parse();
		p+=2;
		vector<Mole> r=parse();
				
		matrix a(Acnt, vector<int>(l.size()+r.size(),0));

		int mlidx = 0;
		for(int i=0; i<l.size(); i++,mlidx++)
		for(int j=0; j<l[i].size(); j++)
		{
			a[l[i][j].a][mlidx] += l[i][j].n;
		}
		for(int i=0; i<r.size(); i++,mlidx++)
		for(int j=0; j<r[i].size(); j++)
		{
			a[r[i][j].a][mlidx] += -r[i][j].n;
		}

		sweep(a);
		for(int i=0; i<l.size()+r.size()-1; i++)
		{
			cout << ABS(a[i].back()) << " ";
		}
		cout << ABS(a[0][0]) << endl;
	}
}