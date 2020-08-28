#include <bits/stdc++.h>
#define inf 99999999

using namespace std;

const int lim = 110;

int adj[lim][lim];
int res[lim][lim];
int parent[lim];
bool visit[lim];

bool bfs(int node, int src, int snk)
{
    memset(visit, false, sizeof visit);
    visit[src] = true;
    queue<int>q;
    q.push(src);

    while(!q.empty()) {
        int u = q.front();q.pop();
        for(int v=1; v<=node; v++){
            if(!visit[v] && res[u][v] > 0) {
                visit[v] = true;
                q.push(v);
                parent[v] = u;
            }
        }
    }
    return (visit[snk] == true);
}

int solve(int node, int src, int snk)
{
    for(int i=1; i<=node; i++){
        for(int j=1; j<=node; j++){
            res[i][j] = adj[i][j];
        }
    }
    int mx_flow = 0 ;
    while(bfs(node, src, snk)) {
        int u, v;
        int path_flow = inf;

        for(v=snk; v != src; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, res[u][v]);
        }
        for(v=snk; v != src; v = parent[v]) {
            u = parent[v];
            res[u][v] -= path_flow;
            res[v][u] -= path_flow;
        }
        mx_flow += path_flow;
    }
    return mx_flow;
}

int main()
{
    int node, edge, kase=1;
    while(cin>>node, node != 0) {
        
        int src, snk, con;
        memset(adj, 0, sizeof adj);
        memset(res, 0, sizeof res);
        memset(parent, 0, sizeof parent);

        
        cin>>src>>snk>>con;

        for(int i=1; i<=con; i++){
            int u, v, c;
            cin>>u>>v>>c;
            adj[u][v] += c;
            adj[v][u] += c;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n", kase++, solve(node, src, snk));
    }

    return 0;
}
