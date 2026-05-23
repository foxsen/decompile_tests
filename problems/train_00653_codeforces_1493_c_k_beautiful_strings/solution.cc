#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1e5 + 10 ;

int need[27] ;
int n , k ;

string s ;

bool check(int idx)
{
	memset(need , 0 , sizeof(need)) ;
	for(int i = 0 ; i < idx ; ++i)
		need[s[i]-'a'] = (need[s[i]-'a'] - 1 + k) % k ;
	int sum = 0 ;
	for(int i = 0 ; i < 26 ; ++i)
		sum += need[i] ;
	if(idx == n)
		return (sum == 0) ;
	for(char c = s[idx]+1 ; c <= 'z' ; ++c)
	{
		sum -= need[c-'a'] ;
		need[c - 'a'] = (need[c - 'a'] - 1 + k) % k ;
		sum += need[c-'a'] ;
		int x = n-idx-1 - sum ;
		if(x >= 0 && x % k == 0)
			return true ;
		sum -= need[c-'a'] ;
		need[c-'a'] = (need[c-'a'] + 1) % k ;
		sum += need[c-'a'] ;
	}
	return false ;
}

void build(int idx)
{
	memset(need , 0 , sizeof(need)) ;
	for(int i = 0 ; i < idx ; ++i)
		need[s[i]-'a'] = (need[s[i]-'a'] - 1 + k) % k ;
	int sum = 0 ;
	for(int i = 0 ; i < 26 ; ++i)
		sum += need[i] ;
	if(idx == n)
	{
		cout<<s<<"\n" ;
		return ;
	}
	for(char c = s[idx]+1 ; c <= 'z' ; ++c)
	{
		sum -= need[c-'a'] ;
		need[c - 'a'] = (need[c - 'a'] - 1 + k) % k ;
		sum += need[c-'a'] ;
		int x = n-idx-1 - sum ;
		if(x >= 0 && x % k == 0)
		{
			for(int i = 0 ; i < idx ; ++i)
				cout<<s[i] ;
			cout<<c ;
			for(int i = 0 ; i < x ; ++i)
				cout<<'a' ;
			for(int i = 0 ; i < 26 ; ++i)
			{
				for(int j = 0 ; j < need[i] ; ++j)
					cout<<(char)('a' + i) ;
			}
			cout<<"\n" ;
			return ;
		}
		sum -= need[c-'a'] ;
		need[c-'a'] = (need[c-'a'] + 1) % k ;
		sum += need[c-'a'] ;
	}
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin>>t ;
	while(t--)
	{
		cin>>n>>k ;
		cin>>s ;
		if(n % k != 0)
		{
			cout<<-1<<"\n" ;
			continue ;
		}
		if(check(n))
		{
			cout<<s<<"\n" ;
			continue ;
		}
		memset(need , 0 , sizeof(need)) ;
		int sum = 0 , idx = 0 ;
		for(int i = 0 ; i < n ; ++i)
		{
			for(char c = s[i]+1 ; c <= 'z' ; ++c)
			{
				sum -= need[c-'a'] ;
				need[c - 'a'] = (need[c - 'a'] - 1 + k) % k ;
				sum += need[c-'a'] ;
				int x = n-i-1 - sum ;
				if(x >= 0 && x % k == 0)
					idx = i ;
				sum -= need[c-'a'] ;
				need[c-'a'] = (need[c-'a'] + 1) % k ;
				sum += need[c-'a'] ;
			}
			sum -= need[s[i] - 'a'] ;
			need[s[i] - 'a'] = (need[s[i] - 'a'] - 1 + k) % k ;
			sum += need[s[i] - 'a'] ;
		}
		build(idx) ;
	}
	return 0 ;
}		