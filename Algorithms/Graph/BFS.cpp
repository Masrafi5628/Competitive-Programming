#include <bits/stdc++.h>

using namespace std;

const int inf = 1e5;

vector<int> adj[100];
int visited[100];
int level[100];

void BFS(int starting_vertex,int total_node)
{
    queue<int>q;

    q.push(starting_vertex);
    visited[starting_vertex] = 1;// visit hoice kina
    level[starting_vertex]=0;// shortest path rakar jonno, source teke

    //cout << starting_vertex<< ' ';

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v=0;v<adj[u].size();v++){
            int x=adj[u][v];

            if(!visited[x]){
                //cout <<x << ' ';
                visited[x]=1;
                level[x]=level[u]+1;
                q.push(x);
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
        //adj[v].push_back(u);
    }

    for(int i=1;i<=vertex;i++)
        visited[i]=0,level[i]=inf;// 0 if not visited,1 if visited

    int component = 0;
    for(int i=1;i<=vertex;i++){
        if(visited[i]==0){
            component++;
            BFS(i,vertex);
        }

    }
    cout <<component << endl;
    for(int i=1;i<=vertex;i++){
        printf("%d --> %d = %d\n", 1, i, level[i]);
    }

    return 0;
}
