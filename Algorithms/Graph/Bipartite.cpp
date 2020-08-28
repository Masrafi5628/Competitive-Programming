#include <bits/stdc++.h>

using namespace std;

vector<int>adj[111];
int color[111]; // -1 ->no color, 0 ->first color, 1->second color


bool isBipartite(int vertex, int src)
{
	color[src] = 1;
	queue<int>q;
	q.push(src);

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for(int v: adj[u]) {
			if(color[v] == -1) {
				color[v] = 1-color[u];
				q.push(v);
			}
			else if(color[u] == color[v]) {
				return false;
			}
		}

	}
	return true;
}

int main()
{
	int n, m;// n = vertex, m = edge
	cin>>n>>m;
	
	memset(color, -1, sizeof color);
	
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if(isBipartite(n, 1)) {
		printf("yes\n");
	}else {
		printf("No\n");
	}

	return 0;
}