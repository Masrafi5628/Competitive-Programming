#include <bits/stdc++.h>
#define white 1
#define gray 2
#define black 3

using namespace std;
const int sz = 2e5+5;
int cycle;

vector<int>adj[sz];
vector<int>color(sz);
vector<int>temp(sz);

void dfsVisit(int vertex)
{
    color[vertex]=gray;
    temp.push_back(vertex);
    for(int i=0;i<adj[vertex].size();i++){
        if(color[adj[vertex][i]] == white)

            dfsVisit(adj[vertex][i]);

    }
}

void dfs(int vertex,int edge)
{
    for(int i=1;i<=vertex;i++){
        color[i]=white;
    }
    int cnt=0;
    for(int i=1;i<=vertex;i++){
        if(color[i]==white){
            temp.clear();
            dfsVisit(i);
            int size=temp.size(),k;

            for(k=0;k<size;k++){
                if(adj[temp[k]].size()==2)
                    continue;
                else break;
            }
            if(k==size) cycle++;
        }
    }
}

int main()
{
    int vertex,edge,u,v;

    cin>>vertex>>edge;
    for(int i=0;i<edge;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(vertex,edge);
    cout<<cycle<<endl;

    return 0;
}
