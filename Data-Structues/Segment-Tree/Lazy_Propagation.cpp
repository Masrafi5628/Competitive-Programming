#include <bits/stdc++.h>

using namespace std;
int ara[1000];

struct info {
    long long sum=0,prop=0;
} tree[4000];

void segment(int node,int b,int e)
{
    if(b==e)  {
        tree[node].sum=ara[b];
        return;
    }
    int mid=(b+e)/2;

    segment(node*2,b,mid);
    segment(node*2+1,mid+1,e);

    tree[node].sum=tree[node*2].sum + tree[(node*2)+1].sum;
}

void update(int node,int b,int e,int i,int j,int x)
{
    if(i>e || j<b) return;
    if(b>=i && e<=j) {
        tree[node].sum+=(e-b+1)*x;
        tree[node].prop+=x;
        return;
    }
    int left=node*2;
    int right=(node*2) +1;
    int mid=(b+e)/2;

    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);

    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}

int query(int node,int b,int e,int i,int j,int carry=0)
{
    if(i>e || j<b) return 0;
    if(b>=i && e<=j) {
        return tree[node].sum+(e-b+1)*carry;
    }
    int left,right,mid,p1,p2;
    left=node*2;
    right=node*2+ 1;
    mid=(b+e)/2;

    p1=query(left,b,mid,i,j,carry+tree[node].prop);
    p2=query(right,mid+1,e,i,j,carry+tree[node].prop);

    return p1+p2;
}

int main()
{
    int n,q;
    cout << "Enter number of elements\n";
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ara[i];
    segment(1,0,n-1);
    for(int i=1;i<=14;i++){
        cout <<tree[i].sum<< " ";
    }
    cout <<endl;
    cout << "sum of the range [3,5] " <<query(1,0,n-1,3,5)<<endl;
    update(1,0,n-1,2,5,3);
    cout << "sum of the range [3,5] " <<query(1,0,n-1,3,5)<<endl;

    return 0;
}
