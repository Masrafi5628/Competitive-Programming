#include <bits/stdc++.h>

using namespace std;

vector<int>adj[100];
int visited[100];
int dist[100];// distance from starting vertex
int p[100];   // we came to i from p[i]

// s -> starting vertex, t -> destination vertex, n-> total number of nodes

int s,t;

void bfsPath(int s,int n)
{
    queue<int>q;

    for(int i=0;i<n;i++) visited[i]=0;

    visited[s]=1;
    dist[s]=0;

    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0;i<adj[u].size();i++){

            int v = adj[u][i];

            if(visited[v] == 0){
                visited[v]=1;
                dist[v]=dist[u]+1;

                p[v]=u; // we came to u from p[v]
                q.push(v);
            }
        }
    }

    if(visited[t]==0) {
        cout << "No path from s to t\n" <<endl;
        return;
    }

    vector<int>path;
    path.push_back(t);

    int now = t;

    while(now != s){
        now = p[now];
        path.push_back(now);
    }

    printf("distance is %d\n",dist[t]);
    for(int i=path.size()-1;i>=0;i--){
        printf("%d ",path[i]);
        if(i) cout << "-> ";
        else cout <<endl;
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
    cin>>s>>t;

    bfsPath(s,vertex);

    return 0;
}
