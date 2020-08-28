#include <bits/stdc++.h>

using namespace std; 
#define N 100000 

 
vector<int> gr1[N], gr2[N]; 

bool vis1[N], vis2[N]; 
 
void dfs1(int x) 
{ 
    vis1[x] = true; 

    for (auto i : gr1[x]) 
        if (!vis1[i]) 
            dfs1(i); 
} 

void dfs2(int x) 
{ 
    vis2[x] = true; 

    for (auto i : gr2[x]) 
        if (!vis2[i]) 
            dfs2(i); 
} 

bool Is_Connected(int n) 
{ 
    memset(vis1, false, sizeof vis1); 
    dfs1(1); 
 
    memset(vis2, false, sizeof vis2); 
    dfs2(1); 

    for (int i = 1; i <= n; i++) { 

        if (!vis1[i] && !vis2[i]) 
            return false; 
    } 
    return true; 
} 
 
int main() 
{ 

    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        gr1[u].push_back(v); 
        gr2[v].push_back(u);
    }
 
    if (Is_Connected(n)) 
        cout << "Yes"; 
    else
        cout << "No"; 

    return 0; 
} 
