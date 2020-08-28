#include <bits/stdc++.h>

using namespace std;
int parent[10000];

void init(int n)
{
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
}

int Find(int r)
{
    if(parent[r]==r) return r;
    parent[r]=Find(parent[r]);
    return parent[r];
}

void make_friend(int p,int q)
{
    parent[p]=q;
}

void check(int x,int y)
{
    int p=Find(x);
    int q=Find(y);

    if(p!=q){
        make_friend(p,q);
        cout<< "Make friend\n";
        return;
    }
    cout << "They already friends\n";
}

int main()
{
    int n;
    cin>>n;

    init(5);

    make_friend(2,3);
    make_friend(1,3);
    make_friend(4,5);

    cout << Find(5) <<endl;
    check(2,3);
    check(1,2);

    return 0;
}
