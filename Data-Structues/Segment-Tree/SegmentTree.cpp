#include <bits/stdc++.h>

using namespace std;

int a[10005],tree[40006];

///Complexity will be O(n)
void build_segment(int node,int start,int end)
{
    if(start==end) {
        tree[node]=a[start];
        return;
    }
    int mid=(start+end)/2;
    build_segment(2*node,start,mid);
    build_segment(2*node+1,mid+1,end);

    tree[node]=tree[node*2]+tree[node*2+1];
}

///Complexity will be O(log2n)
void update(int node,int start,int end,int idx,int val)
{
    if(start==end) {
        a[idx]=val;
        tree[node]=val;
        return;
    }
    int mid=(start+end)/2;

    if(start<=idx && idx<=mid){
        update(node*2,start,mid,idx,val);
    }
    else {
        update(node*2+1,mid+1,end,idx,val);
    }

    tree[node]=tree[node*2]+tree[node*2+1];
}

///Time complexity will be O(log2n)
int query(int node,int start,int end,int l,int r)
{
    if(end<l or r<start) return 0;//completely outside of the range
    else if (start >= l and end <= r) {
        return tree[node];//completely inside of the range
    }
    else {
        int mid=(start+end)/2;
        int p1=query(node*2,start,mid,l,r);
        int p2=query(node*2+1,mid+1,end,l,r);

        return p1+p2;// Partially inside and Partially outside
    }
}
int main()
{
    int n,m,l,r,ans;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build_segment(1,1,n);

    for(int i=0;i<m;i++){
        char ch;
        cin>>ch>>l>>r;

        if(ch=='q')
             ans = query(1,1,n,l,r);
        else
            update(1,1,n,l,r);

        cout <<ans<<endl;

    }

    return 0;
}
