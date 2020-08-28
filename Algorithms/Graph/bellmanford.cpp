#include <bits/stdc++.h>

using namespace std;

const int inf = 1<<30;

int n,e;

struct Edge {
    int u,v,w;
};

vector<Edge> adj;
int dist[100];

void bellman(int src)
{
    for(int i=0;i<n;i++) dist[i]=inf;

    dist[src]=0;

    for(int i=0;i<n;i++){
        for(Edge ed : adj){
            dist[ed.v]=min(dist[ed.v],dist[ed.u]+ed.w);
        }
        for(int i=0;i<n;i++)
            cout <<dist[i]<< ' ';
        cout <<endl;
    }

    for(int i=0;i<n;i++){
        printf("%d --> %d = %d\n",src,i,dist[i]);
    }

}

int main()
{
    cin>>n>>e;

    Edge graph;

    for(int i=0;i<e;i++){
        cin>>graph.u>>graph.v>>graph.w;
        adj.push_back(graph);
    }

    bellman(0);

    return 0;
}
