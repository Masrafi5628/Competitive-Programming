#include <bits/stdc++.h>


using namespace std;

vector<bool>visit;
vector<int>adj[200005],ans[200005];
int cnt;

void dfsVisit(int x)
{
	if(visit[x])
		return;

	visit[x]=true;
	ans[cnt].push_back(x);

	for(int i=0; i<adj[x].size(); i++){
		if(visit[adj[x][i]] == false)
			dfsVisit(adj[x][i]);
	}
}

int dfs(int t)
{
	visit.resize(t+1,false);

	for(int i=1; i<=t; i++){
		if(visit[i] == false){
			dfsVisit(i);
			cnt++;
		}
	}

	return cnt;
}

int main()
{
	int n,m,u,v,cyclic=0;
	cin>>n>>m;

	for(int i=0; i<m; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(n);

	for(int i=0; i<cnt; i++){
		int sz=ans[i].size();

		if(sz>=3){
			int j;
			for(j=0; j<sz; j++){
				if(adj[ans[i][j]].size() == 2)
					continue;
				else 
					break;
			}
			if(j == sz)
				cyclic++;

		}
	}
	cout<<cyclic<<endl;

	return 0;
}