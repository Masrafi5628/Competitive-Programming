#include <bits/stdc++.h>


using namespace std;

const int white = 0, gray = 1, black = 2;

vector<int>adj[111];
int color[111]; // fill with 0

bool dfsVisit(int x)
{
	color[x] = gray;
	for(int i=0; i<adj[x].size(); i++){
		if(color[adj[x][i]]==gray){
			return true;
		}
		else if(color[adj[x][i]]==white && 
			dfsVisit(adj[x][i])){
			return true;
		}
	}
	color[x] = black;
	return false;
}

void dfs(int vertex)
{
	for(int i=0; i<vertex; i++){
		if(color[i] == white){
			if(dfsVisit(i)) {
				printf("Graph contain cycle\n");
				return;
			}
		}
	}
	printf("Graph does not contain cycle\n");
}

int main()
{
	int vertex, edge;
	cin>>vertex>>edge;

	for(int i=0; i<edge; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	dfs(vertex);

	return 0;
}