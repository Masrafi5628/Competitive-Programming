#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str1;
    string str2;

    cin>>str1>>str2;

    int dp[100][100];

    int len1=str1.length(),len2=str2.length();

    dp[0][0]=0;
    for(int i=1;i<=len1;i++)
        dp[0][i]=i;
    for(int i=1;i<=len2;i++)
        dp[i][0]=i;

    for(int i=1;i<=len2;i++){
        for(int j=1;j<=len1;j++){
            if(str2[i-1] == str1[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else {
                dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
            }
        }
    }

    cout <<dp[len2][len1]<<endl;

    return 0;
}
