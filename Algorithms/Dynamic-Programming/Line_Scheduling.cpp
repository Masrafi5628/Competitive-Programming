#include <bits/stdc++.h>

using namespace std;

void Optimal(int l,int n,vector<vector<int> >line)
{
    int i=l;
    int ara[n+1];
    ara[n]=l;
    for(int j=n-1;j>=1;j--){
        if(i%2==0) ara[j]=i=line[1][j];
        else ara[j]=i=line[0][j];
    }

    for(int i=1;i<=n;i++){
        printf("Line %d Station %d\n",ara[i],i);
    }
}

int assembly_line(int n,int *entry,int *exit,vector<vector<int> >station,vector<vector<int> >transfer)
{
    int dp[2][n+1];
    vector<vector<int> >line(2,vector<int> (n+1));

    dp[0][0]=entry[0]+station[0][0];
    dp[1][0]=entry[1]+station[1][0];

    for(int i=1;i<n;i++){

        // for station i of assembly line 1
        dp[0][i]=min(dp[0][i-1],dp[1][i-1]+transfer[1][i-1])+station[0][i];

        if(dp[0][i-1]<=dp[1][i-1]+transfer[1][i-1]){
            line[0][i]=1;
        }else {
            line[0][i]=2;
        }

        // for station i of assembly line 2
        dp[1][i]=min(dp[1][i-1],dp[0][i-1]+transfer[0][i-1])+station[1][i];

        if(dp[1][i-1]<=dp[0][i-1]+transfer[0][i-1]){
            line[1][i]=2;
        }else {
            line[1][i]=1;
        }
    }
    for(int i=0;i<n;i++){
        cout << line[0][i]<< ' ';
    }
    cout <<endl;

    for(int i=0;i<n;i++){
        cout << line[1][i]<< ' ';
    }
    cout <<endl;

    dp[0][n]=dp[0][n-1]+exit[0];
    dp[1][n]=dp[1][n-1]+exit[1];

    int ans,temp;

    if(dp[0][n]<dp[1][n]){
        ans=dp[0][n];
        temp=1;
    }
    else {
        ans=dp[1][n];
        temp=2;
    }
    Optimal(temp,n,line);
    return ans;

}

int main()
{
    int entry[2],exit[2];


    int n;
    printf("Enter no of stations: ");
    cin>>n;

    vector<vector<int > >station(2,vector<int>(n));
    vector<vector<int > >transfer(2,vector<int>(n));

    printf("Enter the entry cost for assembly line 1 and 2\n");
    cin>>entry[0]>>entry[1];

    printf("Enter the exit cost for assembly line 1 and 2\n");
    cin>>exit[0]>>exit[1];

    printf("Enter the processing time for assembly line 1\n");
    for(int i=0;i<n;i++)
        cin>>station[0][i];

    printf("Enter the processing time for assembly line 2\n");
    for(int i=0;i<n;i++)
        cin>>station[1][i];

    printf("Enter the transfer time for assembly line 1 to 2\n");
    for(int i=0;i<n-1;i++)
        cin>>transfer[0][i];

    printf("Enter the transfer time for assembly line 2 to 1\n");
    for(int i=0;i<n-1;i++)
        cin>>transfer[1][i];

    printf("Minimum %d time are required to jobs done\n",assembly_line(n,entry,exit,station,transfer));

    return 0;
}
