#include <bits/stdc++.h>

using namespace std;

int rod_cutter(int *cost, int n)
{
    int rod[n+1];
    rod[0]=0;

    for(int i=1;i<=n;i++){
        int max_val=INT_MIN;
        for(int j=1;j<=i;j++){
            max_val=max(max_val,cost[j]+rod[i-j]);
        }
        rod[i]=max_val;
    }
    return rod[n];
}

int main()
{
    int cost[]={0,2,4,5,7};
    int n;

    cin>>n;

    cout << rod_cutter(cost, n)<<endl;

    return 0;
}
