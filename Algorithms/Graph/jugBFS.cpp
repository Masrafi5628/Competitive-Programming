#include<bits/stdc++.h>
#define make_pair mp

using namespace std;

typedef pair<int,int> pii;

void BFS(int a,int b,int target)
{
    map<pii,int> m;
    bool isSolvable = false;
    vector<pii> path;

    queue<pii>q;
    q.push({0,0});

    while(!q.empty()){
        pii u =q.front();
        q.pop();

        if(m[{u.first,u.second}] == 1)
            continue;
        if(u.first>a || u.second>b ||
           u.first<0 || u.second<0)
            continue;

        path.push_back({u.first,u.second});

        m[{u.first,u.second}]=1;

        if(u.first == target || u.second == target){

            isSolvable=true;

            if(u.first == target){
                if(u.second != 0){
                    path.push_back({u.first,0});
                }
            }
            else {
                if(u.first != 0)
                path.push_back({0,u.second});
            }

            int sz=path.size();
            for(int i=0;i<sz;i++){
                printf("(%d,%d)\n",path[i].first,path[i].second);
            }
            break;
        }
        q.push({u.first,b});// fill jug 2
        q.push({a,u.second});// fill jug 1

        for(int ap=0;ap<=max(a,b);ap++){
            int c = u.first+ap;
            int d = u.second-ap;

            if(c==a || (d==0 && d>=0))
                q.push({c,d});

            c = u.first-ap;
            d = u.second+ap;

            if((c==0 && c>=0) || d == b)
                q.push({c,d});
        }
        q.push({a,0});// Empty jug 2
        q.push({0,b});// Empty jug 1

    }
    if(!isSolvable)
        printf("No Solution\n");
}

int main()
{
    int m,n,d;
    cin>>m>>n>>d;

    BFS(m,n,d);

    return 0;
}
