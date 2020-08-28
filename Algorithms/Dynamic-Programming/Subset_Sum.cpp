#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;

    n=10;
    int ara[]={0,2,3,7,8,10};

    bool dp[100][100];

    for(int i=0;i<=5;i++) dp[i][0]=true;

    for(int i=1;i<=5;i++){
        for(int j=1;j<=n;j++){

            if(j<ara[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j] || dp[i-1][j-ara[i]];
        }
    }
    if(dp[5][n]==true) {
        cout << "Yes\n";

        // Printing subset which is equal to n
        for(int i=(sizeof(ara)/sizeof(ara[0]))-1;i>=0;){
            if(dp[i][n] == false){
                cout << ara[i+1] << ' ';
                n-=ara[i+1];
                i--;
            }
            else i--;
        }
        cout << endl;
    }
    else cout << "No\n";

    return 0;
}

