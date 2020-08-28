#include <bits/stdc++.h>

using namespace std;

vector<int>adj[100];
int vis[100];

void dfs(int at)
{
    if(vis[at]) {
        return;
    }
    vis[at]=1;
    cout <<at<< ' ';
    for(int i=0;i<adj[at].size();i++)
        dfs(adj[at][i]);
    
}

int main()
{
    int vertex,edge;
    cin>>vertex>>edge;

    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u >> v;

        adj[u].push_back(v);// for an edge from u to v
        adj[v].push_back(u);
    }
    for(int i=0;i<=vertex;i++)
        vis[i]=0;

    dfs(2);
    cout <<endl;

    return 0;
}
