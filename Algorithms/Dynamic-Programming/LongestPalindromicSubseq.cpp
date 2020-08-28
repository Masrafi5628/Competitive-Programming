#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;

    cin>>str;
    int len=str.length();

    int dp[100][100];

    for(int i=0;i<len;i++)
        dp[i][i]=1;

    int k=1;

    for(int i=0;i<len;i++){
        int l=k;
        for(int j=0;l<len;j++,l++){
            if(str[j] == str[l]){
                dp[j][l]=dp[j+1][l-1]+2;
            }
            else {
                dp[j][l]=max(dp[j][l-1],dp[j+1][l]);
            }
        }
        k++;
    }


    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++)
            cout << dp[i][j] << ' ';
        cout <<endl;
    }

    cout <<dp[0][len-1]<<endl;

    return 0;
}
