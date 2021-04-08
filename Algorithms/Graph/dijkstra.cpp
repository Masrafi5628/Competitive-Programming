// Program to find shortest paths from src to all other vertices
// using Dijkstra algorithm

#include<bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110;

int node, edge;
vector<pii>adj[N];
vector<int>dis;

void DJ(int src)
{
	priority_queue<pii, vector<pii>, greater<pii> >pq;
	pq.push({0, src});// {cost, node}

	dis.resize(node);
	dis.assign(node, 99999999);
	dis[src] = 0;

	while(!pq.empty()) {
		int u = pq.top().ss;

		pq.pop();

		for(pii now: adj[u]) {
			int v = now.ff;
			int cost = now.ss;

			if(dis[v] > dis[u] + cost) {
				dis[v] = dis[u] + cost;
				pq.push({dis[u]+cost, v});
			}
		}
	}

    for(int i = 0; i < node; i++) {
        printf("src %d -> %d = %d\n", src, i, dis[i]);
    }
}

int main()
{

	cin >> node >> edge;

	for(int i=0; i < edge; i++){
		int u, v, w;

		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	
	DJ(0);

	return 0;
}

