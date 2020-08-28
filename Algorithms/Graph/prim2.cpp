#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 5;

typedef pair<int, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;// This will work like as min Heap

    long long minimumCost = 0;

    Q.push(make_pair(0, x));// first is cost,second is node

    while(!Q.empty())
    {
        // Select the edge with minimum weight
        PII p = Q.top();
        Q.pop();

        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;

        minimumCost += p.first;
        marked[x] = true;

        for(int i = 0;i < adj[x].size();++i)
        {
            int y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }

    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);

    cout << minimumCost << endl;
    return 0;
}
