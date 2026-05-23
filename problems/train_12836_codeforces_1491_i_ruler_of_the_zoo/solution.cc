#include <bits/stdc++.h>

const int red = 0;
const int blue = 1;
const int green = 2;

const long long inf = 1e16;

typedef std::pair<long long, long long> ii;
typedef std::pair<long long, ii> iii;

struct animal
{
	long a, b, c;
	int id, pos, color, redHere;
};

long long moves = 0;

std::vector<animal> belt;
std::vector<animal> animals;
std::vector<iii> s;
std::vector<ii> reds;

void makeLast(long long b, long long beltPos, long long pos)
{
	while (!s.empty() && s.back().first >= b)
	{
		s.pop_back();
	}
	s.push_back(iii(b, ii(beltPos, pos)));
}

void cycle(int n)
{
	std::deque<animal> q;
	animal current = animals[0];
	
	for (int i = 1; i < n; i++)
	{
		q.push_back(animals[i]);
	}
	
	int wins = 1;
	for (int x = 1; ; x++)
	{
		if (x > 2 * n)
		{
			break;
		}
		
		if (wins == 3)
		{
			std::cout << current.id << " " << x << "\n";
			exit(0);
		}
		
		if (wins == 1)
		{
			if (current.b > q.front().a)
			{
				animal y = q.front();
				q.push_back(y);
				q.pop_front();
				wins++;
			}
			else
			{
				q.push_back(current);
				current = q.front();
				q.pop_front();
				wins = 1;
			}
		}
		else
		{
			if (current.c > q.front().a)
			{
				animal y = q.front();
				q.push_back(y);
				q.pop_front();
				wins++;
			}
			else
			{
				q.push_back(current);
				current = q.front();
				q.pop_front();
				wins = 1;
			}
		}
	}
}

int main()
{
	int n = 0;
	std::cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		long a = 0, b = 0, c = 0;
		std::cin >> a >> b >> c;
		animals.push_back({ a, b, c, i, -1, 1, -1 });
	}

	if (animals[0].a > animals[1].a)
	{
		std::swap(animals[0], animals[1]);
	}
	animals.push_back(animals[0]);
	animals.erase(animals.begin());
	
	cycle(n);
	
	// Find reds
	for (int i = 1; i < n; i++)
	{
		if (animals[i - 1].b > animals[i].a)
		{
			animals[i].color = red;
		}
	}
	
	// Find blues and greens
	for (int i = 0; i < n; i++)
	{
		animals[i].pos = i;
		
		if (animals[i].color == red)
		{
			continue;
		}
		
		int next = i + 1;
		if (next == n)
		{
			next = 0;
		}
		
		if (animals[next].color == red)
		{
			next++;
		}
		if (next == n)
		{
			next = 0;
		}
		
		if (animals[i].c > animals[next].a)
		{
			animals[i].color = green;
		}
		else
		{
			animals[i].color = blue;
		}
	}
	
	animals.push_back(animals[0]);
	for (int i = 0; i < n; i++)
	{
		if (animals[i].color != red)
		{
			if (animals[i + 1].color == red)
			{
				animals[i].redHere = animals[i + 1].pos;
			}
			belt.push_back(animals[i]);
		}
	}
	
	while (true)
	{
		s.clear();
		reds.clear();
		
		for (int i = 0; i < (int)belt.size(); i++)
		{
			animal a = belt[i];
			if (a.color == blue)
			{
				makeLast(a.b, a.pos, i);
			}
			else
			{
				makeLast(-inf, a.pos, i); // Clear stack except for green
			}
		}
		
		long long minMoves = inf;
		for (int i = 0; i < (int)belt.size(); i++)
		{		
			animal a = belt[i];
			if(a.color == blue) 
			{
				makeLast(a.b, a.pos, i);
			}
			else 
			{
				makeLast(-inf, a.pos, i);
			}
			
			// Find the red
			int red = a.redHere;
			if (red == -1)
			{
				continue;
			}
			reds.push_back(ii(red, i));
			
			//Find the earliest event_callback
			auto early = std::lower_bound(s.begin(), s.end(), iii(animals[red].a, ii(-1, -1)));
			
			if (early == s.begin())
			{
				continue;
			}
			
			early--;
			
			// Number of rotations
			long long distance = i - (early->second).second;
			if (distance < 0)
			{
				distance += belt.size();
			}
			minMoves = std::min(distance, minMoves);
		}
		
		if (minMoves == inf)
		{
			std::cout << "-1 -1\n";
			return 0;
		}
		else if (minMoves != 0)
		{
			moves += minMoves * (n - 1);
			for (ii red : reds)
			{
				belt[red.second].redHere = -1;
			}
			for (ii red : reds)
			{
				int pos = red.second;
				pos -= minMoves;
				if (pos < 0)
				{
					pos += belt.size();
				}
				belt[pos].redHere = red.first;
			}
		}
		
		auto ans = ii(inf, inf);
		
		// Update belt
		for (int i = 0; i < (int)belt.size(); i++)
		{
			if (belt[i].redHere == -1)
			{
				continue;
			}
			animal red = animals[belt[i].redHere];
			
			// Blue event
			if (belt[i].b < red.a)
			{
				belt[i].redHere = -1;
				belt.insert(belt.begin() + (i + 1), red); // Insert to the middle
				
				// Update colors
				if (belt[i].c > red.a)
				{
					belt[i].color = green;
				}
				else
				{
					belt[i].color = blue;
				}
				
				int next = i + 2;
				if (next == (int)belt.size())
				{
					next = 0;
				}
				if (belt[i + 1].c > belt[next].a)
				{
					belt[i + 1].color = green;
				}
				else
				{
					belt[i + 1].color = blue;
				}
			}
			else if (belt[i].color == green)
			{
				ans = std::min(ans, ii(moves + red.pos + 2, belt[i].id));
			}
		}
		
		if (ans.first != inf)
		{
			std::cout << ans.second << " " << ans.first;
			return 0;
		}
	}

	return 0;
}