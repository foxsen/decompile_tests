#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1000000007;
const int INF = MOD + 1;
const ld EPS = 1e-12;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

/*--------------------template--------------------*/

enum yaku
{
	hc, op, tp, tc, st, fl, fh, fc, sf, rsf
};
typedef pii card;
typedef pair<yaku, vi> hand;

card parse(string s)
{
	int suit;
	if (s[0] == 'S') suit = 0;
	else if (s[0] == 'H') suit = 1;
	else  if (s[0] == 'D') suit = 2;
	else if (s[0] == 'C') suit = 3;
	int n;
	if (isdigit(s[1])) n = s[1] - '0';
	else if (s[1] == 'A') n = 1;
	else if (s[1] == 'T') n = 10;
	else if (s[1] == 'J') n = 11;
	else if (s[1] == 'Q') n = 12;
	else if (s[1] == 'K') n = 13;
	return card(n, suit);
}

vector<vi> pat;

void init()
{
	vi v = { 0,1,2,3,4,5,6 };
	do
	{
		vi tmp;
		REP(i, 5) tmp.push_back(v[i]);
		sort(ALL(tmp));
		pat.push_back(tmp);
	} while (next_permutation(ALL(v)));
	sort(ALL(pat));
	pat.erase(unique(ALL(pat)), pat.end());
}

int is_straight(const vector<card>& cards)
{
	vi v;
	for (auto i : cards) v.push_back(i.first);
	if (v == vi{1, 10, 11, 12, 13}) return 14;
	REP(i, 4)
	{
		if (v[i + 1] - v[i] != 1) return 0;
	}
	return v.back();
}

hand calc(const vector<card>& cards)
{
	int straight = is_straight(cards);
	bool flush = true;
	vi rank(13);
	REP(i, 5)
	{
		rank[cards[i].first - 1]++;
		if (i != 4 && cards[i + 1].second != cards[i].second) flush = false;
	}
	if (straight && flush)
	{
		if (straight == 14) return hand(rsf, {});
		else return hand(sf, { straight });
	}
	vi two, three, four;
	REP(i, 13)
	{
		if (rank[i] == 2) two.push_back(i+1);
		if (rank[i] == 3) three.push_back(i+1);
		if (rank[i] == 4) four.push_back(i+1);
	}
	if (four.size() == 1)
	{
		vi v = four;
		if (rank[0] == 1) v.push_back(1);
		for (int i = 12; i > 0; i--)
		{
			if (rank[i] == 1) v.push_back(i + 1);
		}
		REP(i, v.size())
		{
			if (v[i] == 1) v[i] = 14;
		}
		
		return hand(fc, v);
	}
	if (three.size() == 1 && two.size() == 1)
	{
		vi v = { three[0], two[0] };
		REP(i, v.size())
		{
			if (v[i] == 1) v[i] = 14;
		}
		return hand(fh, v);
	}
	vi tmp;
	for (auto i : cards)
	{
		if (i.first == 1) tmp.push_back(14);
		else tmp.push_back(i.first);
	}
	sort(tmp.rbegin(), tmp.rend());
	if (flush) return hand(fl, tmp);
	if (straight) return hand(st, { straight });
	if (three.size() == 1)
	{
		vi v = three;
		if (rank[0] == 1) v.push_back(1);
		for (int i = 12; i > 0; i--)
		{
			if (rank[i] == 1) v.push_back(i + 1);
		}
		REP(i, v.size())
		{
			if (v[i] == 1) v[i] = 14;
		}
		return hand(tc, v);
	}
	if (two.size() == 2)
	{
		sort(two.rbegin(), two.rend());
		vi v = two;
		if (v[1] == 1) swap(v[0], v[1]);
		if (rank[0] == 1) v.push_back(1);
		for (int i = 12; i > 0; i--)
		{
			if (rank[i] == 1) v.push_back(i + 1);
		}
		REP(i, v.size())
		{
			if (v[i] == 1) v[i] = 14;
		}
		return hand(tp, v);
	}
	if (two.size() == 1)
	{
		vi v = two;
		if (rank[0] == 1) v.push_back(1);
		for (int i = 12; i > 0; i--)
		{
			if (rank[i] == 1) v.push_back(i + 1);
		}
		REP(i, v.size())
		{
			if (v[i] == 1) v[i] = 14;
		}
		return hand(op, v);
	}
	return hand(hc, tmp);
}

int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	init();
	vs v(7);
	while (cin >> v[0], v[0] != "#")
	{
		set<card> used;
		REP(i, 6) cin >> v[i + 1];
		vector<card> my_cards, op_cards;
		REP(i, 2) my_cards.push_back(parse(v[i]));
		REP(i, 2) op_cards.push_back(parse(v[i+2]));
		REP(i, 3)
		{
			my_cards.push_back(parse(v[i + 4]));
			op_cards.push_back(parse(v[i + 4]));
		}
		REP(i, 5)
		{
			used.insert(my_cards[i]);
			used.insert(op_cards[i]);
		}
		int cnt = 0, cnt2 = 0;
		REP(suit1, 4)FOR(num1, 1, 14)REP(suit2, 4)FOR(num2, 1, 14)
		{
			if (suit1 == suit2 && num1 == num2) continue;
			card c1(num1, suit1), c2(num2, suit2);
			if (used.count(c1) || used.count(c2)) continue;
			vector<card> t_my = my_cards;
			vector<card> t_op = op_cards;
			t_my.push_back(c1); t_my.push_back(c2);
			t_op.push_back(c2); t_op.push_back(c1);
			hand my_hand(hc, {}), op_hand(hc, {});
			for (auto use : pat)
			{
				vector<card> t_my_cards;
				vector<card> t_op_cards;
				for (auto i : use)
				{
					t_my_cards.push_back(t_my[i]);
					t_op_cards.push_back(t_op[i]);
				}
				sort(ALL(t_my_cards));
				sort(ALL(t_op_cards));
				chmax(my_hand, calc(t_my_cards));
				chmax(op_hand, calc(t_op_cards));
			}
			if (my_hand > op_hand) cnt++;
			cnt2++;
		}
		cout << (ld)cnt / cnt2 << endl;
	}
	return 0;
}