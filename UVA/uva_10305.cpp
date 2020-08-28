#include <bits/stdc++.h>
#define pb push_back

using namespace std;

vector<int>adj[111];
stack<int>stk;

bool visit[111];

void dfsVisit(int u)
{
	visit[u] = true;

	for(int v: adj[u]) {
		if(!visit[v]) {
			dfsVisit(v);
		}
	}
	stk.push(u);
}

void dfs(int vertex)
{
	memset(visit, false, sizeof visit);
	for(int i=1; i<=vertex; i++){
		if(!visit[i]) {
			dfsVisit(i);
		}
	}
}

int main()
{
	int n, m;
	while(cin>>n>>m) {
		if(!n && !m)
			break;
		
		for(int i=0; i<m; i++){
			int u,v;
			cin>>u>>v;
			adj[u].pb(v);
		}

		dfs(n);
		while(!stk.empty()) {
			int x = stk.top();
			stk.pop();
			cout<<x;
			if(!stk.empty())
				cout<< ' ';
		}
		cout<<endl;
		for(int i=1; i<=n; i++)
			adj[i].clear();
	}

	return 0;
}