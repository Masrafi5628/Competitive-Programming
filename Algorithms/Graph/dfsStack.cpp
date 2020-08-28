#include <bits/stdc++.h>

using namespace std;

vector<int>adj[100];
int vis[100];
int edge_id[100];

void dfsStack(int s,int n)
{
    for(int i=0;i<n;i++) edge_id[i]=vis[i]=0;

    stack<int>stk;

    stk.push(s);

    while(!stk.empty()){
        int u = stk.top();
        stk.pop();

        while(edge_id[u]<adj[u].size()){

            int v = adj[u][edge_id[u]];

            edge_id[u]++;

            if(vis[u]==0){
                cout << u << ' ';
                vis[u]=1;
            }

            if(vis[v]==0){
                vis[v]=1;

                cout << v << ' ';
                stk.push(u);
                stk.push(v);

                break;
            }
        }
    }
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
    dfsStack(2,vertex);
    cout <<endl;

    return 0;
}
