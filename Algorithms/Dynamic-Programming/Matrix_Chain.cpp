#include <bits/stdc++.h>

using namespace std;

int s[15][15];

int MatrixChainMult(int *ara,int l,int r)
{
    int cost[r+1][r+1];//stores the cost of multiplications


    for(int i=0;i<=r;i++) cost[i][i]=0;

    for(int len=1;len<r;len++){// len size er matrix er jonno
        for(int i=1;i<r;i++){
            int j=i+len;
            cost[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int temp=cost[i][k]+cost[k+1][j]+(ara[i-1]*ara[k]*ara[j]);
                if(temp<cost[i][j]){
                    cost[i][j]=temp;
                    s[i][j]=k;
                }
            }
        }
    }
    return cost[1][r];
}

void optimal_chain_order(int i,int j)
{
    if(i==j) printf("%c",i+65);
    else {
        printf("(");
        optimal_chain_order(i,s[i][j]);
        optimal_chain_order(s[i][j]+1,j);
        printf(")");
    }
}

int main()
{
    int ara[]={10, 100, 5, 50, 30};
    int len= sizeof(ara)/sizeof(ara[0]);

    printf("Minimum cost is %d\n",MatrixChainMult(ara,0,len-1));
    
    optimal_chain_order(0,len-2);
    printf("\n");

    return 0;
}
