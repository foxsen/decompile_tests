// Hypercube Coloring

#include<bits/stdc++.h>
#define P pair<int,int>
#define x first
#define y second
using namespace std;

bool isPowerOfTwo(int n)
{
    return n == (n & -n);
}

// Coloring exists if and only if n is a power of two.
vector<int> getSimpleHypercubeColoring(const int n)
{
    const int N = 1 << n;
    vector<int> c(N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i & (1 << j)) c[i] ^= j;
        }
    }
    return c;
}

// Get a permutation that transform a standard hypercube to the given hypercube
vector<int> getHypermutation(const int n, const vector<P> &edgeList)
{
    const int N = 1 << n;
    vector<set<int>> edges(N);
    for(P p: edgeList)
    {
        edges[p.x].insert(p.y);
        edges[p.y].insert(p.x);
    }

    vector<int> p(N, -1);
    vector<bool> used(N, false);
    // Select Arbitrary First Vertex
    p[0] = 0;
    used[0] = true;
    // Its n neighbor's order is arbitrary
    int h = 0;
    for(int v: edges[0])
    {
        p[1 << h] = v;
        used[v] = true;
        h++;
    }

    for(int u = 0; u < N; u++)
    {
        if(p[u] != -1) continue;    // It was assigned
        // Now, u has at least two 1s
        vector<int> baseNeighbor;
        for(int i = 0; i < n; i++)
        {
            const int v = u ^ (1 << i);
            if(v < u) baseNeighbor.push_back(v);
        }

        for(int w: edges[p[baseNeighbor[0]]])
        {
            if(used[w]) continue;

            bool eligible = true;

            for(int v: baseNeighbor)
            {
                if(edges[w].find(p[v]) == edges[w].end())
                {
                    eligible = false;
                    break;
                }
            }

            if(eligible)
            {
                p[u] = w;
                used[w] = true;
                break;
            }
        }
    }
    return p;
}

bool permutationCheck(const int n, const vector<P> &edgeList, const vector<int> &p)
{
    const int N = 1 << n;
    vector<int> pinv(N, -1);
    for(int i = 0; i < N; i++)
    {
        if(pinv[p[i]] != -1)
        {
            fprintf(stderr,"Invalid Permutation");
            return false;
        }

        pinv[p[i]] = i;
    }

    for(P e: edgeList)
    {
        int u = pinv[e.x];
        int v = pinv[e.y];

        int w = u ^ v;
        if(!isPowerOfTwo(w))
        {
            fprintf(stderr,"(%d,%d) is not an edge in a standard hypercube\n", u, v);
            return false;
        }
    }
    return true;
}

vector<int> getColoringFromPermutation(const int n, const vector<int> &p)
{
    const vector<int> b = getSimpleHypercubeColoring(n);
    const int N = 1 << n;
    vector<int> c(N);
    for(int i = 0; i < N; i++) c[p[i]] = b[i];
    return c;
}



int main()
{
    int tc; scanf("%d",&tc);
    while(tc--)
    {
        int n; scanf("%d",&n);
        const int M = n * (1 << (n - 1));
        vector<P> edgeList(M);
        for(int i = 0; i < M; i++) scanf("%d%d",&edgeList[i].x, &edgeList[i].y);


        vector<int> p = getHypermutation(n, edgeList);
        for(int v: p) printf("%d ", v);
        printf("\n");

        assert(permutationCheck(n, edgeList, p));

        if(isPowerOfTwo(n))
        {
            vector<int> c = getColoringFromPermutation(n, p);
            for(int v: c) printf("%d ", v);
            printf("\n");
        }
        else
        {
            printf("-1\n");
        }

    }
    return 0;
}

