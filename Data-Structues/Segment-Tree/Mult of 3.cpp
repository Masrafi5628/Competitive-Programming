#include <bits/stdc++.h>

using namespace std;

const int sz = 100005;

int tree[3][4*sz];
int cnt[4*sz];

void build_segment(int node, int st, int ed)
{
    if(st == ed){
        tree[0][node] = 1;
        tree[1][node] = 0;
        tree[2][node] = 0;
        return;
    }
    int mid = st+(ed-st)/2;
    build_segment(node*2, st, mid);
    build_segment(node*2+1, mid+1, ed);

    tree[0][node] = tree[0][node*2]+tree[0][node*2+1];
    tree[1][node] = tree[1][node*2]+tree[1][node*2+1];
    tree[2][node] = tree[2][node*2]+tree[2][node*2+1];
}

void update(int node, int st, int ed, int l, int r)
{
    if(cnt[node]){

        if(cnt[node]%3==1){
            int temp=tree[1][node];
            tree[1][node]=tree[0][node];
            tree[0][node]=tree[2][node];
            tree[2][node]=temp;
        }
        else if(cnt[node]%3==2){
            for(int i=0; i<2; i++){
                int temp=tree[1][node];
                tree[1][node]=tree[0][node];
                tree[0][node]=tree[2][node];
                tree[2][node]=temp;
            }
        }

        if(st != ed){
            cnt[node*2] += cnt[node];
            cnt[node*2+1] += cnt[node];
        }
        cnt[node]=0;

    }

    if(r<st || ed<l)
        return;
    if(l<=st && ed<=r){
        int temp=tree[1][node];
        tree[1][node]=tree[0][node];
        tree[0][node]=tree[2][node];
        tree[2][node]=temp;

        if(st != ed){
            cnt[node*2]++;
            cnt[node*2+1]++;
        }

        return;
    }
    int mid = st+(ed-st)/2;

    update(node*2, st, mid, l, r);
    update(node*2+1, mid+1, ed, l, r);

    int lft=node*2;
    int rgt=lft+1;
    for(int i=0; i<3; i++)
        tree[i][node] = tree[i][lft]+tree[i][rgt];

}

int query(int node, int st, int ed, int l, int r)
{
    //printf("node %d cnt %d prop %d\n", node, cnt[node], prop);

    if(r<st || ed<l)
        return 0;

    if(cnt[node]){

        if(cnt[node]%3==1){
            int temp=tree[1][node];
            tree[1][node]=tree[0][node];
            tree[0][node]=tree[2][node];
            tree[2][node]=temp;
        }
        else if(cnt[node]%3==2){
            for(int i=0; i<2; i++){
                int temp=tree[1][node];
                tree[1][node]=tree[0][node];
                tree[0][node]=tree[2][node];
                tree[2][node]=temp;
            }
        }

        if(st != ed){
            cnt[node*2] += cnt[node];
            cnt[node*2+1] += cnt[node];
        }
        cnt[node]=0;

    }

    if(l<=st && ed<=r){
        return tree[0][node];
    }
    int mid=st+(ed-st)/2;

    int p1=query(node*2, st, mid, l, r);
    int p2=query(node*2+1, mid+1, ed, l, r);
    //printf("node %d p1 %d p2 %d\n", node, p1, p2);

    return p1+p2;
}

int main()
{
    int n, q, a, b, c;
    scanf("%d%d", &n, &q);

    memset(tree, 0 , sizeof tree);

    build_segment(1, 1, n);

    while(q--){
        scanf("%d%d%d", &a, &b, &c);

        if(a){
            printf("%d\n", query(1, 1, n, b+1, c+1));
            /*for(int i=0; i<3; i++){
            printf("bagses %d\n", i);
            for(int j=0; j<=7;j++){
                printf("%d ", tree[i][j]);
            }
            printf("\n");
            }*/
        }else {
            update(1, 1, n, b+1, c+1);
        }
        
    }

    return 0;
}